#include "encryption.h"

Encryption::Encryption(){}

string
Encryption::substitution(string text, string key)
{
  string cypherText;

  cypherText = this->monoalphabetic(text, key);
  //cypherText = this->vernam(cypherText, key);

  return cypherText;
}

string 
Encryption::monoalphabetic(string text, string key)
{
  for(unsigned int i=0; i<text.size(); i++)
  {
    for(int j=0; j<(((int)key[0]+(int)key[key.size()-1])*(int)(i+1)); j++)
    {
      if(text[i] == 32)
      {
        text[i] = '0';
        continue;
      }
      else if(text[i] == '9')
      {
        text[i] = 'A';
        continue;
      }
      else if(text[i] == 'Z')
      {
        text[i] = 'a';
        continue;
      }
      else if(text[i] == 'z')
      {
        text[i] = 32;
        continue;
      }
      
      text[i]++;
    }
  }

  return text;
}

bool boundEncryption(char a)
{
  return (a==32) || (a>='0'&&a<='9') || (a>='A'&&a<='Z') || (a>='a'&&a<='z');
}

string 
Encryption::vernam(string text, string key)
{
  string cypherText = text;
  unsigned int j=0;

  for(unsigned int i=0; i<text.size(); i++, j=((j+1)%key.size()))
  {
    cypherText[i] = text[i] ^ key[j];

    //while(!boundEncryption(cypherText[i]))
      //cypherText[i]++;
  }

  return cypherText;
}

string 
Encryption::transposition(string text, string key)
{
	string matrix[8],result;
	unsigned int itext,imatrix;
	
	itext = imatrix = 0;
	while(itext < text.size()){

		matrix[imatrix] += text[itext];
	
		imatrix = (imatrix+1) % 8;
		itext++;
	}

	for( imatrix=0;imatrix<8;imatrix++)
		result += matrix[imatrix];

	return  result;
}

string 
Encryption::cypher(string text, string key, int FLAG)
{
  string cypherText;

	switch(FLAG)
  {
    case 1:
      cypherText = this->transposition(text, key);
      break;
    case 2:
      cypherText = this->substitution(text, key);
      break;
  }

  return cypherText;
}

