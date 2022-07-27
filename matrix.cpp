#include"Matrix.h"
#include<iostream>

#define _SIGN_ 99999
const char _ERROR_RANGE_[]{ "THE INDEX OUT OF RANGE!" };
const char _ERROR_ASSIGN_[]{ "ASSIGN INVALID!" };
const char _SIZE_NMATCH[]{ "WRONG SIZE" };
const char _N_SQUARE_[]{ "NOT A SQUARE MATRIX" };

template<typename T,size_t r,size_t c>
bool Matrix<T, r, c>::_assign_check()const
{
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			if (*(*(Data + i) + j) == _SIGN_)
			{
				return 0;
			}
		}
	}
	return 1;
}




template<typename T, size_t r, size_t c>
void Matrix<T, r, c>::_initial_()
{
	Data = new T * [r];
	
	for (size_t i = 0; i < r; i++)
		*(Data + i) = new T[c];
}

template<typename T, size_t r, size_t c>
Matrix<T, r, c>::Matrix()
{
	_initial_();
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			*(*(Data + i) + j)=_SIGN_;
		}
	}
}


template<typename T, size_t r, size_t c>
Matrix<T, r, c>::~Matrix()
{
	for (size_t i = 0; i < r; i++)
	{
		delete[] * (Data + i);
	}
	delete Data;
}

template<typename T, size_t r, size_t c>
T& Matrix<T, r, c>::operator()(size_t i,size_t j)
{
	try {
		if (i > r || i<0 || j>c|| j < 0)
			throw _ERROR_RANGE_;
	}
	catch (const char[])
	{
		abort();
	}

	return *(*(Data + i) + j);
}

template<typename T, size_t r, size_t c>
T Matrix<T, r, c>::operator()(size_t i, size_t j)const
{
	try {
		if (i > r || i<0 || j>c|| j < 0)
			throw _ERROR_RANGE_;
	}
	catch (const char[])
	{
		abort();
	}

	return *(*(Data + i) + j);
}


template<typename T, size_t r, size_t c>
Matrix<T, r, c>::Matrix(const Matrix<T, r, c>& Other)
{
	this->_initial_();
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			this->operator()(i,j)= Other(i, j);
		}
	}
	
}


template<typename T, size_t r, size_t c>
std::ostream& operator<<(std::ostream& output, const Matrix<T, r, c>&P)
{
	
	try
	{
		if (!P._assign_check())
		{
			throw _ERROR_ASSIGN_;
		}
	}
	catch (const char[])
	{
		abort();
	}
	
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			output << P(i, j) << ' ';
			if (j + 1 == c) output << '\n';
		}
	}
	return output;
}



template<typename T, size_t r, size_t c>
Matrix<T, r, c>& Matrix<T, r, c>::operator << (T val)
{
	this->operator()(0, 0) = val;
	return *this;
}

template<typename T, size_t r, size_t c>
Matrix<T, r, c>& Matrix<T, r, c>::operator, (T val)
{
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (this->operator()(i, j) == _SIGN_ )
			{
				this->operator()(i, j) = val;
				return *this;
			}
			

		}
	}
	return *this;
}


template<typename T, size_t r, size_t c>
Matrix<T, r, c>& Matrix<T, r, c>::Identity()
{
	try {
		if (r != c) throw _SIZE_NMATCH;
	}
	catch (const char[])
	{
		abort();
	}

	for(size_t i=0;i<r;i++)
		for (size_t j = 0; j < c; j++)
		{
			if (i == j)
			{
				this->operator()(i, j) = 1;
			}
			else this->operator()(i, j) = 0;
		}

	return *this;
}
template<typename T, size_t r, size_t c>
Matrix<T, r, c>& Matrix<T, r, c>::Zero()
{
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
		{
			this->operator()(i, j) = 0;
		}

	return *this;
}

template<typename T, size_t r, size_t c>
Matrix<T,r,c> Matrix<T, r, c>:: operator+(const Matrix<T, r, c>&Other)const
{
	Matrix<T, r, c>* tmp = new Matrix<T, r, c>;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			tmp->operator()(i, j) = this->operator()(i, j) + Other(i, j);
		}
	}
	return *tmp;
}

template<typename T, size_t r, size_t c>
Matrix<T, r, c> Matrix<T, r, c>:: operator+=(const Matrix<T, r, c>& Other)
{

	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			this->operator()(i, j) += Other(i, j);
		}
	}
	return *this;
}





template<typename T, size_t r, size_t c>
Matrix<T, r, c> Matrix<T, r, c>:: operator-(const Matrix<T, r, c>& Other)const
{
	Matrix<T, r, c>* tmp = new Matrix<T, r, c>;
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			tmp->operator()(i, j) = this->operator()(i, j) - Other(i, j);
		}
	}
	return *tmp;
}

template<typename T, size_t r, size_t c>
Matrix<T, r, c> Matrix<T, r, c>:: operator-=(const Matrix<T, r, c>& Other)
{
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			this->operator()(i, j) -=Other(i, j);
		}
	}
	return *this;
}



template<typename T, size_t r, size_t c>
template<size_t N>
Matrix<T, r, N> Matrix<T, r, c>::operator*(const Matrix<T, c, N>& Other)const
{
	Matrix<T, r, N>* tmp = new Matrix<T, r, N>;
	tmp->Zero();
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			for (size_t k = 0; k < N; k++)
			{

				tmp->operator()(i, k) += this->operator()(i, j) * Other(j, k);
			}
		}
	}
	return *tmp;
}



template<typename T, size_t r, size_t c>
template<size_t N>
Matrix<T, r, N> Matrix<T, r, c>::operator*=(const Matrix<T, c, N>& Other)
{
	Matrix<T, r, N>* tmp = new Matrix<T, r, N>;
	tmp->Zero();
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			for (size_t k = 0; k < N; k++)
			{

				tmp->operator()(i, k) += this->operator()(i, j) * Other(j, k);
			}
		}
	}
	*this = *tmp;
	tmp->~Matrix();
	return *this;
}





template<typename T, size_t r, size_t c>
bool Matrix<T, r, c>::_square_check()const
{
	if (r == c) 
		return 1;
	else
		return 0;
}

template<typename T, size_t r, size_t c>
T Matrix<T, r, c>::trace()const
{
	T res=0;
	try
	{
		if (!_square_check())
		{
			throw _N_SQUARE_;
		}
	}
	catch (const char[])
	{
		abort();
	}

	for(size_t i=0;i<r;i++)
		for (size_t j = 0; j < c; j++)
		{
			if (i == j)
			{
				res += this->operator()(i, j);
			}
		}
	return res;
}

template<typename T,size_t r,size_t c>
Matrix<T, c, r> Matrix<T, r, c>::Transpose()const
{
	Matrix<T, c, r>* p = new Matrix<T, c, r>;
	
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			p->operator()(j, i) = this->operator()(i, j);
		}
	}
	return *p;
}


template<typename T,size_t r,size_t c>
template<typename C>
Matrix<T, r, c> Matrix<T, r, c>::operator*(const C Val)const
{
	Matrix<T, r, c>Obj(*this);
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			Obj(i, j) *= Val;
		}
	}
	return Obj;
}


template<typename T, size_t r, size_t c>
template<typename C>
Matrix<T, r, c> Matrix<T, r, c>::operator*=(const C Val)
{
	
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			this->operator()(i, j) *= Val;
		}
	}
	return *this;
}

