
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rps.h"

int main(int argc, char* args[]){
    if(argc != 3){
        fprintf(stderr,"Please provide choices for player 1 and player 2\n");
        return 1;
    }

    // prints result of the game engine
    switch (rps_match(args[1], args[2])) {
    case RPS_P1_INVALID:{
        fprintf(stderr, "P1 INVALID\n");
        return 1;
    }
    case RPS_P2_INVALID:{
        fprintf(stderr, "P2 INVALID\n");
        return 2;
    }
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
    }
    case RPS_ERROR: {
        fprintf(stderr, "SOME WEIRD ERROR");
        return 3;
    }
    }

    return 0;
}

