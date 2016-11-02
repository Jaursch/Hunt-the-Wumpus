#include "./event.h"

class gold : public event{
   	public:
	   	gold();
	       	~gold();
		void action(bool &, int &, int &, int);	
		void message(); 
};
