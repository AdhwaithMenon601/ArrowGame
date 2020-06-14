#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


using namespace std;

//Class for object that stores file data
class Score {
	int score;
	char name[10];

public :
	Score() {
        score = 0;
	}
	void display() {
		std::cout << name << "\t\t" << score;
		std::cout << '\n';
	}
	void assignValues(long input , char* nm) {
        score = input;
        strcpy(name , nm);
	}
};


//Function definitions
void createFile(long input) {
	ofstream ofile ("Scores.dat" , ios::binary | ios::app);
	//Creating object of class
	char nm[10];
	system("cls");
	std::cout << "Please enter the name \n";
	std::cin.ignore(10, '\n');
	cin.getline(nm, 10);
	Score obj;

	//Putting data into the object
	obj.assignValues(input , nm);


	//Writing into file
	ofile.write((char*) &obj, sizeof(obj));

	ofile.close();
}

void displayFile() {
	ifstream ifile ("Scores.dat" , ios::binary);

	Score obj;
	//Reading the files or a score
	system("cls");
    ifstream file ("scores.txt" , ios::in);
	char c;
	while(file.get(c)) {
        std::cout << c;
	}
	file.close();
	std::cout << "\n\n";


	std::cout << "NAME" << "\t\t" << "SCORES" << '\n';

    ifile.seekg(0, ios::end);
    auto size = ifile.tellg() / sizeof obj;
    ifile.seekg(0, ios::beg);
	for (size_t i = 0; i < size; ++i) {
        ifile.read((char*) &obj, sizeof(obj));
        obj.display();
	}

	ifile.close();
	getchar();
}

//Function to sort the high score in descending order
/*void sortScore() {
    Score* obj;

    ifstream ifile ("Scores.dat" , ios::in , ios::binary);

    ifile.seekg(0, ios::end);
    auto size = ifile.tellg() / sizeof obj;
    ifile.seekg(0, ios::beg);
	for (size_t i = 0; i < size; ++i) {
        ifile.read((char*) &(obj + (i * sizeof(Score)) , sizeof(Score));
	}
	ifile.close();

	//Sorting the data of object pointer
	for (int j = 0; j < size; ++j) {
        for (int k = j + 1; k < size - 1; ++k) {
            if ((obj + (k * sizeof(Score))) < (obj + (j * sizeof(Score))) ) {
                Score *temp;
                temp = obj + (k * sizeof(Score))
                obj + (k * sizeof(Score)) = obj + (j * sizeof(Score));
                obj + (j * sizeof(Score)) = temp;
            }
        }
	}
}*/

#endif  //SCORE_H_INCLUDED
