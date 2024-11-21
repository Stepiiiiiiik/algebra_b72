
COMPILER=g++

main: src/main.cpp
	$(COMPILER) $< -o main
	./main

.PHONY:
clean:
	$(RM) main
	

