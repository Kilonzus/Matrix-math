/* -----------------------------------------------------------------------------

FILE NAME:         Matrix.cpp
DESCRIPTION:       This is the implementation file for the Matrix class
USAGE:             This program is linkked to the driver via a .o file
COMPILER:          g++ compiler c++11 standard
NOTES:             both Matrix and Matrix_ops specifications are included here Matrix_ops is at the bottom

MODIFICATION HISTORY:

Author             Date           Modification(s)
----------------   -----------    ---------------
Peter Kilonzo      2018-05-15     Version 1
---------------------------------------------------------------------------- */
#include "Matrix.h"

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix()
PURPOSE:           default constructor
RETURNS:           Nothing 
NOTES:             This is the default constructor that sets al the private members to 0
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>::Matrix()
{
	rows = 0;
	cols = 0; 

	array = NULL;


}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix(int n_rows, int n_cols)
PURPOSE:           overloaded constructor
RETURNS:           Nothing 
NOTES:             This is the overloaded constructor that sets the values of the matrix to any parameters passed to it.
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new T*[rows];

	for (int i = 0; i < rows; ++i) {
	    array[i] = new T[cols];
		for (int j = 0; j < cols; ++j) {
			array[i][j] = 0;
		}
	}

//	cout << "Matrix Constructor: ";
//	cout << rows << " X " << cols << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix(const Matrix<T> &)
PURPOSE:           Copy constructor
RETURNS:           Nothing 
NOTES:             This is the copy constructor that sets the values of the matrix to the values of the matrix passed to it passed to it.
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>::Matrix(const Matrix<T> & ml)
{
	rows = ml.rows;
	cols = ml.cols;

	array = new T * [rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T [cols];
		for (int j = 0; j < cols; j++)
		{
		    array[i][j] = ml.array[i][j];
			
		}
//	cout << endl;
	}

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     ~Matrix();
PURPOSE:           This is the destructor for the Matrix which deallocated all the memory for the object.
RETURNS:           Nothing
NOTES:             usages is *matrix*.~Matrix()
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete []array;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     ostream& operator << (ostream &strm, const Matrix<R> &))
PURPOSE:           this is the outstream operator overloading to make displaying of the matrix easy and readable
RETURNS:           strm
NOTES:             usage for oustream is now 'cout << *matrix*'
----------------------------------------------------------------------------- */
template <class R>
ostream& operator << (ostream &strm, const Matrix<R> &m)
{
	strm << setw(4) << m.rows << " X " << m.cols << endl;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			strm << setw(4) << m.array[i][j];
		}
		strm << endl;
	}
	strm << endl;
	return strm;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     istream& operator >> (istream &istrm, Matrix<R> &))
