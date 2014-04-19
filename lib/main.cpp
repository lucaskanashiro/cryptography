#include <iostream>
#include <fstream>
#include "key.h"
#include "encryption.h"
#include "decryption.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

int main(int argc, char *argv[]){

  if(argc != 3)
  {
    cout << "Should pass as parameter the name of .txt file with clear or cypher text and key!!!" << endl;
    return -1;
  }

	//Key key;
	Encryption encryption;
  Decryption decryption;

  //key.generate("key.txt",512);  
  //cout << "KEY: " <<  key.getKeyText() << endl;

  ifstream fileText;
  fileText.open(argv[1]);

  string text;
  getline(fileText, text);

  cout << "TEXT: " << text << endl;

  fileText.close();

  ifstream fileKey;
  fileKey.open(argv[2]);

  string key;
  getline(fileKey, key);

  cout << "Key: " << key << endl << endl;

  fileKey.close();

  string cypherTextSubstitution = encryption.cypher(text, key, SUBSTITUTION);
  string cypherTextTransposition = encryption.cypher(text, key, TRANSPOSITION);

  cout << "ENCRYTION" << endl;

	cout << "TRANSPOSICAO: [" << cypherTextTransposition << "]" << endl;
  cout << "SUBSTITUICAO : [" << cypherTextSubstitution << "]" << endl << endl;

  string cypherText = encryption.cypher(text, key.getKeyText(), SUBSTITUTION);
	string cypherText2 = encryption.cypher(text ,key.getKeyText(), TRANSPOSITION);
  
	cout << "DECRYPTION" << endl;
	
	cout << "TRANSPOSICAO: [" << decryption.decrypt(cypherText2 ,key.getKeyText(), TRANSPOSITION) << "]" << endl;
  cout << "SUBSTITUICAO : [" << decryption.decrypt(cypherText, key.getKeyText(), SUBSTITUTION) << "]" << endl;

	return 0;
}
