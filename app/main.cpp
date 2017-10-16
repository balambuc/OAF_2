#include <iostream>
#include <cstdlib>
#include "Bignum.h"


using namespace std;

bool read(Bignum& num);
void printMenu();

int main() {
    char option;
    Bignum lhs, rhs;

    do
    {
        printMenu();
        cin >> option;
        switch (option)
        {
            case '1':
                if (read(lhs) && read(rhs))
                    cout << lhs << " + " << rhs << " = " << (lhs + rhs) << endl;
                break;

            case '2':
                if (read(lhs) && read(rhs))
                    cout << lhs << " * " << rhs << " = " << (lhs * rhs) << endl;
                break;

            default:
                cout << "Nincs ilyen opcio :(" << endl;
        }
    }
    while (option != 'e' && option != 'E');
}

bool read(Bignum& num) {
    try
    {
        cout << "Szam: ";
        cin >> num;
    }
    catch (exception& e)
    {
        cout << "HIBA: " << e.what() << endl;
        return false;
    }
    return true;
}

void printMenu() {
    cout << endl
         << "Nagyszamokat kezelo program" << endl
         << endl
         << "Valasszon az alabbi opciok kozul: " << endl
         << "1) ket nagy szam osszeadasa" << endl
         << "2) ket nagy szam szorzata" << endl
         << "e) kilepes" << endl
         << endl
         << "Valasztott opcio: ";
}
