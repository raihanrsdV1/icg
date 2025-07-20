#ifndef HEADER_HPP
#define HEADER_HPP



#include <iostream>
#include <string>
#include <cstdio>   
#include <fstream>
#include <limits>
#include <cstring>
#include <vector>




using namespace std;


#define DEFAULT_BUCKETS 7
#define MAX_CHAIN_LENGTH 10
#define REHASH_INTERVAL 50
#define MurmurSeed 5113
#define JENKINS_A 0x9e3779b9U
#define JENKINS_B 0x9e3779b9U
#define JENKINS_C 0U
#define INSERT_SAMPLES 10000
#define SAMPLES 5
#define NUM_HASHES 3
#define PRINT_OUTPUT false
#define AVG_CHAIN_LENGTH 5
#define REHASH false
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef ui (*HashFn)(const string&, const ui &);
#define MAX_PARAMETERS 100

#endif