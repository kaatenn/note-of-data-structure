#include "bits/stdc++.h"
#include "../public/Matrix.h"

Matrix initMatrix(int k);

int main() {
    Matrix matrix1 = initMatrix(1), matrix2 = initMatrix(2);
    Matrix result = matrix1 * matrix2;
    std::cout << "矩阵乘法的结果为：" << std::endl;
    result.showMatrix();
    return 0;
}

Matrix initMatrix(int k) {
    int r, c;
    std::cout << "请输入矩阵" << k << "的行数和列数：" << std::endl;
    std::cin >> r >> c;
    Matrix src(r, c);
    std::cout << "请输入矩阵的元素，用 i j e 的形式表示（在 i 处输入 -1 表示结束）：" << std::endl;
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
