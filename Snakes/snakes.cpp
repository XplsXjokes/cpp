#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <thread>

using namespace std;

const int width = 80;
const int height = 20;
int X = width/2;
int Y = height/2;
int TailY[100];
int TailX[100];
int sLen = 0;
int sDir = 0;
int score = -1;
int count = 0;
bool gameover;
WINDOW * win;
WINDOW * win2;

void start(){
    gameover=false;
    }
void gover(){
    initscr();
    noecho();
    curs_set(0);
    win = newwin(height, width, 0, 0);
    box(win, 0, 0);
    mvwprintw(win,10,35,"GAME OVER");
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
        sLen++;
        count++;
        wrefresh(win2);
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
    wrefresh(win2);
   
}

void GameUpdate(int &diff, int &fX, int &fY){
int prevX=TailX[0];
int prevY=TailY[0];
int prev2X,prev2Y;
TailX[0]=X;
TailY[0]=Y;

for(int i=1; i<sLen; i++){
    prev2X=TailX[i];
    prev2Y=TailY[i];
    TailX[i]=prevX;
    TailY[i]=prevY;
    prevX=prev2X;
    prevY=prev2Y;
  }


switch(sDir){
case 97:
case 68:
        X--;
        if (X <= 0)
            gameover=true;
        break;
case 100:
case 67:
        X++;
         if (X >= 80)
            gameover=true;
        break;
case 119:
case 65:
        Y--;
         if (Y <= 0)
            gameover=true;
        break;
case 115:
case 66:
        Y++;
         if (Y >= 20)
            gameover=true;
        break;    
}
mvwprintw(win, Y, X, "o");
for(int i=0;i<sLen;i++){
  mvwprintw(win, TailY[i], TailX[i],"o");
  }
for(int i=1; i<sLen; i++){
    if (TailY[i]==Y && TailX[i]==X)
      gameover=true;
  }
mvwprintw(win2, 1, 3, "Score: %d", score);
fruit(fX, fY);
wrefresh(win2);
wrefresh(win);
if (count >= 5 && diff != 50){
    count = 0;
    diff -= 50;}
this_thread::sleep_for(chrono::milliseconds(diff));
}

int main(){
int tmpv;
int fX;
int fY;
int diff = 400;
start();


while(!gameover){
    UserInput(tmpv);
    RenderField();
    GameUpdate(diff,fX,fY);
    //cout<<sDir<<endl;
           
}
gover();



return 0;
}

