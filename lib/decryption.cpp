#include "decryption.h"

Decryption::Decryption(){}

string
Decryption::substitution(string cypherText, string key)
{
  string plainText;

  plainText = this->vernam(cypherText, key);
  plainText = this->monoalphabetic(plainText, key);

  return plainText;
}

string 
Decryption::monoalphabetic(string cypherText, string key)
{
  string plainText = cypherText;

  for(unsigned int i=0; i<cypherText.size(); i++)
    plainText[i] = (char) ((int)cypherText[i] - (int)key[0] - (int)key[1]);

  return plainText;
}

string 
Decryption::vernam(string cypherText, string key)
{
  string plainText = cypherText;
  unsigned int j=0;

  for(unsigned int i=0; i<cypherText.size(); i++, j=((j+1)%key.size()))
    plainText[i] = cypherText[i] ^ key[j];

  return plainText;
}

string 
Decryption::decrypt(string cypherText, string key, int FLAG)
{
  string plainText;

	switch(FLAG)
  {
    case 1:
      plainText = this->transposition(cypherText, key);
      break;
    case 2:
      plainText = this->substitution(cypherText, key);
      break;
  }

  return plainText;
}

string 
Decryption::transposition(string cypherText, string key)
{
  return "";  
}

