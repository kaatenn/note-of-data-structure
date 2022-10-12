//
// Created by 86137 on 2022/10/12.
//

#ifndef NOTE_OF_DATA_STRUCTURE_NUMBERLINK_H
#define NOTE_OF_DATA_STRUCTURE_NUMBERLINK_H


class NumberLink {
private:
    int factor, exponent;
    NumberLink *next;
public:
    NumberLink() = default;

    NumberLink(int factor, int exponent);

    void addElement(NumberLink *element);

    void initOver() {
        next = nullptr;
    }

    NumberLink *getNext() {
        return next;
    }

    int getFactor() const {
        return factor;
    }

    int getExponent() const {
        return exponent;
    }

    void setFactor(int newFactor) {
        factor = newFactor;
    }

    void setNext(NumberLink* newNext) {
        next = newNext;
    }
};


#endif //NOTE_OF_DATA_STRUCTURE_NUMBERLINK_H
