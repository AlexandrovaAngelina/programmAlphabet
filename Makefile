CXX=gcc

CFLAGS =  -c -Wall -Werror -std=c99

FLAGS  =  -Wall -Werror -std=c99

OBJECTS = build/src/main.o build/src/interface.o build/src/work_file.o build/src/print.o build/src/sort.o

OBJECTS_TEST = build/test/main.o build/test/tests.o build/src/interface.o build/src/work_file.o build/src/sort.o build/src/print.o

.PHONY: clean all bin build default

all: default test

default: bin build bin/key

test: bin build bin/key_test
	bin/key_test

bin/key_test: $(OBJECTS_TEST)
	$(CXX) $(FLAGS) $(OBJECTS_TEST) -o bin/key_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/src/main.o: src/main.c 
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o 

build/src/interface.o: src/interface.c 
	$(CXX) $(CFLAGS) src/interface.c -o build/src/interface.o

build/src/work_file.o: src/work_file.c 
	$(CXX) $(CFLAGS) src/work_file.c -o build/src/work_file.o

build/src/print.o: src/print.c 
	$(CXX) $(CFLAGS) src/print.c -o build/src/print.o

build/src/sort.o: src/sort.c 
	$(CXX) $(CFLAGS) src/sort.c -o build/src/sort.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin
