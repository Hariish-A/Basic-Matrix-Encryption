#pragma once
/*#ifndef MATRIX_H
#define MATRIX_H*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Matrix 
{
    public:
        vector<vector<double>> m_data;
        int m_rows;
        int m_cols;
        
        /*Constuctors*/
        Matrix() : m_rows(0), m_cols(0) {}      
        Matrix(int, int);                       
        Matrix(const vector<int>&);             
        Matrix(const Matrix&);

        /*Overloaded functions*/
        Matrix& operator=(const Matrix&);
        Matrix operator+(const Matrix&) const;
        Matrix operator-(const Matrix&) const;
        Matrix operator*(const double) const ; 
        Matrix operator*(const Matrix&) const;  
        friend ostream& operator<<(ostream&, const Matrix&);
        friend istream& operator<<(istream&, Matrix&);
        
        /*Special Matrix Operations*/
        Matrix transpose() const;               
        double determinant() const;             
        Matrix inverse() const;

        /*Vector Functions*/
        void setPair(int, int, const vector<int>&);
        vector<int> toVector() const;


};

/*Caesar Functions*/
Matrix createMatrix();
string encrypt(string , int , const Matrix& );
string decrypt(string , int , const Matrix& );
int char_to_num(char);
char num_to_char(int);
void display_menu();
void display_menu2();
void display_main();

/*Inverse Functions*/
string encrypt(string);
string decrypt(string);



//#endif