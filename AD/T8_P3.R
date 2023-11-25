# Cargando las bibliotecas necesarias
library(MASS)
library(ggplot2)

# Establecer parámetros
mu <- c(0, 0, 0, 0)

# Definir diferentes matrices de covarianza
Sigma1 <- matrix(c(1, 0.1, 0.6, 0.5, 
                   0.1, 1, 0.7, 0.6, 
                   0.6, 0.7, 1, 0.7, 
                   0.5, 0.6, 0.7, 1), 
                 ncol=4)

Sigma2 <- matrix(c(1, 0.9, 0.6, 0.5, 
                   0.9, 1, 0.7, 0.6, 
                   0.6, 0.7, 1, 0.7, 
                   0.5, 0.6, 0.7, 1), 
                 ncol=4)


# Generar datos
set.seed(123) # Para reproducibilidad

sample_data1 <- mvrnorm(n=1000, mu=mu, Sigma=Sigma1)
df1 <- as.data.frame(sample_data1)

sample_data2 <- mvrnorm(n=1000, mu=mu, Sigma=Sigma2)
df2 <- as.data.frame(sample_data2)

# Crear gráficas
p1 <- ggplot(df1, aes(x=V1, y=V2)) +
  geom_point(aes(color=V1), alpha=0.6) +
  labs(title="Scatter plot de V1 vs V2 (Sigma1)", x="V1", y="V2") +
  theme_minimal()

p2 <- ggplot(df2, aes(x=V1, y=V2)) +
  geom_point(aes(color=V1), alpha=0.6) +
  labs(title="Scatter plot de V1 vs V2 (Sigma2)", x="V1", y="V2") +
  theme_minimal()

# Mostrar gráficas
print(p1)
print(p2)
