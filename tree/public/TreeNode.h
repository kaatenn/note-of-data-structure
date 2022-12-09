//
// Created by 86137 on 2022/11/24.
//

#ifndef NOTE_OF_DATA_STRUCTURE_TREE_NODE_H
#define NOTE_OF_DATA_STRUCTURE_TREE_NODE_H

#include "bits/stdc++.h"

using namespace std;

class TreeNode {
private:
    char data;
    TreeNode *lChild, *rChild;
public:
    TreeNode();
    void initTree();
    void inorderTraversal();
    void traversalByHierarchy();
};


#endif //NOTE_OF_DATA_STRUCTURE_TREE_NODE_H
