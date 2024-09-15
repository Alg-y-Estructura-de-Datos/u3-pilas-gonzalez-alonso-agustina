/*Ejercicio N°1
Escriba un programa que introduzca una palabra y utilice una pila para imprimir la misma
palabra invertida.*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

int main () {
    cout << "Ejercico N1 " << endl;

    Pila<char> pila;
    char a;

    cout << "Ingrese una palabra o frase (finalizar con un punto)" << endl;

    do {
        cin.get(a);
        if (a != '.') {
            pila.push(a);
        }
    } while (a != '.');


    while (!pila.esVacia()) {
        cout << pila.pop();
    }
}

