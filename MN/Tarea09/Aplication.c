
# include <stdio.h>
# include "matrix.h"


int main() {
    double I_values[] = {0.001, 0.005, 0.010, 0.015, 0.019, 0.022};
    double V_values[] = {0.7252, 0.62625, 0.57969, 0.53438, 0.43906, 0.28125};
    int n = 6;

    double I_to_interpolate[] = {0.0075, 0.0125, 0.0175};
    double V_interpolated[3];

    for(int i = 0; i < 3; i++) {
        V_interpolated[i] = polinomioLagrange(n-1, I_values, V_values, I_to_interpolate[i]);
        printf("V(%.4lf) = %.4lf\n", I_to_interpolate[i], V_interpolated[i]);
    }

    // Ahora, guardaremos la matriz en un archivo
    double matrix[3][2];  // Una matriz para guardar las coordenadas I y V interpoladas
    for (int i = 0; i < 3; i++) {
        matrix[i][0] = I_to_interpolate[i];
        matrix[i][1] = V_interpolated[i];
    }
    saveMatrixToFile((double *)matrix, 3, 2, "interpolated_values.txt");

    return 0;
}
