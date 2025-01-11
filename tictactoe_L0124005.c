#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

int checkFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switchPlayer(int *player) {
    *player = (*player == 1) ? 2 : 1;
}

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int row, col, player = 1;
    char mark;
    int isRunning = 1;

    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);

    while (isRunning) {
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter row (1-3) and column (1-3): ", player, mark);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row-1][col-1] = mark;
        printBoard(board);

        if (checkWin(board)) {
            printf("Player %d (%c) wins!\n", player, mark);
            isRunning = 0;
        } else if (checkFull(board)) {
            printf("It's a draw!\n");
            isRunning = 0;
        } else {
            switchPlayer(&player);
        }
    }

    return 0;
}
