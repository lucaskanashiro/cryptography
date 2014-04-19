#include "encryption.h"

Encryption::Encryption(){}

string
Encryption::substitution(string text, string key)
{
  string cypherText;

  cypherText = this->monoalphabetic(text, key);
  cypherText = this->vernam(cypherText, key);

  return cypherText;
}

string 
Encryption::monoalphabetic(string text, string key)
{
  string cypherText = text;

  for(unsigned int i=0; i<text.size(); i++)
    cypherText[i] = (char) ((int)text[i] + (int)key[0]);

  return cypherText;
}

string 
Encryption::vernam(string text, string key)
{
  string cypherText = text;
  unsigned int j=0;

  for(unsigned int i=0; i<text.size(); i++, j=((j+1)%key.size()))
    cypherText[i] = text[i] ^ key[j];

  return cypherText;
}

string 
Encryption::transposition(string text, string key)
{

	text = this->lineTransposition(text,key);

	return  text;
}


string
Encryption::lineTransposition(string text,string key)
{
	string columm[8],result;
	unsigned int itext,icolumm;

	key = prepareKey(key);
	key.erase(key.begin()+8,key.end());

	for(int i=0;i<8;i++)
		columm[i] += key[i];	
	
	for(itext=0,icolumm=0;itext<text.size();itext++,icolumm = (icolumm+1)%8)
			columm[icolumm] += text[itext];

	sort(key.begin(),key.end());

	for(int i=0;i<8;i++)			
	{
		for(int j=0;j<8;j++)
		{
			if(key[i] == columm[j][0]){
				columm[j].erase(0,1);
				result+= columm[j];
			}
		}
	}
	return result;
}

string 
Encryption::colummTransposition(string text , string key)
{
	return " ";
}


string
Encryption::prepareKey(string key){
	string result;	
	result += key[0];
	
	for(unsigned int i=1;i<key.size();i++)
	{
		if( 0 == count(result.begin(),result.end(),key[i]) ){
			result+= key[i];
		}
	}
	return result;
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

