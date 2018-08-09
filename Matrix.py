import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1
        return I

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])

    #
    # Primary matrix math methods
    #############################

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same")
        summ = zeroes(self.h, self.w) 
        for i in range(self.h):
            for j in range(self.w):
                summ.g[i][j] = self.g[i][j] + other.g[i][j]
        return summ 


    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        negati = zeroes(self.h, self.w)   
        for i in range(self.h):
            for j in range(self.w):
                negati.g[i][j] = self.g[i][j]*-1

        return negati

    def __sub__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same")
        diff = zeroes(self.h, self.w) 
        for i in range(self.h):
            for j in range(self.w):
                diff.g[i][j] = self.g[i][j] - other.g[i][j]
        return diff

    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        prod = zeroes(self.h, other.w)
        for i in range(self.h):
            for j in range(other.w):
                for k in range(self.w):
                    prod.g[i][j] += self.g[i][k] * other.g[k][j]

        return prod

    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
        nm = zeroes(self.h, self.w)
        if isinstance(other, numbers.Number):
            pass
            for i in range(self.h):
                for j in range(self.w):
                    nm.g[i][j] = other * self.g[i][j]
        return nm
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
        
        if self.h == 1:
            return self.g
        if self.h == 2:
            det = (self.g[0][0]*self.g[1][1]) - (self.g[0][1]*self.g[1][0])
            return det

    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate the trace of a non-square matrix.")

        trac = 0

        for vals in range (self.h):
            trac = trac + self.g[vals][vals]
        return trac

    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")

        if self.h == 1:
            invv = (1/self.g[0][0])
            return invv
        if self.h == 2:
            inv = zeroes(2, 2)
            inv = 1/self.determinant() * self.adjugate()
        return inv

    def adjugate(self):
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an adjugate.")
        if self.h > 2:
            raise(NotImplementedError, "adjugation not implemented for matrices larger than 2x2.")
        if self.h == 1:
            adj = 1
            return invv
        if self.h == 2:
            adjt = zeroes(2, 2)
            adjt.g = self.g
            temp = adjt.g[0][0]
            adjt.g[0][0] = adjt.g[1][1]
            adjt.g[1][1] = temp
            adjt.g[0][1] *= -1
            adjt.g[1][0] *= -1
        return adjt

    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        trans = zeroes(self.w, self.h)
        for i in range(self.h):
            for j in range(self.w):
                trans.g[i][j] =self.g[j][i]
        return trans

   # def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        # TODO - your code here

    def is_square(self):
        return self.h == self.w

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s


mat1 = Matrix([[2,4], [3,1]])

mat2 = identity(2)

mat3 = Matrix([[1,2,3], [4,5,6]])

mat4 = Matrix([[7,-2], [-3,-5], [4,1]])

print (mat3, mat4)

#wiw = mat1.trace()

#tre = -mat1

#print (wiw) 

#print (mat1)

#print (mat1+mat3)

#print (mat1-mat3)

print (mat3*mat4)

#print (4* mat2)

#print (tre)

#print (mat4.determinant())

#print (mat4)

#print (mat4.inverse())
