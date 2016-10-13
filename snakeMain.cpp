// Simple Snake Game C++
// Created by Wilson Fransicius Willyam Lo
// Student at International Bina Nusantara
// Majoring in Computer Science
// ID 2001585303
// © 2016 Wilson Fransicius

#include <iostream>
using namespace std;

int width = 75;
int height = 35;

void Cage();

int main(){

	Cage();
	
	return 0;	
}

void Cage(){
	// system("cls");
	for (int i = 0; i < width; i++){
		
		cout << "&";
	}
	
	cout << endl;
	
	for (int k = 0; k < height; k++){
		
		for (int l=0; l < width; l++){
		
		if (l == 0){
			cout << "*";
		}
		
		else if (l == width-1){
			cout << "x" << endl;
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


