// Simple Snake Game C++
// Created by Wilson Fransicius Willyam Lo
// Student at International Bina Nusantara
// Majoring in Computer Science
// ID 2001585303
// © 2016 Wilson Fransicius

#include <iostream>
#include <conio.h>					//for the direction input
#include <stdlib.h>					//for random
using namespace std;


class Something
{
private:
	int x, y, foodX, foodY;				// X, Y Coordinate
public:
	int width = 75;						// Cage width
	int height = 35;					// Cage height
	bool gameOver = false;				// logic
	enum direction {START = 0, LEFT, RIGHT, UP, DOWN}; // for the direction
	direction dir;
	
	Something(int, int);
};

Something::Something(int x, int y){
	this->x = x;
	this->y= y;
}

void base();
void cage();
void snake();
void logic();

int main(){
	
	/*base();
	while (!gameOver){
		cage();
		snake();
		logic();
	}
	*/
	base();
	cage();
	
	return 0;	
}


void base(){					// Base logic
	Something something;
	something.gameOver = false;
	something.dir = START;
	x = width/2;
	y = height/2;
	foodX = rand() % width;		//Generate random food X coordinate
	foodY = rand() % height;	//Generate random food Y coordinate
}

void cage(){
	// system("cls");
	for (int i = 0; i < width; i++){
		
		cout << "&";
	}
	
	cout << endl;
	
	for (int k = 0; k < height; k++){ // for Y
		
		for (int l=0; l < width; l++){ // for X
		if (l ==0){
			
			cout << "x";
		}
		if (l == width-2){
			cout << "x" << endl;
		}
		
		
		if (l == x && k == y){
			cout << "S";				//Snake starts here
		}
		else if (l == foodX && k == foodY){
			cout << "F";
		}
		
	    else {
			cout << " ";
		}
		
				
	
	}
	}
		
	for (int j = 0; j < width; j++){
		
		cout << "&";
	}
	
}

void snake(){
}

void logic(){
	
}

