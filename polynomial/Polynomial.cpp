//
// Created by 86137 on 2022/10/12.
//

#include "Polynomial.h"
#include "iostream"

using namespace std;

NumberLink *Polynomial::initLink() {
    int exponent = 0;
    createHead(exponent);
    initElement(exponent);
    return this->head;
}

void Polynomial::createHead(int &exponent) {
    int inputFactor;
    cout << "输入 x^" << exponent << " 项的系数：";
    cin >> inputFactor;
    while (inputFactor == 0) {
        exponent++;
        cout << "输入 x^" << exponent << " 项的系数：";
        cin >> inputFactor;
    }
    head->addElement(new NumberLink(inputFactor, exponent++));
}

void Polynomial::initElement(int exponent) {
    NumberLink *index = head;
    char input;
    int inputFactor;
    index = index->getNext();
    cout << "输入 x^" << exponent << " 项的系数（输入f表示结束）：";
    cin.get();
    while ((input = cin.get()) != 'f') {
        inputFactor = input - '0';
        while ((input = cin.get()) != '\n')
            inputFactor = inputFactor * 10 + input - '0';

        if (inputFactor != 0) {
            index->addElement(new NumberLink(inputFactor, exponent));
            index = index->getNext();
        }
        exponent++;
        cout << "输入 x^" << exponent << " 项的系数（输入f表示结束）：";

    }
    index->setNext(nullptr);
}

Polynomial Polynomial::operator+(Polynomial &polynomial) {
    NumberLink *index1 = this->head->getNext(), *index2 = polynomial.head->getNext();
    Polynomial result;
    NumberLink *rIndex = result.head;
    while (index1 != nullptr && index2 != nullptr) {
        if (index1->getExponent() < index2->getExponent()) {
            rIndex->addElement(index1);
            index1 = index1->getNext();
            rIndex = rIndex->getNext();
        } else if(index1->getExponent() == index2->getExponent()) {
            rIndex->addElement(new NumberLink(index1->getFactor() + index2->getFactor(), index1->getExponent()));
            index1 = index1->getNext();
            index2 = index2->getNext();
            rIndex = rIndex->getNext();
        } else {
            rIndex->addElement(index2);
            index2 = index2->getNext();
            rIndex = rIndex->getNext();
        }
    }
    if (index1 == nullptr) {
        while (index2 != nullptr) {
            rIndex->addElement(index2);
            rIndex = rIndex->getNext();
            index2 = index2->getNext();
        }
    } else {
        while (index1 != nullptr) {
            rIndex->addElement(index1);
            rIndex = rIndex->getNext();
            index1 = index1->getNext();
        }
    }
    rIndex->setNext(nullptr);
    return result;
}

ostream &operator<<(ostream &os, const Polynomial &polynomial) {
    NumberLink *index = polynomial.head;
    index = index->getNext();
    cout << "f = ";
    while (index->getNext() != nullptr) {
        cout << index->getFactor() << " * x ^ " << index->getExponent() << " + ";
        index = index->getNext();
    }
    cout << index->getFactor() << " * x ^ " << index->getExponent() << endl;
    return os;
}


