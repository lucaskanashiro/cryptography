#include "key.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

Key::Key(){}

void writeKeyInFile(string key);

string
Key::generate(int numberOfBits)
{
  this->numberOfBits = numberOfBits;

  ostringstream randomKey;

  srand(time(NULL) + (getpid()/2));

  for(int i=0; i<(numberOfBits/8); i++)
  {
    randomKey << (char)(rand() % 94 + 33);
  }

  writeKeyInFile(randomKey.str());

  return randomKey.str();
}

void 
writeKeyInFile(string key)
{
  ofstream output;
  
  output.open("key.txt");
  
	output << key;

  output.close();
}

