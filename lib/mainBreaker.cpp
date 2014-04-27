#include <iostream>
#include <fstream>
#include "key.h"
#include "encryption.h"
#include "decryption.h"
#include "breakerCypher.h"
#include <string>

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2


string readFile(string fileName){
		ifstream fileText;
		string text;
		fileText.open(fileName.c_str());
    getline(fileText, text);
  	fileText.close();
		return text;
}


int main(int argc, char *argv[]){

	string name = argv[0];

	if(argc != 4)
	{
		cout << "Try to type :"<< endl
				 << " ./breaker <cyoherText> <plainWords> <mode>" <<endl
				 << " Mode = ('-sub') | ('-tran') | ('-all')"<<endl;
		exit(-1);
	}
	
  BreakerCypher breaker;
  string cypherText;
  string plainWords;
  string plainText;

  cypherText = readFile(argv[1]);
  cout << cypherText << endl;
 
  plainWords = readFile(argv[2]);
  cout << plainWords << endl;

  string mode = argv[3];

  if(mode == "-sub")	
    plainText = breaker.broke(cypherText, plainWords, SUBSTITUTION);
  else if(mode == "-tran")
    plainText = breaker.broke(cypherText, plainWords, TRANSPOSITION);
  else if(mode == "-all")
    cout << "todos" << endl;
  else
  {
     cout << "invalid command " << endl;
     exit(-1);
  }
  
  cout <<"["<<plainText<<"]"<< endl;

  return 0;
}
