/*

    Filename: Keywords.h

    Description:

    Various structures needed by the lexer.

*/

#ifndef KEYWORDS_H
#define KEYWORDS_H

/*

    Tokens for the operators must be ordered
    from the tokens with the lowest precedence to the
    highest precedence. By precedence I am reffering
    to PEMDAS

*/

enum Tokens {
    JUNK,
    /*BEGIN OPERATORS*/
    BEGINOPERATORS,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    /*BEGIN OPERANDS*/
    BEGINOPERANDS,
    LEFTPARENTH, 
    /*END OPERATORS*/
    ENDOPERATORS,
    // FOR SOME REASON THE EXPRESSION EVALAUTOR ALGORITHIM ONLY WORKS IF RIGHTPARENTH IS NOT AN OP LOL
    RIGHTPARENTH,
    NUM, 
    STRING,
    IDENTIFIER,
    /*END OPERANDS*/
    ENDOPERANDS,
    COMMA,
    ENDLINE,
    ENDOFFILE
};

enum Types {
    NUMBER,
    STRINGTYPE,
    BINOP,
    OP,
    NONE
};

/*

    The lexer outputs a series of these as an
    intermediate representation of the source program

*/

struct TokenStruct {
    enum Tokens token;
    enum Types type;
    char* lexeme;
    long line;
};

#endif