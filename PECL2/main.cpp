#include <iostream>
#include <utilidades.h>
using namespace std;

int main()
{
    for(int i = 0; i<100; ++i){
        Paquete paquete;
        cout << paquete.coordenadas<<endl;
        cout << paquete.ID<<endl;
        cout << paquete.NIF << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
