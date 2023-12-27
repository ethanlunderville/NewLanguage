/*

    Filename: Interpreter.c

    Description:

    VM for Wizard. opCodes from the program identifier
    are processed 1 by 1.

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Keywords.h"
#include "Interpreter.h"
#include "Keywords.h"

#define STACK_LIMIT 100

// These two are defined in Codegen.c
extern long programSize; 
extern struct opCode * program;

// These two are defined in Codegen.c
extern long wizSlabSize;
extern struct wizObject * wizSlab;

// Runtime Stack 
struct wizObject* stack[STACK_LIMIT];
int stackSize = 0;

// Approaches program size as the program executes.
long instructionIndex = 0;

/*

    This is to fetch args from the flattened list of
    arguments. See the initWizArg function in
    Codegen.c for a explaination as to why this is
    done in this way

*/

struct wizObject * fetchArg (struct opCode * op, int argNum) {
    return &wizSlab[op->argIndexes[argNum]];
}

// Stack dumper for debugging.

void dumpStack() {
    puts("|---------Dump-----------|");
    for (int i = stackSize ; i > -1; i--) {
        if (stack[i] == NULL) 
            continue;
        switch (stack[i]->type) {
            case STRINGTYPE:
                printf(
                    " %s\n", 
                    stack[i]->value.strValue
                ); break;
            case NUMBER:
                printf(
                    " %f\n", 
                    stack[i]->value.numValue
                ); break;
        }
        puts(" ------------------------");
    }    
}

// Pops a value off of the Runtime Stack.

struct wizObject* pop() {
    if (stackSize == 0) {
        puts("Attempted to pop empty stack!");
        exit(EXIT_FAILURE);
    }
    struct wizObject* element = stack[stackSize-1];
    stack[stackSize-1] = NULL;   
    stackSize--;
    return element;
}

// Pushes a value onto the Runtime Stack.

void* push() {
    if (stackSize == STACK_LIMIT) {
        puts("Stack Overflow!");
        exit(EXIT_FAILURE);
    }
    // NOTE :: THE FIRST ARGUMENT OF THE CURRENT opCode IS PUSHED
    stack[stackSize] = fetchArg(&(program[instructionIndex]),0);
    stackSize++;
    return NULL;
}

// Handles binary operations.

#define OP_EXECUTION_MACRO(op) \
            rightHand = pop()->value.numValue; \
            fetchArg(&program[instructionIndex],0)->value.numValue = ( \
                pop()->value.numValue op rightHand \
            ); \
            fetchArg(&program[instructionIndex],0)->type = NUMBER; \
            push(); \
            break;

void* binOpCode() {
    enum Tokens operation = fetchArg(&program[instructionIndex],0)->value.opValue;
    double rightHand;
    switch (operation) {
        case ADD: 
        {   
            if (0) {

            } else if (0) {

            } else if (0) {

            } else if (0) {

            }
            OP_EXECUTION_MACRO(+)
        }
        case SUBTRACT: OP_EXECUTION_MACRO(-);
        case MULTIPLY: OP_EXECUTION_MACRO(*);
        case DIVIDE: OP_EXECUTION_MACRO(/);
        case POWER:
        {
            double rightHand = pop()->value.numValue;
            fetchArg(&program[instructionIndex],0)->value.numValue = (pow(pop()->value.numValue, rightHand));
            fetchArg(&program[instructionIndex],0)->type = NUMBER;
            push();
            break;
        }
        case OR: OP_EXECUTION_MACRO(||);
        case AND: OP_EXECUTION_MACRO(&&);
        case LESSEQUAL: OP_EXECUTION_MACRO(<=);
        case GREATEREQUAL: OP_EXECUTION_MACRO(>=);
        case GREATERTHAN: OP_EXECUTION_MACRO(>);
        case LESSTHAN: OP_EXECUTION_MACRO(<);
        case NOTEQUAL: OP_EXECUTION_MACRO(!=);
        case EQUAL: OP_EXECUTION_MACRO(==);
        case PIPE: {break;}
        case ASSIGNMENT: {break;};
        default: break;
    }
    
    return NULL;
}

/*

    Interpreter: Stage 4

    Description:

    Driver code for the VM.

*/

void interpret() {
    while (instructionIndex < programSize) {
        program[instructionIndex].associatedOperation();
        instructionIndex++;
        dumpStack();
    }
}