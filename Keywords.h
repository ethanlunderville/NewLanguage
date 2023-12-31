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
    /*BEGIN OPERATORS*/
    BEGINOPERATORS,

    ASSIGNMENT,
    PIPE,
    EQUAL,
    NOTEQUAL,

    LESSTHAN,
    GREATERTHAN,
    GREATEREQUAL,
    LESSEQUAL,
    AND,
    OR,

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
    FUNCTIONCALLIDENT,
    INDEXIDENT,
    /*END OPERANDS*/
    ENDOPERANDS,
    COMMA,
    ENDLINE,
    
    IF,
    ELSE,
    WHILE,

    OPENBRACE,
    CLOSEBRACE,

    DEF,
    RETURN,

    OPENBRACKET,
    CLOSEBRACKET,

    ENDOFFILE
};

#define KEYWORD_LISTSIZE 5
static char* keywords[KEYWORD_LISTSIZE] = {
    "if", "else", "while", "def", "return"
};

const char* getTokenName(enum Tokens token);


enum Types {
    NUMBER,
    STRINGTYPE,
    BINOP,
    OP,
    //Chars are handled uniquely to prevent the need to make a wizobject for every char
    CHARADDRESS, 
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