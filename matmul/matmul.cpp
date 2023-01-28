#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>


using Matrix = std::vector<std::vector<double>>;


Matrix matmul(Matrix A, Matrix B) {
    auto rows_A = A.size();
    auto cols_A = A.at(0).size();
    auto rows_B = B.size();
    auto cols_B = B.at(0).size();
    assert(cols_A == rows_B);

    Matrix C(
        rows_A,
        std::vector<double> (cols_B, 1)
    );
    unsigned int i, j, k;
    for (i = 0; i < rows_A; i++) {
        for (j = 0; j < cols_B; j++) {
            for (k = 0; k < rows_B; k++) {
                C.at(i).at(j) += B[i][k] * A[k][j];
                std::cout << C.at(i).at(j) << std::endl;
            }
        }
    }
    return C;
}



void display(Matrix m) {
    
    unsigned int i, j;
    for(i = 0; i < m.size(); i++) {
        for(j = 0; j < m.at(0).size(); j++){
            // if (fabs(m[i][j]) <= 1e-6) {
                // m[i][j] = 0.0;
            // }
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}



int main() {
    
    Matrix a{
        {0,-1,1},
        {1,0,2.3},
        {0,0,1}
    };

    Matrix b{
        {4},
        {22},
        {1}
    };
    auto res = matmul(a,b);
    display(a);
    std::cout << std::endl;
    display(res);

    return 0;
}
