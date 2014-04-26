
mainCypher = lib/mainCypher.cpp
mainDecypher = lib/mainDecypher.cpp
lib = lib/key.cpp lib/encryption.cpp lib/decryption.cpp
flags = -W -Wall -pedantic -ansi

all:
	g++ -o cypher $(flags) $(mainCypher) $(lib) 
	g++ -o decypher $(flags) $(mainDecypher) $(lib)
clean:
	rm cypher decypher
