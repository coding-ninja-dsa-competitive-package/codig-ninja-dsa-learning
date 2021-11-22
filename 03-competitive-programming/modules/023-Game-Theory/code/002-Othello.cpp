#include<bits/stdc++.h>

using namespace std;

int** makeMove(int **board, int x, int y, int player, int ischeck){
    int **newBoard;
    //  new_board points towards the board, if you make any changes, they will be 
    //  reflected in the original board
    if (ischeck) {
        newBoard = board;
    } else {
        newBoard = new int *[4];
        for (int i=0; i<4; i++) {
            newBoard[i] = new int[4];
            for (int j=0; j<4; j++) {
                newBoard[i][j] = board[i][j];
            }
        }
    }
    int xDir[] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
    int yDir[] = {0, 1, 1, 1, 0, -1, -1, -1};
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || board[x][y] != 0){
        return NULL;
    }
    bool movePossible = false;
    for (int i=0; i<8; i++){
        int xStep = xDir[i];
        int yStep = yDir[i];
        int currX = x + xStep;
        int currY = y + yStep;
        int count = 0;
        while (currX >= 0 && currX < 4 && currY >= 0 && currY < 4){
            if (newBoard[currX][currY] == 0){
                break;
            } else if (newBoard[currX][currY] != player) {
                currX += xStep;
                currY += yStep;
                count++;
            } else {
                if(count>0) {
                    movePossible=true;
                    if(ischeck) {
                        return newBoard;
                    }
                    int convert_x=currX-xStep;
                    int convert_y=currY-yStep;
                    while(convert_x!=x||convert_y!=y) {
                        newBoard[convert_x][convert_y]=player;
                        convert_x=convert_x-xStep;
                        convert_y=convert_y-yStep;
                    }
                    newBoard[x][y]=player;
                }
                break;
            }
        }   
    }
    if(movePossible) {
        return newBoard;
    } else {
        return NULL;
    }
    
}

vector<pair<int, int> *>* possibleMoves(int **board, int player){
    vector<pair<int, int> *> *output = new vector<pair<int, int> *>();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                if (makeMove(board, i, j, player, true)){
                    pair<int, int> *p = new pair<int, int>(i, j);
                    output->push_back(p);
                }
            }
        }
    }
    return output;
}

int evaluateBoard(int **board, bool &completed){
    if (possibleMoves(board, 1)->size() != 0 || possibleMoves(board, 2)->size() != 0) {
        completed = false;
        return 0;
    }
    completed = true;
    int count[3];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            count[board[i][j]]++;
        }
    }
    return count[1] - count[2];
}

int main(){
    int **board=new int* [4];
    for(int i=0; i<4; i++) {
        board[i]=new int [4];
        for(int j=0; j<4; j++) {
            board[i][j]=0;
        }
    }
    board[1][1]=2;
    board[1][2]=1;
    board[2][1]=1;
    board[2][2]=2;
    bool check=false;
    cout << evaluateBoard(board, check) << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}