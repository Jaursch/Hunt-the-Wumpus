CC = g++
exe_file = huntdawumpus
$(exe_file): driver.o game.o room.o event.o wampus.o bats.o pit.o gold.o
	$(CC) driver.o game.o room.o event.o wampus.o bats.o pit.o gold.o -o $(exe_file)

clean:
	rm -f *.out *.o $(exe_file) 
