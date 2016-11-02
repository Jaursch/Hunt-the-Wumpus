#include "./event.h"

class pit: public event{
   	private:

	public:
   		pit();
     		~pit(); 		
		void action(bool&,int&,int&,int); 
		void message(); 
};

