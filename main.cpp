// Simple Snake Game C++
// Created by Wilson Fransicius Willyam Lo
// Student at International Bina Nusantara
// Majoring in Computer Science
// ID 2001585303
// © 2016 Wilson Fransicius

#include "Function.hpp"
char name[100];

int main()
{	
	
	cout << "Enter Nickname: ";
	cin.getline (name, 100);
	Menu();
	
	system ("cls");
	cout << "Congrats "<< name << ", your Score is: " << score<< endl << endl;
	
	if(score>=0 && score<=20)
	{
		cout << "\nThis game is hard, why don't give it one more try? :)";
	}
	else if (score>20 && score <=35)
	{
		cout << "\nPlaying SNEK is fun, but don't forget to study!";
	}
	else if (score>35 && score <=55)
	{
		cout << "\nWhoaa, we have a pro here, enough playing, go study!";
	}
	else if (score>=55 && score <=100)
	{
		cout << "\nGODLIKE";
	}
	else
	{
		cout << "ENOUGH! NOW STUDY!!!";
	}
	
	return 0;
}
