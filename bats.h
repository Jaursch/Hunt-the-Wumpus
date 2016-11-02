#include "./event.h"

class bat : public event{
	public:
	   	bat();
	       	~bat(); 	
	   	void action(bool&, int&, int&, int); 
		void message(); 
};
