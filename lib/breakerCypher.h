#ifndef BREAKER_CYPHER_H 
#define BREAKER_CYPHER_H

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class BreakerCypher
{
  public:

    BreakerCypher();

		string broke(string cypherText, string plainWords, int FLAG);

	private:

    string substitution(string cypherText, string plainWords);
    string alphabetic(string cypherText, string plainWords);

		string colummTransposition(string cypherText, string plainWords);
		string transposition(string cypherText, string plainWords);
};

#endif 

