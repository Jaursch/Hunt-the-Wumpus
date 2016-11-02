#include "./room.h"
#include "./pit.h"
#include "./bats.h"
#include "./wampus.h"
#include "./gold.h"

class game{
	protected:
	   	int size; //size of grid i.e. 4 = 4x4grid
	  	room** rooms;
		bool hasgold;
		bool wumpusdead;
		int arrows;
		event * events[6]; //events
		int currentC;
		int currentR; //starting position
	public:
	   	game(int);
	       	~game();
		game(const game&);
	       	void operator =(const game&); 	
		void print_board();
		void place(int &, int &); 
	       	void add_events(); 	
		void play_game(); 
		void add_jeremy();
		void check_surrounding(); 
		void choice(); 
		void shoot();
	       	void move(); 
		void where(char &);
		void lost(string); 	
		bool will_continue();
	       	void end_game(); 	


};
