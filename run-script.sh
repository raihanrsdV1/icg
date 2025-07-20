antlr4 -v 4.13.2 -Dlanguage=Cpp C2105046Lexer.g4
antlr4 -v 4.13.2 -visitor -Dlanguage=Cpp C2105046Parser.g4
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c C2105046Lexer.cpp C2105046Parser.cpp Ctester.cpp
g++ -std=c++17 -w C2105046Lexer.o C2105046Parser.o Ctester.o -L/usr/local/lib/ -lantlr4-runtime -o Ctester.out -pthread
LD_LIBRARY_PATH=/usr/local/lib ./Ctester.out $1
