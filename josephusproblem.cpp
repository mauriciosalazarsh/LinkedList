//
// Created by mauri on 28/08/2024.
//

#include <iostream>
using namespace std;

// Definición del nodo de la lista enlazada
struct Node {
    int data;       // El valor del nodo (número de persona)
    Node* next;     // Puntero al siguiente nodo en la lista
};

// Función para crear un nuevo nodo
Node* newNode(int data) {
    Node* temp = new Node;   // Crear un nuevo nodo dinámicamente
    temp->data = data;       // Asignar el valor al nodo
    temp->next = nullptr;    // Inicialmente, el siguiente nodo es null
    return temp;             // Devolver el nodo creado
}

// Función para resolver el problema de Josephus
int josephus(int n, int k) {
    // Crear el primer nodo (persona 1)
    Node* head = newNode(1);
    Node* prev = head;  // El puntero 'prev' rastrea el nodo anterior en la lista

    // Crear el resto de los nodos (personas 2 a n)
    for (int i = 2; i <= n; i++) {
        prev->next = newNode(i); // Crear un nuevo nodo y enlazarlo con el nodo anterior
        prev = prev->next;       // Mover 'prev' al nodo recién creado
    }
    // Hacer la lista circular cerrando el último nodo hacia el primero
    prev->next = head;

    // Mientras quede más de un nodo en la lista
    Node* ptr = head;  // Iniciar 'ptr' en la cabeza de la lista
    while (ptr->next != ptr) {  // Este bucle continúa hasta que solo queda un nodo
        // Avanzar k-1 nodos (para encontrar el nodo que se eliminará)
        for (int count = 1; count < k; count++) {
            prev = ptr;      // Mover 'prev' al nodo actual
            ptr = ptr->next; // Mover 'ptr' al siguiente nodo
        }
        // Eliminar el k-ésimo nodo
        prev->next = ptr->next; // Saltar el nodo que será eliminado
        delete ptr;             // Liberar la memoria del nodo eliminado
        ptr = prev->next;       // Mover 'ptr' al siguiente nodo en la lista
    }

    // El nodo restante es el ganador
    int res = ptr->data; // Guardar el valor del nodo ganador
    delete ptr;          // Liberar la memoria del nodo restante
    return res;          // Devolver el valor del nodo ganador
}

int main() {
    int n = 7; // Número de personas en el círculo
    int k = 3; // Paso en el que se elimina a la persona
    // Llamar a la función josephus y mostrar el resultado
    cout << "El ganador es la persona en la posición: " << josephus(n, k) << endl;
    return 0;
}
