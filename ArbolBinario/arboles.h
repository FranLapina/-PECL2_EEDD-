#ifndef ARBOLES_H
#define ARBOLES_H

#include <iostream>

using namespace std;

class Nodo {
    private:
        // Miembros:
        int dato;
        Nodo *izquierdo;
        Nodo *derecho;
        friend class Arbol;

    public:
        // Constructor:
        Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
};
typedef Nodo *pNodo;

class Arbol {
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        pNodo raiz;
        pNodo actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor b�sicos:
        Arbol() : raiz(NULL), actual(NULL) {}
        ~Arbol() { Podar(raiz); }
        // Insertar en �rbol ordenado:
        void Insertar(const int dat);
        // Borrar un elemento del �rbol:
        void Borrar(const int dat);
        // Funci�n de b�squeda:
        bool Buscar(const int dat);
        // Comprobar si el �rbol est� vac�o:
        bool Vacio(pNodo r) { return r==NULL; }
        // Comprobar si es un nodo hoja:
        bool EsHoja(pNodo r) { return !r->derecho && !r->izquierdo; }
        // Contar n�mero de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const int dat);
        // Devolver referencia al int del nodo actual:
        int ValorActual() { return actual->dato; } //&ValorActual()
        // Moverse al nodo raiz:
        void Raiz() { actual = raiz; }
        // Aplicar una funci�n a cada elemento del �rbol:
        void InOrden(void (*func)(int&) , pNodo nodo=NULL, bool r=true);
        void PreOrden(void (*func)(int&) , pNodo nodo=NULL, bool r=true);
        void PostOrden(void (*func)(int&) , pNodo nodo=NULL, bool r=true);
        private:
        // Funciones auxiliares
        void Podar(pNodo &nodo);
        void auxContador(pNodo nodo);
        void auxAltura(pNodo nodo, int alt);
};

void Mostrar(int&);
void generarArbol(Arbol&);

#endif

