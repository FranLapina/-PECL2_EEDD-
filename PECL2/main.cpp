#include <iostream>
#include <utilidades.h>

using namespace std;

int main()
{
    CentralDePaqueteria cp1;
    CentralDePaqueteria cp2;
    CentralDePaqueteria cp3;
    Arbol arbolGeneral;
    for(int i = 0; i<100; ++i){
        Paquete paquete;
        paquete.numeroCP = cp1.numeroCP;
        cp1.listaPaquetes.insertarNodo(paquete);
        Paquete paquete2;
        paquete2.numeroCP = cp2.numeroCP;
        cp2.listaPaquetes.insertarNodo(paquete2);
        Paquete paquete3;
        paquete3.numeroCP = cp3.numeroCP;
        cp3.listaPaquetes.insertarNodo(paquete3);
    }


    //cp1.listaPaquetes.esCabeza();
    arbolGeneral.Insertar(cp1);
    arbolGeneral.Insertar(cp2);
    arbolGeneral.Insertar(cp3);
    arbolGeneral.PreOrden(Mostrar);
/*
    while(cp1.listaPaquetes.esActual()){
        cout << cp1.listaPaquetes.valorActual().ID<<endl;
        cout << cp1.listaPaquetes.valorActual().numeroCP<<endl;
        //cout << paquete.ID<<endl;
        //cout << paquete.NIF << endl;
        cout << "------------------------" << endl;
        cp1.listaPaquetes.esSiguiente();
    }
*/
    return 0;
}
