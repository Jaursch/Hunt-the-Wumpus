#include "./event.h"

class wumpus : public event{
   	protected:

	public:
	   	wumpus();
	       	~wumpus();	
		void action(bool&,int&,int&,int	);    
		void message(); 
};
