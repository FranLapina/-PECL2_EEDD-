#include "utilidades.h"

using namespace std;

//Randomiza, con un maximo y un minimo, la longitud.
int definirLongitud(){
    string sec,minutos,grados;
    int sec_max = 59;
    int sec_min = 0;
    int sec_num = (sec_min + rand() % (sec_max+1 - sec_min));
    int min_max = 6;
    int min_min = 34;
    int minutos_num = (min_min + rand() % (min_max+1 - min_min));
    int grados_num = 40;
    //Si los segundos y los minutos son menores de 2 digitos
    //Añadimos un 0 a la izquierda, para que a la hora de pasar
    //a modelar el numero, sea más comodo introducir los caracteres,
    //de grado,minuto y segundo.
    if(sec_num < 10){
        sec = "0"+to_string(sec_num);
    }else{
        sec = to_string(sec_num);
    }
    if(minutos_num < 10){
        minutos = "0"+to_string(minutos_num);
    }else{
        minutos = to_string(minutos_num);
    }
    grados = to_string(grados_num);
    string longitud = grados+minutos+sec;
    return stoi(longitud);
}

//Randomiza, con un maximo y un minimo, la latitud.
int definirLatitud(){
    string sec,minutos,grados;
    int sec_max = 59;
    int sec_min = 0;
    int sec_num = (sec_min + rand() % (sec_max+1 - sec_min));
    int min_max = 5;
    int min_min = 34;
    int minutos_num = (min_min + rand() % (min_max+1 - min_min));
    int grados_num = -3;
    //Si los segundos y los minutos son menores de 2 digitos
    //Añadimos un 0 a la izquierda, para que a la hora de pasar
    //a modelar el numero, sea más comodo introducir los caracteres,
    //de grado,minuto y segundo.
    if(sec_num < 10){
        sec = "0"+to_string(sec_num);
    }else{
        sec = to_string(sec_num);
    }
    if(minutos_num < 10){
        minutos = "0"+to_string(minutos_num);
    }else{
        minutos = to_string(minutos_num);
    }
    grados = to_string(grados_num);
    string latitud = grados+minutos+sec;
    return stoi(latitud);
}

//Modela la longitud parseandola a string y colocando los numeros de la siguiente forma XXº XX' XX''
//mediante un bucle que añade espacios y caracteres en posiciones determinadas.
string modelarLongitud(int longitudNumerica){
    string longitud = to_string(longitudNumerica);
    for(int i = 0; i <= 11; ++i){
        if(i == 3 || i == 7){
            longitud.insert(i," ");
        }else if(i == 2){
            longitud.insert(i,"*"); //al poner el caracter de los grados, sale otra cosa.
        }else if(i == 6 || i == 10 || i == 11){
            longitud.insert(i,"'");
        }
    }
    return longitud;


}
//Modela la latitud parseandola a string y colocando los numeros de la siguiente forma XXº XX' XX''
//mediante un bucle que añade espacios y caracteres en posiciones determinadas.
string modelarLatitud(int latitudNumerica){
    string latitud = to_string(latitudNumerica);
    for(int i = 0; i <= 11; ++i){
        if(i == 3 || i == 7){
            latitud.insert(i," ");
        }else if(i == 2){
            latitud.insert(i,"*"); //al poner el caracter de los grados, sale otra cosa.
        }else if(i == 6 || i == 10 || i == 11){
            latitud.insert(i,"'");
        }
    }
    return latitud;
}
//Genera los números del ID con un random que va de 0 a 999999
//No es necesario pasarlo a el header.
int generarNumerosID(){
    int maximo = 999999;
    int minimo = 0;
    int numerosID;
    numerosID = (minimo + rand() % (maximo+1 - minimo));
    return numerosID;
}
//Modela el ID introduciendo 0 a la izquierda en caso de que no cumpla el requisito de 6 cifras numericas
//Y en la posicion 2 introduce una letra generada con un random como 65 de minimo y 90 de maximo que
//acapara las mayusculas a nivel numerico dentro de la tabla ascii y las introduce.
string modelarID(){
    //Usamos generarNumerosID.
    string numerosID = to_string(generarNumerosID());
    while(numerosID.length() < 6){
        numerosID = "0"+numerosID;
    }
    int maximo = 90;
    int minimo = 65;
    std::string letraID;
    letraID = (minimo + rand() % (maximo+1 - minimo));
    numerosID.insert(2, letraID);
    return numerosID;
}
//Genera de forma aleatoria numeros del 100 al 99999999
int generarNumerosNIF(){
        //Para generar NIFs relativamente
        //Realistas
        int maximo = 59000000;
        int minimo = 51000000;
        int numerosNIF;
        numerosNIF = (minimo + rand() % (maximo+1 - minimo));
        return numerosNIF;
}
//parsea el numero a string y completa el NIF añadiendole la letra que le corresponderia para los numeros que tiene
//Y si no llega a 9 digitos (letra incluida) añade 0s a la izquierda hasta completarlo.
string modelarNIF(){
    int numerosNIF = generarNumerosNIF();
    char letras[] = {'T','R','W','A','G','M','Y',
            'F','P','D','X','B','N','J','Z','S',
            'Q','V','H','L','C','K','E'};
    string NIFCompleto;
    int posicion = numerosNIF%23;
    NIFCompleto = to_string(numerosNIF);
    NIFCompleto = NIFCompleto+letras[posicion];
    //Comprobar si el NIF tiene un tamaño de 9 caracteres, si no lo tiene se añaden 0s a la izquierda.
    if(NIFCompleto.length() < 9){
        int exceso = 9 - NIFCompleto.length();
        for(int i = 0; i < exceso; ++i){
            NIFCompleto = "0"+NIFCompleto;
        }
    }
    return NIFCompleto;
}
Lista::~Lista()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodo(Paquete v)
{
    pnodo aux;
    if (listaVacia())
    {
        cabeza = new Nodo(v, NULL);
        final=cabeza;
    }
    else
    {
        aux= new Nodo(v,NULL);
        final->siguiente=aux;
        final=aux;
    }
}
void Lista::borrarNodo(Paquete v)
{
    pnodo anterior;
    actual = cabeza;
    while (actual->valor.ID!=v.ID && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza) // Primer elemento
        cabeza = actual->siguiente;
    else
    {
        anterior->siguiente = actual->siguiente;
        if(actual==final) final=anterior;
    }
    actual->siguiente=NULL;
    delete actual;
}
bool Lista::listaVacia()
{
    return cabeza == NULL;
}
void Lista::esCabeza()
{
    actual = cabeza;
}
void Lista::esFinal()
{
    esCabeza();
    if(!listaVacia()) // Más sencillo
        while(actual->siguiente) // actual = final;
            esSiguiente();
}
void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}
bool Lista::esActual()
{
    return actual != NULL;
}
Paquete Lista::valorActual()
{
    return actual->valor;
}
string definirCiudad(int p){
    string ciudades[8] = {"Daganzo","Alcala","Mejorada","Nuevo Baztan","Arganda","Carabana","Chinchon","Villarejo"};
    ++p;
    if(p-1 > 7){
        return "";
    }else{
        return ciudades[p-1];
    }
}

int generarCP(){
    int cp_max = 999;
    int cp_min = 100;
    int cp;
    cp = (cp_min + rand() % (cp_max+1 - cp_min));
    return cp;
}

/*
void Lista::recorrerLista()
{
    pnodo aux;
    aux = cabeza;
    while(aux)
    {
        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}*/

