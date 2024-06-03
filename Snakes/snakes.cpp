#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <thread>

using namespace std;

const int width = 80;
const int height = 20;
int X = width/2;
int Y = height/2;
int sDir = 0;
int score = -1;
int var = 4;
bool gameover;
WINDOW * win;
WINDOW * win2;
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
void gover(){
    initscr();
    noecho();
    curs_set(0);
    win = newwin(height, width, 0, 0);
    refresh();
    box(win, 0, 0);
    mvwprintw(win,width/2,height/2,"GAME OVER");
    wrefresh(win);
    wgetch(win);
    endwin();

}

void UserInput(int tmpv) {
    nodelay(stdscr, TRUE);
    tmpv = getch();
    if (tmpv != ERR) {
        sDir = tmpv;
    }
}

void fruit(int &fX, int &fY){ 
    if (score != -1) {
    mvwprintw(win, fY, fX, "F");
  }
    if (score == -1 || (fX == X && fY == Y)){
        score++;
        fX = 3 + (rand() % 75);
        fY = 3 + (rand() % 15);
    }
}

void RenderField(){
    initscr();
    noecho();
    curs_set(0);
    win = newwin(height, width, 0, 0);
    win2 =newwin(3,width,20,0);
    box(win2,20,0);
    box(win, 0, 0);
    wrefresh(win);
   
}

void GameUpdate(int &fX, int &fY){

switch(sDir){
case 97:
        X--;
        if (X <= 0)
            gameover=true;
        break;
case 100:
        X++;
         if (X >= 80)
            gameover=true;
        break;
case 119:
        Y--;
         if (Y <= 0)
            gameover=true;
        break;
case 115:
        Y++;
         if (Y >= 20)
            gameover=true;
        break;    
}
mvwprintw(win, Y, X, "o");
mvwprintw(win2, 1, 3, "Score: %d", score);
fruit(fX, fY);
wrefresh(win2);
wrefresh(win);
this_thread::sleep_for(chrono::milliseconds(400));
}

int main(){
int tmpv;
int fX;
int fY;
start();


while(!gameover){
    UserInput(tmpv);
    //printw("sDir: %d", sDir);
    RenderField();
    GameUpdate(fX,fY);
       
    //cout << snakeXmv << endl; 
    
}
gover();



return 0;
}

