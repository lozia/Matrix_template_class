//
//  main.cpp
//  Matrix
//
//  Created by Louie Li on 2/12/21.
//

#include <iostream>
#include "Matrix.h"

using namespace std;


int main(int argc, const char* argv[]) {
    cout << "This matrix index system starts at 0, not 1." << endl;
    cout << "****************Part 1******************" << endl;
    Matrix<int> first_matrix = Matrix<int>();
    cout << "printing matrix:" << endl;
    first_matrix.printMatrix();

    cout << "trying ostream operator <<" << endl;
    cout << first_matrix;

    cout << "testing operator+, adding itself " << endl;
    cout << (first_matrix + first_matrix);

    cout << "testing operator*, multiplying itself " << endl;
    cout << (first_matrix * first_matrix);

    cout << "give me the second column in the initial matrix: " << endl;
    for (auto const& a : first_matrix[1])
    {
        cout << a << endl;

    }
    cout << "****************Part 2******************" << endl;
    vector<vector<float>> float_vectors_1;
    float_vectors_1.push_back(vector<float>({ 1,3,5,7,9 }));
    float_vectors_1.push_back(vector<float>({ 2, 4, 6, 8, 10 }));
    float_vectors_1.push_back(vector<float>({ 11, 13, 15, 17, 19 }));
    /*
    for (auto a:float_vectors_1)
    {
        for (auto b : a)
        {
            cout << b;
        }
        cout << endl;
    }
    */
    vector<vector<float>> float_vectors_2;
    float_vectors_2.push_back(vector<float>({ 1.1,3.1,5.1 }));
    float_vectors_2.push_back(vector<float>({ 2.1, 4.1, 6.1}));
    float_vectors_2.push_back(vector<float>({ 11.1, 13.1, 15.1}));
    cout << "constructing a matrix from vector 1" << endl;
    Matrix<float> second_matrix = Matrix<float>(float_vectors_1);
    cout << "second matrix is: " << second_matrix;
    cout << "constructing a matrix from vector 2" << endl;
    Matrix<float> third_matrix = Matrix<float>(float_vectors_2);
    cout << "third matrix is: " << third_matrix;
    Matrix<float> fourth_matrix = Matrix<float>();
    cout << "assigning the fourth matrix to the third matrix: " << endl;
    cout << "the fourth matrix before operation= is: " << fourth_matrix;
    fourth_matrix = third_matrix;
    cout << "the fourth matrix after operation= is: " << fourth_matrix;
    cout << "testing operator*, multiplying the second with the fourth matrix " << endl;
    cout << (second_matrix * fourth_matrix);

    cout << "****************Part 3******************" << endl;
    cout << "creating a 2x2 matrix: " << endl;
    Matrix<float> two_by_two(2, 2);
    cout << two_by_two;
    cout << "testing operator[] :" << endl;
    two_by_two[1][1] = 1;
    cout << two_by_two;
    const float test_number = two_by_two[1][1];
    cout << "trying to fetch A[1,1]: " << test_number << endl;
    
    return 0;
}
