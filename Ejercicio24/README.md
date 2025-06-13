Ejercicio 24:
=============

- Comprender el uso de variables y métodos ``static`` para mantener información común a todas las instancias de una clase.
- Crear una clase ``Persona`` que tenga:

	- Un atributo ``nombre`` (tipo ``QString``).
	- Un constructor que reciba el nombre.
	- Un método ``mostrar()`` que imprima el nombre.

- Además:

	- Usar un **miembro estático** para contar cuántas personas se crearon.
	- Agregar un método estático ``totalPersonas()`` que devuelva ese valor.

- En ``main()``, crear varias instancias de ``Persona`` y mostrar cuántas personas se crearon usando el método estático.