#include<stdio.h>
char board[3][3]; //3x3 tic toe board 
int i,j;
// function to initialize the board 
void initializeboard(){
    for(i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
    board[i][j]= ' ';
} 
//function to print the board
void printboard(){
    printf("\n");
    for(i = 0;i < 3;i++){
        printf("%c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

//function to check if a player has won
int checkwin(){
    //check rows and columns 
    for(i = 0;i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        return 1;
    }
    //check diagonals 
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    return 1;
    return 0;
}

//function to check if board is full
int isdraw(){
    for(i = 0;i<3;i++)
    for(j = 0;j<=3;j++)
    if(board[i][j] == ' ')
    return 0;
    return 1;
}
int main(){
    int row ,col;
    char currentplayer = 'X';
    initializeboard();
    printf("welcome to tic tac toe!\n");
    printboard();
    while(1){
        printf("player %c, enter row (1-3) and coloumn (1-3): ",currentplayer);
        scanf("%d %d",&row,&col);
        if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' '){
            printf("invalid move! try again.\n");
            continue;
        }
        //make a move
        board[row-1][col-1] = currentplayer;
        printboard();
        // check for win
        if(checkwin()){
            printf("player %c wins!\n",currentplayer);
            break;
        }
        if(isdraw()){
            printf("it is draw\n");
            break;
        }
        //switch player
        currentplayer = (currentplayer == 'X')? 'O' : 'X';
    } 
    return 0;
}
