#include <assert.h>
#include "rps.hpp"
#include <string.h>

/*
 rock = 0, paper = 1, scissors =2
 */
void rps_rock_lost(FILE* stream){
    fprintf(stream, "Rock says: I am blind!!!\n");
}

void rps_paper_lost(FILE* stream){
    fprintf(stream, "Paper says: I feel divided!!!\n");
}

void rps_scissors_lost(FILE* stream){
    fprintf(stream, "Scissors says: I am crushed!!!\n");
}

const RPSItem items[] = {
    RPSItem("rock", 0, rps_rock_lost),
    RPSItem("paper", 1, rps_paper_lost),
    RPSItem("scissors", 2, rps_scissors_lost)
};

RPSItem::RPSItem()
    :name(0), id(0), say_you_lost(0) // initialize constants here...
{
    // cannot initialize constants in here...
    // there is a time before the constructor that will deal with
    // initializing member variables

}

RPSItem::RPSItem(const char *name, const int id, void(*say_you_lost)(FILE*))
    :name(name), id(id), say_you_lost(say_you_lost) // initialize constants here...
{
    // cannot initialize constants in here...
    // there is a time before the constructor that will deal with
    // initializing member vari-ables

}

const int TRUE = 0;
const int FALSE = 1;
const int NUM_ITEMS = sizeof(items)/sizeof(items[0]);

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
        return TRUE;
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


RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick){
    assert(p1_pick);
    assert(p2_pick);
    int result = (p1_pick->id - p2_pick->id + NUM_ITEMS) % NUM_ITEMS;
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

RPSItem* rps_item_by_name(const char* name, RPSItem* destination){
    for(const RPSItem* i = items; i < items + NUM_ITEMS; ++i){
        // (*items).name same as item->name if it points to a struct or a class in C++
        if(rps_strcmp(i->name, name)==0){
            // copy item to some storage on the heap:
            // 1. Put memory aside for the new item. Rig,ht now it's not even initialized,
            // there are random bytes in it.

            // 2. copies the pointer to the stack to a pointer to memory
            memcpy(destination, i, sizeof(RPSItem));

                // 3. return the newly copied item on the heap.
            return destination;
        }

    }
    return 0;
}


