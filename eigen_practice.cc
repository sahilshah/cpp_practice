#include <iostream>
#include <Eigen/Eigen>


int main(int argc, char** argv) {

	// Simple initialization.
	Eigen::Matrix<double,3,3> square3;
	square3 << 2,1,3,5,7,8,9,12,11;
	std::cout << square3 << std::endl;
	std::cout << "Trace: ";
	std::cout << square3.trace() << std::endl;

	std::cout << "Max: ";
	int mr,mc;
	std::cout << square3.maxCoeff(&mr,&mc) << std::endl;
	std::cout << mr << " , " << mc << std::endl;

	std::cout << "Min: ";
	std::cout << square3.minCoeff(&mr,&mc) << " at " << std::endl;
	std::cout << mr << " , " << mc << std::endl;

	// Invert it.
	Eigen::Matrix3d inv_square3 = square3.inverse();
	std::cout << inv_square3 << std::endl;
	std::cout << "Trace: ";
	std::cout << inv_square3.trace() << std::endl;

	// Example of solve.
	Eigen::Matrix2f A, b;
	A << 2, -1, -1, 3;
	b << 1, 2, 3, 1;
	std::cout << "Here is the matrix A:\n" << A << std::endl;
	std::cout << "Here is the right hand side b:\n" << b << std::endl;
	Eigen::Matrix2f x = A.llt().solve(b);
   	std::cout << "The solution is:\n" << x << std::endl;


	return 0;
}