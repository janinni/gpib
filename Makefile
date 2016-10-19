CXX		= g++
CXXFLAGS	= -O2 -Wall 
LDFLAGS		= -lgpib
SRCFILES	= gpib.cpp gpibMain.cpp
OBJFILES    = gpib.o gpibMain.o

gpib:		$(OBJFILES)
		$(CXX) $(OBJFILES) $(LDFLAGS) -o $@

clean:
		rm -f $(OBJFILES) gpib 

gpib.o:	gpib.cpp gpib.h
gpibMain.o:	gpibMain.cpp gpib.h