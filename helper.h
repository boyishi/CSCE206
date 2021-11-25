#ifndef HELPER_H
#define HELPER_H

typedef struct BattleShipGame_struct {
    char playerOneBoard[20][20];
    char playerTwoBoard[20][20];

    int playerOneHits;
    int playerTwoHits;
    int hitsToWin;
    int gameFinished;
} BattleShipGame;

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

BattleShipGame createBattleshipGame();

// Print Player Board to help with manual placement of ships
void printPlayerBoard (char a[20][20]);

// Shows the current status of the game by printing both boards side by side
void printBothBoard (char a[20][20], char b[20][20]);

int validShipPlacement(char* ship, int sizeShip);

void autoPlaceShips(char board[20][20]);

void manualPlaceShips(char playerBoard[20][20], int sizeOne);

int performAttack(char board[20][20]);

void playGameEasyMode (BattleShipGame b);

#endif