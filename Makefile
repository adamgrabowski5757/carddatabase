
# *****************************************************

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************

main: cardcollection.o 
	$(CXX) $(CXXFLAGS) -o cardcollection cardcollection.o 



cardcollection.o: cardcollection.cpp cardcollection.h 
	$(CXX) $(CXXFLAGS) -c cardcollection.cpp



