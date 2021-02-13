//
//  Matrix.h
//  Matrix
//
//  Created by Louie Li on 2/12/21.
//

#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <iostream>

using namespace std;

template<class T> class Matrix;

template<class T>
std::ostream& operator<< (std::ostream& os, const Matrix<T>& m);

template<class T>
class Matrix {
    friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& m);
public:
    // default gives a 3x3 identity matrix
    Matrix();
    Matrix(unsigned int r, unsigned int c);
    Matrix(const vector<vector<T>>& m);
    ~Matrix();
    //given row and col, initialize an all-zero matrix
    void setMatrix(int row_n, int col_n);
    // fill the matrix with a 2D vector
    void setMatrix(const vector< vector<T> > &m);
    // fill the matrix with another matrix
    Matrix<T> setMatrix(const Matrix<T> &m);
    Matrix<T> operator= (const Matrix<T> &m);
    void printMatrix();
    Matrix<T> add(const Matrix<T> &m);
    Matrix<T> multiply(const Matrix<T>& m);
    T at(size_t i, size_t j);
    vector<T>& operator[] (unsigned int index);
    vector<T> operator[] (unsigned int index) const;
    Matrix<T> operator* (const Matrix<T> &m);
    Matrix<T> operator+ (const Matrix<T> &m);
private:
    size_t row_n, col_n;
    // vectors are vertical. see them as columns.
    vector< vector<T> > m_matrix;
    void _init_();
};

template<class T>   // there is no need to add endl after using this operation.
inline std::ostream& operator<< (std::ostream& os, const Matrix<T>& m)
{
    cout << "\nrow_n: " << m.row_n << " col_n: " << m.col_n << endl;
    for (size_t i = 0; i < m.row_n; ++i)
    {
        for (size_t j = 0; j < m.col_n; ++j)
        {
            os << m[j][i] << ' ';
        }
        os << endl;
    }
    return os;
}


template<class T>
Matrix<T>::Matrix()
{
    _init_();
}

template<class T>
Matrix<T>::Matrix(unsigned int r, unsigned int c)
{
    setMatrix(r, c);
}

template<class T>
Matrix<T>::Matrix(const vector<vector<T>>& m)
{
    setMatrix(m);
}


template<class T>
void Matrix<T>::_init_()
{
    row_n = col_n = 3;
    m_matrix.push_back(vector<T>(3, 0));
    m_matrix.push_back(vector<T>(3, 0));
    m_matrix.push_back(vector<T>(3, 0));
    m_matrix[0][0] = m_matrix[1][1] = m_matrix[2][2] = 1;
}

template<class T>
Matrix<T>::~Matrix()
{
    for (auto v: m_matrix)
    {
        v.clear();
    }
    m_matrix.clear();
}

template<class T>
void Matrix<T>::printMatrix()
{
    cout << endl;
    for (size_t i = 0; i < row_n; ++i)
    {
        for (size_t j = 0; j < col_n; ++j)
        {
            cout << m_matrix[j][i] << ' ';
        }
        cout << endl;
    }
}

template<class T>
void Matrix<T>::setMatrix(int r, int c)
{
    row_n = r;
    col_n = c;
    for (size_t i = 0; i < col_n; ++i)
    {
        m_matrix.push_back(vector<T>(row_n, 0));
    }
}

// be careful for different matrix types, will cause ending the program.
template<class T>
void Matrix<T>::setMatrix(const vector< vector<T> > &m)
{
    col_n = m.size();
    row_n = m[0].size();
    m_matrix = m;
}

template<class T>
Matrix<T> Matrix<T>::setMatrix(const Matrix<T>& m)
{
    return *this = m;
}

template<class T>
inline Matrix<T> Matrix<T>::add(const Matrix<T>& m)
{
    return (*this + m);
}

template<class T>
inline Matrix<T> Matrix<T>::multiply(const Matrix<T>& m)
{
    return (*this * m);
}

template<class T>
inline vector<T> Matrix<T>::operator[](unsigned int index) const
{
    return m_matrix[index];
}

template<class T>
inline vector<T>& Matrix<T>::operator[](unsigned int index)
{
    return m_matrix[index];
}

template<class T>
Matrix<T> Matrix<T>::operator= (const Matrix<T>& m)
{
    if (this == &m)
    {
        return *this;
    }
    col_n = m.col_n;
    row_n = m.row_n;
    m_matrix = m.m_matrix;
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& mtx)
{
    if (col_n != mtx.row_n)
    {
        cerr << "not a valid operation!" << endl;
        return Matrix();
    }
    Matrix<T> result = Matrix<T>(row_n, mtx.col_n);
    for (size_t o = 0; o < mtx.col_n; ++o)
    {
        T tmp = T();
        for (size_t m = 0; m < row_n; ++m)
        {
            for (size_t n = 0; n < col_n; ++n)
            {
                tmp += m_matrix[n][m]*mtx[o][n];
            }
            result[o][m] = tmp;
            tmp = T();
        }
    }
    return result;
}

template<class T>
inline Matrix<T> Matrix<T>::operator+ (const Matrix<T> &m) 
{
    if (m.row_n != row_n || m.col_n != col_n)
    {
        std::cerr << "not a valid operation!" << endl;
        return Matrix();
    }
    Matrix<T> result = Matrix<T>(row_n, col_n);
    for (size_t i = 0; i < row_n; ++i)
    {
        for (size_t j = 0; j < col_n; ++j)
        {
            result[j][i] = m_matrix[j][i] + m[j][i];
            // cout << result[j][i] << endl;
        }
    }
    return result;
}

template<class T>
inline T Matrix<T>::at(size_t i, size_t j)
{
    return m_matrix[j][i];
}

#endif Matrix_h
