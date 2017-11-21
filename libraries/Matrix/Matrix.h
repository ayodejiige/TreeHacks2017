#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix(int * rowPins, int *colPins, int nRows, int nCols);
    void setup();
    void setRow(int row);
    void setCol(int col);
    void on(int row, int col);
    void off(int row, int col);
    void set(int n, int val);
    void set(int row, int col, int val);
    void clear(int n);
    void clear(int row, int col);
    void clear();
    void update();

private:
    int * m_rowPins;
    int * m_colPins;
    int ** m_state;
    int ** m_prevState;
    int m_nRows;
    int m_nCols;

    void onCol(int col);
    void onRow(int row);
    void offCol(int col);
    void offRow(int row);
};
#endif
