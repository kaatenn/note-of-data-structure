#include "bits/stdc++.h"
#include "../public/Matrix.h"

int main() {
    int r, c;
    std::cout << "����������������������" << std::endl;
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
    src.transposed();
    std::cout << "ת�ú�Ľ��Ϊ��\n";
    src.showMatrix();
    return 0;
}