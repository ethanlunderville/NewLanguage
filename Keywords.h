/*

    Note: Tokens for the operators must be ordered
    from the tokens with the lowest precedence to the
    highest precedence. By precedence I am reffering
    to PEMDAS

*/

#ifndef KEYWORDS_H
#define KEYWORDS_H

enum Tokens {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    LEFTPARENTH,
    RIGHTPARENTH, 
    ENDOPS,
    /*END OPERATORS*/
    NUM,
    END
};

enum Types {
    NUMBER,
    STRING,
    BINOP,
    OP,
    NONE
};

struct TokenStruct {
    enum Tokens token;
    enum Types type;
    char* lexeme;
    long line;
};

#endif