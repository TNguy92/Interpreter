#ifndef TYPES_H
#define TYPES_H

enum Instruction {
	PUSH, DUP, COPY,// Stack manipulations
	ADD, SUB, MUL, DIV, MOD, // Arithmetic operations
	ENDPROG, // Flow control

};

enum Mode {
	ARITH, FLOWCONT,
};
typedef std::vector<Instruction> Program;

#endif