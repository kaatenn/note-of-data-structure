#include "bits/stdc++.h"

#define FINISH -1

void initSet(int pInt[100]);

void sort(int *pInt, int i);

void deleteElement(int *pInt, int k);

void showSet(int *pInt);

void xo(int pInt[100], int pInt1[100], int result[200]);

int main() {
    int set1[100], set2[100], result[200];
    initSet(set1);
    initSet(set2);
    xo(set1, set2, result);
    std::cout << "������Ϊ��" << std::endl;
    showSet(result);
    return 0;
}

void xo(int pInt[100], int pInt1[100], int result[200]) {
    while(*pInt != -1 && *pInt1 != -1) {
        if (*pInt < *pInt1) {
            *(result++) = *(pInt++);
        } else if (*pInt > *pInt1) {
            *(result++) = *(pInt1++);
        } else {
            pInt1++;
            pInt++;
        }
    }
    int *p = *pInt == -1 ? pInt1 : pInt;
    while (*p != -1) {
        *(result++) = *(p++);
    }
    *result = -1;
}

void initSet(int pInt[100]) {
    std::cout << "���뼯�ϵ�Ԫ�أ�����100�������� -1 ����" << std::endl;
    int input;
    int index = 0;
    std::cin >> input;
    while (input != FINISH && index < 100) {
        pInt[index++] = input;
        std::cin >> input;
    }
    pInt[index] = input; //�����һ�� FINISH ���뵽�����б��Ϊĩβ
    sort(pInt, index);//������
    std::cout << "�����������ϵ�Ԫ��Ϊ��" << std::endl;
    showSet(pInt);
}

void showSet(int *pInt) {
    while (*pInt != FINISH) {
        std::cout << *(pInt++) << ' ';
    }
    std::cout << std::endl;
}

void sort(int *pInt, int i) {
    //�����ϵ�Ԫ�ؽ�������
    for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i - j - 1; ++k) {
            if (pInt[k] > pInt[k + 1]) {
                int t = pInt[k];
                pInt[k] = pInt[k + 1];
                pInt[k + 1] = t;
            } else if (pInt[k] == pInt[k + 1]) {
                i--;//���ܳ��ȼ�һ
                deleteElement(pInt, k);
                k--;//�Ӹ�λ���ٴο�ʼѭ��
            }
        }
    }
}

void deleteElement(int *pInt, int k) {
    //������Ԫ����ǰһλ����
    while (pInt[k] != FINISH) {
        pInt[k] = pInt[k + 1];
        k++;
    }
}
