#pragma once
#include<iostream>




template<typename T, size_t r, size_t c>
//Matrix<T,r,c>
//Matrix<int,3,4>....

class Matrix {
public:

	Matrix();
  //constructor

	~Matrix();
	//destructor
  
	Matrix<T, r, c>& Zero();
  //zero matrix

	T& operator()(size_t,size_t);
  //index access operator
  //allow to assign value and access
  //Matrix<int,3,3>A;
  //A(1,2)= int
  
	T operator()(size_t,size_t)const;
	//index access operator 
  // only read
  
	Matrix(const Matrix<T, r, c>&);
  //copy constructor
  
	template<typename T, size_t row, size_t column>
	friend std::ostream& operator<<(std::ostream&, const Matrix<T,row,column>&);
	// << ostream operator overloading 
  // allow to use std::cout<<Matrix;
  
	Matrix<T,r,c>& operator << (T);
  // <<operator allow to assign the first value of the matrix
  
	Matrix<T, r, c>& operator , (T);
  // alllow to assgin value in the below form
  // Matrix<int,3,3>A;
  //A<<1,2,3,4,5,6,7,8,9;
  
	Matrix<T, r, c>& Identity();
  //Create identity Matrix
  
	Matrix<T, c, r> Transpose()const;
  // Transpose func
  
	Matrix<T, r, c> operator+(const Matrix<T, r , c>& )const;
  // + operator overloading
  // Matrix add
  
	Matrix<T, r, c> operator+=(const Matrix<T, r, c>&);
  // += operator overloading
  
	Matrix<T, r, c> operator-(const Matrix<T, r, c>&)const;
  //Matrix substract
  // - operator overloading
  
	Matrix<T, r, c> operator-=(const Matrix<T, r, c>&);
  // -= operator
  
	template<typename C>
	Matrix<T, r, c> operator*(const C)const;
  // scarlar product
  // allow Matrix<3,3,B>=A*3  
  
	template<size_t N>
	Matrix<T,r,N> operator*(const Matrix<T,c, N>&)const;
	// Matrix product
  // allow Matrix<int,3,4> C = Matrix<int,3,4>A * Matrix<int,4,4>B
  
	template<typename C>
	Matrix<T, r, c> operator*=(const C);
	// *=operator overloading

	template<size_t N>
	Matrix<T, r, N> operator*=(const Matrix<T, c, N>&);
  // *=operator overloading
  
	T trace()const;
  // square matrix trace

private:
	T** Data;
  // second rank pointer
  
	void _initial_();
  // assign heap space
  
	bool _assign_check()const;
  // check Matrix asssign
  
	bool _square_check()const;
  // check is a square matrix
	

};

