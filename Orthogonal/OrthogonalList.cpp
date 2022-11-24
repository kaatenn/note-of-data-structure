//
// Created by 86137 on 2022/11/17.
//

#include "OrthogonalList.h"

void createNode(int x, int y, int e, OLNode *olNode) {
    olNode->i = x;
    olNode->j = y;
    olNode->e = e;
}

OrthogonalList::OrthogonalList(int row, int column) {
    this->row = row;
    this->column = column;
    total = 0;
    rHead = new OLink[row];
    for (int i = 0; i < row; i++) {
        rHead[i] = nullptr;
    }
    cHead = new OLink[column];
    for (int i = 0; i < column; i++) {
        cHead[i] = nullptr;
    }
}

void OrthogonalList::initList() {
    cout << "请输入元素的信息（输入形式为 x y e，在 x 处输入 -1 表示结束输入）：" << endl;
    int x, y, e;
    cin >> x;
    while (x != -1) {
        x--;
        auto *olNode = new OLNode;
        cin >> y >> e;
        y--;
        createNode(x, y, e, olNode);

        //确定该元素在第 x 行的位置
        if (rHead[x] == nullptr || rHead[x]->j > y) {
            OLNode *temp = rHead[x];
            rHead[x] = olNode;
            olNode->right = temp;
        } else {
            OLNode *i = rHead[x];
            OLNode *pre = nullptr;
            while (i && i->j < y) {
                pre = i;
                i = i->right;
            }
            pre->right = olNode;
            olNode->right = i;
        }

        //确定该元素在第 y 列的位置
        if (cHead[y] == nullptr || cHead[y]->i > x) {
            OLNode *temp = cHead[y];
            cHead[y] = olNode;
            olNode->down = temp;
        } else {
            OLNode *i = cHead[y];
            OLNode *pre = nullptr;
            while (i && i->i < x) {
                pre = i;
                i = i->down;
            }
            pre->down = olNode;
            olNode->down = i;
        }
        total++;
        cin >> x;
    }
}

void OrthogonalList::showList() {
    cout << setw(3) << 'x' << setw(3) << 'y' << setw(3) << 'e' << endl;
    for (int i = 0; i < row; i++) {
        OLNode *node = rHead[i];
        while (node) {
            cout << setw(3) << node->i + 1 << setw(3) << node->j + 1 << setw(3) << node->e << endl;
            node = node->right;
        }
    }
}

void OrthogonalList::operator+=(OrthogonalList &orthogonalList) {
    for(int i = 0; i < row; i++) {
        OLNode* element1 = rHead[i], *element2 = orthogonalList.rHead[i];
        OLNode* pre = nullptr;
        while (element1 && element2) {
            if (element1->j == element2->j) {
                element1->e += element2->e;
                pre = element1;
                element1 = element1->right;
                element2 = element2->right;
            } else if (element1->j > element2->j) {
                if (!pre) {
                    rHead[i] = element2;
                    element2 = element2->right;
                    rHead[i]->right = element1;
                    pre = rHead[i];
                } else {
                    pre->right = element2;
                    element2 = element2->right;
                    pre->right->right = element1;
                    pre = pre->right;
                }
                OLNode* ec = cHead[pre->j];
                OLNode* ePre = nullptr;
                while (ec && ec->i < i) {
                    ePre = ec;
                    ec = ec->down;
                }
                if(ePre == nullptr) {
                    cHead[pre->j] = element2;
                    pre->down = ec;
                } else {
                    ePre->down = element2;
                    pre->down = ec;
                }
            } else {
                pre = element1;
                element1 = element1->right;
            }
        }
        if (!element1)
            pre->right = element2;
    }
}
