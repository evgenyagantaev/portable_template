TARGET=~/bin/hello
OBJECTS1=obj/main.o obj/one_hz_timer_obj.o obj/ten_hz_timer_obj.o
OBJECTS2=obj/one_minute_timer_obj.o obj/udp_transmitter_obj.o
LIBS=-lncurses -lpthread -lm

all: $(TARGET)

$(TARGET): $(OBJECTS1) $(OBJECTS2)
	clang  $(OBJECTS1) $(OBJECTS2) -o $(TARGET) $(LIBS)

obj/main.o: src/main.c inc/main.h
	clang -c src/main.c -o obj/main.o
obj/one_hz_timer_obj.o: src/one_hz_timer_obj.c inc/one_hz_timer_obj.h
	clang -c src/one_hz_timer_obj.c -o obj/one_hz_timer_obj.o
obj/ten_hz_timer_obj.o: src/ten_hz_timer_obj.c inc/ten_hz_timer_obj.h
	clang -c src/ten_hz_timer_obj.c -o obj/ten_hz_timer_obj.o
obj/one_minute_timer_obj.o: src/one_minute_timer_obj.c inc/one_minute_timer_obj.h
	clang -c src/one_minute_timer_obj.c -o obj/one_minute_timer_obj.o
obj/udp_transmitter_obj.o: src/udp_transmitter_obj.c inc/udp_transmitter_obj.h
	clang -c src/udp_transmitter_obj.c -o obj/udp_transmitter_obj.o

clean:
	rm -rf obj/*.o $(TARGET)
