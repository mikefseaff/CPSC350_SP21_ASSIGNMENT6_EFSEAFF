#include "Rollback.h"

//default contructor
Rollback::Rollback(){

}
//destructor
Rollback::~Rollback(){
    delete RollbackStack;
}
//pushes command to stack
void Rollback::rollbackPush(Command command){
    RollbackStack->push(command);
}
//returns true if the stack is empty
bool Rollback::isEmpty(){
    return (RollbackStack->isEmpty());
}
//pops the command off the stack
Command Rollback::rollbackPop(){
    return RollbackStack->pop();
}