#include <iostream>
#include <cstring>
#include "Matrix.h"
#include "BasicCalculator.h"
#include "MatrixCalculator.h"

/*
 * Utwórz klasę o nazwie Matrx reprezentującą macierz. Klasa ma posiadać następujące właściwości:
 *  - ilosc kolumn c (int),
 *  - ilosc wierzy r (int),
 *  - wyznacznik det (double),
 * Klasa ma posiadać następujące konstruktory:
 *  - konstruktor bezargumentowy (tworzy macierz jednostkową o wymiarze 3x3, ustawia odpowiednio wartosci pól c i r);
 *  - konstruktor argumentowy przyjmujący następujące wartości jako parametry:
 *      1. wymiar macierzy c (int),
 *      2. wymiar macierzy r (int),
 *      3. wartosci macierzy a_11, ..., a_rc (dwuwymiarowa tablica typu double).
 *  - konstruktor kopiujący;
 *  - konstruktor przenoszący.
 * ---------------------------------------------------------------------------------------------------------------------
 * Dodatkowo, klasa Matrix ma udostępniać następujące metody publicze:
 *  - determinant() - obliczająca wyznacznik macierzy;
 *  - inverse() - metoda zwraca odwróconą macierz;
 * ---------------------------------------------------------------------------------------------------------------------
 * Klasa Matrix ma przeciążać następujące opratory:
 *  - +, += (dodawanie macierzy),
 *  - -, -= (odejmowanie macierzy),
 * ---------------------------------------------------------------------------------------------------------------------
 *  - *, *= (mnożenie macierzy),
 *  - ///= (dzielenie macierzy),
 *  - (string) - operator rzutowania na string,
 *  - (double) - operator rzutowania na double (do wyznacznika).
 */
/*
---------------------------------
BasicCalculator.exe -p 2.0 3.5 +
>>> 5.5
BasicCalculator.exe -p 2.0 3.5 *
>>> 7.0
---------------------------------
*/
int main(int argc, char *argv[]) {
    MatrixCalculator *bc = new MatrixCalculator();

    if (argc > 1 && strcmp(argv[1], "-p") == 0) {
        std::cout << "res = " << static_cast<BasicCalculator *>(bc)->calculate(std::stod(argv[2]), std::stod(argv[3]),
                                                                               argv[4]).dValue << std::endl;
        return 0;
    }

    std::cout << "Wpisz q aby zakonczyc program..." << std::endl;
    std::string action, sign;
    double var1, var2, res;
    std::cin >> action;
    while (action != "q") {
        std::cout << "var1 =";
        std::cin >> var1;
        std::cout << "var2 =";
        std::cin >> var2;
        std::cout << "sign:";
        std::cin >> sign;
        res = static_cast<BasicCalculator *>(bc)->calculate(var1, var2, sign).dValue;
        std::cout << "res =" << res << std::endl;
        std::cout << "press \'q\' to quit or \'m\' to see memory...";
        std::cin >> action;
        if (action == "m")
            bc->memory();
    }

    Matrix *ob1 = new Matrix();
    std::cout << "ob1\n" << ob1->to_string() << std::endl;
    //utworzyć tablice do przesłania i dokońćzyć testowanie
    Matrix ob2(3, 3, nullptr);
    std::cout << "ob2\n" << ob2.to_string() << std::endl;

    int height = 3, width = 3;
    double **mainArray;
    mainArray = new double *[width];
    for (int i = 0; i < width; i++)
        mainArray[i] = new double[height];
    for (int j = 0; j < width; j++)
        for (int k = 0; k < height; k++)
            if (j == k)mainArray[j][k] = 2;
            else mainArray[j][k] = 1;

    Matrix ob3(height, width, mainArray);
    Matrix ob4(ob3);
    std::cout << "ob4\n" << ob4.to_string() << std::endl;

    Matrix ob5(height, width, mainArray);
//    Matrix ob6 = std::move(ob5);
    std::cout << "ob4\n" << ob4.to_string() << std::endl;
    std::cout << "ob5\n" << ob5.to_string() << std::endl;
//    std::cout << "ob6\n" << ob6.to_string() << std::endl;

    Matrix *ob7 = bc->calculate(*ob1, ob5, "+").mValue;
    std::cout << "ob7\n" << ob7->to_string() << std::endl;
    Matrix *ob8 = bc->calculate(*ob7, *ob1, "-").mValue;
    std::cout << "ob8\n" << ob8->to_string() << std::endl;
    Matrix *ob9 = bc->calculate(*ob7, *ob1, "*").mValue;
    std::cout << "ob9\n" << ob9->to_string() << std::endl;
    return 0;
}