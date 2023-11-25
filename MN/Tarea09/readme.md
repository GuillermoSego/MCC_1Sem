# Tarea 9 - Métodos numéricos

En este readme se indica como es la compilación y ejecución, además de la estrucutra de los archivos que conforman la tarea 9.

## Requisitos

- GCC o cualquier otro compilador compatible.
- Herramientas estándar de Unix/Linux para compilar y ejecutar.

## Compilación

Para compilar los programas, se ha proporcionado un archivo `Makefile`. El makefile, automáticamente crea las carpetas `build/` necesaria para almacenar los ejecutables de los programas. Para correrse, simplemente ejecute el siguiente comando en la terminal.

```
make
```

Esto generará los archivos binarios necesarios en la carpeta `build/Debug/`. **Nota**: Cabe aclarar que para cambiar entre ambos archivos, hay que modificar las lineas del archivo makefile que digan QR (por ejemplo si se quiere ejecutar el problema 1) a **P_lagrange.o**.

Para los programas *Taylor_a* y *Taylor_b* basta simplemente con compilarlos utilizando el compilador gcc. Para todos los demas es necesario utilizar el `Makefile`.

```
gcc Taylor_a.c -o Taylor_a
```

## Ejecución

Una vez compilado el programa, se puede ejecutar de la siguiente manera:

```
./build/Debug/P_lagrange
```

Para los programas *Taylor_a* y *Taylor_b* no es necesario ejecutarlos desde la carpeta ´Debug´, simplemente ejecutar el ejecutable que se generó de la compilación.

```
./Taylor_a
```