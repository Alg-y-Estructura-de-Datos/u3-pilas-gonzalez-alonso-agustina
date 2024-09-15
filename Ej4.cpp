/*Ejercicio N°4
Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una pila y pedir también un número entero "n". Luego crear una función que
reciba una pila y un número entero “n”, si el "n" se encuentra en una de las posiciones de la
pila, devuelve la suma de los números en cada una de las posiciones de la pila hasta llegar a
"n" (sin incluir a n), si el número "n" no se encuentra en la pila, la función devuelve la suma de
todos los elementos de la pila. Imprimir primero la pila antes de sumar sus elementos.*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

int sumar (Pila<int>&pila, int n){
    bool encontrado = false;
    int suma = 0 ;

    while (!pila.esVacia()){
        int a = pila.pop();

        if ( a == n) {
            encontrado = true;
        }
        if (!encontrado){
            suma=suma+a;
        }
    }
    return suma;
}

void mostrarPila (Pila<int>&pila){
    Pila <int> aux;

    while (!pila.esVacia()){
        int dato = pila.pop();
        cout << dato << " ";
        aux.push(dato);
    }
    cout << endl;

    while (!aux.esVacia()){
        pila.push(aux.pop());
    }
}

int main (){
    cout << "Ejercicio N4" << endl;

    Pila<int> pila;
    int n, m, num;

    cout << "Ingrese la cantidad de elementos de la pila" << endl;
    cin >> m;

    cout << "Ingrese los elementos  " << endl;

    for (int i = 0; i < m; i++) {
        cin >> num;
        pila.push(num);
    }


    cout << "Ingrese un numero entero" << endl;
    cin >> n;

    mostrarPila(pila);
    cout << "Suma: " << sumar(pila,n) << endl;


    return 0;
}