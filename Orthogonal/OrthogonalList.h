//
// Created by 86137 on 2022/11/17.
//

#ifndef NOTE_OF_DATA_STRUCTURE_ORTHOGONAL_LIST_H
#define NOTE_OF_DATA_STRUCTURE_ORTHOGONAL_LIST_H

#include "bits/stdc++.h"

using namespace std;

struct OLNode {
    int i = 0, j = 0;
    int e = 0;
    struct OLNode *right, *down;
};

typedef OLNode *OLink;

class OrthogonalList {
private:
    OLink *rHead, *cHead;
    int row, column, total;
public:
    OrthogonalList(int row, int column);

    void initList();

    void showList();

    void operator+=(OrthogonalList &orthogonalList);
};


#endif //NOTE_OF_DATA_STRUCTURE_ORTHOGONAL_LIST_H
