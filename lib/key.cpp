#include "key.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

Key::Key(){}

void 
Key::writeKeyInFile(string key)
{
  ofstream output;
  
  output.open("key.txt");
  
	output << key;

  output.close();
}

void
Key::generate(int numberOfBits)
{
  this->numberOfBits = numberOfBits;

  ostringstream randomKey;

  srand(time(NULL) + (getpid()/2));

  for(int i=0; i<(this->numberOfBits/8); i++)
  {
    randomKey << (char)(rand() % 94 + 33);
  }

  writeKeyInFile(randomKey.str());

  this->keyText = randomKey.str();
}

string
Key::getKeyText()
{
  return this->keyText;
}

