#include <assert.h>
#include "rps.hpp"
#include <string.h>

/*
 rock = 0, paper = 1, scissors =2
 */

Rock rock;
Paper paper;
Scissors scissors;

const RPSItem* items[] = {
    &rock, &paper, &scissors

};

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

const RPSItem* rps_item_by_name(const char* name){
    for(const RPSItem **item = items; item < items + NUM_ITEMS; ++item){
        if(rps_strcmp((*item)->name, name) == 0){
            return (*item);
        }
    }
    return 0;
}

RPSItem::RPSItem()
    : name(0), id(0)
{


}

RPSItem::RPSItem(const char * name, const int id)
    :name(name), id(id)
{

}


Rock::Rock()
    :RPSItem("rock",0)
{
}


void Rock::say_you_lost(FILE *stream) const
{
    fprintf(stream, "Rock says: I am blind!!!\n");

}


Paper::Paper()
    :RPSItem("paper",1)
{
}


void Paper::say_you_lost(FILE *stream) const
{
    fprintf(stream, "Paper says: I am divided!!!\n");

}


Scissors::Scissors()
    :RPSItem("Scissors",2)
{
}


void Scissors::say_you_lost(FILE *stream) const
{
    fprintf(stream, "Scissors says: I am crushed!!!\n");

}












