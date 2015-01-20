#include <stdio.h>

typedef enum{
             RPS_P1_WINS,
             RPS_P2_WINS,
             RPS_TIE,
             RPS_ERROR
            } RPS_Result;

// members of struct are public by default :D
// constants need an initialization
class RPSItem{
    // CLASS members go up here and must be declared static and constant, and must be initialized
    // static const int rps_class_member = 5;

public:

    // example of static pointer that can access constructors
    // static RPSItem* creator();

    // These are declarations of INSTANCE members, and NOT CLASS members
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
protected:
    RPSItem();
    RPSItem(const char* name, const int id);

};

class Rock : public RPSItem{
    public:
    Rock();
    virtual void say_you_lost(FILE*) const;


};

class Paper : public RPSItem{
    public:
    Paper();
    virtual void say_you_lost(FILE*) const;


};

class Scissors : public RPSItem{
    public:
    Scissors();
    virtual void say_you_lost(FILE*) const;


};

const RPSItem* rps_item_by_name(const char* name);

RPS_Result rps_match(const RPSItem* p1_pick, const RPSItem* p2_pick);

