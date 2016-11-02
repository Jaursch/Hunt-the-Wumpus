#include "./game.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*******************************************************************************
 ** Function: game
 ** Description: game constructor
 ** Parameters: int
 ** Pre-Conditions: int s has value
 ** Post-Conditions: game will be constructed
 *****************************************************************************/
game::game(int s){
   	hasgold = false;
	wumpusdead = false;
	arrows=3;
   	size = s;
	rooms = new room*[size];
	for(int i=0; i<size; i++){
		rooms[i] = new room[size];
	}for(int i=0; i<6; i++){
		if(i<2){
			events[i]=new pit;
		}else if(i>=2 && i<=3){
			events[i]=new bat;
		}else if(i==4)
		 	events[i]=new gold;
	      	else
	   		events[i]=new wumpus;	   
	} 	
}

/*******************************************************************************
 ** Function: ~game
 ** Description: game destructor
 ** Parameters: none
 ** Pre-Conditions: game constructed
 ** Post-Conditions: game destructed
 *****************************************************************************/
game::~game(){
   	for(int i=0; i<6; i++) 
		delete events[i];
	for(int i=0; i<size; i++){
		delete [] rooms[i];
	}delete [] rooms; 
}

/*game::game(const game &other){
	hasgold = other.hasgold;
	wumpusdead = other.wumpusdead;
	arrows = other.arrows;
	size = other.size;
	rooms = new room*[size];
	for(int i=0; i<size; i++){
		rooms[i] = new room[size];
	}for(int)  
	//for(int i=0; i<size; i++){
	//	for(int k=0; k<size; k++) 
	//	   	r[i][k] = new room;
	//} 
}*/

//game::operator =(const game &other){
//	hasgo

/*******************************************************************************
 ** Function: print_board
 ** Description: prints board with events and person
 ** Parameters: none
 ** Pre-Conditions: board initalized
 ** Post-Conditions: board will be printed
 *****************************************************************************/
void game::print_board(){
	for(int i=0; i<size; i++){
	   	for(int k=0; k<size; k++){
			cout << "---"; //row seperator
		}cout << endl;
	       	for(int k=0; k<size; k++){
			cout << "|";
			if(i == currentR && k == currentC ) //current location
			  	cout << "X|";  
			else if(rooms[i][k].get_event()==events[0] || rooms[i][k].get_event()==events[1]) //pits
		 		cout << "p|";
			else if(rooms[i][k].get_event()==events[2] || rooms[i][k].get_event()==events[3]) //bats
			  	cout << "b|";
		      	else if(rooms[i][k].get_event()==events[4]) //gold
		   		cout << "g|";
	     		else if(rooms[i][k].get_event()==events[5]) //wumpus
	   			cout << "w|"; 		   
			else if(rooms[i][k].get_rope() == true) //rope
			 	cout << "r|";  
			else
	   			cout << " |"; 		   
		}cout << endl; 	
	}for(int i=0; i<size; i++){
		cout << "---"; //last seperator
	}cout << endl;   
}

/*******************************************************************************
 ** Function: place
 ** Description: places event/jeremy to board where nothing else is
 ** Parameters: int &, int &
 ** Pre-Conditions: w & c must have previous value
 ** Post-Conditions: w and c will have unique location on board
 *****************************************************************************/
void game::place(int &w, int &c){
	//cout << "first: "<< w << " "  << c << endl;	   
	while(rooms[w][c].event_present() == true || (currentR==w && currentC==c )){
		w = rand() % size;
		c = rand() % size;
	//	cout << "try:"<< w << " "  << c << endl;	   
	}//cout <<"last" <<  w << " "  << c << endl;

} 

/*******************************************************************************
 ** Function: add_events
 ** Description: adds events to unique location on board
 ** Parameters: none
 ** Pre-Conditions: board initalized
 ** Post-Conditions: events added
 *****************************************************************************/
void game::add_events(){
	srand(time(NULL));
	for(int i=0; i<6; i++){ 
		int w = rand() % size;
		int c = rand() % size;
		this->place(w, c); 	
	   	rooms[w][c].set_event(events[i]); 	
	}		
		
}

