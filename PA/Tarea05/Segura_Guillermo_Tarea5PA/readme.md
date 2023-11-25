# Tarea 5 - Programación y algoritmos

En este readme se indica como es la compilación y ejecución, además de la estrucutra de los archivos que conforman la tarea 5.

## Requisitos

- GCC o cualquier otro compilador compatible.
- Herramientas estándar de Unix/Linux para compilar y ejecutar.

## Compilación

Para compilar los programas, se ha proporcionado un archivo `Makefile`. El makefile, automáticamente crea las carpetas `build/` necesaria para almacenar los ejecutables de los programas. Para correrse, simplemente ejecute el siguiente comando en la terminal.

```
make
```

Esto generará los archivos binarios necesarios en la carpeta `build/Debug/`. **Nota**: Cabe aclarar que para cambiar entre ambos archivos, hay que modificar las lineas del archivo makefile que digan P2_T6 (por ejemplo si se quiere ejecutar el problema 1) a **T5_P3.o**.

## Ejecución

Una vez compilado el programa, se puede ejecutar de la siguiente manera:

```
./build/Debug/P1_T6
```