mainBreaker = lib/mainBreaker.cpp
mainCypher = lib/mainCypher.cpp
mainDecypher = lib/mainDecypher.cpp
lib = lib/key.cpp lib/encryption.cpp lib/decryption.cpp
libBreaker = lib/breakerCypher.cpp
flags = -W -Wall -pedantic -ansi

all:
	g++ -o cypher $(flags) $(mainCypher) $(lib) 
	g++ -o decypher $(flags) $(mainDecypher) $(lib)
	g++ -o breaker $(flags) $(mainBreaker) $(libBreaker)
clean:
	rm cypher decypher breaker
