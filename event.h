#include <iostream>
#pragma once
using namespace std;

class event{
	protected:
		
	public:
	   	event();
	       	~event();
		virtual void action(bool&, int&, int&, int)=0;
	       	virtual void message()=0; 	
};
