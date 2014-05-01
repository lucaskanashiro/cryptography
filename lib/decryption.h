#ifndef DECRYPTION_H 
#define DECRYPTION_H

#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Decryption
{
  public:

    Decryption();

		string decrypt(string cypherText, string key, int FLAG);

	private:

    string substitution(string cypherText, string key);
    string alphabetic(string cypherText, string key);

		string colummTransposition(string cypherText,string key);
    string transposition(string cypherText, string key);
};

#endif 

