#include "breakerCypher.h"

BreakerCypher::BreakerCypher(){}

string
BreakerCypher::substitution(string cypherText, string plainWords)
{
  string plainText = this->alphabetic(cypherText, plainWords);

  return plainText;
}

string brokeAlphabetic(string cypherText, int key)
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
string 
BreakerCypher::alphabetic(string cypherText, string plainWords)
{
  int key;
	unsigned int i,j,difference;
	vector<int> pattern;
	map<string,vector<int> > diff;
	stringstream ss (plainWords);
	bool found ;
	int aux;
  vector<string> word;
  string tmp;
  while(ss >> tmp) word.push_back(tmp);


	for(i=0;i<word.size();i++)
	{
		vector<int> d;

		for( j=1;j<word[i].size();j++)
		{
			d.push_back( abs(  (int) word[i][j] - (int) word[i][j-1])  );
		}
		diff.insert(pair<string,vector<int> >(word[i],d));
		d.clear();
	}

	found = false;
		for(map<string,vector<int> >::iterator it=diff.begin();it!= diff.end();it++ )
		{
			difference = 0;
			aux = 0;
			
			for(i=1;i<cypherText.size();i++)
			{
				if(aux == it->second.size()-1)
				{
				 key = abs( it->second[ it->second.size()-1] - cypherText[i]  );
				 cout << key << endl;
				 found = true;
				 break;
				}				


				difference	= abs((int) cypherText[i] - (int) cypherText[i-1]) - it->second[aux];
				cout << aux << endl;

				if(difference == 0) aux++;
 			  else							  aux=0;
			}
			if(found)	break;
		}
	

	string result = 	brokeAlphabetic(cypherText,key);

	cout << 	result << endl;


  return "";
}

string 
BreakerCypher::transposition(string cypherText, string plainWords)
{
  string plainText = this->colummTransposition(cypherText, plainWords);

	return  plainText;
}


void writeToFile(string text, int key[8])
{
  ofstream file;
  file.open("plainText.txt");
  file << "PLAIN TEXT: " << endl <<  text << endl;
  file << "KEY: " << endl;

  for(int i=0; i<8; i++)
    file << key[i] << " ";

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



  cout << "PLAIN TEXT: [" << plainText << "]" << endl;

  cout << "KEY: " << endl;
  for(unsigned int i=0; i<8; i++)
    cout << possibleKey[i] << " ";
  cout << endl;

  cout << "PLAIN WORDS:" << endl;
  for(unsigned int i=0; i<word.size(); i++)
    cout << "[" << word[i] << "]" << endl;

  cout << "CYPHER TEXT:" << endl;
  for(int i=0; i<8; i++)
    cout << "[" << text[i] << "]" << endl;

  writeToFile(plainText, possibleKey);

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

