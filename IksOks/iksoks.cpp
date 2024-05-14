#include <iostream>
using namespace std;


void drawBoard(char board[3][3]) {

cout << board[0][0] << " |" << board[0][1] << "| " << board[0][2] << endl;
cout << "-------\n";
cout << board[1][0] << " |" << board[1][1] << "| " << board[1][2] << endl;
cout << "-------\n";
cout << board[2][0] << " |" << board[2][1] << "| " << board[2][2] << endl;
}


bool checkWin(char board[3][3], char player) {
    
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;}
    if(board[2][0] == player && board[1][1] == player && board[0][2] == player){
        return true;}

    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;}
        
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;}
    }
 
return false;    
}


int main(){

int row;
int col; 
char player = 'X';
char board[3][3] = { { ' ', ' ', ' ' }, 
                     { ' ', ' ', ' ' }, 
                     { ' ', ' ', ' ' } };



cout << "Welcome to Tic-Tac-Toe!\n";

for(int i=0; i<9; i++){
    
    drawBoard(board);
    
    cout << "Player " << player << " choose a row (1-3): ";
    cin >> row;
    while(row > 3){
        cout << "Invalid input\n";
        cout << "Choose a row (1-3): \n";
        cin >> row;
        
    }
    cout << "Choose a column (1-3): ";
    cin >> col;
    while(col > 3){
        cout << "Invalid input\n";
        cout << "Choose a column (1-3): \n";
        cin >> col;
    }
    
    if(board[col-1][row-1] == ' '){
        board[col-1][row-1] = player;
        checkWin(board, player); 
        if(checkWin(board, player)){
            break;
            }
        player = (player == 'X') ? 'O' : 'X';
        }

    else{ 
        cout << "###Place is taken###\n";
        i--;
        continue;
        }
    }

if(checkWin(board, player))
    cout << player << " WON!" << endl;
else    
    cout << "It's Draw\n";

drawBoard(board);

return 0;
}


