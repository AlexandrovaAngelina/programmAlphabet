CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/main.o build/interface.o build/work_file.o build/print.o build/sort.o



.PHONY: clean all bin build default



all: bin build default



default: bin/key




bin/key: $(OBJECTS)

	$(CXX) $(FLAGS) $(OBJECTS) -o bin/prog



build/main.o: src/main.c 

	$(CXX) $(CFLAGS) src/main.c -o build/main.o 



build/interface.o: src/interface.c 

	$(CXX) $(CFLAGS) src/interface.c -o build/interface.o



build/work_file.o: src/work_file.c 

	$(CXX) $(CFLAGS) src/work_file.c -o build/work_file.o



build/print.o: src/print.c 

	$(CXX) $(CFLAGS) src/print.c -o build/print.o



build/sort.o: src/sort.c 

	$(CXX) $(CFLAGS) src/sort.c -o build/sort.o



build:

	mkdir -p build

bin:

	mkdir -p bin 

clean:

	-rm -rf build bin
