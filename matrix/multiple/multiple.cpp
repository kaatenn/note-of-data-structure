#include "bits/stdc++.h"
#include "../public/Matrix.h"

Matrix initMatrix(int k);

int main() {
    Matrix matrix1 = initMatrix(1), matrix2 = initMatrix(2);
    Matrix result = matrix1 * matrix2;
    std::cout << "����˷��Ľ��Ϊ��" << std::endl;
    result.showMatrix();
    return 0;
}

Matrix initMatrix(int k) {
    int r, c;
    std::cout << "���������" << k << "��������������" << std::endl;
    std::cin >> r >> c;
    Matrix src(r, c);
    std::cout << "����������Ԫ�أ��� i j e ����ʽ��ʾ���� i ������ -1 ��ʾ��������" << std::endl;
    while(true) {
        int i, j, e;
        std::cin >> i;
        if(i == -1)
            break;
        std::cin >> j >> e;
        src.addElement(i - 1, j - 1, e);
    }
    return src;
}
