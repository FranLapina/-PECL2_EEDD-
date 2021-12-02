#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;
/*
    DECLARACION
    DE METODOS
*/
static int cpContador = 0;
int definirLatitud();
int definirLongitud();
string modelarLatitud(int latitudNumerica);
string modelarLongitud(int longitudNumerica);
string modelarID();
string modelarNIF();
int generarCP();
string definirCiudad(int p);

struct Paquete{


    private:
        //Se necesitan estas variables para
        //Hacer más comoda la detección de la zona del paquete.
        //No hacen falta verlas en el main.
        int latitudNumerica = definirLatitud();
        int longitudNumerica = definirLongitud();
        string longitud = modelarLongitud(longitudNumerica);
        string latitud = modelarLatitud(latitudNumerica);

    public:
        string ID = modelarID();
        string coordenadas = longitud+" , "+latitud;
        string NIF = modelarNIF();
        int numeroCP;

};


class Nodo
{
private:
    Paquete valor;
    Nodo *siguiente;
    friend class Lista;
public:
    Nodo(Paquete v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pnodo;
class Lista
{
private:
    pnodo cabeza, actual, final;
public:

    Lista()
    {
        cabeza = actual = final = NULL;
    }
    ~Lista();
    void insertarNodo(Paquete v);
    void borrarNodo(Paquete v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    Paquete valorActual();
    void recorrerLista();
};

struct CentralDePaqueteria{
    int numeroCP = generarCP();
    string localidad = definirCiudad(cpContador);
    Lista listaPaquetes;

};
class NodoArbol {
    private:
        // Miembros:
        CentralDePaqueteria dato;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class Arbol;

    public:
        // Constructor:
        NodoArbol(CentralDePaqueteria dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
};
typedef NodoArbol *pNodo;

class Arbol {
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        pNodo raiz;
        pNodo actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor básicos:
        Arbol() : raiz(NULL), actual(NULL) {}
        ~Arbol() { Podar(raiz); }
        // Insertar en árbol ordenado:
        void Insertar(CentralDePaqueteria dat);
        // Borrar un elemento del árbol:
        void Borrar(CentralDePaqueteria dat);
        // Función de búsqueda:
        bool Buscar(CentralDePaqueteria dat);
        // Comprobar si el árbol está vacío:
        bool Vacio(pNodo r) { return r==NULL; }
        // Comprobar si es un nodo hoja:
        bool EsHoja(pNodo r) { return !r->derecho && !r->izquierdo; }
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(CentralDePaqueteria dat);
        // Devolver referencia al int del nodo actual:
        CentralDePaqueteria ValorActual() { return actual->dato; } //&ValorActual()
        // Moverse al nodo raiz:
        void Raiz() { actual = raiz; }
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(CentralDePaqueteria&) , pNodo nodo=NULL, bool r=true);
        void PreOrden(void (*func)(CentralDePaqueteria&) , pNodo nodo=NULL, bool r=true);
        void PostOrden(void (*func)(CentralDePaqueteria&) , pNodo nodo=NULL, bool r=true);
        private:
        // Funciones auxiliares
        void Podar(pNodo &nodo);
        void auxContador(pNodo nodo);
        void auxAltura(pNodo nodo, int alt);
};

void Mostrar(CentralDePaqueteria&);
#endif // UTILIDADES_H
