#include "./pit.h" 

/*******************************************************************************
 ** Function: pit
 ** Description: pit constructor
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: pit constructed
 *****************************************************************************/
pit::pit() : event() {
} 

/*******************************************************************************
 ** Function: ~pit
 ** Description: pit destructor
 ** Parameters: none
 ** Pre-Conditions: pit constructed
 ** Post-Conditions: pit destructed
 *****************************************************************************/
pit::~pit(){
}

/*******************************************************************************
 ** Function: action
 ** Description: pit action
 ** Parameters: bool &, int &, int &, int
 ** Pre-Conditions: none
 ** Post-Conditions: action printed
 *****************************************************************************/
void pit::action(bool&gold, int&r, int&c, int size){
	cout << "You walk into the room for a while until you realize you aren't walking on anything." << endl; 
}

/*******************************************************************************
 ** Function: message 
 ** Description: pit message
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: message printed
 *****************************************************************************/
void pit::message(){
	cout << "You feel a breeze." << endl; 
} 
