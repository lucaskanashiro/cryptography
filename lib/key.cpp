#include "key.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>

Key::Key(){}

string
Key::generate(int numberOfBits)
{
  this->numberOfBits = numberOfBits;

  string randomKey;

  for(int i=0; i<(numberOfBits/8); i++)
  {
    srand(time(NULL) + (getpid()/2));

    randomKey[i] = rand() % 94 + 33;

    srand(rand());
  }

  writeKeyInFile(randomKey);

  return randomKey;
}

void writeKeyInFile(string key)
{
  ofstream output;
  
  output.open("key.txt");

  output << key;

  output.close();
}

