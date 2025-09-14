**Conceptos que deberías dominar primero:**

1. **Estructuras de datos fundamentales**
	* Listas enlazadas: Como ya tienes en tu linkedList.c, entender perfectamente cómo crear, manipular y liberar memoria de listas enlazadas
	* Pilas (Stacks): El concepto LIFO (Last In, First Out) y cómo implementarlas usando listas enlazadas

2. **Algoritmos de ordenamiento**
	*Bubble sort, insertion sort (para entender los fundamentos)
	* Algoritmos más eficientes como merge sort, quick sort
	* Radix sort (que mencionas en tu comentario) - muy importante para push_swap

3. **Análisis de complejidad**
	* Notación Big O
	* Cómo evaluar la eficiencia de diferentes enfoques
	* El proyecto tiene límites estrictos de operaciones según el número de elementos

4. **Manipulación de argumentos**
* Parsing de argumentos de línea de comandos
* Validación de entrada (números válidos, duplicados, etc.)
* Manejo de errores


**Fases de implementación recomendadas:**

**Fase 1: Fundamentos**
1. Implementar la estructura de datos (stack usando listas enlazadas)
2. Implementar todas las operaciones básicas (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
3. Crear funciones de utilidad (imprimir stacks, validar entrada)

**Fase 2: Parsing y validación**
1. Función para parsear argumentos
2. Validación de entrada (solo números, sin duplicados)
3. Manejo de errores y casos edge

**Fase 3: Algoritmos básicos**
1. Detectar si ya está ordenado
2. Algoritmo para 2-3 elementos (casos simples)
3. Algoritmo para elementos pequeños (≤5 elementos)

**Fase 4: Algoritmo principal**
1. Investigar y elegir algoritmo principal (radix sort es popular)
2. Implementar el algoritmo para casos grandes
3. Optimizar número de operaciones

**Fase 5: Optimización y testing**
1. Probar con diferentes tamaños de input
2. Contar operaciones y optimizar
3. Testing exhaustivo con casos edge




**Estructuras de datos fundamentales**

**Listas enlazadas**: Crear, manipular y liberar memoria de listas enlazadas

	1. Creación de nodos
		1.1 Estática: Como haces en tu código (declarando variables)
		1.2 Dinámica: Usando malloc() - MÁS IMPORTANTE para push_swap
	2. Inserción de nodos
		2.1 Al inicio de la lista
		2.2 Al final de la lista
		2.3 En una posición específica
	3. Eliminación de nodos
		3.1 Del inicio
		3.2 Del final
		3.3 De una posición específica
		3.4 ¡CRÍTICO!: Liberar memoria con free()
	4. Búsqueda y acceso
		4.1	Encontrar un nodo por valor
		4.2 Acceder al nodo en posición N
		4.3 Recorrer toda la lista
	5. Liberación de memoria
		5.1	Recorrer toda la lista liberando cada nodo
		5.2 Evitar memory leaks
