#include "./room.h" 

/*******************************************************************************
 ** Function: room
 ** Description: room constructor
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: room constructed
 *****************************************************************************/
room::room(){
       	
} 

/*******************************************************************************
 ** Function: ~room
 ** Description: room destructor 
 ** Parameters: none
 ** Pre-Conditions: room constructed 
 ** Post-Conditions: room destructed
 *****************************************************************************/
room::~room(){

}

/*******************************************************************************
 ** Function: get_event
 ** Description: returns the event
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: event returned
 *****************************************************************************/
event* room::get_event(){
	return e;
}

/*******************************************************************************
 ** Function: event_present
 ** Description: event will be returned present or not
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returned if present or not
 *****************************************************************************/
bool room::event_present(){
	if(e == NULL)
	  	return false;
       	else
   		return true;	   
}

/*******************************************************************************
 ** Function: set_event
 ** Description: sets type of event to event in room
 ** Parameters: event *
 ** Pre-Conditions: event * must have targeted pointer
 ** Post-Conditions: will be set event
 *****************************************************************************/
void room::set_event(event *evt){
	e=evt;
}

/*******************************************************************************
 ** Function: set_rope
 ** Description: sets rope to certain room
 ** Parameters: bool
 ** Pre-Conditions: none
 ** Post-Conditions: rope value set
 *****************************************************************************/
void room::set_rope(bool s){
	rope = s;
} 

/*******************************************************************************
 ** Function: get_rope
 ** Description: returns if rope is in locations
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: rope value returned
 *****************************************************************************/
bool room::get_rope(){
	return rope;
} 
