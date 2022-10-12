//
// Created by 86137 on 2022/10/12.
//

#include "NumberLink.h"


NumberLink::NumberLink(int factor, int exponent) : factor(factor), exponent(exponent) {
    this->next = nullptr;
}

void NumberLink::addElement(NumberLink* element) {
    this->next = element;
}
