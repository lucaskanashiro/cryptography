#ifndef ENCRYPTION_H 
#define ENCRYPTION_H

#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Encryption
{
  public:

    Encryption();

		string cypher(string text, string key, int FLAG);

	private:

    string substitution(string text, string key);
    string alphabetic(string text, string key);

		string colummTransposition(string text , string key);
		string transposition(string text, string key);
};

#endif 

