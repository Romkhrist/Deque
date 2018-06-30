.PHONY: all install uninstall clean

CPPC = g++
CFLAGS = -c -Wall
LDFLAGS = -o
TARGET = Deque
SRCS = main.cpp
OBJS = main.o
INSTALL_PATH = ~/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) $(LDFLAGS) $(TARGET) $(OBJS)
	
$(OBJS): $(SRCS)
	$(CPPC) $(CFLAGS) $(SRCS)

install: $(TARGET)
	install -D -m 744 $(TARGET) $(INSTALL_PATH)/$(TARGET)
	make clean
		
uninstall: $(TARGET)
	rm -rf $(INSTALL_PATH)/$(TARGET)
	
clean:
	rm -rf $(TARGET) *.o 
