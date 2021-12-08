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

    //For custom AI

    b.playerTwoRow = 0;
    b.playerTwoColumn = 0;
    b.playerTwoRestart = 1;

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

    //Aircraft carrier - 5 cells

    int r = rand() % 20;
    int c = rand() % 20;

    while(board[r][c] != '*') {

        r = rand() % 20;
        c = rand() % 20;

    }

    if(board[r][c] == '*') {
        board[r][c] = 'S';

        if(c >= 4 && c <= 16) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';
            board[r][c+3] = 'S';
            board[r][c+4] = 'S';

        }

        else if(c < 4) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';
            board[r][c+3] = 'S';
            board[r][c+4] = 'S';

        }

        else if(c > 16) {

            board[r][c-1] = 'S';
            board[r][c-2] = 'S';
            board[r][c-3] = 'S';
            board[r][c-4] = 'S';

        }

        else if(r >= 4 && r <= 16) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';
            board[r+3][c] = 'S';
            board[r+4][c] = 'S';

        }


        else if(r > 16) {

            board[r-1][c] = 'S';
            board[r-2][c] = 'S';
            board[r-3][c] = 'S';
            board[r-4][c] = 'S';

        }

        else if(r < 4) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';
            board[r+3][c] = 'S';
            board[r+4][c] = 'S';

        }

    }


    //Battleship - 4 cells

    r = rand() % 20;
    c = rand() % 20;

    while(board[r][c] != '*') {

        r = rand() % 20;
        c = rand() % 20;

    }

    if(board[r][c] == '*') {
        board[r][c] = 'S';

        if(c > 3 && c < 17) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';
            board[r][c+3] = 'S';

        }

        else if(c <= 3) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';
            board[r][c+3] = 'S';

        }

        else if(c >= 17) {

            board[r][c-1] = 'S';
            board[r][c-2] = 'S';
            board[r][c-3] = 'S';

        }

        else if(r > 3 && r < 17) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';
            board[r+3][c] = 'S';

        }


        else if(r >= 17) {

            board[r-1][c] = 'S';
            board[r-2][c] = 'S';
            board[r-3][c] = 'S';

        }

        else if(r <= 3) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';
            board[r+3][c] = 'S';

        }

    }


    //Submarine - 3 cells

    r = rand() % 20;
    c = rand() % 20;

    while(board[r][c] != '*') {

        r = rand() % 20;
        c = rand() % 20;

    }

    if(board[r][c] == '*') {
        board[r][c] = 'S';

        if(c > 2 && c < 18) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';

        }

        else if(c <= 2) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';

        }

        else if(c >= 18) {

            board[r][c-1] = 'S';
            board[r][c-2] = 'S';

        }

        else if(r > 2 && r < 18) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';

        }


        else if(r >= 18) {

            board[r-1][c] = 'S';
            board[r-2][c] = 'S';

        }

        else if(r <= 2) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';

        }

    }


    //Destroyer - 3 cells

    r = rand() % 20;
    c = rand() % 20;

    while(board[r][c] != '*') {

        r = rand() % 20;
        c = rand() % 20;

    }

    if(board[r][c] == '*') {
        board[r][c] = 'S';

        if(c > 2 && c < 18) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';

        }

        else if(c <= 2) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';

        }

        else if(c >= 18) {

            board[r][c-1] = 'S';
            board[r][c-2] = 'S';

        }

        else if(r > 2 && r < 18) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';

        }


        else if(r >= 18) {

            board[r-1][c] = 'S';
            board[r-2][c] = 'S';

        }

        else if(r <= 2) {

            board[r+1][c] = 'S';
            board[r+2][c] = 'S';

        }

    }

    //Patrol boat - 2 cells

    r = rand() % 20;
    c = rand() % 20;

    while(board[r][c] != '*') {

        r = rand() % 20;
        c = rand() % 20;

    }

    if(board[r][c] == '*') {
        board[r][c] = 'S';

        if(c > 1 && c < 19) {

            board[r][c+1] = 'S';

        }

        else if(c <= 1) {

            board[r][c+1] = 'S';
            board[r][c+2] = 'S';

        }

        else if(c >= 19) {

            board[r][c-1] = 'S';

        }

        else if(r > 1 && r < 19) {

            board[r+1][c] = 'S';

        }


        else if(r >= 19) {

            board[r-1][c] = 'S';

        }

        else if(r <= 1) {

            board[r+1][c] = 'S';

        }

    }


}

