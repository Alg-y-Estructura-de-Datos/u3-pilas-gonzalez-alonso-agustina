/*Ejercicio N°2
Escribir una función Reemplazar que tenga como argumentos una pila con tipo de elemento
int y dos valores int: viejo y nuevo de forma que, si el primer valor (viejo) aparece en algún
lugar de la pila, sea reemplazado por el segundo (nuevo)..
*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void cambiar (Pila<int> &pila, int nuevo, int viejo){
    Pila<int> aux;

    while (!pila.esVacia()){
        int a = pila.pop();

        if (a == viejo ){
            aux.push(nuevo);
        }
        else {
            aux.push(a);
        }
    }

    while (!aux.esVacia()){
        pila.push(aux.pop());
    }
}

void mostrar (Pila<int>&pila){
    Pila<int>aux;

    while (!pila.esVacia()){
        int a = pila.pop();
        cout << a << " " << endl;
        aux.push(a);
    }
    while (!pila.esVacia()){
        pila.push(aux.pop());
    }
}

int main (){
    cout << "Ejercicio N2" << endl;

    Pila<int> pila;
    int nuevo, viejo;

    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    cout << "Ingrese el valor viejo " << endl;
    cin >> viejo;
    cout << "Ingrese el valor nuevo " << endl;
    cin >> nuevo;

    cambiar(pila,nuevo, viejo);

    mostrar(pila);
}