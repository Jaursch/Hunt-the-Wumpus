#include "./wampus.h" 

/*******************************************************************************
 ** Function: wumpus
 ** Description: wumpus constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: wumpus constructed
 *****************************************************************************/
wumpus::wumpus(){

}

/*******************************************************************************
 ** Function: ~wumpus
 ** Description: wumpus destructor
 ** Parameters: none
 ** Pre-Conditions: wumpus constructed
 ** Post-Conditions: wumpus destructed
 *****************************************************************************/
wumpus::~wumpus(){

}

/*******************************************************************************
 ** Function: action
 ** Description: wumpus action
 ** Parameters: bool &, int &, int &, int
 ** Pre-Conditions: none
 ** Post-Conditions: action printed
 *****************************************************************************/
void wumpus::action(bool &gold, int &r, int &c, int size){
	cout << "Uh oh. You stepped into the wumpus room and woke him up!" << endl; 
}

/*******************************************************************************
 ** Function: message
 ** Description: wumpus message
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: message printed
 *****************************************************************************/
void wumpus::message(){
	cout << "You smell a stench." << endl;  
} 
