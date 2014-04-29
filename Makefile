mainBreaker = lib/mainBreaker.cpp
mainCypher = lib/mainCypher.cpp
mainDecypher = lib/mainDecypher.cpp
mainKey = lib/mainKey.cpp
lib = lib/encryption.cpp lib/decryption.cpp
libBreaker = lib/breakerCypher.cpp
libKey = lib/key.cpp
flags = -W -Wall -pedantic -ansi

all:
	g++ -o cypher $(flags) $(mainCypher) $(lib) 
	g++ -o decypher $(flags) $(mainDecypher) $(lib)
	g++ -o breaker $(flags) $(mainBreaker) $(libBreaker)
	g++ -o key $(flags) $(mainKey) $(libKey)
clean:
	rm cypher decypher breaker key
