#include "Matrix.h"
#include "iostream"

Matrix::Matrix(int r, int c) : r(r), c(c) {
    len = 0;
}

/**
 * 数组初始化
 * @param array 待初始化数组
 * @param len 数组长度
 */
void initArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        *array = 0;
        array++;
    }
}

/**
 * 添加一个元素到矩阵中
 * @param i 添加的行号
 * @param j 添加的列号
 * @param element 元素值
 */
void Matrix::addElement(int i, int j, int element) {
    int k = 0;
    while (e[k].i < i && k < len)
        k++;
    int l = len;

    while (l > k) {
        e[l] = e[l - 1];
        l--;
    }

    e[l].i = i;
    e[l].j = j;
    e[l].e = element;
    len++;
}

/**
 * 打印矩阵
 */
void Matrix::showMatrix() {
    int index = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (e[index].i == i && e[index].j == j && index < len) {
                std::cout << e[index].e << " ";
                index++;
            } else {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * 矩阵转置
 */
void Matrix::transposed() {
    int ri[c];
    Triple t[len];
    initArray(ri, c);
    for (int i = 0; i < len; i++) {
        ri[e[i].j + 1]++;
    }

    for (int i = 0; i < len - 1; i++) {
        ri[i + 1] += ri[i];
    }

    for (int i = 0; i < len; i++) {
        t[ri[e[i].j]].i = e[i].j;
        t[ri[e[i].j]].j = e[i].i;
        t[ri[e[i].j]].e = e[i].e;
        ri[e[i].j]++;
    }

    for (int i = 0; i < len; i++) {
        e[i] = t[i];
    }
    int temp = r;
    r = c;
    c = temp;
}

Matrix Matrix::operator*(Matrix &matrix) {
    Matrix result(r, matrix.c);
    int ri[matrix.r];
    initArray(ri, matrix.r);
    for (int i = 0; i < matrix.len; i++) {
        ri[matrix.e[i].i + 1]++;
    }
    for (int i = 0; i < matrix.r - 1; ++i) {
        ri[i + 1] += ri[i];
    }
    int sumR[c], index = 0;
    initArray(sumR, c);
    for (int i = 0; i < len; ++i) {
        for (int j = ri[e[i].j]; j < (e[i].j + 1 == c ? ri[e[i].j + 1] : len); ++j) {
            if (e[i].j == matrix.e[j].i)
                sumR[matrix.e[j].j] += e[i].e * matrix.e[j].e;
        }
        if (i == len || e[i].i != e[i + 1].i) {
            for (int j = 0; j < c; ++j) {
                if (sumR[j] != 0) {
                    result.e[index].i = e[i].i;
                    result.e[index].j = j;
                    result.e[index].e = sumR[j];
                    index++;
                    result.len++;
                }
            }
            initArray(sumR, c);
        }
    }
    return result;
}

Matrix::Matrix(const Matrix &matrix) {
    r = matrix.r;
    c = matrix.c;
    len = matrix.len;
    for (int i = 0; i < len; ++i) {
        e[i] = matrix.e[i];
    }
}

