#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <thread>
using namespace std;
const int width = 80;
const int height = 20;
int snakeX = width/2;
int snakeY = height/2;
bool gameover;
int sDir;
WINDOW * win;
int snakeXmv = snakeX;
/*void draw(){
//Change "clear" to "cls" if compiling for Windows
    system("clear");
for(int i=0; i<width; i++){
    cout << "#";
}
cout << endl;
for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
        if(j==0 || j==width-2){
            cout<<"#";  
        }
        if(j==snakeX && i==snakeY)
            cout<<"o";
        else
            cout<<" ";
    }cout<<endl;
}
for(int i=0; i<width; i++){
    cout << "#";
}
cout<<endl;
}*/


void start(){
    gameover=false;
    }

void UserInput(int sDir){
    nodelay(stdscr, TRUE);
    sDir = getch();
}

void RenderField(WINDOW * win, int height, int width){
    initscr();
    noecho();
    curs_set(0);
    win = newwin(height, width, 0, 0);
    refresh();
    box(win, 0, 0);
    mvwprintw(win,snakeY,snakeXmv,"o");
    wrefresh(win);
    getch();
    endwin();
}

void GameUpdate(int sDir, int snakeXmv, WINDOW * win){
switch(sDir){
case 97:
    for(int i; i < snakeX; snakeXmv--){
        mvwprintw(win,snakeY,snakeXmv,"o");
        mvwprintw(win,snakeY,snakeXmv+1," ");
        wrefresh(win);
        this_thread::sleep_for(chrono::milliseconds(1000));
        if(sDir != 97){
            break;}
        }
    
case 100:
    for(int i; i < snakeX; snakeXmv++){
        mvwprintw(win,snakeY,snakeXmv,"o");
        mvwprintw(win,snakeY,snakeXmv-1," ");
        wrefresh(win);
        this_thread::sleep_for(chrono::milliseconds(1000));
        if(sDir != 100){
            break;}
        }
    }
}

int main(){
start();

while(!gameover){
    UserInput(sDir);
    printw("%d", sDir);
    RenderField(win, height, width);
    GameUpdate(sDir, snakeXmv, win);
    //cout << snakeXmv << endl;
    
}


return 0;
    

}