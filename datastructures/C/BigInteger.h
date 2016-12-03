//BigInteger.h
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

typedef struct {
    char *digits;
    char sign;
} BigInteger;

BigInteger *construct(char[]);
void print(BigInteger*);

#endif