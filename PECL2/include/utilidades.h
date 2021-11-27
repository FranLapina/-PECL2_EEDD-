#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;
/*
    DECLARACION
    DE METODOS
*/
int definirLatitud();
int definirLongitud();
string modelarLatitud(int latitudNumerica);
string modelarLongitud(int longitudNumerica);
string modelarID();
string modelarNIF();

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
struct CentralDePaqueteria{
    int numeroCP;
    string localidad;
    //TODO: LISTA DE PAQUETES.
};

#endif // UTILIDADES_H
