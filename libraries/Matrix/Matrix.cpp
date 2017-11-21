#include "Arduino.h"
#include "Matrix.h"

Matrix::Matrix(int * rowPins, int * colPins, int nRows, int nCols)
: m_nRows(nRows)
, m_nCols(nCols)
{
    m_rowPins = new int[m_nRows];
    m_colPins = new int[m_nCols];
    m_state = new int*[m_nRows];
    m_prevState = new int*[m_nRows];
    for(int i = 0; i < m_nRows; i++)
    {
        m_rowPins[i] = rowPins[i];
        m_state[i] = new int[m_nCols];
        m_prevState[i] = new int[m_nCols];
    }
    for(int i = 0; i < m_nCols; i++)
    {

        m_colPins[i] = colPins[i];
    }
}

void
Matrix::setup()
{
    for(int i = 0; i < m_nRows; i++)
    {
        pinMode(m_rowPins[i], OUTPUT);
    }
    for(int i = 0; i < m_nCols; i++)
    {
        pinMode(m_colPins[i], OUTPUT);
    }
    clear();
}

void
Matrix::on(int row, int col)
{
    digitalWrite(m_rowPins[row], HIGH);
    digitalWrite(m_colPins[col], LOW);
}


void
Matrix::off(int row, int col)
{
    digitalWrite(m_rowPins[row], LOW);
    digitalWrite(m_colPins[col], HIGH);
}

void
Matrix::onCol(int col)
{
    digitalWrite(m_colPins[col], LOW);
}


void
Matrix::onRow(int row)
{
    digitalWrite(m_rowPins[row], HIGH);
}

void
Matrix::offCol(int col)
{
    digitalWrite(m_colPins[col], HIGH);
}


void
Matrix::offRow(int row)
{
    digitalWrite(m_rowPins[row], LOW);
}

void
Matrix::set(int row, int col, int val)
{
    m_state[row][col] = val;
}

void
Matrix::set(int n, int val)
{
    m_state[n/m_nCols][n%m_nCols] = val;
}

// void
// Matrix::clear(int row, int col)
// {
//     m_state[row][col] = 0;
// }

// void
// Matrix::clear(int n)
// {
//      m_state[n/m_nRows][n%m_nCols] = 0;
// }

void
Matrix::update()
{
    for(int i = 0; i < m_nRows; i++)
    {
       onRow(i);
       for(int j = 0; j < m_nCols; j++)
       {
            if(m_state[i][j])
            {
                onCol(j);
            }
       }
       delay(0.1);
       offRow(i);
       for(int j = 0; j < m_nCols; j++)
       {
            offCol(j);
       }
    }
}

void
Matrix::clear()
{
    for(int i = 0; i < m_nRows; i++)
    {
        for(int j = 0; j < m_nCols; j++)
        {
            m_state[i][j] = 0;
        }
    }
}
