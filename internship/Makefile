all: cache_system

cache_system: main.o cache_level.o multi_level_cache.o
	g++ -o cache_system main.o cache_level.o multi_level_cache.o

main.o: src/main.cpp
	g++ -c src/main.cpp

cache_level.o: src/cache_level.cpp
	g++ -c src/cache_level.cpp

multi_level_cache.o: src/multi_level_cache.cpp
	g++ -c src/multi_level_cache.cpp

clean:
	rm *.o cache_system
