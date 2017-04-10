﻿#include "Parser.h"
#include "Lexer.h"
#include "Token.h"
#include <string>
#include <list>
#include <iostream>	
#include <map>
#include <algorithm>
#include <vector>
#include <deque>




Parser::Parser(std::string filename)
{
	this->filename = filename;

}

void Parser::grabLineCode()
{
	
	Lexer lex = Lexer(filename);
	int LineNum = 1;
	Token tok = lex.nextToken();
	tokens.push_back(tok);
	while (lex.fp.is_open()) {

		
		
		if (tokens.back().getLexeme() == "if") {
			foundIF();
			
		}
		else if (tokens.back().getLexeme() == "then") {
			foundTHEN();
		}
		else if (tokens.back().getLexeme() == "while") {
			foundWHILE();
		}
		else if (tokens.back().getLexeme() == "end") {
			foudnEND();
		}
		else if (tokens.back().getLexeme() == "=") {
			//foundEQ();
		}


		
		// Checking for new LINE
		 tok = lex.nextToken();
		if (tokens.back().getLineNum() < tok.getLineNum()) {
			tokens.push_back(tok);
			newLine();
		}


	}

}

void Parser::newLine() {
	//Token that belongs to the new line
	Token tmp = tokens.back();
	tokens.pop_back();

	if (tmp.getToken() == "ID" || tmp.getToken() == "LP") {
		tokens.push_back(tmp);
		list.push_back(tokens);

		// Clearing the queue for the new line of the source code
		tokens.clear();

	
	}


	else if ((tokens.front().getLexeme() == "if" || tokens.front().getLexeme() == "while")) {
		tokens.push_back(Token("RP", ")", tokens.back().getLineNum()));
		tokens.push_back(Token("LC", "{", tokens.back().getLineNum()));
		list.push_back(tokens);

		// Clearing the queue for the new line of the source code
		tokens.clear();
		//Pushing the first token of the new line
		tokens.push_back(tmp);

	}


	else if (tokens.back().getToken() != "LP" && tokens.back().getToken() != "LC" && tokens.back().getToken() != "RP") {
		tokens.push_back(Token("SEMI", ";", tokens.back().getLineNum()));
		list.push_back(tokens);

		// Clearing the queue for the new line of the source code
		tokens.clear();
		//Pushing the first token of the new line
		tokens.push_back(tmp);

	}
}
	
	


void Parser::foudnEND() {

	Token tmp = Token("RC", "}", tokens.back().getLineNum());
	tokens.pop_back();
	tokens.push_back(tmp);

}

void Parser::foundWHILE() {

	tokens.push_back(Token("LP", "(", tokens.back().getLineNum()));

}

void Parser::foundDO() {

	tokens.pop_back();
	tokens.push_back(Token("RP", ")", tokens.back().getLineNum()));
	tokens.push_back(Token("LC", "{", tokens.back().getLineNum()));
}

void Parser::foundIF() {

	tokens.push_back(Token("LP", "(", tokens.back().getLineNum()));

}

void Parser::foundTHEN() {

	tokens.pop_back();
	tokens.push_back(Token("RP", ")", tokens.back().getLineNum()));
	tokens.push_back(Token("RC", "{", tokens.back().getLineNum()));

}

void Parser::foundCOMMA() {

	if (tokens.front().getLexeme() != "local" || tokens.front().getLexeme() != "type") {

		std::cout << "ERROR ON LINE:" << tokens.front().getLineNum() << ",  define kind of variable" << std::endl;
	}
}

void Parser::foundEQ() {


	// Looping through the list checking all of the deques for the variable definition
		bool search = false;

		for (int i = 0; i < list.size()-1; i++) {

			search = ScanQUEUE(tokens.back(), list[i]);
		}

		if (!search) {
			std::cout << "Error in line" << tokens.back().getLineNum() << " variable is not defined" << std::endl;
		}



}
void Parser::foundSM(){
	Token tmp = tokens.back();
	tokens.pop_back();
	if(tokens.back().getLexeme() == "+")
	{
		bool search = false;
		for (unsigned int i = 0; i < list.size()-1; i++) 
		{
			search = ScanQUEUE(tokens.back(), list[i]);
		}
		if (!search) 
		{
			std::cout << "Error in line" << tokens.back().getLineNum() << " variable is not defined" << std::endl;
		}
		tokens.push_back(tmp);
		
	}
	if(tokens.front().getLexeme() != "ID" || tokens.front().getLexeme() != "NUM")
	{
		std::cout<<"Error, Number or ID expected at: " << tokens.back().getLineNum() << std::endl;
	}
}
void Parser::foundMUL(){
	Token tmp = tokens.back();
	tokens.pop_back();
	if(tokens.back().getLexeme() == "*")
	{
		bool search = false;
		for (unsigned int i = 0; i < list.size()-1; i++) 
		{
			search = ScanQUEUE(tokens.back(), list[i]);
		}
		if (!search) 
		{
			std::cout << "Error in line" << tokens.back().getLineNum() << " variable is not defined" << std::endl;
		}
		tokens.push_back(tmp);
		
	}
	if(tokens.front().getLexeme() != "ID" || tokens.front().getLexeme() != "NUM")
	{
		std::cout<<"Error, Number or ID expected at: " << tokens.back().getLineNum() << std::endl;
	}
	
}
void Parser::foundSUB(){
	Token tmp = tokens.back();
	tokens.pop_back();
	if(tokens.back().getLexeme() == "-")
	{
		bool search = false;
		for (unsigned int i = 0; i < list.size()-1; i++) 
		{
			search = ScanQUEUE(tokens.back(), list[i]);
		}
		if (!search) 
		{
			std::cout << "Error in line" << tokens.back().getLineNum() << " variable is not defined" << std::endl;
		}
		tokens.push_back(tmp);
		
	}
	if(tokens.front().getLexeme() != "ID" || tokens.front().getLexeme() != "NUM")
	{
		std::cout<<"Error, Number or ID expected at: " << tokens.back().getLineNum() << std::endl;
	}
	
}
void Parser::foundDIV(){
	Token tmp = tokens.back();
	tokens.pop_back();
	if(tokens.back().getLexeme() == "/")
	{
		bool search = false;
		for (unsigned int i = 0; i < list.size()-1; i++) 
		{
			search = ScanQUEUE(tokens.back(), list[i]);
		}
		if (!search) 
		{
			std::cout << "Error in line" << tokens.back().getLineNum() << " variable is not defined" << std::endl;
		}
		tokens.push_back(tmp);
		
	}
	if(tokens.front().getLexeme() != "ID" || tokens.front().getLexeme() != "NUM")
	{
		std::cout<<"Error, Number or ID expected at: " << tokens.back().getLineNum() << std::endl;
	}
	
}




// Searches a deque for a specific token
bool Parser::ScanQUEUE(Token var, std::deque<Token> deq) {


	// using a lambda function to search the 
	// since we are searching a list of deques of tokens
	// and looking for a specific string
	std::find_if(deq.begin(),
		deq.end(),
		[&lx = var]( Token& x) -> bool {return lx.getLexeme() == x.getLexeme(); });
	
	return false;
}


void Parser::printT() 
{
	// For every queue in the list
	for (std::vector<std::deque<Token>>::iterator queue = list.begin(); queue < list.end(); queue++)
	{
		// for every token in the queue 		
		for(std::deque<Token>::iterator it=(*queue).begin(); it < (*queue).end(); it++)
		{ 			
			// print the lexeme
			std::cout<< (*it).getLexeme() << " "; 		
		} 	

		std::cout<<std::endl;
	}
}