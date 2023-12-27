
#include <stdio.h>
#include <string.h>
void printBoard();
int checkWin();
void system();
char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1Name[50];
char player2Name[50];
void takePlayerNames() {
    printf("Enter name for Player 1: ");
    scanf("%s", player1Name);
    printf("Enter name for Player 2: ");
    scanf("%s", player2Name);
}
int main() {
    int player = 1, input, gameover = -1;
    takePlayerNames();
    printBoard();
    while (gameover == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("Please enter Number for %s (%c)\n", (player == 1) ? player1Name : player2Name, mark);
        scanf("%d", &input);
        if (input < 1 || input > 9) {
            printf("Invalid input\n");
            continue;
        }
        if (board[input] == 'X' || board[input] == 'O') {
            printf("Invalid move. Cell already taken.\n");
            continue;
        }
        board[input] = mark;
        printBoard();
        int result = checkWin();
        if (result == 1) {
            printf("Congratulations! %s  is the winner\n", (player == 1) ? player1Name : player2Name);
            gameover = 1;
        } else if (result == 0) {
            printf("It's a draw\n");
            gameover = 1;
        }
        player++;
    }
    return 0;
}
void printBoard() {
    system("cls");
    printf("|  %c  |  %c  |  %c  |\n", board[1], board[2], board[3]);
    printf("|  %c  |  %c  |  %c  |\n", board[4], board[5], board[6]);
    printf("|  %c  |  %c  |  %c  |\n", board[7], board[8], board[9]);
}
int checkWin() {
     if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }
    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
    }
    if(count==9){
        return 0;
    }
    return -1;
}
