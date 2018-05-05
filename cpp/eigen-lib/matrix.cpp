/*
    Very good intro to Eiugen library here:
    https://dritchie.github.io/csci2240/assignments/eigen_tutorial.pdf
    
    https://eigen.tuxfamily.org/dox/group__QuickRefPage.html
    
    for compile this file, do 
    $ g++ -I /usr/include/eigen3/ matrix.cpp -o matrix

*/
#include <iostream>
#include <Eigen/Geometry>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

int main() {
  cout << "Eigen version: " <<  EIGEN_MAJOR_VERSION << "."<<  EIGEN_MINOR_VERSION << endl ;
  
  Matrix3f A;   // matrix 3x3 of floats
  Matrix4d B;   // matrix 4x4 of doubles
  Matrix<float, 5, 6> C;    // matrix 5x6 of floats
  
  /* !!! initialization of matrieses */
  A <<  1.0f, 1.0f, 1.0f,
        1.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 3.0f;
  
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
        B(j, i) = 0.0;  // round brackets... uuggm... :(
        // they say that it is more efficient to go through the first columns, then the lines...
        // This is because Eigen stores matrices in column-major order by default
    }
  }
  cout << A << endl;
  cout << B << endl;
    
  /* !!! awesome example of block matrix :) */
  double lambda = 420.0f;
  Matrix2f D;
  Matrix2f E;
  MatrixXf F(4,4);
  D << lambda, 0.0f, 0.0f, lambda;
  E << 0.0f, 0.0f, 0.0f, 0.0f;
  F << D/10, E, E, D/100;
  cout << F << endl;
  /*
    output:
     42   0   0   0
      0  42   0   0
      0   0 4.2   0
      0   0   0 4.2
      Are you sure that it's С++, matherfucker??
  */
  
  /* predefined usefull functinos*/
  Matrix3f G = Matrix3f::Random();   // 3x3 matrix of randoms in range [-1,1]
  cout << G << endl;    // AWESOM-O
  G = Matrix3f::Identity();
  cout << G << endl;
  G = Matrix3f::Zero();
  cout << G << endl;
  G = Matrix3f::Ones();
  cout << G << endl;
  G = Matrix3f::Constant(42.0f);
  cout << G << endl;
  
  /* MATRIX operations */
  cout << G + Matrix3f::Constant(8.0f) << endl;
  cout << G * G << endl;
  Matrix3f H = G.diagonal().asDiagonal();
  cout << H << endl;
  H(0,2) = 13;
  cout << H.transpose() << endl;
  cout << H.inverse() << endl;
  
  /* for apply operations to matrix as array, i.e. element-wise*/
  Matrix4f K = Matrix4f::Ones() * 13.0f;
  cout << K * Matrix4f::Identity() << endl;

  Matrix4f L = K.array();
  Matrix4f L1 = Matrix4f::Identity().array();
  cout << L * L1 << endl;
  
  /* Vectors! Actually it is nothing more then a matrix with a single column:
    typedef Matrix<float, 3, 1> Vector3f;  
  */
  Vector3f v;
  Vector4f a(1.0f, 2.0f, 3.0f, 1.0f);
  v << 1.0f, 1.0f, 1.0f;
  // Also
  Vector3f v1 = Vector3f::Ones();
  Vector3f v2 = Vector3f::Zero();
  Vector3f v3 = Vector3f::Random();
  Vector3f v4 = Vector3f::Constant(1.57f);
  cout << v2 - v1 << endl;
  cout << v1 * 3.14f << endl;
  Vector3f b = Vector3f::Ones() * 3;
  Vector3f c = Vector3f::Constant(3);
  bool d =  b == c;
  cout << d << endl;
  
  Vector3f e(1, 2, 3);
  Vector3f f(4, 5, 6);
  cout << e.dot(f) << endl;
  cout << e.normalized() << endl;
  cout << e.cross(f) << endl;
  Vector4f g = e.homogeneous();
  cout << g << endl;
  cout << g.array().sin() << endl;
  
  /* EXAPMLE vertex transformation */
  float arrVertices[] = {   
    -1.0, 1.0, 1.0,
    -1.0, -1.0, 1.0,
    1.0, -1.0, -1.0,
    -1.0, 1.0, 1.0, 
    -1.0, -1.0, 1.0, 
    1.0, -1.0, -1.0, 
    -1.0, -1.0, 1.0, 
    1.0, 1.0, 1.0
  };
  
  MatrixXf mVertices = Map< Matrix<float, 3, 8> >(arrVertices);
  Transform<float, 3, Affine> t = Transform<float, 3, Affine>::Identity();
  
  t.scale(1);
  t.rotate(AngleAxisf(M_PI, Vector3f::UnitX())); // awwww
  t.translate(Vector3f(0, 0, 1));

  cout << t * mVertices.colwise().homogeneous() << endl ;
  
  cout << endl << mVertices.colwise().homogeneous() << endl;
  cout << endl << mVertices << endl;
  
  return 0;
}


