//
//  main.c
//  rps-izzy
//
//  Created by Isabella Cheng on 1/12/15.
//  Copyright (c) 2015 Isabella Cheng. All rights reserved.
//

#include <stdio.h>
#include <string.h>
/*
 rock = 0, paper = 1, scissors =2
 */
const char* choices[] = {"rock", "paper", "scissors"};
const char* results[] = {"We tired", "Player 2 wins", "Player 1 wins"};
const int TRUE = 0;
const int FALSE = 1;
const int NUMRESULTS = sizeof(results) / sizeof(results[0]);

int input_id(const char* input){
    for(unsigned long i = 0; i < sizeof(choices) / sizeof(choices[0]); ++i){
        if(strcmp(input, choices[i]) == TRUE){
            return i;
        }
    }
    return -1;
}

// use const all the time because it signals that the function will not change the parameters
// compiler will throw you errors if it will. So take advantage.
int check_choices(const int* const c, const int csize){
    for(const int* i = c; i < c+csize; ++i){
        if(*i < 0){
            return i - c;
        }
    }

    // success!
    return -1;
}

int main(int argc, char* args[]){
    if(argc != 3){
        fprintf(stderr,"Please provide choices for player 1 and player 2\n");
        return 1;
    }

    int pchoices[] = {0, 0};

    for(int i = 1; i < argc; ++i){
        const int pcindex = i - 1;
        pchoices[pcindex] = input_id(args[i]);
    }

    int res = 0;
    if((res = check_choices(pchoices, 2)) > -1){
        fprintf(stderr, "Player choice '%s' is invalid. Please choose '%s' '%s' '%s'.\n",
                args[res+1], choices[0], choices[1], choices[2]);
        return 1;
    }

    printf("%s\n", results[(pchoices[1]-pchoices[0] + NUMRESULTS) % NUMRESULTS]);




    return 0;
}

