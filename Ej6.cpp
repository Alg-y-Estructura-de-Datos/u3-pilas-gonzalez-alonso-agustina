
/*Ejercicio N°6 : Control de Desplazamientos en un Edificio

Contexto: Un edificio cuenta con un sistema de control de accesos a través de tarjetas
magnéticas. Cada vez que una persona entra o sale del edificio, su tarjeta se registra en el
sistema. Queremos implementar un programa que, utilizando una pila, simule el movimiento
de una persona dentro del edificio.

Enunciado:
Implementa un programa en C++ que utilice una pila para simular el movimiento de una
persona en un edificio. Cada vez que la persona entra en un área del edificio (por ejemplo,
"Recepción", "Sala de Reuniones", "Oficina"), se debe apilar el nombre del área. Cuando la
persona sale del área, se debe desapilar el nombre. Al final del día, el programa debe mostrar
el recorrido de la persona en orden inverso al que lo hizo (último lugar visitado al primero).
Entrada:
Serie de operaciones de entrada ("in") o salida ("out") de áreas específicas del edificio.
Salida:
El recorrido completo de la persona en orden inverso, mostrando los lugares que visitó.*/


#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void funcionMovimiento (Pila<string>&pila, const string lugar, const string mov) {

    if (mov == "in") {
        pila.push(lugar);
    } else {
        pila.pop();
    }

}

void funcionMostrar (Pila<string> &pila){
    Pila<string>aux;

    while (!pila.esVacia()){
        string x = pila.pop();
        aux.push(x);
        cout << x << " " << endl;
    }
    cout << endl;
    
    while (!aux.esVacia()){
        pila.push(aux.pop());
    }
}

int main () {
    cout << "Ejercicio N6" << endl;

    Pila<string> pila;
    string lugar;
    string mov;

    for (int i = 0; i < 5; ++i) {
        cout << "Ingrese el lugar" << endl;
        getline(cin, lugar);
        cout << "Ingrese el movimiento" << endl;
        getline(cin, mov);

        funcionMovimiento(pila,lugar,mov);
    }


    funcionMostrar(pila);

    return 0;
}
