/*

    Filename: Interpreter.h

    Description:

    Contains declarations for the Codegen.c and
    Interpreter.c

*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Keywords.h"

#define OPCODE_ARGLIMIT 5
#define LINE_STACK_LIMIT 100
#define STACK_LIMIT 100

struct TokenStruct;
struct AST;

enum Types;
enum Tokens;

typedef void* (*ByteCodeFunctionPtr)();

union TypeStore {
    double numValue;
    char* strValue;
    enum Tokens opValue;
};

struct wizObject {
    enum Types type;
    union TypeStore value;  
};

struct opCode {
    long lineNumber;
    int currentIndex;
    long argIndexes[OPCODE_ARGLIMIT];
    ByteCodeFunctionPtr associatedOperation;
};

struct lineCounterStack {
    long stack[LINE_STACK_LIMIT];
    int stackSize;
};

long fetchCurrentLine();

struct wizObject * fetchArg(long opCodeIndex, int argNum);
struct opCode * codeGen(struct AST * aTree);
void codeGenWalker(struct AST * aTree);
void printOpCodes();

struct wizObject* pop();
void* pushInternal(struct wizObject* arg);

void* targetOffset();
void* createStackFrame();
void* fReturnNoArg();
void* fReturn();
void* call();
void* fAssign();
void* push();
void* binOpCode();
void* jump();
void* jumpNe();
void* pushLookup();

int dumpStack();
void interpret();

// Helpers
int floatStrContainsDecimal(char * str);
int removeZerosFromDoubleString(char * str);
void processPlusOperator(struct wizObject* val1, struct wizObject* val2, struct wizObject* opArgRef);

#endif