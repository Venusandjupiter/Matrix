# Matrix
A simple matrix class with C++ and template.  
We can do some basic matrix operations like (Matrix,number )product, add, substract, Transpose. And we also define the identitiy matrix generating function and zero matrix generating function.  
The most fascinating part is that we allow to input the matrix or access the element of Matrix like the style of Eigen:  
//CODE BLOCK  
  
auto A = new Matrix<int,3,3>;  
*A<<1,0,0,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0,1,0,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0,0,1;  
std::cout<<*A<<std::endl； 
//print the Matrix  
std::cout<<*A(2,2)<<std::endl;  
//print the element A_{2,2}  
  
//CODE BLOCK  
  
THE WORK LEFT NEED TO DO:  
ROW VECTOR;  
COLUMN VECTOR;  
SOLVE LINEAR EQUATION;  
THE GAUSSIAN ELIMINATION;  
THE DETMINANT OF MATRIX FUNCTION;  
THE EIGENVALUE FUNCTION;  
THE EIGENVECTOR FUNCTION;  
THE LU DECOMPOSITION;  
THE QR DECOMPOSITION;  
THE SVD DECOMPOSITION;  
THE CHOLESKY DECOMPOSITION;  
F-NORM FUNCTION;  
2-NORM FUNCTION;  
......  