/*******************************************************************************
 ** Function: add_jeremy
 ** Description: adds jeremy to the board
 ** Parameters: none
 ** Pre-Conditions: board initalized
 ** Post-Conditions: jeremy will be placed
 *****************************************************************************/
void game::add_jeremy(){
  	srand(time(NULL) );
	int w = rand() % size;
	int c = rand() % size;
      	this->place(w, c);
	currentC = c;
	currentR = w;
	rooms[w][c].set_rope(true); 	

} 

/*******************************************************************************
 ** Function: check_surroundings
 ** Description: will give percepts to screen
 ** Parameters: none
 ** Pre-Conditions: board initalized
 ** Post-Conditions: message will be printed
 *****************************************************************************/
void game::check_surrounding(){ //make messages
	cout << endl;
   	for(int r=0; r<size; r++){
		for(int c=0; c<size; c++){
			if(rooms[r][c].get_event() != NULL){
			  	if(abs(r-currentR)<=1 && abs(c-currentC)<=1){
					rooms[r][c].get_event()->message();  
			
				}
			}	
		} 
	}cout << endl; 
} 

/*******************************************************************************
 ** Function: choice
 ** Description: gives user choice to move/shoot
 ** Parameters: none
 ** Pre-Conditions: choice/arrows initalized
 ** Post-Conditions: choice will be given
 *****************************************************************************/
void game::choice(){ //returns false if game has been lost (out of arrows) 
	int choice;
   	cout << "Mr. Cole, would you like to shoot(1) or move(2)?: ";
	while(!(cin>>choice) || (choice>2 || choice<1)){
		cin.clear(); //error handling
	       	cin.ignore();
		cout << "Jeremy, please pick a choice: "; 	
	}if(choice ==1){
		this->shoot();
		if(arrows == 0 && wumpusdead==false){
			this->lost("You ran out of arrows, and it is still out there"); 
		} 
	}else
   		this->move();
} 

/*******************************************************************************
 ** Function: where
 ** Description: prints where user would like to shoot/move
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: movement given
 *****************************************************************************/
void game::where(char & direct){
	cout << " Up - u\n Down - d\n Left - l\n Right - r\n : ";
	while(!(cin>>direct) || (direct!=117 && direct!=100 && direct!=108 && direct!=114) ){
		cin.clear();
	       	cin.ignore();
		cout << "Jeremy. Please. Pick a letter: "; 	
	}
	
} 

/*******************************************************************************
 ** Function: shoot
 ** Description: will shoot arrow in inputted direction
 ** Parameters: none
 ** Pre-Conditions: game board initalized
 ** Post-Conditions: arrow will be shot
 *****************************************************************************/
