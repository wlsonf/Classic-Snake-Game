/*28 SEPTEMBER 2016
WILSON FRANSICIUS 
2001585303
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	float time, acceleration, destination, distance;
	const int V0 = 0;
	const int MAXSPEED = 60;
	const int CONSTANT = 10;
	
	cout<< "Initial Velocity (m/s): 0 "; 
		
	cout<< "\n\nTime (s): "; //input time
	cin>> time;
	
	cout<< "\nAcceleration (a): "; //input acceleration
	cin>> acceleration;
	
	cout<< "\nDestination (m): "; //input destination
	cin>> destination;
	
	/*
	1 asterisk = 10m)
	Vt = vo + at
	vt^2 = vo^2 + 2aS
	S = vot + 1/2 at^2
	*/
	

	for (float t=0; t<time; t++){ 
				
	distance = V0 * t + acceleration * (t * t) / 2; // distance daenery's travelled
		
		cout<<"\nDuration: "<< t <<"		Distance Traveled: "<< distance;
		
		int asterisk = distance / CONSTANT;
		int x=0;
		
			while(x<asterisk){
				cout<<x;
				
				cout<< "*";
				x++;
			}	
			
	}
	
	return 0;
}
