/*Ejercicio N°3
Crear una función que reciba una pila por referencia y un número. La función debe sacar la
primera ocurrencia de dicho valor de la pila sino se repite el valor en la pila, de lo contrario
debe eliminar todos los valores repetidos a excepción de la primera ocurrencia. Si el valor no
se encuentra en la pila muestra un mensaje indicando que no pertenece a la pila. Imprimir la
pila al final para verificar si hubo o no modificaciones.
*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void remover (Pila<int>pila, int num){
    Pila<int>aux;
    bool dato = false;
    int cont = 0;

    while (!pila.esVacia()){
        int a = pila.pop();

        if ( a == num ){
            if (!dato){
                dato=true;
                aux.push(a);
            }
           cont ++;
        }
        else {
            aux.push(a);
        }
    }
    if (!dato) {
        cout << "El valor " << num << " no pertenece a la pila." << endl;
    }

    // Volver a llenar la pila original
    while (!aux.esVacia()) {
        pila.push(aux.pop());
    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main (){
    cout << "Ejercicio N3" << endl;

    Pila<int> pila;
    int num;

    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    cout << "Ingrese el numero a remover " << endl;
    cin >> num;

    remover(pila, num);
    mostrarPila(pila);

}