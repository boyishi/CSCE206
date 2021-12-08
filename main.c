#include "helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); 
    BattleShipGame game = createBattleshipGame();
    int gameMode;
    int shipPlacement;
    int difficulty;

    printf("------Game Modes------\n");
    printf("1: CPU\n");
    printf("2: PvP\n");
    printf("\n");
    printf("Select game mode: ");
    scanf("%d", &gameMode);

    printf("\n");
    printf("1 - Autoplace ships \n");
    printf("2 - Place your own ships \n");
    printf("Select option: ");
    scanf("%d", &shipPlacement);

    printf("\n");
    printf("1 - Basic AI\n");
    printf("2 - Advanced AI\n");
    printf("3 - Custom AI\n");
    printf("Select AI type: ");
    scanf("%d", &difficulty);

    if (gameMode == 1){
        if (shipPlacement == 1){
            autoPlaceShips(game.playerOneBoard);
            autoPlaceShips(game.playerTwoBoard);
        }
        else {
            manualPlaceShips(game.playerOneBoard, 4);
            autoPlaceShips(game.playerTwoBoard);
        }

        printf("\n");
        printBothBoard(game.playerOneBoard, game.playerTwoBoard);

        if(difficulty == 1) {

            playGameEasyMode(game);
        }

        else if(difficulty == 3) {

            playGameCustomMode(game);

        }
    }
    else {
        if (shipPlacement == 1){
            autoPlaceShips(game.playerOneBoard);
            autoPlaceShips(game.playerTwoBoard);

            scanf("%*c");
            PvP(game);
        }
    }

}

