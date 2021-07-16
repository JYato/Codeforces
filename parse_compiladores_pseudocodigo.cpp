#include <iostream>

using namespace std;

///S → + S S | - S S | a

void stmt(){
    switch(lookahead){
    case "+":
        match("+");
        stmt();
        stmt();
        break;
    case "-":
        match("-");
        stmt();
        stmt();
        break;
    case "a":
        match("a");
        break;
    default:
        report("syntax error");
    }
}

void match(terminal t){
    if(lookahead == t ){
        lookahead = nextTerminal;
    }
    else{
        report("syntax error");
    }
}

///S → S ( S ) S | ε

void stmt(){
    switch(looakahead){
        case "(":
            match("(");
            stmt():
            match(")");
            stmt();
            break;
        case "ε":
            stmt();
            break;
        default:
            report("syntax error");
    }
}

void match(terminal t){
    if(lookahead == t){
        lookahead = nextTerminal;
    }
    else{
        report("Syntax error");
    }
}

