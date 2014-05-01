#include "breakerCypher.h"

BreakerCypher::BreakerCypher(){}

string
BreakerCypher::substitution(string cypherText, string plainWords)
{
  string plainText = this->alphabetic(cypherText, plainWords);

  return plainText;
}

int 
findDiff(char a, char b)
{
  int diff;

  if(a < b) swap(a,b);

  if(b == 32 && (a >= '0' && a <= '9'))
    diff = abs(b-a)-15;
  else if(b == 32 && (a >= 'A' && a <= 'Z'))
    diff = abs(b-a)-22;
  else if(b == 32 && (a >= 'a' && a <= 'z'))
    diff= abs(b-a)-28;
  else if((b >= '0' && b <= '9') && (a >= 'A' && a <= 'Z'))
    diff = abs(b-a)-7;
  else if((b >= '0' && b <= '9') && (a >= 'a' && a <= 'z'))
    diff = abs(b-a)-13;
  else if((b >= 'A' && b <= 'Z') && (a >= 'a' && a <= 'z'))
    diff = abs(b-a)-6;
  else
    diff = abs(b-a);

  return diff;
}

string 
brokeAlphabetic(string cypherText, int key)
{
  for(unsigned int i=0; i<cypherText.size(); i++)
  {
    for(int j=0; j<key; j++)
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

void 
writeToFile(string text, int key[8], int oneKey)
{
  ofstream file;
  file.open("brokeText.txt");
  file << "PLAIN TEXT: " << endl <<  text << endl;
  file << "KEY: " << endl;

  if(oneKey == -1)
  {
    for(int i=0; i<8; i++)
      file << key[i] << " ";
  }
  else
    file << oneKey;

  file.close();
}

string 
BreakerCypher::alphabetic(string cypherText, string plainWords)
{
  int key;
	unsigned int i, j, aux;
	map<string,vector<int> > diff;
	bool found;
  vector<string> word;
  string tmp;

	stringstream ss (plainWords);
  while(ss >> tmp) word.push_back(tmp);

	for(i=0;i<word.size();i++)
	{
		vector<int> d;

		for( j=1;j<word[i].size();j++)
		{
      int var = findDiff(word[i][j], word[i][j-1]);
			d.push_back(var);
		}
		diff.insert(pair<string,vector<int> >(word[i],d));
		d.clear();
	}

	found = false;
  
  for(map<string,vector<int> >::iterator it=diff.begin();it!= diff.end();it++ )
  {
    aux = 0;
    
    for(i=1;i<cypherText.size();i++)
    {
      if(aux == it->second.size())
      {
       key = findDiff(word[0][word[0].size()-1], cypherText[i-1]);
       key = abs(63-key);
       found = true;
       break;
      }				

      int var = findDiff(cypherText[i], cypherText[i-1]);

      if((var - it->second[aux] == 0) || ((63 - var) - it->second[aux] == 0)) aux++;
      else	aux=0;
    }

    if(found)	break;
  }

	string result =	brokeAlphabetic(cypherText,key);

  writeToFile(result, 0, key);

  return result;
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
  vector<int> key;
  string text[8];
  int index=0;

  stringstream ss (plainWords);

  vector<string> word;
  string tmp;

  while(ss >> tmp) word.push_back(tmp);

  for(unsigned int i=0; i<cypherText.size(); i++, index = (index+1)%8)
    text[index].append(1, cypherText[i]);

  unsigned int sizeColumn = text[0].size();

  for(int i=0; i<8; i++)
  {
    if(text[i].size() < sizeColumn)
      text[i].append(1, ' ');
  }

  string plainText = "";
  int possibleKey[] = {0,1,2,3,4,5,6,7};

  do
  {
    plainText.clear();

    bool isEnd = true;

    for(unsigned int i=0; i<sizeColumn; i++)
    {
      for(unsigned int j=0; j<8; j++)
        plainText.append(1, text[possibleKey[j]][i]);
    }

    for(unsigned int i=0; i<word.size(); i++)
    {
      if(plainText.find(word[i]) == string::npos)
      {
        isEnd = false;
        break;
      }
    }

    if(isEnd) break;

  } while(next_permutation(possibleKey, possibleKey+8));

  writeToFile(plainText, possibleKey, -1);

  return plainText;
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

