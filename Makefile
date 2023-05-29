CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS = -fsanitize=address

SRC = Main.cpp src/Account.cpp src/Bank.cpp src/BonusAccount.cpp src/SavingsAccount.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = run

#SRCTEST = Test.cpp src/Account.cpp src/Bank.cpp src/BonusAccount.cpp src/SavingsAccount.cpp
#OBJTEST = $(SRCTEST:.cpp=.o)
#EXECTEST = test

all: $(EXEC) #$(EXECTEST)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ)

#$(EXECTEST): $(OBJTEST)
#	$(CXX) $(LDFLAGS) -o $@ $(OBJTEST)

clean:
	rm -rf $(OBJ) $(EXEC) $(OBJTEST) $(EXECTEST)
