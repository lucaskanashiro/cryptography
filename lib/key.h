#ifndef KEY_H
#define KEY_H

#include <string>
#include <unistd.h>
using namespace std;

class Key
{
  public:

    Key();

    void generate(int numberOfBits);
    string getKeyText();

  private:

    void writeKeyInFile(string key);

    int numberOfBits;
    string  keyText;
};

#endif
