
main = lib/main.cpp
lib = lib/key.cpp lib/encryption.cpp 
flags = -W -Wall -pedantic -ansi

all:
	g++ -o prog $(flags) $(main) $(lib) 

clean:
	rm key.txt prog
