//
// Created by semcjaku on 20.03.18.
//

#ifndef JIMP_EXERCISES_DTAB_H
#define JIMP_EXERCISES_DTAB_H

#include <iostream>

class DTab
{
    public:
        // Konstruktor bezparametrowy. Powinien tworzyć tablicę o rozmiarze 10. (wykorzystaj metode resize)
        DTab();
        // Tworzy tablice o rozmiarze podanym jako parametr. (wykorzystaj metode resize)
        DTab(int initLength);
        // Destruktor. Uwaga! Tablicę tworzymy dynamicznie, czyli tutaj jest wymagany!
        ~DTab();

        // Dodaje element do na koniec tablicy. Jeśli tablica jest za mała
        // rozszerza ją. (wykorzystaj metode resize)
        void add(double element);
        / Pobiera element z tablicy z podanego indexu
        double get(int index);
        // Ustawia element o danym indeksie na daną wartość
        void set(double element, int index);
        // wyświetla tablice.
        void print();
    private:
        double * tab;
        int length;
        int last;

        // Metoda rozszerzajaca rozmiar tablicy do rozmiaru podanego jako parametr
        void resize(int newSize);
};


#endif //JIMP_EXERCISES_DTAB_H
