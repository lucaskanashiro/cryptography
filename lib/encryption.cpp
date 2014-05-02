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
  int length=0;

  for(unsigned int i=0; i<key.size(); i++)
    length = (length + key[i]) % text.size();

  for(unsigned int i=0; i<text.size(); i++)
  {
    for(int j=0; j<length; j++)
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
		multimap<char,string> matrix;
		unsigned int maxSize, i;
		string result;

    if(key.size() > 8)
		  key.erase(key.begin()+8,key.end());

		for(i=0;i<key.size();i++)
			matrix.insert(pair<char,string>(key[i], ""));

    multimap<char,string>::iterator it = matrix.begin();

		for(i=0;i<text.size();i++)
    {
			if(it == matrix.end()) it = matrix.begin();

			it->second.append(1, text[i]);
      it++;
    }

		sort(key.begin(), key.end(), greater<char>());

    it = matrix.begin();
		maxSize = it->second.size();

    for(; it != matrix.end(); it++)
    {
      if(it->second.size() < maxSize)
        it->second.append(1, ' ');
    }

    it = matrix.begin();
    unsigned int lineSize = maxSize;

    for(unsigned int j=0; j<maxSize; j++)
    {
      for(i=0; i<8; i++)
      {
        pair<multimap<char,string>::iterator, multimap<char,string>::iterator> ret;

        ret = matrix.equal_range(key[i]);

        for(it=ret.first;it!=ret.second;it++)
        {
					if(it->second.size() == lineSize)  
          	break;
        }

        result.append(1, it->second[0]);
        it->second.erase(0, 1);
      }

      lineSize--;
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
    case 3:
      cypherText = this->transposition(text, key);
      cypherText = this->substitution(cypherText, key);
      break;
  }

  return cypherText;
}

