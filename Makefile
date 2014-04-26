
main = lib/main.cpp
lib = lib/key.cpp lib/encryption.cpp lib/decryption.cpp
flags = -W -Wall -pedantic -ansi

all:
	g++ -o cypher $(flags) $(main) $(lib) 
	g++ -o decypher $(flags) $(main) $(lib)
clean:
	rm key.txt prog
