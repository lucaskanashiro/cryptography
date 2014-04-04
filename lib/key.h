#ifndef KEY_H
#define KEY_H

#include <string>

class Key
{
  public:

    Key();

    string generate(int numberOfBytes);

  private:

    int numberOfBytes;
    string  keyText;
};

#endif

