#ifndef NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H
#define NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H


#include "NumberLink.h"
#include "iostream"

class Polynomial {
private:
    NumberLink *head{new NumberLink()};

    void createHead(int &exponent);

public:
    NumberLink *initLink();

    void initElement(int exponent);

    Polynomial operator+(Polynomial &polynomial);

    friend std::ostream &operator<<(std::ostream& os,const Polynomial& polynomial);
};


#endif //NOTE_OF_DATA_STRUCTURE_POLYNOMIAL_H
