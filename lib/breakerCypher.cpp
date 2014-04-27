#include "breakerCypher.h"

BreakerCypher::BreakerCypher(){}

string
BreakerCypher::substitution(string cypherText, string plainWords)
{
  string plainText = this->alphabetic(cypherText, plainWords);

  return plainText;
}

string 
BreakerCypher::alphabetic(string cypherText, string plainWords)
{
  return "";
}

string 
BreakerCypher::transposition(string cypherText, string plainWords)
{
  string plainText = this->colummTransposition(cypherText, plainWords);

	return  plainText;
}


string
BreakerCypher::colummTransposition(string cypherText, string plainWords)
{
  return "";
}

string 
BreakerCypher::broke(string cypherText, string plainWords, int FLAG)
{
  string plainText;

	switch(FLAG)
  {
    case 1:
      plainText = this->transposition(cypherText, plainWords);
      break;
    case 2:
      plainText = this->substitution(cypherText, plainWords);
      break;
  }

  return plainText;
}

