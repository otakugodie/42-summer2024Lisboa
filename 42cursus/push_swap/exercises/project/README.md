# Push_swap

Este proyecto implementa un algoritmo eficiente para ordenar una pila de enteros utilizando un conjunto limitado de operaciones y una pila auxiliar.

## Descripción

El objetivo de `push_swap` es ordenar una pila de enteros (stack a) en orden ascendente utilizando el menor número de operaciones posible. Para ello, se puede usar una segunda pila auxiliar (stack b) y un conjunto específico de operaciones.

## Operaciones Disponibles

- **sa**: Intercambia los dos primeros elementos del stack a
- **sb**: Intercambia los dos primeros elementos del stack b
- **ss**: Ejecuta sa y sb simultáneamente
- **pa**: Mueve el primer elemento de stack b al top de stack a
- **pb**: Mueve el primer elemento de stack a al top de stack b
- **ra**: Rota stack a hacia arriba (primer elemento se convierte en último)
- **rb**: Rota stack b hacia arriba
- **rr**: Ejecuta ra y rb simultáneamente
- **rra**: Rota stack a hacia abajo (último elemento se convierte en primero)
- **rrb**: Rota stack b hacia abajo
- **rrr**: Ejecuta rra y rrb simultáneamente

## Compilación

```bash
make
```

## Uso

```bash
./push_swap [lista de números enteros]
```

### Ejemplos

```bash
# Ordenar 3 números
./push_swap 2 1 3

# Ordenar 5 números
./push_swap 5 4 3 2 1

# Con números ya ordenados (no imprime nada)
./push_swap 1 2 3 4 5
```

## Algoritmo

El programa utiliza diferentes estrategias según el tamaño del stack:

- **2 elementos**: Una operación swap si es necesario
- **3 elementos**: Algoritmo específico optimizado
- **4-5 elementos**: Algoritmos simples que mueven elementos pequeños
- **Más de 5 elementos**: Algoritmo complejo basado en el "costo más barato"

### Algoritmo Complejo

Para stacks grandes, el programa:

1. Mueve aproximadamente la mitad de los elementos más pequeños a stack b
2. Ordena los 3 elementos restantes en stack a
3. Para cada elemento en stack b, calcula el costo de moverlo a su posición correcta
4. Ejecuta el movimiento más barato
5. Finalmente, rota stack a para que el elemento más pequeño esté en el top

## Gestión de Errores

El programa maneja los siguientes casos de error:

- Argumentos no numéricos
- Números duplicados
- Números fuera del rango de enteros
- Sin argumentos

En caso de error, imprime "Error" en stderr y termina con código de salida 1.

## Estructura del Proyecto

```
push_swap/
├── push_swap.h              # Header principal
├── main.c                   # Función principal
├── validation.c             # Validación de entrada
├── stack_operations.c       # Operaciones básicas de stack
├── stack_operations2.c      # Operaciones adicionales de stack
├── operations_swap.c        # Operaciones sa, sb, ss
├── operations_push.c        # Operaciones pa, pb
├── operations_rotate.c      # Operaciones ra, rb, rr
├── operations_reverse_rotate.c # Operaciones rra, rrb, rrr
├── simple_sort.c           # Algoritmos para 3-5 elementos
├── complex_sort.c          # Algoritmo para stacks grandes
├── position.c              # Cálculo de posiciones
├── cost.c                  # Cálculo de costos
├── moves.c                 # Ejecución de movimientos
├── moves2.c                # Movimientos adicionales
├── utils.c                 # Funciones auxiliares
└── Makefile                # Archivo de compilación
```

## Optimización

El algoritmo está optimizado para cumplir con los siguientes benchmarks:

- **100 números**: ≤ 700 operaciones
- **500 números**: ≤ 5500 operaciones

## Limpieza

```bash
make clean    # Elimina archivos objeto
make fclean   # Elimina archivos objeto y ejecutable
make re       # Recompila todo
```
