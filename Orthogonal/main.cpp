//
// Created by 86137 on 2022/11/17.
//

#include "OrthogonalList.h"

int main() {
    int row, column;
    cout << "请输入行数和列数：";
    cin >> row >> column;
    OrthogonalList orthogonalList1(row, column);
    orthogonalList1.initList();
    orthogonalList1.showList();
    OrthogonalList orthogonalList2(row, column);
    orthogonalList2.initList();
    orthogonalList2.showList();
    orthogonalList1 += orthogonalList2;
    cout << "两个矩阵相加结果为：" << endl;
    orthogonalList1.showList();
    return 0;
}