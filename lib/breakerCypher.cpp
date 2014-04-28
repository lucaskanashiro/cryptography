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

vector<int> findCharacter(string text[8], unsigned int sizeColumn, char c)
{
  vector<int> index;

  for(unsigned int i=0; i<sizeColumn; i++)
  {
    for(unsigned int j=0; j<8; j++)
    {
      if(text[j][i] == c)
        index.push_back(j);
    }
  }

  return index;
}

vector<int> findKey(string text[8], unsigned int sizeColumn, string word)
{
  vector<int> key;
  vector<int> index;
  int aux;

  for(unsigned int j=0; j<word.size(); j++)
  {
    index = findCharacter(text, sizeColumn, word[j]);
    aux = index[rand()%index.size()]; 
    key.push_back(aux);
  }

  return key;
}

void writeToFile(string text)
{
  ofstream file;
  file.open("plainText.txt");
  file << text;
  file.close();
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
    bool isEnd = true;

    for(unsigned int i=0; i<word.size(); i++)
    {
      if(plainText.find(word[i]) == string::npos)
      {
        isEnd = false;
        break;
      }
    }

    if(isEnd) break;

    plainText.clear();

    for(unsigned int i=0; i<sizeColumn; i++)
    {
      for(unsigned int j=0; j<8; j++)
        plainText.append(1, text[possibleKey[j]][i]);
    }
  } while(next_permutation(possibleKey, possibleKey+8));



  cout << "PLAIN TEXT: [" << plainText << "]" << endl;

  cout << "KEY: " << endl;
  for(unsigned int i=0; i<key.size(); i++)
    cout << key[i] << " ";
  cout << endl;

  cout << "PLAIN WORDS:" << endl;
  for(unsigned int i=0; i<word.size(); i++)
    cout << "[" << word[i] << "]" << endl;

  cout << "CYPHER TEXT:" << endl;
  for(int i=0; i<8; i++)
    cout << "[" << text[i] << "]" << endl;

  writeToFile(plainText);

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

