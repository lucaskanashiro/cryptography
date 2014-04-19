#include <iostream>
#include "key.h"
#include "encryption.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

int main(){

	Key key;
	Encryption encryption;

  key.generate("key.txt",512);  
  cout << key.getKeyText() << endl;

	cout << "TRANSPOSICAO: [" << encryption.cypher("teste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografia" , key.getKeyText(), TRANSPOSITION) << "]" << endl;
  cout << "SUBSTITUICAO : [" << encryption.cypher("teste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografiateste criptografia", key.getKeyText(), SUBSTITUTION) << "]" << endl;

	return 0;
}
