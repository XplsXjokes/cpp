#include <ncurses.h>
#include <iostream>
#include <thread>

int main(){
	initscr();
	noecho();
	WINDOW * win = newwin(10,10,0,0);
	refresh();	
	for(int i=0; i < 1000000; i++){
		std::cout<<"Ping\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		nodelay(stdscr,TRUE);
        	int p = getch();
		if (p > 0){
			std::cout<<"Pong\n";
			}
	}
	endwin();
return 0;
}


