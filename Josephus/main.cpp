#include "bits/stdc++.h"

int josephus(int total, int step);

int main() {
    int total, step;
    std::cout << "�����ܹ��ж��ٸ�Ԫ���Լ�ÿ���ƶ��ľ���" << std::endl;
    std::cin >> total >> step;
    std::cout << "����ʣ������Ϊ��" << josephus(total, step);
    return 0;
}

int josephus(int total, int step) {
    if (total == 1) {
        return 0;
    } else {
        return (josephus(total - 1, step) + step) % total;
    }
}
