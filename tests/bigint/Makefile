objects=main.o bigint.o
cc=g++

main: $(objects)
	$(cc) -o main $(objects)

main.o: main.cpp
	$(cc) -c main.cpp

bigint.o: bigint.cpp bigint.hpp
	$(cc) -c bigint.cpp

.PHONY: clean
clean:
	-rm main $(objects)