void game::shoot(){
   	srand(time(NULL)); 
	cout << "Smelling that old furball? Alright, where wil you aim? \n";
	cout << "You have " << arrows << " arrows remaining." << endl;  
	//this->print_board(); 	
	arrows = arrows-1;
   	char direct;
	this->where(direct); 
	if(direct == 117){ //if u
	   	cout << "You aim north, draw, and let one rip" << endl; 
		for(int r=0; r<size; r++){
		   	int shot = 0; //used for 75% chance wumpus moves if miss
			for(int c=0; c<size; c++ ){
				if(rooms[r][c].get_event() == events[5]){//locates wampus
				  	if((currentR-r<4 && currentR-r>0) && (currentC==c)){ //if wampus <= 3 spots away in pointed direction
						cout << "Holy crap, you hit it! The Wumpus is dead!" << endl;
					       	wumpusdead = true;
						rooms[r][c].set_event(NULL); 	
					}else{ //if wampus not within 3 spots from direction
						cout << "The wumpus wasn't over there, Mr. Cole. Get your ears checked if you get out of here\n"; 
						shot = rand() % 4; 
						if(shot == 3){
							cout << "The wumpus woke up Mr. Cole! He moved somewhere else.\n"; 
							int w = rand() % size;
							int d = rand() % size;
							this->place(w, d); 	
						   	rooms[w][d].set_event(events[5]);
							rooms[r][c].set_event(NULL); 
							break;	
						} 		   
					}
				}	
			}if(shot == 3) //if missed, break out of next for loop
		      		break;	
		}
	}else if(direct == 100){ //if d
	   	cout << "You aim south, draw, and let one rip" << endl; 
		for(int r=0; r<size; r++){
		   	int shot = 0; //used for 75% chance wumpus moves if miss
			for(int c=0; c<size; c++ ){
				if(rooms[r][c].get_event() == events[5]){//locates wampus
				  	if((r-currentR<4 && r-currentR>0) && (currentC==c)){ //if wampus <= 3 spots away in pointed direction
						cout << "Holy crap, you hit it! The Wumpus is dead!" << endl;
					       	wumpusdead = true;
						rooms[r][c].set_event(NULL); 	
					}else{ //if wampus not within 3 spots from direction
						cout << "The wumpus wasn't over there, Mr. Cole. Get your ears checked if you get out of here\n"; 
						shot = rand() % 4; 
						if(shot == 3){
							cout << "The wumpus woke up Mr. Cole! He moved somewhere else.\n"; 
							int w = rand() % size;
							int d = rand() % size;
							this->place(w, d); 	
						   	rooms[w][d].set_event(events[5]);
							rooms[r][c].set_event(NULL); 
							break;	
						} 		   
					}
				}	
			}if(shot == 3) //if missed, break out of next for loop
		      		break;	
		}
	}else if(direct == 108){ //if l
	   	cout << "You aim east, draw, and let one rip" << endl; 
		for(int r=0; r<size; r++){
		   	int shot = 0; //used for 75% chance wumpus moves if miss
			for(int c=0; c<size; c++ ){
				if(rooms[r][c].get_event() == events[5]){//locates wampus
				  	if((currentC-c<4 && currentC-c>0) && (currentR==r)){ //if wampus <= 3 spots away in pointed direction
						cout << "Holy crap, you hit it! The Wumpus is dead!" << endl;
					       	wumpusdead = true;
						rooms[r][c].set_event(NULL); 	
					}else{ //if wampus not within 3 spots from direction
						cout << "The wumpus wasn't over there, Mr. Cole. Get your ears checked if you get out of here\n"; 
						shot = rand() % 4; 
						if(shot == 3){
							cout << "The wumpus woke up Mr. Cole! He moved somewhere else.\n"; 
							int w = rand() % size;
							int d = rand() % size;
							this->place(w, d); 	
						   	rooms[w][d].set_event(events[5]);
							rooms[r][c].set_event(NULL); 
							break;	
						} 		   
					}
				}	
			}if(shot == 3) //if missed, break out of next for loop
		      		break;	
		}
	}else{ //if r
	   	cout << "You aim west, draw, and pray you hit something" << endl;
		for(int r=0; r<size; r++){
		   	int shot = 0; //used for 75% chance wumpus moves if miss
			for(int c=0; c<size; c++ ){
				if(rooms[r][c].get_event() == events[5]){//locates wampus
				  	if((c-currentC<4 && c-currentC>0) && (currentR==r)){ //if wampus <= 3 spots away in pointed direction
						cout << "Holy crap, you hit it! The Wumpus is dead!" << endl;
					       	wumpusdead = true;
						rooms[r][c].set_event(NULL); 	
					}else{ //if wampus not within 3 spots from direction
						cout << "The wumpus wasn't over there, Mr. Cole. Get your ears checked if you get out of here\n"; 
						shot = rand() % 4; 
						if(shot == 3){
							cout << "The wumpus woke up Mr. Cole! He moved somewhere else.\n"; 
							int w = rand() % size;
							int d = rand() % size;
							this->place(w, d); 	
						   	rooms[w][d].set_event(events[5]);
							rooms[r][c].set_event(NULL); 
							break;	
						} 		   
					}
				}	
			}if(shot == 3) //if missed, break out of next for loop
		      		break;	
		}
	}   	
}

