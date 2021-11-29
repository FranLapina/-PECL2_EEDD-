#include <iostream>
#include <utilidades.h>
using namespace std;

int main()
{
    CentralDePaqueteria cp1;
    for(int i = 0; i<100; ++i){
        Paquete paquete;
        paquete.numeroCP = cp1.numeroCP;
        cp1.listaPaquetes.insertarNodo(paquete);
    }
    cout << cp1.localidad << endl;
    cout << cp1.numeroCP << endl;
    cp1.listaPaquetes.esCabeza();
    while(cp1.listaPaquetes.esActual()){
        cout << cp1.listaPaquetes.valorActual().ID<<endl;
        cout << cp1.listaPaquetes.valorActual().numeroCP<<endl;
        //cout << paquete.ID<<endl;
        //cout << paquete.NIF << endl;
        cout << "------------------------" << endl;
        cp1.listaPaquetes.esSiguiente();
    }

    return 0;
}
