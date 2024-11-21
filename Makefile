
COMPILER=g++

main: src/main.cpp
	$(COMPILER) $< -o main
	./main
	make clean

.PHONY:
clean:
	$(RM) main
	
