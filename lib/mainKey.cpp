#include <iostream>
#include <string>
#include <sstream>
#include "key.h"

using namespace std;

int 
main(int argc, char *argv[])
{

	string name = argv[0];

	if(argc != 2)
	{
		cout << "Try to type :"<< endl
				 << " ./key <sizeKey>" <<endl;
		return -1;
	}
	
  Key key;

  stringstream ss(argv[1]);
  int sizeKey;

  ss >> sizeKey;
 
  key.generate("generatedKey.txt", sizeKey);  
  
  cout << "[" << key.getKeyText() << "]" << endl;

  return 0;
}

