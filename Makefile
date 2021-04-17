CC = gcc
CFLAGS = -W -Wall
TARGET = fruitshop
DTARGET = fruitshop_debug
OBJECTS = productMain.c product.o manager.o moreFunc.o
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean:
	rm *.o
	rm fruitshop fruitshop_debug
