#ifndef HELPERFUNCTION_HPP
#define HELPERFUNCTION_HPP
#include "2105046_header.hpp"

inline string getTokens(const string& line, const ui want){
    bool start = false;
    int tokenStart = 0;
    int tokenIndex = 0;

    for(int i = 0; i < line.size(); i++){
        if(!isspace(line[i])){
            if(!start){
                start = true;
                tokenStart = i;
            }
        }
        else if(start){
            if(tokenIndex == want){
                return line.substr(tokenStart, i - tokenStart);
            }
            tokenIndex++;
            start = false;
        }
    }

    if(start && tokenIndex == want){
        return line.substr(tokenStart);
    }
    return "";
}

inline static string trimLine(const string& line) {
    size_t start = 0, end = line.size();

    while (start < end && isspace(static_cast<unsigned char>(line[start]))) {
        ++start;
    }

    while (end > start && isspace(static_cast<unsigned char>(line[end - 1]))) {
        --end;
    }
    return line.substr(start, end - start);
}

inline ui countTokens(const string & line){
    bool start = false;
    int tokenCount = 0;

    for(int i = 0; i < line.size(); i++){
        if(!isspace(line[i])){
            if(!start){
                start = true;
                tokenCount++;
            }
        }
        else{
            start = false;
        }
    }

    return tokenCount;
}


inline int nextPrime(int n)
{
    if (n <= 1)
    {
        n = 2;
        return n;
    }
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0){
            n++;
            i = 2;
        }
        else i++;
        
    }
    return n;
}


#endif

