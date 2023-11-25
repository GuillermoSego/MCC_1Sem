# Cargar bibliotecas necesarias
library(ggplot2)
library(readr)

# Leer el archivo CSV
data <- read_csv("penguins.csv")

# Eliminar filas con NA's para evitar problemas con ggplot2
data <- data[complete.cases(data), ]

# 1. Histograma de bill_length_mm
ggplot(data, aes(x=bill_length_mm)) +
  geom_histogram(binwidth=2, fill="blue", color="white", alpha=0.7) +
  labs(title="Histograma de Longitud del Pico", x="Longitud del Pico (mm)", y="Número de Pingüinos") +
  theme_minimal()

# 2. Histograma de bill_depth_mm
ggplot(data, aes(x=bill_depth_mm)) +
  geom_histogram(binwidth=1, fill="red", color="white", alpha=0.7) +
  labs(title="Histograma de Profundidad del Pico", x="Profundidad del Pico (mm)", y="Número de Pingüinos") +
  theme_minimal()

# 3. Gráfico de dispersión entre bill_length_mm y bill_depth_mm
ggplot(data, aes(x=bill_length_mm, y=bill_depth_mm)) +
  geom_point(aes(color=species), alpha=0.7) +
  labs(title="Scatter Plot de Longitud vs. Profundidad del Pico", x="Longitud del Pico (mm)", y="Profundidad del Pico (mm)") +
  theme_minimal()

# 4. Histograma de flipper_length_mm
ggplot(data, aes(x=flipper_length_mm)) +
  geom_histogram(binwidth=5, fill="green", color="white", alpha=0.7) +
  labs(title="Histograma de Longitud de Aletas", x="Longitud de Aletas (mm)", y="Número de Pingüinos") +
  theme_minimal()

# 5. Diagrama de caja de body_mass_g agrupado por sex
ggplot(data, aes(x=sex, y=body_mass_g, fill=sex)) +
  geom_boxplot(alpha=0.7) +
  labs(title="Diagrama de Caja de Masa Corporal por Sexo", x="Sexo", y="Masa Corporal (g)") +
  theme_minimal()

# 6. Gráfico de barras de species
ggplot(data, aes(x=species, fill=species)) +
  geom_bar(alpha=0.7) +
  labs(title="Distribución de Especies", x="Especie", y="Número de Pingüinos") +
  theme_minimal()

# 7. Gráfico de barras de island
ggplot(data, aes(x=island, fill=island)) +
  geom_bar(alpha=0.7) +
  labs(title="Distribución por Isla", x="Isla", y="Número de Pingüinos") +
  theme_minimal()

# Scatter plot
ggplot(data, aes(x=bill_length_mm, y=bill_depth_mm, color=species, shape=island)) +
  geom_point(alpha=0.6) +
  labs(title="bill_length_mm vs bill_depth_mm", x="Longitud del pico (mm)", y="Profundidad del pico (mm)") +
  theme_minimal()
