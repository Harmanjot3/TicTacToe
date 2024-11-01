#include<iostream>
#include <string>
using namespace std;
void displayBoard(char board[3][3]) {
    cout << "Current board state:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | "; // Print a vertical separator between columns
        }
        cout << endl;
        if (i < 2) cout << "--|---|--\n"; // Print a horizontal line between rows
    }
}

bool iswinner(char board[3][3] , char player){
    //check rows and columns
    for (int i = 0; i < 3; ++i) {
    if((board[i][0] == player &&
        board[i][1] == player &&
        board[i][2] == player ||
        board[0][i] == player &&
        board[1][i] == player &&
        board[2][i] == player))
        {   return true; }
    }
    //checking tircha (diagonals)
    if((board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player ||
        board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player))
        {   return true; }
    return false;
}

bool isdraw(char board[3][3]){
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j]== ' ')
            {
                return false;
            }
        }
    }
    return true;
}



int main() { 
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currplayer='x';
    int row, col;
    bool gamewon=false;

    while(!gamewon && !isdraw(board)){
    displayBoard(board);
    cout<<"Player"<<currplayer<<",enter move ";
    cin>>row>>col;
    row--;
    col--;  //11 12 13
            //21 22 23
            //31 32 33 //for 0 index we are doing "--"

    //now we will validate the move
    if(row >=0 && row< 3 && 
       col >=0 && col< 3 && 
       board[row][col]==' ')
    {
        board[row][col] = currplayer;
        if(iswinner(board , currplayer)){
            displayBoard(board);
            cout<<"Player"<<currplayer<<" wins!\n";
            gamewon=true;
        } 
        else if(isdraw(board)){
            displayBoard(board);
            cout<<"DRAW hai bhadwe\n";
        } else {
            currplayer= (currplayer=='x')?'o':'x';
        }
    } else {
        cout << "Invalid Move , Try Again";
        }
    }
    return 0;
}
