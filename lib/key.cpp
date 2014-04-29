#include "key.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

Key::Key(){}

void 
Key::writeKeyInFile(string fileName,string key)
{
  ofstream output;
  
  output.open(fileName.c_str());
  
	output << key;

  output.close();
}

void
Key::generate(string fileName,int numberOfBits)
{
  this->numberOfBits = numberOfBits;

  ostringstream randomKey;

  srand(time(NULL) + (getpid()/2));

  for(int i=0; i<(this->numberOfBits/8); i++)
  {
    char caracter = (char)(rand() % 94 + 33);
    int length = rand() % 87 + 22;

    for(int i=0; i<length; i++)
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

    randomKey << num; 
  }

  writeKeyInFile(fileName,randomKey.str());

  this->keyText = randomKey.str();
}

string
Key::getKeyText()
{
  return this->keyText;
}

