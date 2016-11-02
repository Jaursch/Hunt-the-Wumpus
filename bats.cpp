#include "./bats.h" 
#include <time.h>
#include <cstdlib>

using namespace std;

/*******************************************************************************
 ** Function: bat 
 ** Description: bat constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: bat constructed
 *****************************************************************************/
bat::bat(){

}

/*******************************************************************************
 ** Function: ~bat
 ** Description: bat destructor
 ** Parameters: none
 ** Pre-Conditions: bat constructed
 ** Post-Conditions: bat destructed
 *****************************************************************************/
bat::~bat(){

}

/*******************************************************************************
 ** Function: action
 ** Description: bat action
 ** Parameters: bool &, int &, int &, int
 ** Pre-Conditions: r and c have value
 ** Post-Conditions: returned random places
 *****************************************************************************/
void bat::action(bool &g, int &r, int &c, int size){
   	srand(time(NULL)); 
   	cout << "You ran into the super bats Jeremy!" << endl;
       	cout << "They transported you to a different room!" <<endl;
	r = rand() % size;
	c = rand() % size; 	

}

/*******************************************************************************
 ** Function: message
 ** Description: bat message
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: message printed
 *****************************************************************************/
void bat::message(){
	cout << "You hear flapping. " << endl;  
} 
