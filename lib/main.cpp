#include <iostream>
#include <fstream>
#include "key.h"
#include "encryption.h"
#include "decryption.h"
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
				 << " ./cypher <plainText> <key> <mode>" <<endl
				 << " ./decypher <cypherText> <key> <mode>" << endl
				 << " Mode = ('-sub') | ('-tran') | ('-all')"<<endl;
		exit(-1);
	}
	
 if( name == "./cypher")
	{
		Encryption encryption;
		string plainText;
		string key;
		string cypherText;
		plainText = readFile(argv[1]);
		cout << plainText << endl;
 	 
		key = readFile(argv[2]);
		cout << key << endl;

   string mode = argv[3];
	 if(mode == "-sub")	
   {
     cypherText = encryption.cypher(plainText, key, SUBSTITUTION);
	 }	
	 else if(mode == "-tran")
	 { 
     cypherText = encryption.cypher(plainText, key, TRANSPOSITION);
   }
   else if(mode == "-all")
	 {
			cout << "todos" << endl;
	 }else{
			cout << "invalid command " << endl;
			exit(-1);
	 }
	 cout <<"["<<cypherText<<"]"<< endl;

	}
	else 	if( name == "./decypher")
	{
  	Decryption decryption;

		string cypherText;
		string key;
		string plainText;
		cypherText = readFile(argv[1]);
		cout << cypherText << endl;
 	 
		key = readFile(argv[2]);
		cout << key << endl;

		string mode = argv[3];
		if(mode == "-sub")
		{
      plainText = decryption.decrypt(cypherText, key, SUBSTITUTION);
		}else if(mode == "-tran")
		{
			plainText= decryption.decrypt(cypherText ,key, TRANSPOSITION);
		}else if(mode == "-all")
		{
			cout << "todos" << endl;
		}else{
			cout << "invalid comand" << endl;
		}
	  cout <<"["<<plainText<<"]"<< endl;
	}	

	return 0;
}
