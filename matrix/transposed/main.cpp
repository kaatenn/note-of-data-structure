#include "bits/stdc++.h"
#include "../public/Matrix.h"

int main() {
    int r, c;
    std::cout << "请输入矩阵的行数和列数：" << std::endl;
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
    src.transposed();
    std::cout << "转置后的结果为：\n";
    src.showMatrix();
    return 0;
}