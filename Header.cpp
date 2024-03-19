#include "Header.h"

Matrix :: Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
    m_data.resize(rows);
    for (int i = 0; i < rows; ++i) 
    {
        m_data[i].resize(cols);
    }
}

Matrix :: Matrix(const vector<int>& pair) : m_rows(1), m_cols(2)
{
    m_data.resize(m_rows);
    m_data[0].resize(m_cols);
    for (int i = 0; i < m_cols; ++i) 
    {
        m_data[0][i] = static_cast<double>(pair[i]);
    }
}

Matrix :: Matrix(const Matrix& other)
{
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_data = other.m_data;
}
    
Matrix& Matrix::operator=(const Matrix& other)
{
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_data = other.m_data;
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
 {
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        throw runtime_error("Matrix dimensions do not match.");
    }

    Matrix result(m_rows, m_cols);

    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        throw runtime_error("Matrix dimensions do not match.");
    }

    Matrix result(m_rows, m_cols);

    for (int i = 0; i < m_rows; ++i) 
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
        }
    }

    return result;
}

Matrix Matrix ::operator*(const double scalar) const
{
    Matrix result(m_rows, m_cols);

    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.m_data[i][j] = scalar * m_data[i][j];
        }
    }

    return result;
}

Matrix Matrix ::operator*(const Matrix& other) const
{
    if (m_cols != other.m_rows) 
    {
        throw runtime_error("Matrix dimensions do not match.");
    }

    Matrix result(m_rows, other.m_cols);

    for (int i = 0; i < m_rows; ++i) 
    {
        for (int j = 0; j < other.m_cols; ++j)
        {
            double sum = 0;
            for (int k = 0; k < m_cols; ++k) 
            {
                sum += m_data[i][k] * other.m_data[k][j];
            }
            result.m_data[i][j] = sum;
        }
    }

    return result;
}

Matrix Matrix::transpose() const 
{
    Matrix result(m_cols, m_rows);

    for (int i = 0; i < m_rows; ++i) 
    {
        for (int j = 0; j < m_cols; ++j) 
        {
            result.m_data[j][i] = m_data[i][j];
        }
    }

    return result;
}

double Matrix::determinant() const
{
    if (m_rows != m_cols) 
    {
        throw runtime_error("Matrix is not square.");
    }
    if (m_rows == 1) 
    {
        return m_data[0][0];
    }

    double det = 0;

    for (int i = 0; i < m_cols; ++i)
    {
        Matrix submatrix(m_rows - 1, m_cols - 1);

        for (int j = 1; j < m_rows; ++j)
        {
            int k = 0;
            for (int l = 0; l < m_cols; ++l) 
            {
                if (l != i) 
                {
                    submatrix.m_data[j - 1][k++] = m_data[j][l];
                }
            }
        }

        double subdet = submatrix.determinant();

        if (i % 2 == 0) 
        {
            det += m_data[0][i] * subdet;
        } 
        else 
        {
            det -= m_data[0][i] * subdet;
        }
    }
    return det;
}

Matrix Matrix ::inverse() const 
{
    if (m_rows != m_cols) 
    {
        throw runtime_error("Matrix is not square.");
    }

    double det = determinant();

    if (det == 0) 
    {
        throw runtime_error("Matrix is not invertible.");
    }

    Matrix result(m_rows, m_cols);

    for (int i = 0; i < m_rows; ++i) 
    {
        for (int j = 0; j < m_cols; ++j)
        {
            Matrix submatrix(m_rows - 1, m_cols - 1);

            int p = 0;
            for (int k = 0; k < m_rows; ++k) 
            {
                if (k == i) 
                {
                    continue;
                }

                int q = 0;
                for (int l = 0; l < m_cols; ++l) 
                {
                    if (l == j) 
                    {
                        continue;
                    }

                    submatrix.m_data[p][q++] = m_data[k][l];
                }

                ++p;
            }

            double subdet = submatrix.determinant();

            if ((i + j) % 2 == 0) 
            {
                result.m_data[i][j] = subdet / det;
            } 
            else 
            {
                result.m_data[i][j] = -subdet / det;
            }
        }
    }

    return result.transpose();
}

istream& operator>>(istream& is, Matrix& matrix) 
{
    cout << "Enter the number of rows: ";
    is >> matrix.m_rows;
    cout << "Enter the number of columns: ";
    is >> matrix.m_cols;
    matrix.m_data.resize(matrix.m_rows);
    for (int i = 0; i < matrix.m_rows; i++)
    {
        matrix.m_data[i].resize(matrix.m_cols);
        for (int j = 0; j < matrix.m_cols; j++)
        {
            cout << "Enter element (" << i << ", " << j << "): ";
            is >> matrix.m_data[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& matrix) 
{
    for (int i = 0; i < matrix.m_rows; ++i) 
    {
        for (int j = 0; j < matrix.m_cols; ++j) 
        {
            os << matrix.m_data[i][j] << " ";
        }
        os << endl;
    }

    return os;
}

vector<int> Matrix::toVector() const
{
    std::vector<int> result;
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.push_back(m_data[i][j]);
        }
    }
    return result;
}
void Matrix::setPair(int row, int col, const vector<int>& pair)
{
    m_data[row][col] = pair[0];
    m_data[row][col + 1] = pair[1];
}

