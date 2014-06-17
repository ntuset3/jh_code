CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		aqw.o

LIBS =

TARGET =	aqw.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
