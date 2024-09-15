/*Ejercicio N°7:Deshacer Operaciones en un Editor de Texto
Contexto: Imagina que estás utilizando un editor de texto que tiene una función de "deshacer"
para revertir los cambios recientes. Cada vez que realizas un cambio en el documento, el
editor lo guarda para que puedas deshacerlo si es necesario. Implementa esta funcionalidad
usando una pila.
Enunciado:
Escribe un programa en C++ que simule la funcionalidad de "deshacer" de un editor de texto
utilizando una pila. Cada vez que el usuario realiza una acción (por ejemplo, escribir una
palabra, borrar una palabra), se debe apilar esta acción. Cuando el usuario decide "deshacer"
una acción, se debe desapilar y mostrar cuál fue la última acción realizada.
Entrada:
Serie de acciones como "escribir" o "borrar" seguidas de la palabra correspondiente.
Comando "deshacer" para revertir la última acción.
Salida:
Estado actual del texto después de cada operación.
Acción revertida en cada comando de "deshacer".
*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;


void funcion (Pila<string> &pila,string accion,string p, string comando){

    pila.push(p);

    if ( comando == "deshacer"){
        if (!pila.esVacia()){
            pila.pop();
        }
        else {
            cout << "No hay acciones para deshacer" << endl;
        }
    }
}

void mostrarPila (Pila<string>&pila){

    Pila<string> aux;

    while (!pila.esVacia()){
        string x = pila.pop();
        aux.push(x);
        cout << x << " " << endl;
    }

    while (!aux.esVacia()){
        pila.push(aux.pop());
    }
}

int main (){
    cout << "Ejercicio N7" << endl;

    Pila<string> pila;
    string comando;
    string p;

    funcion(pila, "escribir", "hola", "mantener");
    funcion(pila, "escribir", "mundo", "deshacer");
    funcion(pila, "borra", "mundo", "deshacer");

    mostrarPila(pila);
    return 0;
}
