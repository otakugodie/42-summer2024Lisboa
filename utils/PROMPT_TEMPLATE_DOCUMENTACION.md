# 📝 Prompt Template para Documentación Completa de Proyectos

## 🎯 Prompt Base para AI

```
Quisiera que analizaras todos los archivos que están dentro de la carpeta [NOMBRE_CARPETA] 
y me crearas un archivo .md que resuma y explique cómo funciona el proyecto, como si fuera 
un tutorial que ayudará a explicar por sí mismo el proyecto.

El documento debe incluir:

### 📊 Estructura y Análisis:
- **Arquitectura general** del proyecto con estructura de archivos
- **Diagramas de flujo** (usando sintaxis Mermaid para gráficos)
- **Estructuras de datos** principales explicadas en detalle
- **Flujo de ejecución** completo paso a paso

### 🔧 Análisis por Módulos:
- **Análisis individual** de cada archivo/módulo
- **Propósito específico** y responsabilidades
- **Funciones principales** con explicaciones detalladas
- **Interacciones entre módulos** y dependencias

### 🎨 Elementos Visuales y Pedagógicos:
- **Emojis** para navegación visual
- **Bloques de código** con syntax highlighting
- **Ejemplos prácticos** de transformaciones de datos
- **Casos de uso** y escenarios reales

### 📚 Contenido Educativo:
- **Explicación de algoritmos** implementados
- **Conceptos técnicos** subyacentes
- **Decisiones de diseño** y su justificación
- **Optimizaciones** y características técnicas

### 🔄 Flujos y Procesos:
- **Flujo completo** desde entrada hasta salida
- **Interacción del usuario** (si aplica)
- **Manejo de errores** y casos edge
- **Gestión de recursos** (memoria, archivos, etc.)

El documento debe ser **autoexplicativo** y permitir que cualquier persona 
entienda cómo funciona el proyecto sin necesidad de explicaciones adicionales.
```

## 🎛️ Variaciones del Prompt según Tipo de Proyecto:

### Para Proyectos Web:
```
Agrega además:
- **API endpoints** y sus responsabilidades
- **Frontend/Backend** interacciones
- **Base de datos** esquemas y relaciones
- **Autenticación** y seguridad
```

### Para Algoritmos/Estructuras de Datos:
```
Agrega además:
- **Complejidad temporal** y espacial
- **Casos de prueba** y ejemplos
- **Comparación** con alternativas
- **Visualización** del algoritmo paso a paso
```

### Para Sistemas/OS:
```
Agrega además:
- **Gestión de procesos** y threads
- **Manejo de memoria** detallado
- **System calls** utilizadas
- **Concurrencia** y sincronización
```

### Para Proyectos Gráficos:
```
Agrega además:
- **Pipeline de renderizado**
- **Transformaciones matemáticas**
- **Gestión de buffers**
- **Optimizaciones gráficas**
```

## 🔧 Personalización por Lenguaje:

### C/C++:
```
Enfócate en:
- **Gestión manual de memoria**
- **Punteros y referencias**
- **Compilación y linking**
- **Headers y modularización**
```

### Python:
```
Enfócate en:
- **Módulos y packages**
- **Decoradores y metaclases**
- **Gestión de dependencias**
- **Programación orientada a objetos**
```

### JavaScript:
```
Enfócate en:
- **Asincronía** (callbacks, promises, async/await)
- **Closures y scoping**
- **Event loop**
- **Módulos ES6**
```

## 💡 Tips para Mejorar el Prompt:

### 1. **Sé específico sobre el contexto:**
```
"Este es un proyecto de [DESCRIPCIÓN] que implementa [TECNOLOGÍA] 
para resolver [PROBLEMA ESPECÍFICO]"
```

### 2. **Menciona el nivel de audiencia:**
```
"El documento debe ser comprensible para [principiantes/intermedios/avanzados] 
en [TECNOLOGÍA/LENGUAJE]"
```

### 3. **Especifica el formato deseado:**
```
"Usa emojis para navegación, diagramas Mermaid para flujos, 
y código con syntax highlighting"
```

### 4. **Incluye ejemplos específicos:**
```
"Incluye ejemplos paso a paso de [FUNCIONALIDAD ESPECÍFICA] 
mostrando entrada → procesamiento → salida"
```

## 🎯 Ejemplo de Prompt Completo:

```
Quisiera que analizaras todos los archivos de mi proyecto FdF (visualizador 3D) 
en la carpeta /source y me crearas una documentación completa en .md.

Este es un proyecto de gráficos en C que renderiza mapas topográficos en 3D 
usando MiniLibX, dirigido a estudiantes de 42 School.

Incluye:
- Arquitectura modular con diagramas Mermaid
- Análisis detallado de cada archivo (.c/.h)
- Explicación de algoritmos (Bresenham, proyección isométrica)
- Flujo desde carga de archivo hasta renderizado
- Gestión de memoria y optimizaciones
- Interactividad del usuario en tiempo real
- Ejemplos prácticos con archivos reales

El documento debe servir como tutorial autoexplicativo y referencia técnica.
```

## 📋 Checklist Post-Documentación:

Después de recibir la documentación, verifica que incluya:

- [ ] Diagrama de arquitectura general
- [ ] Análisis de cada módulo/archivo
- [ ] Flujos de datos con diagramas
- [ ] Estructuras de datos explicadas
- [ ] Algoritmos paso a paso
- [ ] Ejemplos prácticos
- [ ] Gestión de recursos
- [ ] Casos de uso
- [ ] Optimizaciones implementadas
- [ ] Navegación visual con emojis

¡Úsala este template como base y personalízalo según tu proyecto específico!
