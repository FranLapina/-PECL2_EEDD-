#include "utilidades.h"
#include <iostream>
#include <iomanip>

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
        ++cantidadPaquetes;
    }
    else
    {

        aux= new Nodo(v,NULL);
        final->siguiente=aux;
        final=aux;
        ++cantidadPaquetes;
    }
}
void Lista::borrarNodo(Paquete v)
{
    pnodo anterior;
    actual = cabeza;
    while ((actual->valor.ID != v.ID) && (actual->siguiente != NULL))
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
    --cantidadPaquetes;
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
bool Lista::listaRecorrida(){
    if(actual == NULL && actual != cabeza){
        return true;
    }
    return false;
}

string definirCiudad(){
    string ciudades[8] = {"Daganzo","Alcala","Mejorada","Nuevo Baztan","Arganda","Carabana","Chinchon","Villarejo"};
    ++cpContador;
    if(cpContador-1 > 7){
        return "";
    }else{
        return ciudades[cpContador-1];
    }
}

int generarCP(){
    int cp_max = 999;
    int cp_min = 100;
    int cp;
    cp = (cp_min + rand() % (cp_max+1 - cp_min));
    //Se guarda el CP generado en un array de CPs.
    arrayCPs[cpContador] = cp;
    return cp;
}


//------------ARBOL------------------

// Poda: borrar todos los nodos a partir de uno, incluido
void Arbol::Podar(pNodo &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void Arbol::Insertar(CentralDePaqueteria dat)
{
   pNodo padre = NULL;
   actual = raiz;
  // Buscar el Central de paqueteria en el árbol, si está vacio y si el numero
   //de CP actual esta en la cabeza del arbol
   while(!Vacio(actual) && (dat.numeroCP  != actual->dato.numeroCP)) {
      padre = actual;
      //Si el numero de CP es mayor que el actual va a la derecha, en caso
      //Contrario va a la izquierda
      if(dat.numeroCP > actual->dato.numeroCP) actual = actual->derecho;
      else if(dat.numeroCP < actual->dato.numeroCP) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat.numeroCP < padre->dato.numeroCP) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat.numeroCP > padre->dato.numeroCP) padre->derecho = new NodoArbol(dat);

}

// Eliminar un elemento de un árbol ABB
void Arbol::Borrar(CentralDePaqueteria dat)
{
   pNodo padre = NULL;
   pNodo nodo;
   CentralDePaqueteria aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat.numeroCP == actual->dato.numeroCP) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat.numeroCP > actual->dato.numeroCP) actual = actual->derecho;
         else if(dat.numeroCP < actual->dato.numeroCP) actual = actual->izquierdo;
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::InOrden(void (*func)(CentralDePaqueteria&) , pNodo nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}
void Arbol::InOrdenPaquete(void (*func)(CentralDePaqueteria&, string ID) , pNodo nodo, bool r, string ID)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrdenPaquete(func, nodo->izquierdo, false, ID);
   func(nodo->dato, ID);
   if(nodo->derecho) InOrdenPaquete(func, nodo->derecho, false, ID);
}
// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::PreOrden(void (*func)(CentralDePaqueteria&), pNodo nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void Arbol::PostOrden(void (*func)(CentralDePaqueteria&), pNodo nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el árbol por su id.
CentralDePaqueteria& Arbol::BuscarPorCp(int numeroCP)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(numeroCP == actual->dato.numeroCP){
        return actual->dato; // int encontrado
      }else if(numeroCP > actual->dato.numeroCP){
        actual = actual->derecho; // Seguir
      }else if(numeroCP < actual->dato.numeroCP){
        actual = actual->izquierdo;
      }
   }
   return raiz->dato;
}
bool Arbol::Buscar(int numeroCP)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(numeroCP == actual->dato.numeroCP) return true; // int encontrado
      else if(numeroCP > actual->dato.numeroCP) actual = actual->derecho; // Seguir
      else if(numeroCP < actual->dato.numeroCP) actual = actual->izquierdo;
   }
   return false;
}
// Calcular la altura del nodo que contiene el int dat
int Arbol::Altura(CentralDePaqueteria dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat.numeroCP == actual->dato.numeroCP) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat.numeroCP > actual->dato.numeroCP) actual = actual->derecho;
         else if(dat.numeroCP < actual->dato.numeroCP) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int Arbol::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void Arbol::auxContador(pNodo nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int Arbol::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void Arbol::auxAltura(pNodo nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

void Arbol::mostrarDatosDeCP(int numero){
    if(!BuscarPorCp(numero).listaPaquetes.listaVacia()){
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "|" << setw (14) << "Identificador" << setw (4) << "|" << setw (23) << "Coordenadas" << setw (14)
        << "|" << setw (12) << "NIF" << setw (10) << "|" <<endl;
        cout << "------------------------------------------------------------------------------" << endl;

        BuscarPorCp(numero).listaPaquetes.esCabeza();
        while(!BuscarPorCp(numero).listaPaquetes.listaRecorrida()){
            Paquete paqueteAux = BuscarPorCp(numero).listaPaquetes.valorActual();
            cout << "|" << setw (14) << paqueteAux.ID << setw (4) << "|" << setw (23) << paqueteAux.coordenadas << setw (10)
            << "|" << setw (12) << paqueteAux.NIF << setw (10) << "|" <<endl;

            BuscarPorCp(numero).listaPaquetes.esSiguiente();
        }
        cout << "------------------------------------------------------------------------------" << endl;
    }else{
        cout << "----------------------------------------------" << endl;
        cout << "La CP esta vacia" << endl;
        cout << "----------------------------------------------" << endl;
    }
}

// Función mostrar el contenido de los nodos del árbol
void Mostrar(CentralDePaqueteria &d)
{
   cout << d.localidad << ",";

}
void MostrarNumeroYLocalidad(CentralDePaqueteria &d)
{
   cout <<"Localidad: "<<d.localidad<<"--> Numero: "<< d.numeroCP << endl;
}
void MostrarDatosPaquete(CentralDePaqueteria &d, string ID){
    d.listaPaquetes.esCabeza();
    while(!d.listaPaquetes.listaRecorrida()){

        if(d.listaPaquetes.valorActual().ID == ID){

            cout << "-----------------------------------------------------"<<endl;
            cout << "El paquete se encuentra en la localidad: " << d.localidad << endl;
            cout << "El numero de CP es: "<< d.numeroCP << endl;
            cout << "El id del paquete es: "<< ID << endl;
            cout << "Las coordenadas del paquete son: " << d.listaPaquetes.valorActual().coordenadas <<endl;
            cout << "El NIF del comprador es: " << d.listaPaquetes.valorActual().NIF <<endl;
            cout << "-----------------------------------------------------"<<endl;
            break;
        }else d.listaPaquetes.esSiguiente();
    }

}
void EliminarPaquete(CentralDePaqueteria &d, string ID){
    d.listaPaquetes.esCabeza();
    while(!d.listaPaquetes.listaRecorrida()){

        if(d.listaPaquetes.valorActual().ID == ID){
            cout << "-----------------------------------------------------"<<endl;
            cout << "Se procedera a la eliminacion del paquete: "<< ID <<endl;
            cout << "-----------------------------------------------------"<<endl;
            d.listaPaquetes.borrarNodo(d.listaPaquetes.valorActual());
            break;
        }else d.listaPaquetes.esSiguiente();
    }

}

Paquete Lista::BuscarPaqueteLista(string ID){
    esCabeza();
    while(!listaRecorrida()){
        if(valorActual().ID == ID){
            return valorActual();
        }
        esSiguiente();
    }
    cout << "-----------------------------------" << endl;
    cout << "No se ha encontrado el paquete" << endl;
    cout << "-----------------------------------" << endl;
    Paquete paqueteAux;
    paqueteAux.ID = "";
    return paqueteAux;

}
void MostrarEstadisticas(CentralDePaqueteria &d)
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << "|" << setw(5) << d.numeroCP << setw(5) << "|" << setw(20) << d.localidad
    << setw(8) << "|" << setw(15) << d.listaPaquetes.cantidadPaquetes << setw(18) << "|" <<endl;
    cout << "------------------------------------------------------------------------" << endl;

}

//Devuelve la cantidad de CPs que hay.
int contadorCPs(){
    return cpContador;
}
//Devuelve el numero de un CP en una posicion especifica dentro de un array donde estan guardados los numeros CP.
int devolverCPporPosicion(int p){
    return arrayCPs[p];
}

CentralDePaqueteria crearCP(){
    string localidad;
    int numeroCP;
    CentralDePaqueteria centralPaqueteria;
    cout << "Introduzca el nombre de la Central de Paqueteria" << endl;
    cin >> localidad;
    cout << "Introduzca el numero de la central de paqueteria" << endl;
    cin >> numeroCP;
    centralPaqueteria.localidad = localidad;
    centralPaqueteria.numeroCP = numeroCP;
    arrayCPs[cpContador] = numeroCP;
    ++cpContador;
    return centralPaqueteria;
}
void Arbol::borrarUnaCP(){
    cout << "Escriba el numero de la CP a borrar: " << endl;
    datosDeLasCP();
    int numero;
    cin >> numero;
    if(Buscar(numero)){
        BuscarPorCp(numero).listaPaquetes.~Lista();
        Borrar(BuscarPorCp(numero));
    }else{
        cout << "----------------------------------------------" << endl;
        cout << "La CP no ha sido encontrada" << endl;
        cout << "----------------------------------------------" << endl;

    }
}
void Arbol::datosDeLasCP(){
    cout << "----------------------------------------------" << endl;
    InOrden(MostrarNumeroYLocalidad);
    cout << "----------------------------------------------" << endl;
    cout << endl;
}


void Paquete::mostrarDatosPaquete(){
    cout << ID <<"|" << setw (14) << coordenadas <<"|" << setw (14) << NIF<< endl;
}


void Lista::MostrarPaquetesLista(){
    esCabeza();
    while(!listaRecorrida()){
        cout << "-----------------------------------------------------"<<endl;
        cout << "El id del paquete es: "<< valorActual().ID << endl;
        cout << "Las coordenadas del paquete son: " << valorActual().coordenadas <<endl;
        cout << "El NIF del comprador es: " << valorActual().NIF <<endl;
        cout << "-----------------------------------------------------"<<endl;

        esSiguiente();

    }
    esFinal();
    cout << valorActual().ID << endl;

}
