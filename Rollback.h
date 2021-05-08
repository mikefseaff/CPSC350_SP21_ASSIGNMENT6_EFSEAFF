#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "MasterTrees.h"
#include "GenStack.h"
#include "Command.h"
//class that handles rollbacking commands
 
class Rollback{
    public:
        //default constructor
        Rollback();
        //destructor
        ~Rollback();
        //pushes the command to the stack
        void rollbackPush(Command command);
        //pops the command off the stack
        Command rollbackPop();
        //returns true if the stack is empty
        bool isEmpty();
    private:
        //stack of commands
        GenStack<Command> *RollbackStack = new GenStack<Command>;
};
#endif