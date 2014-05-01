#include <iostream>
#include <fstream>
#include <string>
#include "encryption.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

string 
readFile(string fileName)
{
	ifstream fileText;
	string text, res="";

	fileText.open(fileName.c_str());

  while(getline(fileText, text))
  res.append(text);

 	fileText.close();

	return res;
}

void 
writeToFile(string text)
{
	ofstream fileText;

	fileText.open("cypherText.txt");
	
	fileText << text << endl;
		
	fileText.close();
}

int 
main(int argc, char *argv[])
{
	string name = argv[0];

	if(argc != 4)
	{
		cout << "Try to type :"<< endl
				 << " ./cypher <plainText> <key> <mode>" <<endl
				 << " Mode = ('-sub') | ('-tran') | ('-all')"<<endl;
		exit(-1);
	}
	
  Encryption encryption;
  string plainText, key, cypherText;

  plainText = readFile(argv[1]);
  cout << plainText << endl;
 
  key = readFile(argv[2]);
  cout << key << endl;

  string mode = argv[3];

  if(mode == "-sub")	
    cypherText = encryption.cypher(plainText, key, SUBSTITUTION);

  else if(mode == "-tran")
    cypherText = encryption.cypher(plainText, key, TRANSPOSITION);

  else if(mode == "-all")
	{
    cypherText = encryption.cypher(plainText, key, TRANSPOSITION);
    cypherText = encryption.cypher(cypherText, key, SUBSTITUTION);
	}
	else
  {
     cout << "invalid command " << endl;
     exit(-1);
  }
  
  cout <<"["<<cypherText<<"]"<< endl;

	writeToFile(cypherText);

  return 0;
}

