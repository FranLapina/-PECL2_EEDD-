#include <iostream>
#include <utilidades.h>
#include <iomanip>
#define N1 8
#define N2 100
#define N3 12
#define N4 6*N3
using namespace std;


int main()
{
    int contadorAux = 0;
    Arbol arbolGeneral;
    for(int i = 0; i<N1; ++i){
        CentralDePaqueteria CPaux;
        arbolGeneral.Insertar(CPaux);
    }
    cout << "--------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Centrales de paqueteria generadas: ";
    arbolGeneral.InOrden(Mostrar);
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------"<<endl;

    Lista listaPaquetesInicial;
    for(int i = 0; i < N2; ++i){
        Paquete paqueteAux;
        //Aleatorizamos el numero CP que va a tener
        //Mediante una aleatorizacion de la posicion del array
        //En la cual se encuentra el numero.
        int cp_max = contadorCPs()-1;
        int cp_min = 0;
        int cp;
        cp = (cp_min + rand() % (cp_max+1 - cp_min));
        paqueteAux.numeroCP = devolverCPporPosicion(cp);
        listaPaquetesInicial.insertarNodo(paqueteAux);

    }
    //Se apunta a la cabeza de la lista.
    listaPaquetesInicial.esCabeza();
    //Bucle para introducir los primeros paquetes.
    for(int i = 0; i < N4; i=12+i){
        cout << endl <<"Pulse enter para enviar "<<N3<<" paquetes."<<endl;
        cin.ignore();
        for(int j = 0; j < N3; ++j){
            Paquete paquete = listaPaquetesInicial.valorActual();
            cout << "Paquete: "<< paquete.ID<<" --> Sera introducido en: "<< arbolGeneral.BuscarPorCp(paquete.numeroCP).localidad<<". Con un CP: "<<paquete.numeroCP<<endl;
            arbolGeneral.BuscarPorCp(paquete.numeroCP).listaPaquetes.insertarNodo(paquete);
            listaPaquetesInicial.borrarNodo(paquete);
        }
    }
    int opcion = 100;
    while(opcion != 0){
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1. Insertar una CP" <<endl;
        cout << "2. Borrar una CP" <<endl;
        cout << "3. Mostrar datos de una CP" << endl;
        cout << "4. Mostrar CPs en orden de mayor cantidad de paquetes contenidos" << endl;
        cout << "5. Buscar paquete por su ID" << endl;
        cout << "6. Extraer paquete de una CP" << endl;
        cout << "7. Llevar paquete del CAE a una CP" <<endl;
        cout << "8. Llevar paquete de una CP a otra"<< endl;
        cout << "9. Continuar con la distribucion de paquetes. Esta opcion inserta los paquetes restantes del CAE" << endl;
        cout << "10. Rellenar una lista vacia o recien creada con una cantidad de "<< N3 << " paquetes"<<endl;
        cout << "0. Salir del programa" << endl;
        cin >> opcion;
        cout << "--------------------------------------------------------------------------------" << endl;
        switch(opcion){
        case 0:
            break;
        case 1:
            {
                CentralDePaqueteria cpAux = crearCP();
                if(!arbolGeneral.Buscar(cpAux.numeroCP)){
                    arbolGeneral.Insertar(cpAux);
                }else{
                    cout << "----------------------------------------------" << endl;
                    cout << "El numero de CP ya esta asignado" << endl;
                    cout << "----------------------------------------------" << endl;
                }
                break;
            }

        case 2:
            if(arbolGeneral.NumeroNodos()>1){
                arbolGeneral.borrarUnaCP();
            }else{
                cout << "----------------------------------------------" << endl;
                cout << "No puede dejar el arbol vacio" << endl;
                cout << "----------------------------------------------" << endl;
            }
            break;
        case 3:
            cout << "Introduzca el numero de la CP a mostrar"<<endl;
            arbolGeneral.datosDeLasCP();
            int numero;
            cin >> numero;
            if(arbolGeneral.Buscar(numero)){
                arbolGeneral.mostrarDatosDeCP(numero);
            }else{
                cout << "----------------------------------------------" << endl;
                cout << "La CP no ha sido encontrada" << endl;
                cout << "----------------------------------------------" << endl;
            }
            break;
        case 4:
            cout << "------------------------------------------------------------------------" << endl;
            cout << "|" << setw(5) << "CP" << setw (5) <<"|" << setw (20) << "Nombre Ciudad" << setw(8) << "|" << setw (25) << "Cantidad de Paquetes" << setw(8) << "|" << endl;
            cout << "------------------------------------------------------------------------" << endl;
            arbolGeneral.InOrden(MostrarEstadisticas);
            break;
        case 5:
            {
                cout << "Inserte el ID del paquete a buscar (Si no hay respuesta, significa que no se encontro el paquete)" << endl;
                string ID;
                cin >> ID;
                arbolGeneral.InOrdenPaquete(MostrarDatosPaquete,NULL,true,ID);
                break;
            }

        case 6:
            {
                arbolGeneral.datosDeLasCP();
                cout << "Inserte el numero de CP de la central a mostrar"<<endl;
                int numero;
                cin >> numero;
                if(arbolGeneral.Buscar(numero))
                {
                    arbolGeneral.mostrarDatosDeCP(numero);
                    cout << "Inserte el ID del paquete a Eliminar (Si no hay respuesta, significa que no se encontro el paquete)" << endl;
                    string ID;
                    cin >> ID;
                    arbolGeneral.InOrdenPaquete(EliminarPaquete,NULL,true,ID);
                }
                else
                {
                    cout << "----------------------------------------------" << endl;
                    cout << "La CP no ha sido encontrada" << endl;
                    cout << "----------------------------------------------" << endl;
                }

                break;
            }
        case 7:
            {
                if(!listaPaquetesInicial.listaVacia()){
                    listaPaquetesInicial.MostrarPaquetesLista();
                    cout << "Seleccione uno introduciendo su ID" << endl;
                    string ID;
                    cin >> ID;
                    cout << "-------------------------------------------------------------------------" << endl;
                    cout << "Seleccione una de las siguientes Centrales introduciendo su numero de CP" << endl;
                    cout << "-------------------------------------------------------------------------" << endl;
                    arbolGeneral.datosDeLasCP();
                    int numero;
                    cin >> numero;
                    if(arbolGeneral.Buscar(numero)){
                        Lista listaAux = arbolGeneral.BuscarPorCp(numero).listaPaquetes;
                        Paquete paqueteAux = listaPaquetesInicial.BuscarPaqueteLista(ID);
                        paqueteAux.numeroCP = numero;
                        arbolGeneral.BuscarPorCp(numero).listaPaquetes.insertarNodo(paqueteAux);
                        arbolGeneral.BuscarPorCp(numero).listaPaquetes.BuscarPaqueteLista(paqueteAux.ID).ID;
                        listaPaquetesInicial.borrarNodo(paqueteAux);
                    }else{
                        cout << "----------------------------------------------" << endl;
                        cout << "El numero de CP introducido no es correcto." << endl;
                        cout << "----------------------------------------------" << endl;
                    }

                }else{
                    cout << "----------------------------------------------" << endl;
                    cout << "No hay paquetes en el CAE" << endl;
                    cout << "----------------------------------------------" << endl;
                }
                break;
            }
        case 8:
            {
                int numeroCPenv;
                int numeroCPrec;
                arbolGeneral.datosDeLasCP();
                cout << "Introduzca el numero de la CP a la cual se enviara el paquete"<<endl;
                cin >> numeroCPenv;
                if(arbolGeneral.Buscar(numeroCPenv)){
                    bool loop = false;
                    do{
                        cout << "Introduzca el numero de la CP de la cual se recogera el paquete"<<endl;
                        cin >> numeroCPrec;

                        loop = arbolGeneral.Buscar(numeroCPrec);
                        if((loop) && (numeroCPrec != numeroCPenv)){
                            string ID;
                            arbolGeneral.mostrarDatosDeCP(numeroCPrec);
                            cout << "Introduzca el ID del paquete a enviar" << endl;
                            cin >> ID;
                            Paquete paqueteAux = arbolGeneral.BuscarPorCp(numeroCPrec).listaPaquetes.BuscarPaqueteLista(ID);
                            if(paqueteAux.ID == ""){

                            }else{
                                arbolGeneral.BuscarPorCp(numeroCPrec).listaPaquetes.borrarNodo(paqueteAux);
                                paqueteAux.numeroCP = arbolGeneral.BuscarPorCp(numeroCPenv).numeroCP;
                                arbolGeneral.BuscarPorCp(numeroCPenv).listaPaquetes.insertarNodo(paqueteAux);
                                cout << "-------------------------------------------------------"<< endl;
                                cout << "Paquete insertado en: " << arbolGeneral.BuscarPorCp(numeroCPenv).localidad << ". Y eliminado de: "<<arbolGeneral.BuscarPorCp(numeroCPrec).localidad<<endl;
                                cout << "-------------------------------------------------------"<< endl;
                            }


                        }else{
                            cout << "----------------------------------------------" << endl;
                            cout << "El numero de CP introducido no es correcto o es igual a la del CP de envio." << endl;
                            cout << "----------------------------------------------" << endl;

                        }

                    }while((!loop) || (numeroCPrec == numeroCPenv));

                }else{
                    cout << "----------------------------------------------" << endl;
                    cout << "El numero de CP introducido no es correcto." << endl;
                    cout << "----------------------------------------------" << endl;
                    break;
                }

            break;

            }
        case 9:

            {
                listaPaquetesInicial.esCabeza();
                while(!listaPaquetesInicial.listaVacia()){
                    Paquete paquete = listaPaquetesInicial.valorActual();
                    cout << "Paquete: "<< paquete.ID<<" --> Sera introducido en: "
                    << arbolGeneral.BuscarPorCp(paquete.numeroCP).localidad<<". Con un CP: "<<arbolGeneral.BuscarPorCp(paquete.numeroCP).numeroCP<<endl;
                    arbolGeneral.InOrdenInsertar(InsertarPaqueteInOrden,NULL,true,paquete);
                    listaPaquetesInicial.borrarNodo(paquete);
                }
            }
            break;
        case 10:
            {
                if(getNumeroListasVacias() != 0 ){
                    arbolGeneral.InOrden(MostrarListasVacias);
                    cout<<"-----------------------------------------------------------------"<<endl;
                    cout<<"Introduce un numero de CP, al cual se le introduciran "<< N3<<" paquetes"<<endl;
                    cout<<"-----------------------------------------------------------------"<<endl;
                    int numero;
                    cin >> numero;
                    if(arbolGeneral.Buscar(numero)){
                        for(int j = 0; j < N3; ++j)
                        {
                            Paquete paquete;
                            paquete.numeroCP = arbolGeneral.BuscarPorCp(numero).numeroCP;
                            cout << "Paquete: "<< paquete.ID<<" --> Sera introducido en: "<< arbolGeneral.BuscarPorCp(paquete.numeroCP).localidad<<". Con un CP: "<<paquete.numeroCP<<endl;
                            arbolGeneral.BuscarPorCp(paquete.numeroCP).listaPaquetes.insertarNodo(paquete);
                        }

                    }else{
                        cout << "---------------------------"<<endl;
                        cout << "No existe la CP introducida" << endl;
                        cout << "---------------------------"<<endl;
                    }

                }else{
                    cout << "-----------------------"<<endl;
                    cout << "No hay listas vacias" << endl;
                    cout << "-----------------------"<<endl;
                }

            }
            break;
        default:
            break;
        }
    }
    return 0;
}
