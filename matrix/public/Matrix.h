//
// Created by 86137 on 2022/11/10.
//

#ifndef NOTE_OF_DATA_STRUCTURE_MATRIX_H
#define NOTE_OF_DATA_STRUCTURE_MATRIX_H
#define MAX_LEN 1024

class Matrix {
private:
    int r, c;
    struct Triple {
        int i = 0, j = 0, e = 0;
    };
    int len;
    Triple e[MAX_LEN]{};
public:
    Matrix(int r, int c);

    Matrix(const Matrix &matrix);

    void addElement(int i, int j, int e);

    void showMatrix();

    void transposed();

    Matrix operator*(Matrix &matrix);

    Matrix& operator=(Matrix &matrix) const;
};


#endif //NOTE_OF_DATA_STRUCTURE_MATRIX_H
