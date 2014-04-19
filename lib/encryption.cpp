#include "encryption.h"

Encryption::Encryption(){}

string
Encryption::substitution(string text, string key)
{
	return " ";  
}

string 
Encryption::monoalphabetic(string text, string key)
{

}

string 
Encryption::vernam(string text, string key)
{

}

string 
Encryption::transposition(string text, string key)
{
	string matrix[8],result;

	unsigned int itext,imatrix;
	
	itext = 0;
	imatrix = 0;
	while(itext < text.size()){
				
		if(imatrix == 8){
			imatrix = 0;
		}
				
		matrix[imatrix] += text[itext];
	
		imatrix++;
		itext++;
	}

	for( imatrix=0;imatrix<8;imatrix++)
		result += matrix[imatrix];

	return  result;
}

string 
Encryption::cypher(string text, string key, int FLAG)
{
  string cypherText;

	switch(FLAG)
  {
    case 1:
      cypherText = this->transposition(text, key);
    case 2:
      cypherText = this->substitution(text, key);
  }

  return cypherText;
}

