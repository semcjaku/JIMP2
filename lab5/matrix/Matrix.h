//
// Created by Kuba on 08-04-18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <cmath>
#include <string>
#include <complex>
#include <vector>
#include <algorithm>
#include <sstream>

namespace algebra
{
    std::string toString(const double value);

    class Matrix
    {
    public:
        Matrix();

        Matrix(const std::initializer_list<unsigned int> &dims);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> elem);

        Matrix(std::string m);
        ~Matrix()=default;

        Matrix(const Matrix& m);
        Matrix & operator=(const Matrix& m);

        std::pair<size_t,size_t> Size();
        std::string Print() const;
        Matrix Add(const Matrix &another) const;
        Matrix Sub(const Matrix &another);
        Matrix Mul(const Matrix &another);
        Matrix Pow(int n);

    private:
        std::vector<std::vector<std::complex<double>>> mat_;
        std::vector<unsigned int> dim_;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
