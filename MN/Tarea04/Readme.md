
# Tarea 4 de Métodos Numéricos

## Problema 1: Factorización de Doolittle
Se anexa un pdf con la implementación de la factorización de Doolittle a mano.

## Problema 2: Factorización de Crout

`T4_P2.c` - Este archivo contiene el código principal del programa que realiza la factorización de Crout en una matriz dada. Implementa el algoritmo de Crout para obtener las matrices \(L\) y \(U\) tales que \( A = L \times U \).

### Descripción de las funciones

- `ReadMatrix` - Esta función se encarga de leer la matriz \( A \) de un archivo de texto. El archivo debe tener una primera línea con dos números que indican las dimensiones de la matriz.

- `crout` - Esta función lleva a cabo la factorización de Crout para una matriz \( A \) dada.

- `MatrixShow` - Esta función es una rutina que imprime la matriz en la consola.

### Fallos

El algoritmo de Crout puede fallar si la matriz \( A \) tiene un elemento diagonal igual a cero durante el proceso. En este caso, el programa se detendrá inmediatamente y mostrará un mensaje de error.

## Problema 3: Método de Cholesky

- `T4_P3.c` - Este archivo contiene el código principal que realiza la descomposición de Cholesky en una matriz dada. Implementa el algoritmo de Cholesky para obtener la matriz \( L \) tal que \( A = L \times L^T \).

### Descripción de las funciones

- `cholesky` - Esta función realiza la descomposición de Cholesky para una matriz \( A \) dada. Llena la matriz \( L \) de manera que \( A = L \times L^T \). Si encuentra que la matriz no es definida positiva, devuelve -1.

- `solveCholesky` - Esta función resuelve el sistema \( Ax = b \) dado que \( A = L \times L^T \). Utiliza primero la matriz \( L \) para resolver \( Ly = b \) y luego utiliza \( L^T \) para encontrar \( x \).

### Fallos

El algoritmo de Cholesky sólo es aplicable a matrices simétricas definidas positivas. Si se intenta aplicar a una matriz que no cumpla con estas condiciones, el algoritmo fallará y el programa se detendrá inmediatamente, mostrando un mensaje de error.