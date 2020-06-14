#ifndef ARROWS_H_INCLUDED
#define ARROWS_H_INCLUDED
#include <iostream>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define width 40

//the arrow class is used for the arrows. It records how many times the player and the enemy have been hit by arrows
class arrow
{
    int xpos;
    char spr;
    int ypos;
    int dir; //The direction of the arrow
    bool exists;
    static int php; //The players hp
    static int ehp;
public:
    arrow()
    {
        xpos = 0;
        ypos = 0;
        dir = 0;
        exists = false;
        php = 6;
        ehp = 10;
    }
    void movement(char field[][width]);
    void create(char field[][width] , int x , int y , int d , char s);
    static void pdmg()
    {
        php--;
    }
    static void edmg()
    {
        ehp--;
    }
    bool exist(){
        return exists;
    }
    void playerHealth(char field[][width]){
        strcpy(field[4] , "                                      ");
        for(int i = 0 ; i < php; i++){
            field[4][width - i - 3] = 'o' ;
        }
    }
    void enemyHealth(char field[][width]){
        for(int i = 0 ; i < ehp; i++){
            field[4][i] = 'o' ;
        }
    }
    bool playerDead(){
        if(php <= 0)
            return true;
        return false;
    }
    bool enemyDead(){
        if(ehp <= 0)
            return true;
        return false;
    }
};

//Initialization of the players hp
int arrow::php = 6;
int arrow::ehp = 10;
//Draws the object on the field
void arrow::create(char field[][width] , int x , int y , int d , char s){
    spr = s;
    xpos = x;
    ypos = y;
    dir = d;
    exists = true;
    field[ypos][xpos] = spr;
}

//Controls the movement of an arrow
void arrow::movement(char field[][width]){

    if(exists){
        //std::cout  << "Walao \n";
        xpos += dir;
        if(field[ypos][xpos] == '*'){
            pdmg();
            exists = false;
        } else if(field[ypos][xpos] == '&'){
            edmg();
            exists = false;
        }else if(field[ypos][xpos] == '|'){
            exists = false;
        } else {
            field[ypos][xpos] = spr;
        }
        field[ypos][xpos - dir] = ' ';
    }
}


#endif // ARROWS_H_INCLUDED
