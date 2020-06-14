#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <Arrows.h>



//the enemy class represents the enemy
class enemy:public player
{
private:
    arrow B[30]; //An array of all the arrows fired by the enemy
    int diff; //The difficulty , can only be set during initialization
public:
    enemy(int d)
    {
        xpos = 1;
        ypos = 2;
        spr = '&';
        isJumping = 0;
        diff = d;
        ArrowCount = 0;
    }
    void jumping(char field[][width]);
    void attack(char field[][width]);
    void deleter(int a);
    void ArrowRun(char field[][width] , int a);
};

//This code causes the enemy to occasionally jump
void enemy::jumping(char field[][width]){
    if(isJumping == 0){
        if((rand() % 60 + 1) == 5){
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
}

//This code causes the enemy to attack
void enemy::attack(char field[][width]){

    if((rand() % diff + 1) == 1){
        B[ArrowCount].create(field , xpos + 1 , ypos , 1 , '>');
        ArrowCount++;
    }
}
void enemy::deleter(int a){
    for(int i = 0; i < ArrowCount; i++){
        if(!B[i].exist()){
            for(int j = i; j < ArrowCount; j++)
                B[j] = B[j+1];
            ArrowCount--;
        }
    }
}

//This code causes every existing arrow to move
void enemy::ArrowRun(char field[][width] , int a){
    for(int i = 0; i <= ArrowCount; i++){
        B[i].movement(field);
    }
}


#endif // ENEMY_H_INCLUDED
