#ifndef NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H
#define NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H


#include "NumberLink.h"
#include "iostream"

class Polynomial {
private:
    NumberLink *head{new NumberLink()};

public:
    void createHead(int &exponent);

    NumberLink *initLink();

    void initElement(int exponent);

    void printPlus(Polynomial &polynomial);
};


#endif //NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H
