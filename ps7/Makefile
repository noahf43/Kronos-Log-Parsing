CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
DEPS = 
LIBS =  -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework -lboost_regex

all: ps7

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(LIBS)
ps7: ps7.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
clean:
	rm *.o ps7
lint:
	cpplint *.cpp *.hpp
	