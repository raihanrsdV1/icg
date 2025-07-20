#ifndef HELPERHASH_HPP
#define HELPERHASH_HPP

#include "2105046_header.hpp"
// helping hash functions
// Hash functions sources:  
//   - SDBM: (https://www.programmingalgorithms.com/algorithm/ sdbm-hash/cpp/)
//   - MurmurHash2: Austin Appleby, https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp (slightly modified MurmurHash2A)
//   - Bob Jenkins' one-at-a-time hash adapted from http://burtleburtle.net/bob/hash/doobs.html

static ui SDBMHash(const string& str, const ui & numBuckets) {
	ui hash = 0;
	unsigned int i = 0;
	unsigned int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = ((str[i]) + (hash << 6) + (hash << 16) - hash);
	}
	return hash % numBuckets;
}

static ui MURMURhash(const string & key, const ui & numBuckets)
{
    int seed = MurmurSeed;
    const uint32_t m = 0x5bd1e995;
    const ui r = 24;
    const uint8_t *data = reinterpret_cast<const uint8_t *>(key.c_str());
    size_t length = key.length();
    uint32_t h = seed ^ (length * m); 

    while (length >= 4)
    {
        uint32_t k = *reinterpret_cast<const uint32_t *>(data);
        k *= m;
        k ^= k >> r;
        k *= m;
        h ^= k;
        h *= m;
        data += 4;
        length -= 4;
    }

    switch (length)
    {
    case 3:
        h ^= data[2] << 16;
        break;
    case 2:
        h ^= data[1] << 8;
        break;
    case 1:
        h ^= data[0];
        h *= m;
    }

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    // Ensure the hash is non-zero
    return h % numBuckets;
}

static ui JENKINSHash(const string& key, const ui & numBuckets) {
    typedef uint32_t ub4;
    typedef uint8_t  ub1;
    const ub1* k = reinterpret_cast<const ub1*>(key.c_str());
    ub4 length = static_cast<ub4>(key.length());
    ub4 a = JENKINS_A, b = JENKINS_B, c = JENKINS_C;

    // mix function (macro) as per Jenkins' original
    #define mix(a,b,c)                          \
        a -= b; a -= c; a ^= (c >> 13);        \
        b -= c; b -= a; b ^= (a << 8);         \
        c -= a; c -= b; c ^= (b >> 13);        \
        a -= b; a -= c; a ^= (c >> 12);        \
        b -= c; b -= a; b ^= (a << 16);        \
        c -= a; c -= b; c ^= (b >> 5);         \
        a -= b; a -= c; a ^= (c >> 3);         \
        b -= c; b -= a; b ^= (a << 10);        \
        c -= a; c -= b; c ^= (b >> 15);

    ub4 len = length;
    while (len >= 12) {
        a += (k[0]  | (ub4)k[1]  << 8 | (ub4)k[2]  << 16 | (ub4)k[3]  << 24);
        b += (k[4]  | (ub4)k[5]  << 8 | (ub4)k[6]  << 16 | (ub4)k[7]  << 24);
        c += (k[8]  | (ub4)k[9]  << 8 | (ub4)k[10] << 16 | (ub4)k[11] << 24);
        mix(a, b, c);
        k += 12;
        len -= 12;
    }
    c += length;
    switch (len) {
        case 11: c += (ub4)k[10] << 24;
        case 10: c += (ub4)k[9]  << 16;
        case 9:  c += (ub4)k[8]  << 8;
        case 8:  b += (ub4)k[7]  << 24;
        case 7:  b += (ub4)k[6]  << 16;
        case 6:  b += (ub4)k[5]  << 8;
        case 5:  b += (ub4)k[4];
        case 4:  a += (ub4)k[3]  << 24;
        case 3:  a += (ub4)k[2]  << 16;
        case 2:  a += (ub4)k[1]  << 8;
        case 1:  a += (ub4)k[0];
        case 0:  break;
    }
    mix(a, b, c);
    #undef mix
    return c % numBuckets;
}

#endif