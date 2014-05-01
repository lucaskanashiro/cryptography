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
		char caracter;
		int type = rand()%3;
		if(type == 0)
		 caracter = (char) (rand()%10 + 48);
		else if(type == 1)
		 caracter = (char) (rand()%26 + 65);	
		else
		 caracter =(char)  (rand()%26 + 97);
    randomKey << caracter; 
  }
  writeKeyInFile(fileName,randomKey.str());

  this->keyText = randomKey.str();
}

string
Key::getKeyText()
{
  return this->keyText;
}

