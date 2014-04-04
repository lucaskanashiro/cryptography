#include <iostream>
#include "key.h"
#include "encryption.h"

using namespace std;

int main(){

	Key key;
	Encryption encryption;

	key.generate(512);  // 16 bytes

	string result;
	result = encryption.transposition("neste exercicio estou testando a transposicao de 8 blocos",key);

	cout << result;

	return 0;
}
