#include "./event.h" 

class room{
   	protected:
		event *e;
		bool rope;	
	public:
		room();
	       	~room(); 	
		//void add_events(); 
		event* get_event();
	       	bool event_present(); 	
		void set_event(event*);
	       	void set_rope(bool);
		bool get_rope(); 	
};
