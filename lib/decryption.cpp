#include "decryption.h"

Decryption::Decryption(){}

string 
Decryption::alphabetic(string cypherText, string key)
{
  int length=0;

  for(unsigned int i=0; i<key.size(); i++)
    length = (length + key[i]) % cypherText.size();

  for(unsigned int i=0; i<cypherText.size(); i++)
  {
    for(int j=0; j<length; j++)
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

string
Decryption::substitution(string cypherText, string key)
{
  string plainText = this->alphabetic(cypherText, key);

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
Decryption::colummTransposition(string cypherText,string key)
{
		multimap<char,string> matrix;
		unsigned int i;
		string result;

    if(key.size() > 8)
		  key.erase(key.begin()+8,key.end());

		for(i=0;i<key.size();i++)
			matrix.insert(pair<char,string>(key[i], ""));

    multimap<char,string>::reverse_iterator it1 = matrix.rbegin();

		for(i=0;i<cypherText.size();i++)
    {
      if(it1 == matrix.rend()) it1 = matrix.rbegin();
			it1->second.append(1, cypherText[i]);
      it1++;
    }

	  multimap<char ,string >::iterator it;	

    it = matrix.begin();
		for(i=0;i<cypherText.size();i++)
		{
			if(it == matrix.end()) it = matrix.begin();
			 unsigned int value =  matrix.count(it->first);
			
			if(value > 1)
			{
				pair<multimap<char,string>::reverse_iterator,multimap<char,string>::reverse_iterator> er = matrix.equal_range(it->first);
				multimap<char,string>::reverse_iterator rv;

				for(rv= er.second; rv!=er.first; ++rv)
				{
						result.append(1,rv->second[0]);
			  		rv->second.erase(0,1);
				}
				for(unsigned int l=0;l<value;l++)
				{
					if(it == matrix.end()) it = matrix.begin();
					it++;
				}
			}
      else
      {
		  	result.append(1,it->second[0]);
			  it->second.erase(0,1);
				it++;
			}
		}
		return result;
}


string 
Decryption::transposition(string cypherText, string key)
{
	string plainText = this->colummTransposition(cypherText,key);

  return plainText;  
}

