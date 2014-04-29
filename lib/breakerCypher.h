#ifndef BREAKER_CYPHER_H 
#define BREAKER_CYPHER_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cmath>

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

