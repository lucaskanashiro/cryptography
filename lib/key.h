#ifndef KEY_H
#define KEY_H

#include <string>
#include <unistd.h>
using namespace std;

class Key
{
  public:

    Key();

    string generate(int numberOfBits);

  private:

    int numberOfBits;
    string  keyText;
};

#endif

