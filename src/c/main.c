
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

    RPSItem p1Loc, p2Loc;

    // &p2 = address of operator, memory address, of memory location of player 2
    // returns a pointer to that particular object
    RPSItem* p1 = rps_item_by_name(args[1], &p1Loc);

    if(p1 == 0){
        fprintf(stderr, "P1 INVALID\n");
        return 1;
    }

    RPSItem* p2 = rps_item_by_name(args[2], &p2Loc);

    if(p2 == 0){
        fprintf(stderr, "P2 INVALID\n");
        return 2;
    }

    int returnValue = 0;

    // prints result of the game engine
    switch (rps_match(&p1Loc, &p2Loc)) {
    case RPS_TIE:{
        printf("WE TIED\n");
        break;
    }
    case RPS_P1_WINS:{
        p2->say_you_lost(stderr);
        printf("PLAYER 1 WINS\n");
        break;
    }
    case RPS_P2_WINS:{
        p1->say_you_lost(stderr);
        printf("PLAYER 2 WINS\n");
        break;
    }case RPS_ERROR:{
        printf("INVALID CHOICE\n");
        returnValue = 255;
    }
    }

    return returnValue;
}

