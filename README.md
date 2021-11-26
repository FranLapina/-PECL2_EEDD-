# -PECL2_EEDD-
Segunda practica de EEDD

Si no lo he entendido mal, hay que generar 100 paquetes.

Solo hay que centrarse en la zona este.

La central de paqueteria (ID_central, Localidad, Lista Paquetes)

Hacer un arbol en el que se almacenen centrales de paqueteria

En principio son 8 centrales, una por localidad pero hay opcion de ampliarlo al doble, dos por localidad.

Lo que quiere decir(Asi lo interpreto yo) que va a haber 8 ID de centrales diferentes, aunque si lo ampliamos serian 16

Y cada una va a pertenecer a una localidad diferente.

Una mejora posible seria cuadrar las coordenadas generadas con la localidad a la que van, creo que es mas o menos sencillo limitar las coordenadas

En caso de boorar una central que aun tenga paquetes pendientes de enviar, habria que habilitar un mecanismo que permita distribuir esos paquetes

Para asignar una lista a una central, con punteros, que este la lista a parte pero que pueda tener acceso a ella.

Otra mejora podria ser generar un txt del arbol binario.
