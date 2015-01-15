#include <assert.h>
#include "rps.h"

/*
 rock = 0, paper = 1, scissors =2
 */
const char* choices[] = {"rock", "paper", "scissors"};
const int TRUE = 0;
const int FALSE = 1;
const int NUM_CHOICES = sizeof(choices)/sizeof(choices[0]);

int rps_strcmp(const char* a, const char* b){
    // check if pointers are zero
    assert(a);
    assert(b);

    for(; *a && *b; ++a, ++b){
        if(*a != *b){
            return -1;
        }
    }

    // the for loop can still pass if a and b
    // are equal characters. But it is still possible
    // one is longer than the other
    if(*a == 0 && *b == 0){
        return 0;
    }

    return -1;
}

int input_id(const char* input){
    for(unsigned long i = 0; i < sizeof(choices) / sizeof(choices[0]); ++i){
        if(rps_strcmp(input, choices[i]) == TRUE){
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


RPS_Result rps_match(const char* p1_pick, const char* p2_pick){
    int pchoices[] = {0, 0};
    pchoices[0] = input_id(p1_pick);
    pchoices[1] = input_id(p2_pick);

    int res = 0;
    if((res = check_choices(pchoices, 2)) > -1){
        switch(res){
        case 0: {
            return RPS_P1_INVALID;
            break;
        }
        case 1: {
            return RPS_P2_INVALID;
            break;
        }
        default: {
            assert(FALSE);
            return RPS_ERROR;
        }
        }
    }

    int result = (pchoices[1]-pchoices[0] + NUM_CHOICES) % NUM_CHOICES;
    switch (result) {
    case 0: return RPS_TIE;
    case 1: return RPS_P1_WINS;
    case 2: return RPS_P2_WINS;
    default: {
        assert(FALSE);
        return RPS_ERROR;
    }
    }

}

