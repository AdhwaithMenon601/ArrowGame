#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <Arrows.h>


//player.h contains the player class which acts as a base class for the other classes in the game as well as being the player character

class player
{
private:
    arrow A[30];
    int isAttacking;

protected:
    char spr; //The Character of the object
    int xpos; //Xposition
    int ypos; //Yposition
    int isJumping; //A variable used for jumping
    int ArrowCount; //The number of arrows
public:
    player()
    {
        spr = '*';
        isJumping = 0;
        isAttacking  = 0;
        xpos = width / 2;
        ypos = 2;
        ArrowCount = 0;
    }
    void create(char field[][width]);
    void movement(char field[][width] , char inp);
    void jumping(char field[][width] , char inp);
    void deleter();
    void ArrowRun(char field[][width]);
    void attack(char field[][width] , char inp);
};

//create initializes the object on the field
void player::create(char field[][width]){
    field[ypos][xpos] = spr;
}

//movement is the code which allows the player to move
void player::movement(char field[][width] , char inp){

    switch(inp)
    {
    case 'a' :
        xpos--;
        if(field[ypos][xpos] == '|'){
            xpos++;
        }else{
            field[ypos][xpos] = spr;
            field[ypos][xpos + 1] = ' ';
        }
        jumping(field , inp);
        break;
    case 'd' :
        xpos++;
        if(field[ypos][xpos] == '|'){
            xpos--;
        }else{
            field[ypos][xpos] = spr;
            field[ypos][xpos - 1] = ' ';
        }
        jumping(field , inp);
        break;
    case ' ' :
        attack(field , inp);
        break;
    default:
        jumping(field , inp);

    }
    if(isAttacking > 0 )
        isAttacking--;
}

//this is the code that allows the player to jump
void player::jumping(char field[][width] , char in){
    if(isJumping == 0){
        if(in == 'w'){
        ypos = 1;
        field[ypos][xpos] = spr;
        field[ypos + 1][xpos] = ' ';
        isJumping++;
        }
    }else{
        if(isJumping == 2){
            ypos = 0;
            field[ypos][xpos] = spr;
            field[ypos + 1][xpos] = ' ';
        }
        if(isJumping == 3){
            ypos = 1;
            field[ypos][xpos] = spr;
            field[ypos - 1][xpos] = ' ';
        }
        isJumping++;
        if(isJumping == 5){
            ypos = 2;
            field[ypos][xpos] = spr;
            field[ypos - 1][xpos] = ' ';
            isJumping = 0;
        }
    }
    //std::cout << "\nXpos : " << xpos << "\nYpos : " << ypos << "\nIsjumping : " << isJumping ;
}

//This code removes any arrows that have collided with something from the array
void player::deleter(){
    for(int i = 0; i < ArrowCount; i++){
        if(!A[i].exist()){
            for(int j = i; j < ArrowCount; j++)
                A[j] = A[j+1];
            ArrowCount--;
        }
    }
}

//This code causes every existing arrow to move
void player::ArrowRun(char field[][width]){
    for(int i = 0; i <= ArrowCount; i++){
        A[i].movement(field);
    }
}

void player::attack(char field[][width] , char inp){
    if(isAttacking == 0){
        if(inp == ' '){
            A[ArrowCount++].create(field , xpos - 1 , ypos , -1 , '<');
            isAttacking = 20;
        }
    }
}

#endif // PLAYER_H_INCLUDED
