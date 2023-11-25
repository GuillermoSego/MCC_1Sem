
# Datos del problema
americano_nativo <- c(8.50, 9.48, 8.65, 8.16, 8.83, 7.76, 8.63)
caucasiano <- c(8.27, 8.20, 8.25, 8.14, 9.00, 8.10, 7.20, 8.32, 7.70)

# Calcular la diferencia absoluta de las medianas originales
diferencia_mediana_original <- abs(median(americano_nativo) - median(caucasiano))

# Combinar los datos
datos_combinados <- c(americano_nativo, caucasiano)

# Número de permutaciones
n_permutaciones <- 100000
contador <- 0

# Realizar permutaciones
for (i in 1:n_permutaciones) {
  datos_permutados <- sample(datos_combinados)
  grupo1 <- datos_permutados[1:length(americano_nativo)]
  grupo2 <- datos_permutados[(length(americano_nativo) + 1):length(datos_combinados)]
  diferencia_mediana_permutada <- abs(median(grupo1) - median(grupo2))
  
  if (diferencia_mediana_permutada >= diferencia_mediana_original) {
    contador <- contador + 1
  }
}

# Calcular el valor p
valor_p <- contador / n_permutaciones

# Imprimir el valor p
sprintf("El valor calculado de p para %d permutaciones es: %f", n_permutaciones, valor_p)


