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
    plainText[i] = (char) ((int)cypherText[i] - (int)key[0]);

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
Decryption::lineTransposition(string cypherText,string key)
{
		map<char,string> matrix;
		unsigned int j,i,imatrix;
		unsigned int maxSize;
		int lines = cypherText.size()/8;
		string result,orderedKey;

		key = this->prepareKey(key);
		key.erase(key.begin()+8,key.end());
		orderedKey =  key;
		sort(orderedKey.begin(),orderedKey.end());

		for(i=0;i<orderedKey.size();i++)
			matrix[orderedKey[i]] = "";

		imatrix =i= 0;
		while(  i < cypherText.size())
		{
				matrix[ orderedKey[imatrix]] += cypherText[i];
				i++;
				if(i%lines == 0)imatrix =(imatrix+1) % 8;
		}			

		for(i = 0;i<lines;i++)
			for(j=0;j<matrix.size();j++)	
				result += matrix[key[j]][i];

		return result;
}

string
Decryption::prepareKey(string key){
	string result;	
	result += key[0];
	for(unsigned int i=1;i<key.size();i++){
		if( 0 == count(result.begin(),result.end(),key[i]) ){
			result+= key[i];
		}
	}
	return result;
}

string 
Decryption::transposition(string cypherText, string key)
{
	string plainText = this->lineTransposition(cypherText,key);
  return plainText;  
}

