/* -----------------------------------------------------------------------------

FILE NAME:         Matrix.h
DESCRIPTION:       This is the specification file for the Matrix class
USAGE:             This program is linkked to the driver via a .o file
COMPILER:          g++ compiler c++11 standard
NOTES:             both Matrix and Matrix_ops specifications are included here

MODIFICATION HISTORY:

Author             Date           Modification(s)
----------------   -----------    ---------------
Peter Kilonzo      2018-05-15     Version 1
---------------------------------------------------------------------------- */
#ifndef MATRIX_H
#define MATRIX_H


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

template <class T>
class Matrix {

    protected:
		int rows;
		int cols;
		T **array;


    public:
		Matrix();                       // Overloaded Constructor
		Matrix(const Matrix<T> &);           // Copy Test
		Matrix(int rows, int cols);     // Accessor
		~Matrix();                      // Destructor
		Matrix<T>& operator = (const Matrix<T> &);


	template <class R>
	friend ostream& operator << (ostream &strm, const Matrix<R> &);
	template <class R>
	friend istream& operator >> (istream &istrm, Matrix<R> &);
	

};


template <class T>
class Matrix_ops : public Matrix<T> {
	using Matrix<T>::rows;
	using Matrix<T>::cols;
	using Matrix<T>::array;

	public:

		Matrix_ops<T> operator + (const Matrix_ops<T> &);
		Matrix_ops<T> operator - (const Matrix_ops<T> &);
		Matrix_ops<T> operator * (const Matrix_ops<T> &);
		bool operator == (const Matrix_ops<T> &) const;
		Matrix_ops<T> transpose();
		//Matrix_ops<T> inverse();
		//Matriix_ops<T> eigenvalues();




};

#endif
