#ifndef ENCRYPTION_H 
#define ENCRYPTION_H

#include "key.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Encryption
{
  public:

    Encryption();

		string cypher(string text, string key, int FLAG);

	private:

    string substitution(string text, string key);
    string monoalphabetic(string text, string key);
    string vernam(string text, string key);

		string prepareKey(string key);
		string colummTransposition(string text , string key);
		string lineTransposition(string text,string key);
		string transposition(string text, string key);
};

#endif 

