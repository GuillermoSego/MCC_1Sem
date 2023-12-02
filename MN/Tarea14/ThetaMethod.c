
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

// Función para el lado derecho de la EDP. Devuelve 0 ya que la difusión
// se maneja a través de la discretización espacial.
double f(double x, double t) {
    // Si hubiera un término fuente adicional, se calcularía aquí.
    return 0.0;
}

// Define la función para la condición inicial u(x, 0) = 4x - 4x^2
double u0(double x) {
    return 4 * x - 4 * x * x;
}

// Método theta para ecuaciones diferenciales
void thetaMethod(double I[], int n[], double bc[], double nu, double theta, double *u, double *x) {
    
    // Paso 1: Inicialización de Parámetros y Espacio-Tiempo
    int nx = n[0];
    double h = (I[1] - I[0]) / nx;

    // Inicializar x con tamaño nx + 1
    linspace(x, I[0], I[1], nx + 1);

    // Inicializar uold con la condición inicial u0
    double* uold = malloc(sizeof(double) * (nx + 1));
    for (int i = 0; i <= nx; i++) {
        double xi = I[0] + i * h; // Calcula el valor actual de x
        uold[i] = u0(xi);         // Asigna el valor de u0 en ese punto
    }

    // Paso 2: Inicialización del Tiempo y Definición de Matrices
    int nt = n[1];
    double k = (I[3] - I[2]) / nt;
    
    // Definir e
    double* e = malloc(sizeof(double) * (nx + 1)); 
    Ones(e, nx + 1); // Arreglo de unos
    
    // Definir K y B
    double** K = createMatrix(nx + 1, nx + 1);
    double** B = createMatrix(nx + 1, nx + 1);

    // Tridiagonalización de las matrices K y B
    tridiagonalMatrix(K, nx + 1, (-nu * theta / h), (2 * nu * theta / h + h / k), (-nu * theta / h));
    tridiagonalMatrix(B, nx + 1, (nu * (1 - theta) / h), (-2 * nu * (1 - theta) / h + h / k), (nu * (1 - theta) / h));

    // Paso 3: Aplicación de Condiciones de Frontera
    // Modificar K para condiciones de frontera de Dirichlet
    K[0][0] = 1.0; K[0][1] = 0.0;  // Primera fila
    K[nx][nx] = 1.0; K[nx][nx - 1] = 0.0;  // Última fila

    // Paso 4: Factorización LU de K
    double *KFlat = FlattenMatrix(K, nx + 1, nx + 1);
    double* L = malloc(sizeof(double) * (nx + 1) * (nx + 1)); 
    double* U = malloc(sizeof(double) * (nx + 1) * (nx + 1)); 
    crout(KFlat, L, U, nx + 1);

    // Crear una matriz para almacenar los resultados en cada paso de tiempo
    double **u_matrix = createMatrix(nt, nx + 1);


    // Paso 5: Bucle Temporal para Resolver la Ecuación
    for (int timeStep = 1; timeStep <= nt; ++timeStep) {
        double t = I[2] + timeStep * k; // Calcula el tiempo actual

        // Calcular fnew y fold
        double* fnew = malloc(sizeof(double) * (nx + 1));
        double* fold = malloc(sizeof(double) * (nx + 1));
        for (int i = 0; i <= nx; i++) {
            double xi = I[0] + i * h;
            fnew[i] = h * f(xi, t); // fnew = h*f(x, t actual)
            fold[i] = h * f(xi, t - k); // fold = h*f(x, t anterior)
        }

        // Aplicar condiciones de frontera
        fnew[0] = bc[0];
        fnew[nx] = bc[1];
        fold[0] = bc[0];
        fold[nx] = bc[1];

        // Calcular el lado derecho del sistema
        double* b = malloc(sizeof(double) * (nx + 1));
        for (int i = 0; i <= nx; i++) {
            b[i] = theta * fnew[i] + (1 - theta) * fold[i];
        }

        // Aplanar la matriz B
        double* BFlat = FlattenMatrix(B, nx + 1, nx + 1);

        // Multiplicar B*uold y sumarlo a b
        double* Buold = (double *)malloc((nx + 1) * sizeof(double));
        MatrixProduct(BFlat, uold, Buold, nx + 1, nx + 1, 1);

        for (int i = 0; i <= nx; i++) {
            b[i] += Buold[i];
        }

        // Aplicar condiciones de frontera en b
        b[0] = 0.0;  // Condición de frontera en x = 0
        b[nx] = 0.0;  // Condición de frontera en x = 1

        // Resolver el sistema lineal para obtener la solución temporal
        double* y = malloc(sizeof(double) * (nx + 1));
        solveLowerTriangular(L, b, y, nx + 1); // Solucionamos Ly = b
        solveUpperTriangular(U, y, uold, nx + 1); // Solucionamos Uu = y

        // Guardar los valores actuales de u en u_matrix
        for (int i = 0; i <= nx; i++) {
            u_matrix[timeStep - 1][i] = uold[i];
        }

        // Liberar la memoria temporal
        free(y);
        free(b);
        free(Buold);
        free(BFlat);
        free(fnew);
        free(fold);
    }

    // Paso 6: Salida de la Solución y los Puntos Espaciales
    for (int i = 0; i <= nx; i++) {
        u[i] = uold[i]; // Asignar la solución final a u
    }

    // Aplanar la matriz de resultados
    double *flat_u_matrix = FlattenMatrix(u_matrix, nt, nx + 1);

    // Guardar la matriz aplanada en un archivo
    const char *filename = "output.txt";
    saveMatrixToFile(flat_u_matrix, nt, nx + 1, filename);

    // Liberar la memoria
    free(flat_u_matrix);
    freeMatrix(u_matrix, nt);
    free(uold);
    free(e);
    freeMatrix(B, nx + 1);
    freeMatrix(K, nx + 1);
    free(KFlat);
    free(L);
    free(U);
}

int main() {
    // Definir los límites espaciales y temporales, [0, 1] y [0, 0.4]
    double I[4] = {0, 1, 0, 0.4};

    // Definir el número de pasos en el espacio y el tiempo
    int n[2] = {100, 100}; 

    // Definir el valor de theta
    double theta = 0.5; // Método de Crank-Nicolson (theta)

    // Definir el valor de nu (coeficiente de difusión, conductividad térmica, etc.)
    double nu = 1.0;

    // Definir las condiciones de frontera de Dirichlet
    double bc[2] = {0.0, 0.0}; // Condición de frontera en ambos extremos

    // Definir arrays para la solución y los puntos espaciales
    double *x = malloc(sizeof(double) * (n[0] + 1));
    double *u = malloc(sizeof(double) * (n[0] + 1));

    // Llamar al método de theta
    thetaMethod(I, n, bc, nu, theta, u, x);

    // Liberar memoria
    free(u);
    free(x);

    return 0;
}