#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "helper.h"


// void saveGame (BattleShipGame b) {
//     char filename[20];
//     printf("Input the name of the file (include .txt): ");
//     scanf("%s", &filename);
    
//     FILE* fp = fopen(filename, 'w');
//     for (int r = 0; r < 20; r++){
//         for (int c = 0; c < 20; c++){
//             fputs(b.board[r][c], fp);
//         }   
//     }

//     fclose(fp);
// }

// void loadGame (BattleShipGame b) {
//     char filename[20];
//     printf("Input the name of the file to load (include .txt): ");
    
//     char a;
//     FILE* fp = fopen(filename, 'r');
//     for (int r = 0; r < 20; r++){
//         for (int c = 0; c < 20; c++){
//             c = fgetc(fp);
//             b.board[r][c] = a;
//         }
//     }
// }

BattleShipGame createBattleshipGame() {
    BattleShipGame b;
    for (int i = 0; i < 20; i++) {
        for (int x = 0; x < 20; x++) {
            b.playerOneBoard[i][x] = '*';
            b.playerTwoBoard[i][x] = '*';
        }
    }

    b.playerOneHits = 0;
    b.playerTwoHits = 0;
    b.hitsToWin = 4;

    return b;
}

void printPlayerBoard (char a[20][20]){
    int numberToPrint = 1;
    for (int r = 0; r < 20; r++){
        // Print player board
        if (numberToPrint < 10)
            printf(" "); 

        printf("%d  ", numberToPrint);
        for (int c = 0; c < 20; c++){
            printf("%c  ", a[r][c]);
        }

        printf("\n");
        numberToPrint += 1;
    }

    printf("    ");
    for (char ch = 'A'; ch <= 'T'; ch++) {
        printf("%c  ", ch);
    }
    printf("\n");    
}

void printBothBoard (char a[20][20], char b[20][20]){
    char s1[20] = "Your Board";
    char s2[20] = "Opponent board";

    printf("%+35s %+75s\n", s1, s2);
    int numberToPrint = 1;
    printf("");
    printf("\n");
    for (int r = 0; r < 20; r++){
        // Print player board
        if (numberToPrint < 10)
            printf(" "); 

        printf("%d  ", numberToPrint);
        for (int c = 0; c < 20; c++){
            printf("%c  ", a[r][c]);
        }

        // Print opponent board
        printf("\t");
        if (numberToPrint < 10)
            printf(" ");
        
        printf("%d  ", numberToPrint);
        for (int c = 0; c < 20; c++){
            if (b[r][c] == 'S'){
                printf("*  ");
            }
            else {
                printf("%c  ", b[r][c]);
            }
        }

        printf("\n");
        numberToPrint += 1;
    }

    for (int i = 0; i < 2; i++){
        if (i == 1)
            printf("\t");
        
        printf("    ");
        for (char ch = 'A'; ch <= 'T'; ch++) {
            printf("%c  ", ch);
        }
    }

    printf("\n\n");
}

void autoPlaceShips(char board[20][20]) {  
    int r = rand() % 20;
    int c = rand() % 20;

    for (int i = 0; i < 4; i++){
        while (board[r][c] != '*') {
            r = rand() % 20;
            c = rand() % 20;
        }

        board[r][c] = 'S';
    }
}

void manualPlaceShips (char playerBoard[20][20], int sizeOne){
    int rowIdx;
    int colIdx;
    char colChar;
    char viewBoard;

    scanf("%*c");
    while (sizeOne != 0){
        printf("\nEnter coordinate (ex. A 5) to place ship: ");
        scanf("%c %d%*c", &colChar, &rowIdx);
        colIdx = (int) colChar - 65;

        if (playerBoard[rowIdx][colIdx] == '*'){
            sizeOne -= 1;
            playerBoard[rowIdx][colIdx] = 'S';
        }

       
        printPlayerBoard (playerBoard);
    }
}

/**
* RETURNS
*   -1: invalid coordinates
*    0: missed shot
*    1: enemy ship hit
*/

int performAttack(char opponentBoard[20][20], int rowIdx, int colIdx) {
    if (opponentBoard[rowIdx][colIdx] == 'S'){
        opponentBoard[rowIdx][colIdx] == 'X';
        return 1;
    }
    else if (opponentBoard[rowIdx][colIdx] == '*'){
        opponentBoard[rowIdx][colIdx] = ' ';
        return 0;
    }

    return -1;
}

void playGameEasyMode (BattleShipGame b){
    char colChar;
    int rowIdx;
    int colIdx;
    int attackSuccess;

    printf ("Game has started!\n");
    scanf("%*c");
    while (1){  
        printBothBoard(b.playerOneBoard, b.playerTwoBoard);
        printf("Enter a coordinate (A 5): ");
        scanf("%c %d%*c", &colChar, &rowIdx);
        colIdx = (int) colChar - 65;
      
        attackSuccess = performAttack(b.playerTwoBoard, rowIdx, colIdx);

        if (attackSuccess == 0){
            printf("Missed hit! \n\n");
        }
        else if (attackSuccess == 1){
            b.playerOneHits += 1;
            printf("Attacked hit!\n\n");
            if (b.playerOneHits == b.hitsToWin){
                printf("Player one has won the game! \n");
                return;
            }
        }
        else {
            printf("Invalid coordinates \n\n");
        }

        do {
            rowIdx = rand() % 20;
            colIdx = rand() % 20; 
        } while (b.playerOneBoard[rowIdx][colIdx] != '*' && b.playerOneBoard[rowIdx][colIdx] != 'S');
        
        printf("Opponent attacks coordinate: %c %d\n", colIdx + 65, rowIdx);
        if (b.playerOneBoard[rowIdx][colIdx] == '*'){
            b.playerOneBoard[rowIdx][colIdx] = ' ';
            printf("Result: Miss!\n");
        }
        else if (b.playerOneBoard[rowIdx][colIdx] == 'S'){
            printf("Result: Your ship has been hit!\n\n");
            b.playerOneBoard[rowIdx][colIdx] = 'X';
            b.playerTwoHits += 1;

            if (b.playerTwoHits == b.hitsToWin){
                printf("Player one has won the game! \n");
                return;
            }
        }
    }
}

