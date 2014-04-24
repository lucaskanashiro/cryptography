#include "encryption.h"

Encryption::Encryption(){}

string
Encryption::substitution(string text, string key)
{
  string cypherText = this->alphabetic(text, key);

  return cypherText;
}

string 
Encryption::alphabetic(string text, string key)
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

string 
Encryption::transposition(string text, string key)
{
  string cypherText = this->colummTransposition(text,key);

	return  cypherText;
}


string
Encryption::colummTransposition(string text,string key)
{
		map<char,string> matrix;
		unsigned int imatrix, space,maxSize,i;
		string result;

		key = this->prepareKey(key);
		key.erase(key.begin()+8,key.end());

		for( i=0;i<key.size();i++)
			matrix[key[i]] = "";

		imatrix = 0;
		for(i=0;i<text.size();i++,imatrix = (imatrix+1)%8)
		{
				matrix[key[imatrix]] += text[i]; 
		}

		maxSize = 0;	
		for(i=0;i<key.size();i++)
			if( maxSize < matrix[key[i]].size())
					maxSize = matrix[key[i]].size(); 

		for(i=0;i<key.size();i++){
			space = maxSize- matrix[key[i]].size();
			if( space != 0 ){	
				while(space != 0){
					matrix[key[i]] += " ";
					space--;	
				}
			}
		}

		sort(key.begin(),key.end());
		for(i=0;i<8;i++)
			result += matrix[key[i]];
		
		return result;
}

string
Encryption::prepareKey(string key){
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

