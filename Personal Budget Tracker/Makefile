CXX = g++
CXXFLAGS = -g -Wall -std=c++11

OBJ = transaction.o category.o ledger.o utils.o report.o main.o

all: budget

budget: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o budget

transaction.o: transaction.cpp transaction.h
	$(CXX) $(CXXFLAGS) -c transaction.cpp -o transaction.o

category.o: category.cpp category.h transaction.h
	$(CXX) $(CXXFLAGS) -c category.cpp -o category.o

ledger.o: ledger.cpp ledger.h category.h
	$(CXX) $(CXXFLAGS) -c ledger.cpp -o ledger.o

utils.o: utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp -o utils.o

report.o: report.cpp report.h ledger.h utils.h
	$(CXX) $(CXXFLAGS) -c report.cpp -o report.o

main.o: main.cpp ledger.h report.h utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o budget