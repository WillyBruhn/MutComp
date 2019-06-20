COMP =	g++ -std=c++11 -c -O3
LINK =	g++ -std=c++11


Catch = ./Catch/
Tests = ./Tests/
SRC = ./Tests/src/
HEADERS = ./Tests/headers/

all: CATCH 
	./CATCH

debug: COMP += -DDEBUG -g
debug: CATCH


CATCH: $(Catch)mainTest.o $(SRC)simpleCall.cpp 
	$(LINK) $(Catch)mainTest.o -o CATCH
	
	
#tool: $(OBJS)
#	$(CXX) $(LDFLAGS) -o tool $(OBJS) $(LDLIBS) 

$(Catch)mainTest.o: $(Catch)mainTest.cpp $(Catch)catch.hpp $(SRC)simpleCall.cpp $(SRC)commandline.cpp
	$(COMP) $(Catch)mainTest.cpp -o $(Catch)mainTest.o;
	
	
#$(Catch)%.o: $(Catch)%.cpp 
#	$(COMP)  $<

	
clean:
	rm -f $(Catch)*.o CATCH
