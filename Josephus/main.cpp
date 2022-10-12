#include "bits/stdc++.h"

int josephus(int total, int step);

int main() {
    int total, step;
    std::cout << "输入总共有多少个元素以及每次移动的距离" << std::endl;
    std::cin >> total >> step;
    std::cout << "最终剩余的序号为：" << josephus(total, step);
    return 0;
}

int josephus(int total, int step) {
    if (total == 1) {
        return 0;
    } else {
        return (josephus(total - 1, step) + step) % total;
    }
}