void manualPlaceShips (char playerBoard[20][20], int sizeOne){
    int rowIdx;
    int colIdx;
    char colChar;
    char viewBoard;

    scanf("%*c");
    while (sizeOne != 0){
        printf("\nEnter coordinate (A-T 1-20) to place ship: ");
        scanf("%c %d%*c", &colChar, &rowIdx);
        colIdx = (int) colChar - 65;
        rowIdx -= 1;

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

int performPlayerMove (BattleShipGame b, int player) {
    int colChar;
    int colIdx;
    int rowIdx;
    int attackSuccess;

    if (player == 0){
        printBothBoard(b.playerOneBoard, b.playerTwoBoard);
        printf("\nPlayer one, please enter a coordinate (A-T 1-20): ");
    }
    else {
        printBothBoard(b.playerTwoBoard, b.playerOneBoard);
        printf("\nPlayer two, please enter a coordinate (A-T 1-20): ");
    }
    
    scanf("%c %d%*c", &colChar, &rowIdx);
    colIdx = (int) colChar - 65;
    rowIdx -= 1;

    if (player == 0){
        attackSuccess = performAttack(b.playerTwoBoard, rowIdx, colIdx);
    }
    else {
        attackSuccess = performAttack(b.playerOneBoard, rowIdx, colIdx);
    }
    
    if (attackSuccess == 0){
        printf("Missed hit! \n\n");
    }
    else if (attackSuccess == 1){
        printf("Attacked hit!\n\n");
        if (player == 0){
            b.playerOneHits += 1;
            printf("Player one has won the game! \n");
            return 1;
        }
        else {
            b.playerTwoHits += 1;
            printf("Player two has won the game! \n");
            return 1;
        }
    }
    else {
        printf("Invalid coordinates \n\n");
        return -1;
    }

    return 0;
}

void PvP (BattleShipGame b) {
    int player = 0;
    int res;
    while (1) {
        res = performPlayerMove(b, player);
        if (res == 0) {
            player = (player + 1) % 2;
        }
        else if (res == 1){
            break;
        }
    }
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
        printf("Enter a coordinate (A-T 1-20): ");
        scanf("%c %d%*c", &colChar, &rowIdx);
        colIdx = (int) colChar - 65;
        rowIdx -= 1;
      
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
        
        printf("Opponent attacks coordinate: %c %d\n", colIdx + 65, rowIdx + 1);
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


void playGameCustomMode (BattleShipGame b){
    char colChar;
    int rowIdx;
    int colIdx;
    int attackSuccess;

    printf ("Game has started!\n");
    scanf("%*c");
    while (1){  
        printBothBoard(b.playerOneBoard, b.playerTwoBoard);
        printf("Enter a coordinate (A-T 1-20): ");
        scanf("%c %d%*c", &colChar, &rowIdx);
        colIdx = (int) colChar - 65;
        rowIdx -= 1;
      
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

        int rowIdx2 = b.playerTwoRow;
        int colIdx2 = b.playerTwoColumn;

        if(b.playerTwoRestart == 1) {
            do {
                rowIdx2 = rand() % 20;
                colIdx2 = rand() % 20; 
            } while (b.playerOneBoard[rowIdx2][colIdx2] != '*' && b.playerOneBoard[rowIdx2][colIdx2] != 'S');
        }
        
        printf("Opponent attacks coordinate: %c %d\n", colIdx2 + 65, rowIdx2 + 1);
        if (b.playerOneBoard[rowIdx2][colIdx2] == '*'){
            b.playerOneBoard[rowIdx2][colIdx2] = ' ';
            printf("Result: Miss!\n");
            
            b.playerTwoRow = rowIdx2 + 1;
            b.playerTwoColumn = colIdx2 + 1;

            if(b.playerTwoRow == 20 || b.playerTwoColumn == 20 || b.playerOneBoard[rowIdx2+1][colIdx2+1] == ' ' || b.playerOneBoard[rowIdx2+1][colIdx2+1] == 'X') {

                b.playerTwoRestart = 1;
            }

            else {

                b.playerTwoRestart = 0;

            }
            

        }

        else if (b.playerOneBoard[rowIdx2][colIdx2] == 'S'){
            printf("Result: Your ship has been hit!\n\n");
            b.playerOneBoard[rowIdx2][colIdx2] = 'X';
            b.playerTwoHits += 1;

            b.playerTwoRestart = 1;

            if (b.playerTwoHits == b.hitsToWin){
                printf("Player one has won the game! \n");
                return;
            }
        }
    }
}

