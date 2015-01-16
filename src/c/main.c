
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rps.h"
#include <stdlib.h>

int main(int argc, char* args[]){
    if(argc != 3){
        fprintf(stderr,"Please provide choices for player 1 and player 2\n");
        return 1;
    }

    RPSItem* p1 = rps_item_by_name(args[1]);

    if(p1 == 0){
        fprintf(stderr, "P1 INVALID\n");
        return 1;
    }

    RPSItem* p2 = rps_item_by_name(args[2]);

    if(p1 == 0){
        free(p1);
        fprintf(stderr, "P2 INVALID\n");
        return 2;
    }

    int returnValue = 0;

    // prints result of the game engine
    switch (rps_match(p1, p2)) {
    case RPS_TIE:{
        printf("WE TIED\n");
        break;
    }
    case RPS_P1_WINS:{
        printf("PLAYER 1 WINS\n");
        break;
    }
    case RPS_P2_WINS:{
        printf("PLAYER 2 WINS\n");
        break;
    }case RPS_ERROR:{
        printf("ERROR\n");
        returnValue = 255;
    }
    }

    free(p1);
    free(p2);
    return returnValue;
}