PURPOSE:           this is the instream operator overloading to make input of a matrix easier.
RETURNS:           istrm
NOTES:             usage for instream is now 'cin >>'
----------------------------------------------------------------------------- */
template <class T>
istream &operator >> (istream & istrm, Matrix<T> &ai)
{
    char let_x;
    int m, n;

    istrm >> m >> let_x >> n;
    Matrix<T> nlp(m, n);
    
    for (int i = 0; i < m; i++)
    {
	for (int j = 0; j < n; j ++)
	    {
		istrm >> nlp.array[i][j];
	    }
    }
	ai = nlp; 
	return istrm;
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix<T> operator = (const Matrix<T> &)
PURPOSE:           This fuction sets a matrix equal to another, similar to a copy constructor
RETURNS:           
NOTES:             Add two Matrices with '+'
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &cv)
{
    for (int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}

	delete [] array; //memory for former matrix must be deallocated

	rows = cv.rows;
	cols = cv.cols;

	array = new T *[rows]; //rellocated correct amount of memory


	for (int i = 0; i < rows; i++)
	{
		array[i] = new T [cols];
		for (int j = 0; j < cols; j++)
		{
		    array[i][j] = cv.array[i][j];
			
		}
//	cout << endl;
	}
	
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix_ops<T> operator + (const Matrix_ops<T> &)
PURPOSE:           This functions adds two matrices with the same dimensions together
RETURNS:           
NOTES:             Add two Matrices with '+'
----------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> &da) {

	Matrix_ops<T> m1;

	if(rows != da.rows || cols != da.cols) {
		cout << "These matrix do not share dimensions therefore additions is impossible\n";
		//return 0;
	}else {

	

		m1.rows = rows;
		m1.cols = cols;

		m1.array = new T *[rows];
	
		for (int i = 0; i < m1.rows; i++)
		{
			m1.array[i] = new T [cols];
			for (int j = 0; j < m1.cols; j++)
			{
			    m1.array[i][j] = array[i][j] + da.array[i][j];
			
			}
//	cout << endl;
		}
		return m1;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix_ops<T> operator - (const Matrix_ops<T> &)
PURPOSE:           This functions subtracts two Matrcies from each other
RETURNS:           
NOTES:             Subtract two Matrices with '-'
----------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T> &nacho) {
	
	Matrix_ops<T> m2;

	if(rows != nacho.rows || cols != nacho.cols) {
		cout << "These matrix do not share dimensions therefore subtraction is impossible\n";
		//return 0;
	}else {
	

		m2.rows = rows;
		m2.cols = cols;

		m2.array = new T *[rows];
	
		for (int i = 0; i < m2.rows; i++)
		{
			m2.array[i] = new T [cols];
			for (int j = 0; j < m2.cols; j++)
			{
			    m2.array[i][j] = array[i][j] - nacho.array[i][j];
			
			}
//	cout << endl;
		}
		return m2;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix_ops<T> operator * (const Matrix_ops<T> &)
PURPOSE:           This functions subtracts two Matrcies from each other
RETURNS:           
NOTES:             Subtract two Matrices with '-'
----------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator * (const Matrix_ops<T> &fdt) {

	Matrix_ops<T> m3;
	int weird = 0;


	if(cols != fdt.rows) {
		cout << "These matrix do not share dimensions therefore multiplication is impossible\n";
		//return 0;
	}else {
		m3.rows = rows;
		m3.cols = fdt.rows;

		m3.array = new T*[rows];

		for(int i = 0; i < rows; ++i)
		{	
			m3.array[i] = new T [fdt.cols];
			for(int j = 0; j < fdt.cols; j++)
			{
				m3.array[i][j] = 0;
				for(int k = 0; k < cols; ++k)
				{
					m3.array[i][j] += array[i][k] * fdt.array[k][j];
					weird++;
				}
			}
		}
	}
	cout << weird << "\n";
	
	return m3;	
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     bool operator == (const Matrix_ops<T> &) const
PURPOSE:           This functions adds two matrices with the same dimensions together
RETURNS:           
NOTES:             Compare two Matrices with '=='
----------------------------------------------------------------------------- */
template <class T>
bool Matrix_ops<T>::operator == (const Matrix_ops<T> &da) const{

	bool tru;

	if(rows != da.rows || cols != da.cols) {
		cout << "These matrix do not share dimensions\n";
		return false;
	}

		for (int i = 0; i < rows; i++)
		{

			for (int j = 0; j < cols; j++)
			{
				if (array[i][j] != da.array[i][j]) return false;
			
			}
//	cout << endl;
		}
		return true;
	
}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     Matrix_ops<T> transpose()
PURPOSE:           This functions is supposed to transpose a matrix
RETURNS:           
NOTES:             The usage is *matrix*.transpose() i.e. Matrix1 = Matrix1.transpose
----------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T>::transpose() {

	Matrix_ops<T> trans;
	trans.rows = cols;
	trans.cols = rows;

	trans.array = new T*[cols];

	for (int i = 0; i < cols; i++)
	{
		trans.array[i] = new T[rows];
		for (int j = 0; j < rows; j++)
		{
			trans.array[i][j] = array[j][i];
		}
//	cout << endl;
	}
	return trans;
}




