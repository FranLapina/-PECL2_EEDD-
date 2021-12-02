#include "arboles.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


int main()
{
   // Un árbol de enteros
   Arbol arbolInt;

      srand(time(NULL));

     // generarArbol(arbolInt);


   // Inserción de nodos en árbol:

//Árbol no equilibrado de altura 5 (0, 1, 2, 3, 4, 5)
//   arbolInt.Insertar(10);
//   arbolInt.Insertar(5);
//   arbolInt.Insertar(12);
//   arbolInt.Insertar(4);
//   arbolInt.Insertar(7);
//   arbolInt.Insertar(3);
//   arbolInt.Insertar(6);
//   arbolInt.Insertar(9);
//   arbolInt.Insertar(8);
//   arbolInt.Insertar(11);
//   arbolInt.Insertar(14);
//   arbolInt.Insertar(13);
//   arbolInt.Insertar(2);
//   arbolInt.Insertar(1);
//   arbolInt.Insertar(15);
//   arbolInt.Insertar(10);
//   arbolInt.Insertar(17);
//   arbolInt.Insertar(18);
//   arbolInt.Insertar(16);

// Arbol totalmente equilibrado de altura 2 (0, 1, 2)
//   arbolInt.Insertar(4);
//   arbolInt.Insertar(2);
//   arbolInt.Insertar(6);
//   arbolInt.Insertar(1);
//   arbolInt.Insertar(3);
//   arbolInt.Insertar(5);
//   arbolInt.Insertar(7);


// Arbol totalmente equilibrado de altura 3 (0, 1, 2, 3)
   arbolInt.Insertar(1);

   arbolInt.Insertar(2);
   arbolInt.Insertar(3);
   arbolInt.Insertar(4);
   arbolInt.Insertar(5);
   arbolInt.Insertar(6);
   arbolInt.Insertar(7);
   arbolInt.Insertar(8);

   arbolInt.Insertar(9);
   arbolInt.Insertar(10);
   arbolInt.Insertar(11);
   arbolInt.Insertar(12);
   arbolInt.Insertar(13);
   arbolInt.Insertar(14);
   arbolInt.Insertar(15);



//Árbol degenerado
//   arbolInt.Insertar(6);
//   arbolInt.Insertar(7);
//   arbolInt.Insertar(8);
//   arbolInt.Insertar(9);
//   arbolInt.Insertar(10);
//   arbolInt.Insertar(11);
//   arbolInt.Insertar(12);

   cout << "Altura de arbol " << arbolInt.AlturaArbol() << endl;

   // Mostrar el árbol en tres ordenes distintos:
   cout << "InOrden: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   arbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   arbolInt.PostOrden(Mostrar);
   cout << endl;
   cout << "Altura de 10 " << arbolInt.Altura(10) << endl;

   // Borraremos algunos elementos:
   cout << "N nodos: " << arbolInt.NumeroNodos() << endl;
   arbolInt.Borrar(5);
   cout << "Borrar   5: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;
   arbolInt.Borrar(8);
   cout << "Borrar   8: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;
   arbolInt.Borrar(1);
   cout << "Borrar  15: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;
   arbolInt.Borrar(2);
   cout << "Borrar 245: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;
   arbolInt.Borrar(4);
   cout << "Borrar   4: ";
   arbolInt.InOrden(Mostrar);
   arbolInt.Borrar(11);
   cout << endl;
   cout << "Borrar  17: ";
   arbolInt.InOrden(Mostrar);
   cout << endl;

   // Veamos algunos parámetros
   cout << "N nodos: " << arbolInt.NumeroNodos() << endl;
   cout << "Altura de 10 " << arbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << arbolInt.AlturaArbol() << endl;

   //cin.get();
   return 0;
}
