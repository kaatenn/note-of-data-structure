//
// Created by 86137 on 2022/11/17.
//

#include "OrthogonalList.h"

int main() {
    int row, column;
    cout << "������������������";
    cin >> row >> column;
    OrthogonalList orthogonalList1(row, column);
    orthogonalList1.initList();
    orthogonalList1.showList();
    OrthogonalList orthogonalList2(row, column);
    orthogonalList2.initList();
    orthogonalList2.showList();
    orthogonalList1 += orthogonalList2;
    cout << "����������ӽ��Ϊ��" << endl;
    orthogonalList1.showList();
    return 0;
}