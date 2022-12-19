//
// Created by 86137 on 2022/12/19.
//

#ifndef NOTE_OF_DATA_STRUCTURE_ITREENODE_H
#define NOTE_OF_DATA_STRUCTURE_ITREENODE_H

#include "bits/stdc++.h"

using namespace std;

class ITreeNode {
private:
    int data;
    ITreeNode *lChild, *rChild;
public:
    ITreeNode(int data);
    static void huffmanTree();
};


#endif //NOTE_OF_DATA_STRUCTURE_ITREENODE_H
