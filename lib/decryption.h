#ifndef DECRYPTION_H 
#define DECRYPTION_H

#include "key.h"
#include <string>
#include <algorithm>
using namespace std;
#include <iostream>
#include <map>
class Decryption
{
  public:

    Decryption();

		string decrypt(string cypherText, string key, int FLAG);

	private:

    string substitution(string cypherText, string key);
    string monoalphabetic(string cypherText, string key);
    string vernam(string cypherText, string key);

		string prepareKey(string key);
		string lineTransposition(string cypherText,string key);
    string transposition(string cypherText, string key);
};

#endif 

