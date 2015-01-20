#include <stdio.h>

typedef enum{
             RPS_P1_WINS,
             RPS_P2_WINS,
             RPS_TIE,
             RPS_ERROR
            } RPS_Result;

// members of struct are public by default :D
// constants need an initialization
struct RPSItem{
    const char* name;
    const int id;

    // ***** pure virtual function *** : POLYMORPHISM!!!
    // virtual: in case you have a pointer to RPSItem and call say_you_lost
    // but it's actually a Rock, call the Rock's function
    // if Rock defines its own implementation
    // pure: RPSItem is abstract has no implementation.
    // nonpure: virtual function has a body and isnt required for the child to define it
    // setting to 0: set to null
    //
    // const: func works on constant values; add const on methods
    // that do not change constant values
    virtual void say_you_lost(FILE*) const = 0;

    // method overloading-CANNOT DO THIS IN C
    RPSItem();
    RPSItem(const char* name, const int id);

};

struct Rock : RPSItem{
    Rock();
    virtual void say_you_lost(FILE*) const;


};

struct Paper : RPSItem{
    Paper();
    virtual void say_you_lost(FILE*) const;


};

struct Scissors : RPSItem{
    Scissors();
    virtual void say_you_lost(FILE*) const;


};

const RPSItem* rps_item_by_name(const char* name);

RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);

