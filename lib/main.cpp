#include <iostream>
#include <fstream>
#include "key.h"
#include "encryption.h"
#include "decryption.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

int main(int argc, char *argv[]){

  if(argc == 1)
  {
    cout << "Should pass as parameter the name of .txt file with clear text!!!" << endl;
    return -1;
  }

	Key key;
	Encryption encryption;
  Decryption decryption;

  key.generate("key.txt",512);  
  cout << "KEY: " <<  key.getKeyText() << endl;

  ifstream file;
  file.open(argv[1]);

  string text;
  getline(file, text);

  cout << "TEXT: " << text << endl << endl;

  file.close();

  cout << "ENCRYTION" << endl;

	cout << "TRANSPOSICAO: [" << encryption.cypher(text , key.getKeyText(), TRANSPOSITION) << "]" << endl;
  cout << "SUBSTITUICAO : [" << encryption.cypher(text, key.getKeyText(), SUBSTITUTION) << "]" << endl << endl;

  string cypherText = encryption.cypher(text, key.getKeyText(), SUBSTITUTION);
	string cypherText2 = encryption.cypher(text ,key.getKeyText(), TRANSPOSITION);
  
	cout << "DECRYPTION" << endl;
	
	cout << "TRANSPOSICAO: [" << decryption.decrypt(cypherText2 ,key.getKeyText(), TRANSPOSITION) << "]" << endl;
  cout << "SUBSTITUICAO : [" << decryption.decrypt(cypherText, key.getKeyText(), SUBSTITUTION) << "]" << endl;

	return 0;
}
