TARGET := run
SRC := sendrecv.cc 

CXX :=    sst++
CC :=     sstcc
CXXFLAGS := -std=c++17 -fPIC
CPPFLAGS := -I. 
LIBDIR :=
PREFIX :=
LDFLAGS :=  -Wl,-rpath,$(PREFIX)/lib

OBJ := $(SRC:.cc=.o)
OBJ := $(OBJ:.cpp=.o)
OBJ := $(OBJ:.c=.o)

.PHONY: clean install

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $+ $(LDFLAGS) $(LIBS)  $(CXXFLAGS)

%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
