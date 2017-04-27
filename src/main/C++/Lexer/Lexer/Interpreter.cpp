#include "Interpreter.h"
#include "Exceptions.h"

using namespace std;

Interpreter::Interpreter(Program p) {
	this->p = p;
}

void Interpreter::interpret() {
	unsigned pc, size = p.size();

	for (pc = 0; pc < size; pc++) {
		switch (p[pc]) {
		// Stack manipulations
		case PUSH: {
			stack.push_front(p[++pc]);
			break;
		}
		case COPY: {
			auto it = stack.begin();
			advance(it, p[++pc]);
			stack.push_front(*it);
			break;
		}



		// Arithmetic
		case ADD: {
			int a = stack.front();
			stack.pop_front();
			int b = stack.front();
			stack.pop_front();
			stack.push_front(b + a);
			break;
		}
		case SUB: {
			int a = stack.front();
			stack.pop_front();
			int b = stack.front();
			stack.pop_front();
			stack.push_front(b - a);
			break;
		}
		case MUL: {
			int a = stack.front();
			stack.pop_front();
			int b = stack.front();
			stack.pop_front();
			stack.push_front(b * a);
			break;
		}
		case DIV: {
			int a = stack.front();
			stack.pop_front();
			int b = stack.front();
			stack.pop_front();
			stack.push_front(b / a);
			break;
		}
		case MOD: {
			int a = stack.front();
			stack.pop_front();
			int b = stack.front();
			stack.pop_front();
			stack.push_front(b % a);
			break;
		}
		case ENDPROG: {
			cout << endl << endl << "Press the Enter key to exit..." << endl;
			cin.ignore();
			exit(0);
			return; // this is officially the end of the interpreter session
		}
		default:
			cout << "hi" << endl;
			//throw InstructionNotFoundException();
		}
	}
}
