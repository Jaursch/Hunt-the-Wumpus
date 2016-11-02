#include "./gold.h" 

/*******************************************************************************
 ** Function: gold
 ** Description: gold constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: gold constructed
 *****************************************************************************/
gold::gold(){

}

/*******************************************************************************
 ** Function: ~gold
 ** Description: gold destructor
 ** Parameters: none
 ** Pre-Conditions: gold constructed
 ** Post-Conditions: gold destructed
 *****************************************************************************/
gold:: ~gold(){

}

/*******************************************************************************
 ** Function: action
 ** Description: gold action
 ** Parameters: bool &, int &, int &, int
 ** Pre-Conditions: gold has value
 ** Post-Conditions: gold will become true
 *****************************************************************************/
void gold:: action(bool &gold, int & R, int & C, int size){
	if(gold==false){ 
	   	cout << "You found the gold!" << endl;
		gold = true;	
	}
}

/*******************************************************************************
 ** Function: message
 ** Description: gold message
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: message printed
 *****************************************************************************/
void gold::message(){
	cout << "You see a shimmer." << endl; 
} 
