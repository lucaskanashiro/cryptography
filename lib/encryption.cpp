#include "encryption.h"

Encryption::Encryption(){}

string
Encryption::substitution(string text, Key key)
{
	return " ";  
}


string 
Encryption::transposition(string text,Key key)
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
/*
string 
Encryption::cypher(string text,Key key)
{
	return " ";
}
*/
