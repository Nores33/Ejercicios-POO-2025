Ejercicio 8:
============

- Tener disponible un endpoint con FastAPI para validar usuarios.
- Registrar en MySQL algunos usuarios en una tabla con campos como: nombre, apellido, usuario, clave, mail
- Desarrollar un login en Qt que permita loguearse mediante una solicitud HTTP POST a una endpoint de FastAPI enviando las credenciales en el cuerpo de la petición.
- Si las credenciales son válidas, el servidor devolverá un token JWT en la respuesta.
- El token debe almacenarse en memoria durante el uso de la aplicación Qt y utilizarse en las siguientes peticiones HTTP como Authorization: Bearer <token>.