#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;
/*
    DECLARACION
    DE METODOS
*/
static int p = 0;
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
    string localidad = definirCiudad(p);
    Lista listaPaquetes;
};
#endif // UTILIDADES_H
