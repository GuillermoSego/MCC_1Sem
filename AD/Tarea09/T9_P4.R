# Definimos la función
f <- function(x) {
  return(exp(-x^2))
}

# Número de muestras
n <- 10000

# Generamos números aleatorios de una distribución uniforme entre -1 y 1
samples <- runif(n, -1, 1)

# Evaluamos la función en esos números aleatorios
evaluations <- f(samples)

# Calculamos el valor medio de esas evaluaciones
mean_val <- mean(evaluations)

# Aproximación de la integral usando Monte Carlo
integral_approximation <- 2 * mean_val
print(integral_approximation)

# Número de muestras
n <- 10000

# Vector para almacenar los resultados
results <- numeric(n)

for (i in 1:n) {
  samples <- runif(i, -1, 1)
  evaluations <- f(samples)
  results[i] <- 2 * mean(evaluations)
}

plot(results, type = "l", main = "Convergencia usando distribución Uniforme", 
     xlab = "Número de muestras", ylab = "Estimación de la integral")
abline(h = integral_approximation, col = "red", lty = 2)
