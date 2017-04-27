#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <list>
#include <map>
#include <vector>
#include <iostream>
#include "Types.h"
#include "Exceptions.h"

class Interpreter {
    public:
        Interpreter(Program);
        void interpret();

    private:
        Program p; // Contains instructions from the Whitespace source
        std::list<int> stack; // To store values
        std::map<int, unsigned> labels; // Lookup table for labels
};

#endif