//
// Created by 86137 on 2022/11/24.
//
#include "public/TreeNode.h"

int main() {
    srand(time(0));
    TreeNode* head = new TreeNode();
    head->initTree();
    head->inorderTraversal();
    cout << endl;
    head->traversalByHierarchy();
    return 0;
}