# Tarea 12 - Métodos numéricos

En este readme se indica como es la compilación y ejecución, además de la estrucutra de los archivos que conforman la tarea 12.

## Requisitos

- GCC o cualquier otro compilador compatible.
- Herramientas estándar de Unix/Linux para compilar y ejecutar.

## Compilación

Para compilar los programas, se ha proporcionado un archivo `Makefile`. El makefile, automáticamente crea las carpetas `build/` necesaria para almacenar los ejecutables de los programas. Para correrse, simplemente ejecute el siguiente comando en la terminal.

```
make
```

Esto generará los archivos binarios necesarios en la carpeta `build/Debug/`. **Nota**: Cabe aclarar que para cambiar entre ambos archivos, hay que modificar las lineas del archivo makefile que digan Minimus2n (por ejemplo si se quiere ejecutar el problema 1) a **Minimus2n.o**.

NOTA: En esta tarea se utilizan dos librerias, por lo que si se quire utilizar una u otra libreria hay que cambiarla. 

## Ejecución

Una vez compilado el programa, se puede ejecutar de la siguiente manera:

```
./build/Debug/Broyden
```