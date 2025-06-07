CXX			:= avr-g++
CXXFLAGS	:= -std=c++20 -O2 -Wall -Wextra -pedantic -Weffc++ -I/usr/avr/include
DEFS		:= -DF_CPU=16000000UL

SRCDIR	:= src
BINDIR	:= bin

SRC 	:= $(SRCDIR)/blink.cpp
OBJ 	:= $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRC))
TARGET 	:= $(BINDIR)/blink

all: $(BINDIR) $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -c -o $@ $<

$(BINDIR):
	mkdir -p $@

.PHONY: upload clean

upload:
	avr-objcopy -O ihex $(TARGET) $(TARGET).hex
	avrdude -p atmega328p -c usbasp -P usb -b 19200 -U flash:w:$(TARGET).hex

clean:
	rm -rf $(BINDIR)
