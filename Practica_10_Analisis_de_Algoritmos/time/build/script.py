import pandas as pd
import matplotlib.pyplot as plt

# Cargar el archivo CSV
df = pd.read_csv('test.csv')

# Verificar las columnas
print(df.columns)

# Si es necesario, renombrar las columnas para que coincidan con el código
df.columns = df.columns.str.strip()  # Eliminar posibles espacios extra al principio y al final de los nombres de columna

# Si el nombre de las columnas de tiempo tiene alguna variación, cámbialo aquí:
df['Time (seconds) Bubble sort'] = df['Time (seconds)'].str.replace('.', '').astype(float)
df['Time (seconds) Merge sort'] = df['Time (seconds).1'].str.replace('.', '').astype(float)
df['Time (seconds) Shell sort'] = df['Time (seconds).2'].str.replace('.', '').astype(float)
df['Time (seconds) Quick sort'] = df['Time (seconds).3'].str.replace('.', '').astype(float)

# a) Comparación promedio
plt.figure(figsize=(10, 6))
plt.plot(df['Size'], df['#Comp Bubble sort'], label='Bubble sort', marker='o')
plt.plot(df['Size'], df['#Comp Merge sort'], label='Merge sort', marker='o')
plt.plot(df['Size'], df['#Comp Shell sort'], label='Shell sort', marker='o')
plt.plot(df['Size'], df['#Comp Quick sort'], label='Quick sort', marker='o')
plt.title('Número Promedio de Comparaciones vs Tamaño de la Entrada')
plt.xlabel('Tamaño de la Entrada')
plt.ylabel('Número de Comparaciones')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# b) Intercambios promedio
plt.figure(figsize=(10, 6))
plt.plot(df['Size'], df['#Swap Bubble sort'], label='Bubble sort', marker='o')
plt.plot(df['Size'], df['#Swap Merge sort'], label='Merge sort', marker='o')
plt.plot(df['Size'], df['#Swap Shell sort'], label='Shell sort', marker='o')
plt.plot(df['Size'], df['#Swap Quick sort'], label='Quick sort', marker='o')
plt.title('Número Promedio de Intercambios vs Tamaño de la Entrada')
plt.xlabel('Tamaño de la Entrada')
plt.ylabel('Número de Intercambios')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# c) Tiempo de ejecución promedio
plt.figure(figsize=(10, 6))
plt.plot(df['Size'], df['Time (seconds) Bubble sort'], label='Bubble sort', marker='o')
plt.plot(df['Size'], df['Time (seconds) Merge sort'], label='Merge sort', marker='o')
plt.plot(df['Size'], df['Time (seconds) Shell sort'], label='Shell sort', marker='o')
plt.plot(df['Size'], df['Time (seconds) Quick sort'], label='Quick sort', marker='o')
plt.title('Tiempo Promedio de Ejecución vs Tamaño de la Entrada')
plt.xlabel('Tamaño de la Entrada')
plt.ylabel('Tiempo (segundos)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# d) Rendimiento por algoritmo (Mejor, Peor, Promedio)
def plot_algorithm_performance(algorithm_name, comp_col, swap_col, time_col):
    best_comp = df[comp_col].min()
    worst_comp = df[comp_col].max()
    avg_comp = df[comp_col].mean()
    
    best_swap = df[swap_col].min()
    worst_swap = df[swap_col].max()
    avg_swap = df[swap_col].mean()
    
    best_time = df[time_col].min()
    worst_time = df[time_col].max()
    avg_time = df[time_col].mean()

    # Graficar operaciones de comparaciones
    plt.figure(figsize=(10, 6))
    plt.bar(['Best', 'Worst', 'Average'], [best_comp, worst_comp, avg_comp], color='lightblue', label='Comparaciones')
    plt.title(f'Rendimiento de {algorithm_name} - Comparaciones')
    plt.ylabel('Número de Comparaciones')
    plt.tight_layout()
    plt.show()

    # Graficar intercambios
    plt.figure(figsize=(10, 6))
    plt.bar(['Best', 'Worst', 'Average'], [best_swap, worst_swap, avg_swap], color='lightgreen', label='Intercambios')
    plt.title(f'Rendimiento de {algorithm_name} - Intercambios')
    plt.ylabel('Número de Intercambios')
    plt.tight_layout()
    plt.show()

    # Graficar tiempo de ejecución
    plt.figure(figsize=(10, 6))
    plt.bar(['Best', 'Worst', 'Average'], [best_time, worst_time, avg_time], color='lightcoral', label='Tiempo')
    plt.title(f'Rendimiento de {algorithm_name} - Tiempo de Ejecución')
    plt.ylabel('Tiempo (segundos)')
    plt.tight_layout()
    plt.show()

# Crear gráficos para cada algoritmo
plot_algorithm_performance('Bubble Sort', '#Comp Bubble sort', '#Swap Bubble sort', 'Time (seconds) Bubble sort')
plot_algorithm_performance('Merge Sort', '#Comp Merge sort', '#Swap Merge sort', 'Time (seconds) Merge sort')
plot_algorithm_performance('Shell Sort', '#Comp Shell sort', '#Swap Shell sort', 'Time (seconds) Shell sort')
plot_algorithm_performance('Quick Sort', '#Comp Quick sort', '#Swap Quick sort', 'Time (seconds) Quick sort')
