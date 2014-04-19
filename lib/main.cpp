#include <iostream>
#include "key.h"
#include "encryption.h"

using namespace std;

#define TRANSPOSITION 1
#define SUBSTITUTION 2

int main(){

	Key key;
	Encryption encryption;

	key.generate(512);  // 16 bytes
  cout << key.getKeyText() << endl;

	string result;
	result = encryption.cypher("neste exercicio estou testando a transposicao de 8 blocos" , key.getKeyText(), TRANSPOSITION);

	cout << result;

	return 0;
}
