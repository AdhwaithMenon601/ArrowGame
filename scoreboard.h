#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>

//Class for object that stores file data
class Score {
	long score;
	char* name;

public :
	Score(long input ,char* nm) {
		score = input;
		strcpy (name , nm);
	}
	Score(long a) {
		score = a;
	}
	void display();
};


//Function definitions
void createFile(long input) {
	ofstream ofile ("Scores.dat" , ios::binary | ios::app | ios::out);
	//Creating object of class
	char nm[100];
	system("cls");
	std::cout << "Please enter the name \n" ;
	cin.getline(nm, 100);
	Score obj(input , nm);


	//Writing into file
	ofile.write (char*(&obj) , sizeof(obj));

	ofile.close();
}

void displayFile() {
	ifstream ifile ("Scores.dat" , ios::in | ios::binary);

	Score obj(2);
	//Reading the files or a score
	system("cls");
	ifstream file ("scores.txt" , ios::in);
	char c;
	while(file.get(c)) {
        std::cout << c;
	}
	file.close();
	std::cout << "\n\n";

	std::cout << "\t\t" << "NAMES" << "\t\t\t\t" << "SCORES" << "\n";

	while(ifile.read(char*(&obj) , sizeof(obj)) {
		obj.display();
	}


	ifile.close();
}

//Class methods
void Score::display() {
    std::cout << name << "\t\t" << score;
    std::cout << '\n';
}

#endif
