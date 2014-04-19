#ifndef ENCRYPTION_H 
#define ENCRYPTION_H

#include "key.h"
#include <string>

class Encryption
{
  public:

    Encryption();

		string cypher(string text, string key, int FLAG);

	private:

    string substitution(string text, string key);
    string monoalphabetic(string text, string key);
    string vernam(string text, string key);

		string transposition(string text, string key);
};

#endif 

