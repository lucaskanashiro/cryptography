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
Key::readKeyInFile(string fileName)
{
	ifstream input;

	input.open(fileName.c_str());

	if(!input.is_open()){
		cout << "Arquivo aberto ou nao existe."<<endl;
		return;
	}
	
	getline(input,this->keyText);

	input.close();
}


void
Key::generate(string fileName,int numberOfBits)
{
  this->numberOfBits = numberOfBits;

  ostringstream randomKey;

  srand(time(NULL) + (getpid()/2));

  for(int i=0; i<(this->numberOfBits/8); i++)
  {
    randomKey << (char)(rand() % 94 + 33);
  }

  writeKeyInFile(fileName,randomKey.str());

  this->keyText = randomKey.str();
}

string
Key::getKeyText()
{
  return this->keyText;
}

