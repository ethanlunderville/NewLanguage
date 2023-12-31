#include <string.h>
#include <stdio.h>
#include "Builtins.h"
#include "Interpreter.h"

extern struct wizObject* stack;

BuiltInFunctionPtr getBuiltin(char * funcName) {
    if (strcmp("echo", funcName)==0) 
        return &fEcho;
    return 0;
}

void* fEcho() {
    struct wizObject* val = pop();
    switch (val->type) 
    {
    case NUMBER:
        {
        printf("%f",val->value.numValue);
        break;
        }
    case STRINGTYPE: 
        {
        printf("%s",val->value.strValue);
        break;
        }
    case CHARADDRESS: 
        {
        printf("%c",*(val->value.strValue));
        break;
        }
    }
    puts("");
}