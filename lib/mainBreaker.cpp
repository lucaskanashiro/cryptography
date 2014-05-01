#include <iostream>
#include <fstream>
#include <string>
#include "breakerCypher.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

string 
readFile(string fileName)
{
		ifstream fileText;
		string text;

		fileText.open(fileName.c_str());

    getline(fileText, text);

  	fileText.close();

		return text;
}


int 
main(int argc, char *argv[])
{

	string name = argv[0];

	if(argc != 4)
	{
		cout << "Try to type :"<< endl
				 << " ./breaker <cyoherText> <plainWords> <mode>" <<endl
				 << " Mode = ('-sub') | ('-tran')"<<endl;
		exit(-1);
	}
	
  BreakerCypher breaker;
  string cypherText, plainWords, plainText;

  cypherText = readFile(argv[1]);
  cout << cypherText << endl;
 
  plainWords = readFile(argv[2]);
  cout << plainWords << endl;

  string mode = argv[3];

  if(mode == "-sub")	
    plainText = breaker.broke(cypherText, plainWords, SUBSTITUTION);

  else if(mode == "-tran")
    plainText = breaker.broke(cypherText, plainWords, TRANSPOSITION);

  else
  {
     cout << "invalid command " << endl;
     exit(-1);
  }
  
  cout <<"["<<plainText<<"]"<< endl;

  return 0;
}
