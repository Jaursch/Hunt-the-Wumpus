/*******************************************************************************
 ** Filename: huntdawumpus
 ** Author: Burton Jaursch
 ** Date: 5/24/2016
 ** Description: Simple polymorphic hunt the wumpus game
 ** Input: command line integer 
 ** Output: Game(?) 
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "./game.h" 
using namespace std;

int main(int argc, char ** argv){
   	int size, choice = 1;
   	if(argc != 2){
		cout << "Please enter the size of your map: ";
	     	cin >> size;	
	}else
	   	size = atoi(argv[1]); 
	if(size < 4)
	 	while(size < 4){ 	
			cout << "Please enter a number greater than 3: ";
		       	cin >> size;	
		}
	cout << "Welcome to Burt's Hunt the Wampus!" << endl;
	cout << "You have decided to make your board a " << size;
	cout << "x" <<size << " size! Have fun!" << endl;
	game g(size);
       	g.add_events();
	g.add_jeremy(); 	
	//g.print_board();
	cout << "Jeremy, you've entered the cave. Good luck kid." << endl;
	cout << "You are given 3 arrows. Don't miss." << endl;
	g.play_game(); 
	g.end_game(); 	
		

} 
