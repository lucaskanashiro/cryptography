#ifndef ENCRYPTION_H 
#define ENCRYPTION_H

#include "key.h"
#include <string>

class Encryption
{
  public:

    Encryption();

    string substitution(string text, Key key);
};

#endif 

