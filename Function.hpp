#ifndef Function_hpp
#define Function_hpp
#include <iostream>
#include <cstdlib>	//rand()
#include <conio.h>	// user input (kbhit, getch)
#ifdef _WIN32		
#include <Windows.h>// for windows user (sleep)
#else				
#include <unistd.h>	// for other than windows user
#endif
using namespace std;
int x, y, foodX, foodY, score;
int width = 75;
int height = 20;
bool gameOver;
enum direction {START=0, LEFT, RIGHT, UP, DOWN};
direction dir;
int arrX[100], arrY[100], body;
/*
void Base();	//basic setup
void Cage();	//cage
void Body();	//snake body
void Input();	//user input (w,a,s,d)
*/	
void Base()
{	
	gameOver = false;
	dir = START;				//START = 0 = middle of the cage
	x = width/2;				//start position x for snake
	y = height/2;				//start position y for snake
	foodX = rand() % width;		//Generate random food X coordinate
	foodY = rand() % height;	//Generate random food Y coordinate
}

void Cage()
{
	system("cls"); // clear screen
	cout << " ";
	for (int i = 0; i < width+1; i++)	// first row
	{		
		cout << "#";
	}
	cout << endl << " ";	// to seperate & and X
	for (int k = 0; k < height; k++) //Y
	{	
		for (int l=0; l < width; l++) //X
		{ 
			if (l ==0)	//left column
			{
				cout << "#";
			}
			if (l == width-1) // right column
			{
				cout << "#" << endl;
			}
			if (l == x && k == y) // snake head logic
			{
				cout << "S";
			}
			else if (l == foodX && k == foodY)	//random food logic
			{
				cout << "O";
			}
			
		}
	}
	for (int j = 0; j < width+1; j++)	// last row
	{
		cout << "#";
	}
	cout << endl << " Score: "<< score << endl;
	cout << "---------- Press [X] to Exit ---------" << endl;	
}

void Body()
{
	int prevX = arrX[0];	// to remember the before body parts of snake before eat 
	int prevY = arrY[0];
	int prev2X, prev2Y;	
	arrX[0] = x;		// to make the body follow its head
	arrY[0] = y;	
	for (int i=1; i < body; i++)
	{
		prev2X = arrX[i];		// the 2 prev body follow the prev body
		prev2Y = arrY[i];
		arrX[i] = prevX;		// change(update) its value to prevX
		arrY[i] = prevY;
		prevX = prev2X;			// prev X to follow the head
		prevY = prev2Y;
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;	// decrease the y value
			break;
		case DOWN:
			y++;	// increase the y value
			break;
		default:
			break;
	}	
	for (int i = 0; i < body; i++)					// to make it's game over when snake eat itself
	{
		if (arrX[i] == x && arrY[i]==y)
		{
			gameOver = true;
		}
	}	
	if (x == foodX && y == foodY)	// body ++ when eat food
	{
		body++;
		score += 5;
		foodX = rand() % width;		// new food x
		foodY = rand() % height;	// new food y
	}
	else
	{
		bool follow = false;	
		for (int m=0; m<body; m++)	//to make the body follow its head
		{			
			if (arrX[m] == l && arrY[m] == k)	// loop to make body ++ when 
			{
				cout << "o";
				follow = true;
			}
		}		
		if(!follow)	//if the body follows the head, it should print blank space
		{
			cout << " ";
		}
	}
}

void Input()
{
	if (_kbhit())	//determines if a keyboard was pressed
	{
		switch (_getch())	//reads a charcter from keyboard
		{
			case 'a' :
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':		// press x to terminate the snek
				gameOver=true;
				break;
			default:
				break;
		}
	}
	
}
void Menu() 
{
	char input1; 
	string input2;	

	do
	{
		system("cls");
		cout << "                     #	   #  " << endl;
		cout << " ##### #####   ##### #    #  " << endl;
		cout << "#      #    # #   #  #   #   " << endl;
		cout << " ####  #    # #  #   # ##    " << endl;
		cout << "     # #    # #      #   #   " << endl;
		cout << "#####  #    #  ##### #    #  " << endl << endl << endl;
		cout << "Press [X] to Continue" << endl;
		cin >> input1;
				
	}
	while ((input1!='x') && (input1!='X'));	
	
	do
	{
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "---------- Welcome to SNEK! ----------" << endl;
		cout << "--- Press [1] to Play In Easy Mode ---" << endl;
		cout << "-- Press [2] to Play In Medium Mode --" << endl;
		cout << "--- Press [3] to Play In Hard Mode ---" << endl;
		cout << "---------- Press [X] to Exit ---------" << endl;
		cout << "--------------------------------------" << endl;
		cin >> input2;
		if (input2 == "1")
		{
			system("cls");
			Base();
			do
			{
				Cage();
				Input();
				if (x >= width) x = 0; else if (x < 0) x = width - 1;	// snek go through the walls
    			if (y >= height) y = 0; else if (y < 0) y = height - 1;
				Body();
				
				Sleep(30);
			}
			while(!gameOver);
		}
		else if (input2 == "2")
		{
			system("cls");
			Base();
			do
			{
				Cage();
				Input();
				if (x >= width) x = 0; else if (x < 0) x = width - 1;
    			if (y >= height) y = 0; else if (y < 0) y = height - 1;
				Body();
				
				Sleep(10);
			}
			while(!gameOver);
		}
		else if (input2 == "3")
		{
			system("cls");
			Base();
			do
			{
				Cage();
				Input();
				Body();
				if (x > width+1 || x < 0 || y > height || y < 0)	// to make it's game Over when snake hits the cage
				{
					gameOver = true;
				}
				Sleep(-50);			
			}
			while(!gameOver);
		}
		else if (input2 == "x" || input2 =="X")
		{
			gameOver=true;
		}		
	}
	while ((input2!="1") && (input2!="2") && (input2!="3") && (input2!="X") && (input2!="x"));                    
}
#endif
