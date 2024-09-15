/*Ejercicio N°5
Crear un programa e implementar una función que reciba una pila de números enteros y
dado un número “n” por el usuario devuelva una nueva pila con la suma de cada uno de los
elementos de la pila original más el n dado por el usuario. Los elementos en la nueva pila
deben tener el orden que tenían en la pila original, y la pila original debe quedar en el mismo
estado a la inicial, mostrar por pantalla ambas pilas.
Por ejemplo, se tiene la pila de enteros [ 1, 2, 3, 6, 2] (tope es el número 2), y la función
sumarNro recibe como parámetros la pila y n=1 (devuelve la suma entre el número 1 y el
número recibido en cada posición de la pila original), la pila resultante debe ser [ 2, 3, 4, 7, 3]
(el tope es el número 3)
*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

Pila<int>suma (Pila<int>&pila, int n){

    Pila<int>aux1;
    Pila<int>aux2;

    while (!pila.esVacia()){
        int a = pila.pop();
        aux1.push(a);
    }

    while (!aux1.esVacia()){
        int nuevo = aux1.pop();
        aux2.push(nuevo);
        pila.push(nuevo+n);
    }
    return aux2;
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
    cout << "Ejercicio N5" << endl;

    Pila<int>pila;
    int n, num, m;

    cout << "Ingrese la cantidad de elementos en la pila" << endl;
    cin >> m;

    cout << "Ingrese los elementos de la pila" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> num;
        pila.push(num);
    }

    cout << "Ingrese un numero entero" << endl;
    cin >> n;

    cout << "Antes: " << endl;
    mostrarPila(pila);
    suma(pila,n);
    cout << "Despues: " << endl;
    mostrarPila(pila);
    return 0;
}