#include <iostream>
#include <Player.h>
#include <Arrows.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <Enemy.h>
#include <Score.h>
using namespace std;

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h,c);
}
//loop contains the functions required to run the game. It is called whenever the game is run
void loop(){
    srand(time(0));
    system("cls");
    cout << "Enter a difficulty : ";
    cout << "\n1)Easy\n2)Medium\n3)Hard\n";
    int op , xfactor;
    cin >> op;
    switch(op)
    {
    case 1:
        op = 40;
        xfactor = 1;
        break;
    case 2:
        op = 30;
        xfactor = 2;
        break;
    case 3:
        op = 20;
        xfactor = 3;
        break;
    default:
        op = 40;
        xfactor = 1;
    }
    enemy e(op);
    player p;
    char ar[5][width];
    for(int i =0; i < 5; i++){
        strcpy(ar[i] , "|                                    |");
    }
    char input;
    long score = 0;
    p.create(ar);
    e.create(ar);
    arrow health;
    system("cls");
    //cout << "Player Health : " << health.playerHealth() << "\nEnemy Health : " << health.enemyHealth();
    ifstream gfile ("game.txt" , ios::in);
    char o;
    while(gfile.get(o)) {
        cout << o;
    }
    gfile.close();
    while(1)
    {
        gotoxy(0 , 20);
        for(int i = 0; i < 5; i++){
            cout << "\t\t\t\t\t\t\t\t" << ar[i] << '\n';
        }
        if(_kbhit() == 1){
            input = getch();
        }
        p.movement(ar , input);
        p.ArrowRun(ar);
        p.deleter();
        e.jumping(ar);
        e.attack(ar);
        e.ArrowRun(ar , 0);
        e.deleter(0);
        health.playerHealth(ar);
        health.enemyHealth(ar);
        Sleep(30);
        input = 'x';
        score += xfactor;
        if(health.playerDead()){
            char c;
            ifstream ifile ("endgame2.txt" , ios::in);

            system("cls");
            while(ifile.get(c)) {
                cout << c;
            }
            getch();
            getch();
            cout << "\nNo scores for you too bad.... \:-( \n";
            break;
        }
        if(health.enemyDead()){
            char c;
            ifstream ifile ("endgame1.txt" , ios::in);

            system("cls");
            while(ifile.get(c)) {
                cout << c;
            }
            getch();
            getch();
            createFile(score);
            break;
        }
    }
    getch();
    displayFile();

}

//About the game / tutorial
void readFile() {
    system("cls");
    char c;
    //Opening the text file
    ifstream ifile ("about.txt" , ios::in);

    while(ifile.get(c)) {
        cout << c;
    }
    ifile.close();
    getchar();
}


//Access main menu
void menu() {
    ifstream ifile;

    char c , f;
    int pos = 1;
    int op = 1;
    while(op) {
            switch(pos) {
            case 1:
                system("cls");
                ifile.open("mainpage1.txt");
                while(ifile.get(c)) {
                    cout << c;
                }
                //Getting input
                f = getch();
                if (f == '\r') {
                    loop();
                }
                ifile.close();
            break;

            case 2:
                system("cls");
                ifile.open("mainpage2.txt");
                while(ifile.get(c)) {
                    cout << c;
                }
                f = getch();
                if (f == '\r') {
                    displayFile(); //Function for loading the scores
                }
                ifile.close();

            break;

            case 3:
                system("cls");
                ifile.open("mainpage3.txt");
                while(ifile.get(c)) {
                    cout << c;
                }
                f = getch();
                if (f == '\r') {
                    readFile(); //Function for loading the tutorial and about the game
                }
                ifile.close();
            break;

            case 4:
                system("cls");
                ifile.open("mainpage4.txt");
                while(ifile.get(c)) {
                    cout << c;
                }
                f = getch();
                if (f == '\r') {
                   op = 0;
                }
                ifile.close();
            break;

        }
        if (f == '\t') {
            pos++;
        }
        if (pos > 4) {
            pos = 1;
        }

    }
}

int main() {
    menu();
    return 0;
}
