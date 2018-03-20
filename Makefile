TARGET=~/bin/hello
LIBS=-lncurses -lpthread -lm

all: $(TARGET)

$(TARGET): main.c 
	clang main.c -o $(TARGET) $(LIBS)

clean:
	rm -rf *.o $(TARGET)