/*******************************************************************************
 ** Function: move
 ** Description: moves character, stops if impossible
 ** Parameters: none
 ** Pre-Conditions: board must be initalized
 ** Post-Conditions: player will be moved
 *****************************************************************************/
void game::move(){
	char direct;
	while(true){ 
	   	cout << "Which way do you want to go?" << endl; 
		this->where(direct);
	       	if(direct == 117){ //if up
			if(currentR != 0 ){ //if can go up
				currentR = currentR-1;
				break;
			}else //if at top
			  	cout << "No way to go anymore north from here, Mr. Cole. Pick another way?" << endl;  
		}else if(direct == 100){//if down
		   	if(currentR != size-1){ //if can go down
				currentR = currentR+1;
				break;
			}else
			  	cout << "South of you is a lava river, can't go that way." << endl;  
		}else if(direct == 108){//if left
		   	if(currentC != 0){
				currentC = currentC-1;
				break;
			}else
			  	cout << "You don't want to go east. 3spooky5u." << endl;
		
		}else //if right   	
		   	if(currentC != size-1){
				currentC = currentC+1;
				break;
			}else
			  	cout << "A wall west of here. Go another way." << endl;  

	}//this->print_board(); 	
}

/*******************************************************************************
 ** Function: lost
 ** Description: prints message if lost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: message will be printed
 *****************************************************************************/
void game::lost(string c){
	cout << c << endl;	
}

/*******************************************************************************
 ** Function: will_continue
 ** Description: descides whether or not loop will continue
 ** Parameters: none
 ** Pre-Conditions: game board intialized
 ** Post-Conditions: boolean returned
 *****************************************************************************/
bool game::will_continue(){
	//cout << wumpusdead << endl << hasgold << endl << rooms[currentR][currentC].get_rope() << endl;   	
	if(wumpusdead == true && hasgold == true && rooms[currentR][currentC].get_rope() == true){ //continue with rope there
	   	return false;
	}else if(arrows<1){ //if out of arrows break loop
	   	return false;
	}else{ //wampus alive or gold not got and not at rope
	  	return true; 
	}
} 

/*******************************************************************************
 ** Function: play_game
 ** Description: plays repeating turns of game
 ** Parameters: none
 ** Pre-Conditions: game board initalized
 ** Post-Conditions: game will be played
 *****************************************************************************/
void game::play_game(){
   	bool play=true;
	cout << "Jeremy, you've started in " << currentR << ", " << currentC << endl;   
	while(play == true){ 
		this->check_surrounding();
		if(rooms[currentR][currentC].get_event() != NULL){
			rooms[currentR][currentC].get_event()->action(hasgold, currentR, currentC, size);
		      	if(rooms[currentR][currentC].get_event() == events[5]){ //wumpus
				this->lost("The wumpus ate you and you died, Mr. Cole.");
				break;	
			}else if(rooms[currentR][currentC].get_event() == events[0] || rooms[currentR][currentC].get_event() == events[1]){//pit
				this->lost("You fell into the pit. Some say you are still falling");
			       	break;	
			}else if(rooms[currentR][currentC].get_event() == events[4]) //gold
		   		rooms[currentR][currentC].set_event(NULL); 	   
		}this->choice();
		play = this->will_continue(); //if wumpus dead, and gold got, will return false, end loop 
	}

}

/*******************************************************************************
 ** Function: end_game
 ** Description: announces game is won/lost
 ** Parameters: none
 ** Pre-Conditions: will_continue is bool
 ** Post-Conditions: none
 *****************************************************************************/
void game::end_game(){
	//int choice;
	if(this->will_continue() == true || arrows<1) 
   		cout << "You have lost. ";
	else if(this->will_continue() == false){
		cout << "You have won. "; 
	}/*cout << "Would you like to play again?\n";
	cout << " 1 - Play on new board\n 2 - Same board\n 3 - Quit: ";
	while(!(cin>>choice) && (choice != 1 || choice != 2)){
		cin.clear();
	       	cin.ignore();
		cout << "Please enter 1 or 2: " << endl;	
	}return choice;*/ 	
	cout << "Thanks for playing!" << endl; 		
} 
