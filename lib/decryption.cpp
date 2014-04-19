#include "decryption.h"

Decryption::Decryption(){}

string
Decryption::substitution(string cypherText, string key)
{
  string plainText;

  //plainText = this->vernam(cypherText, key);
  plainText = this->monoalphabetic(cypherText, key);

  return plainText;
}

string 
Decryption::monoalphabetic(string cypherText, string key)
{
  for(unsigned int i=0; i<cypherText.size(); i++)
  {
    for(int j=0; j<(((int)key[0]+(int)key[key.size()-1])*(int)(i+1)); j++)
    {
      if(cypherText[i] == '0')
      {
        cypherText[i] = 32;
        continue;
      }
      else if(cypherText[i] == 'A')
      {
        cypherText[i] = '9';
        continue;
      }
      else if(cypherText[i] == 'a')
      {
        cypherText[i] = 'Z';
        continue;
      }
      else if(cypherText[i] == 32)
      {
        cypherText[i] = 'z';
        continue;
      }
      
      cypherText[i]--;
    }
  }

  return cypherText;
}

bool boundDecryption(char a)
{
  return (a==32) || (a>='0'&&a<='9') || (a>='A'&&a<='Z') || (a>='a'&&a<='z');
}

string 
Decryption::vernam(string cypherText, string key)
{
  string plainText = cypherText;
  unsigned int j=0;

  for(unsigned int i=0; i<cypherText.size(); i++, j=((j+1)%key.size()))
  {
    plainText[i] = cypherText[i] ^ key[j];

    //while(!boundDecryption(plainText[i]))
      //plainText[i]--;
  }

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

