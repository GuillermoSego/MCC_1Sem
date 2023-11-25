# Librerías requeridas
library(ggplot2)

# Datos
sample_data <- c(1.2, 0.75, -0.39, -0.01, 0.51)
n <- length(sample_data)

# Función de log-verosimilitud
log_likelihood_function <- function(theta) {
  -(n/2) * log(2 * pi) - (n/2) * log(theta^2) - sum(sample_data^2) / (2 * theta^2)
}

# Función de verosimilitud
likelihood_function <- function(theta) {
  exp(log_likelihood_function(theta))
}

# Generamos valores para theta en un rango
theta_values <- seq(0.1, 2, length.out = 1000)
log_likelihood_values <- sapply(theta_values, log_likelihood_function)
likelihood_values <- sapply(theta_values, likelihood_function)

# Gráfica de Log-likelihood
df_log <- data.frame(theta = theta_values, likelihood = log_likelihood_values)
ggplot(df_log, aes(x = theta, y = likelihood)) + 
  geom_line() +
  labs(title = "Logaritmo de la Función de Verosimilitud l(θ)", x = "θ", y = "l(θ)")

# Gráfica de Likelihood
df <- data.frame(theta = theta_values, likelihood = likelihood_values)
ggplot(df, aes(x = theta, y = likelihood)) + 
  geom_line() +
  labs(title = "Función de Verosimilitud L(θ)", x = "θ", y = "L(θ)")
