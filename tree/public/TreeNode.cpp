//
// Created by 86137 on 2022/11/24.
//

#include "TreeNode.h"

TreeNode::TreeNode() {
    lChild = nullptr;
    rChild = nullptr;
    data = (rand() % 26) + 65;;
}

void TreeNode::initTree() {
    int flag = rand() % 2;
    if (flag == 0)
        return;
    lChild = new TreeNode();
    lChild->initTree();
    rChild = new TreeNode;
    rChild->initTree();
}

void TreeNode::inorderTraversal() {
    auto f = [](TreeNode* p) -> bool {
        if (!p) {
            return false;
        }
        cout << p->data;
        return true;
    };
    stack<TreeNode*> stack;
    TreeNode* p = this;
    while (p || !stack.empty()) {
        if (p) {
            stack.push(p);
            p = p->lChild;
        } else {
            p = stack.top();
            stack.pop();
            if (!f(p)) {
                exit(EXIT_FAILURE);
            } else {
                p = p->rChild;
            }
        }
    }
}

void TreeNode::traversalByHierarchy() {
    auto f = [](TreeNode *p) -> bool {
        if (!p) {
            return false;
        }
        cout << p->data;
        return true;
    };
    queue<TreeNode*> queue;
    TreeNode* p = this;
    queue.push(p);
    while (!queue.empty()) {
        p = queue.front();
        if (p->lChild)
            queue.push(p->lChild);
        if (p->rChild)
            queue.push(p->rChild);
        if (!f(p)) {
            exit(EXIT_FAILURE);
        }
        queue.pop();
    }
}

