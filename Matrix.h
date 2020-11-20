//
// Created by djnic on 13.11.2020.
//

#ifndef CLASS_TRAINIG_MATRIX_H
#define CLASS_TRAINIG_MATRIX_H


#include <string>
#include <iostream>

class Matrix {
    int c;
    int r;
    double **data;
    double det;
public:
    Matrix() : c(3), r(3) {
        // macierz jednostkowa - wypelnienie danymi
        double **array;
        array = new double *[c];
        for (int i = 0; i < c; i++)
            array[i] = new double[r];
        for (int j = 0; j < c; j++)
            for (int k = 0; k < r; k++)
                if (j == k)array[j][k] = 1;
                else array[j][k] = 0;
        this->data = array;
    }

    Matrix(int _c, int _r, double **array) : c(_c), r(_r) {
        if (array != nullptr) {
            this->data = new double *[c];
            for (int i = 0; i < c; i++)
                this->data[i] = new double[r];
        }
        this->data = array;
    }

//Konstruktor kopiujący
    Matrix(Matrix &ob) {
        this->c = ob.c;
        this->r = ob.r;
        this->det = ob.det;
        this->data = new double *[c];
        for (int i = 0; i < c; i++)
            this->data[i] = new double[r];
        this->data = ob.data;
    }

//Konstruktor przenoszący
    Matrix(Matrix &&ob) {
        this->c = ob.c;
        this->r = ob.r;
        this->data = new double *[c];
        for (int i = 0; i < c; i++)
            this->data[i] = new double[r];
        for (int i = 0; i < c; i++)
            for (int j = 0; j < r; j++)
                this->data[i][j] = ob.data[i][j];
        this->det = ob.det;

        for (int i = 0; i < ob.c; i++)
            delete[] ob.data[i];
        delete[] ob.data;
        ob.c = 0;
        ob.r = 0;
        ob.det = 0;
    }

//Operator dodawania - ma sie wykonac: Matrix ob7 = ob5 + ob6;
//    void determinant();
//
//    void inverse();

    friend Matrix &operator+(const Matrix &matrix1, Matrix &matrix2) {
        Matrix *result = new Matrix();
        if (matrix1.c == matrix2.c && matrix1.r == matrix2.r
            && matrix1.data != nullptr && matrix2.data != nullptr) {
            result->c = matrix1.c;
            result->r = matrix1.r;
            result->data = new double *[result->c];
            for (int i = 0; i < result->c; i++)
                result->data[i] = new double[result->r];
            for (int i = 0; i < result->c; i++)
                for (int j = 0; j < result->r; j++)
                    result->data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        } else
            std::cerr << "Incorrect matrix data Buddy" << std::endl;
        return *result;
    }

    friend Matrix &operator-(const Matrix &matrix1, Matrix &matrix2) {
        Matrix *result = new Matrix();
        if (matrix1.c == matrix2.c && matrix1.r == matrix2.r
            && matrix1.data != nullptr && matrix2.data != nullptr) {
            result->c = matrix1.c;
            result->r = matrix1.r;
            result->data = new double *[result->c];
            for (int i = 0; i < result->c; i++)
                result->data[i] = new double[result->r];
            for (int i = 0; i < result->c; i++)
                for (int j = 0; j < result->r; j++)
                    result->data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        } else
            std::cerr << "Incorrect matrix data Buddy" << std::endl;
        return *result;
    }
//szerokość to c XD

    friend Matrix &operator*(const Matrix &matrix1, Matrix &matrix2) {
        Matrix *result = new Matrix();
        if (matrix1.c == matrix2.c && matrix1.r == matrix2.r
            && matrix1.data != nullptr && matrix2.data != nullptr) {
            result->c = matrix1.r;
            result->r = matrix2.c;
            result->data = new double *[result->c];
            for (int i = 0; i < result->c; i++)
                result->data[i] = new double[result->r];
            for (int i = 0; i < matrix1.r; i++)
                for (int j = 0; j < matrix2.c; j++)
                    result->data[i][j] = 0;
            for (int i = 0; i < matrix1.r; i++)
                for (int j = 0; j < matrix2.c; j++)
                    for (int k = 0; k < matrix1.c; k++) {
                        result->data[i][j] += (matrix1.data[i][k] * matrix2.data[k][j]);
                    }
        } else
            std::cerr << "Incorrect matrix data Buddy" << std::endl;
        return *result;
    }

    std::string to_string() {
        std::string result = "";
        if (data != nullptr) {
            for (int i = 0; i < this->r; i++) {
                for (int j = 0; j < this->c; j++)
                    result += (std::to_string(this->data[i][j]) + " ");
                result += "\n";
            }
        }
        return result;
    }
};
// konstruktor bezarg. z lita inicjalizacyjna
// Klasa::Klasa() : pole1(wartosc1), pole2(wartosc2), pole3(wartosci3) { }

// konstruktor arg. z lita inicjalizacyjna
// Klasa::Klasa(int _pole1) : pole1(_pole1), pole2(wartosc2), pole3(wartosc3) { }

// konstruktor bezarg. bez listy inicjalizacyjnej
// Klasa::Klasa() {
//  this->pole1 = wartosc1;
//  this->pole2 = wartosc2;
//  this->pole3 = wartosc3;
// }

// konstruktor bezarg. z lita inicjalizacyjna oraz 'standardowa' inicjal. pol
// Klasa::Klasa() : pole1(wartosc1) {
//  this->pole2 = wartosc2;
//  this->pole3 = wartosc3;
// }

#endif //CLASS_TRAINIG_MATRIX_H
