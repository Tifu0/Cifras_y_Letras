# Cifras y Letras (Estructuras de Datos - C++)

![C++ Standard](https://img.shields.io/badge/C%2B%2B-14-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.13%2B-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

Implementación en **C++** del concurso televisivo **Cifras y Letras** (*Countdown*), desarrollado como práctica final de la asignatura de **Estructuras de Datos** (2º curso del Grado en Ingeniería Informática, Universidad de Granada).

El proyecto aborda el diseño e implementación de tipos de datos abstractos (TDA), iteradores personalizados, algoritmos de búsqueda heurística y backtracking sobre diccionarios y conjuntos de datos.

---

## 📋 Tabla de Contenidos
- [Características Principales](#-características-principales)
- [Estructura del Proyecto](#-estructura-del-proyecto)
- [Arquitectura y TDAs](#-arquitectura-y-tdas)
- [Requisitos Previos](#-requisitos-previos)
- [Compilación](#-compilación)
- [Guía de Uso](#-guía-de-uso)
  - [1. Juego de Letras (`letras`)](#1-juego-de-letras-letras)
  - [2. Juego de Cifras (`cifras`)](#2-juego-de-cifras-cifras)
  - [3. Análisis de Frecuencias (`cantidad_letras`)](#3-análisis-de-frecuencias-cantidad_letras)
  - [4. Pruebas y Tests Unitarios](#4-pruebas-y-tests-unitarios)
- [Documentación Doxygen](#-documentación-doxygen)
- [Contexto Académico](#-contexto-académico)

---

## 🚀 Características Principales

- **Juego de Letras Completo**:
  - Extracción aleatoria de letras de la bolsa según frecuencias predefinidas.
  - Comprobación de palabras válidas en diccionario.
  - Dos modos de juego: **por longitud** (palabra más larga) o **por puntuación** (mayor suma de puntos por letra).
  - Cálculo de la solución óptima del ordenador y comparación con la respuesta del usuario.
- **Juego de Cifras (Backtracking)**:
  - Generación de 6 números aleatorios y un objetivo de 3 cifras.
  - Exploración recursiva de árboles de operaciones (`+`, `-`, `*`, `/`) sin números negativos intermedios.
  - Encuentra la solución exacta o la mejor aproximación posible.
- **Eficiencia y Buenas Prácticas**:
  - Búsqueda logarítmica y soporte de iteradores STL estándar.
  - Vector de frecuencias (`O(1)` por carácter) para la comprobación de palabras construibles.
  - Búsqueda eficiente por prefijos (`range_prefix`) mediante `lower_bound`.

---

## 📁 Estructura del Proyecto

```text
├── CMakeLists.txt          # Configuración del sistema de compilación CMake
├── Doxyfile.in             # Plantilla de configuración para Doxygen
├── .gitignore              # Filtros de exclusión para Git
├── .gitattributes          # Normalización de saltos de línea (LF)
├── .github/
│   └── workflows/
│       └── ci.yml          # Integración continua (CI) en Linux y Windows
├── include/                # Cabeceras (.h) de los TDAs
│   ├── dictionary.h        # TDA Dictionary e iteradores
│   ├── letters_set.h       # TDA LettersSet (conjunto de letras y puntuaciones)
│   ├── letters_bag.h       # TDA LettersBag (bolsa de extracción aleatoria)
│   └── solver.h            # TDA Solver (motor de resolución de letras)
├── src/                    # Implementaciones (.cpp) y ejecutables
│   ├── dictionary.cpp      # Implementación del Diccionario
│   ├── letters_set.cpp     # Implementación del LettersSet
│   ├── letters_bag.cpp     # Implementación de LettersBag
│   ├── solver.cpp          # Algoritmo de resolución de partidas
│   ├── letras.cpp          # Programa principal del juego de letras
│   ├── cifras.cpp          # Programa del juego de cifras (backtracking)
│   ├── cantidad_letras.cpp # Cálculo de frecuencias relativas y puntuaciones
│   ├── testdiccionario.cpp # Pruebas del TDA Diccionario
│   ├── proof_letters_set.cpp # Tests unitarios de LettersSet
│   ├── proof_letters_bag.cpp # Tests unitarios de LettersBag
│   └── proof_letras.cpp    # Tests unitarios del Solver
└── data/                   # Ficheros de datos y diccionarios
    ├── diccionario.txt     # Diccionario completo en español (>50k palabras)
    ├── diccionario_small.txt # Diccionario reducido para pruebas rápidas
    ├── letras.txt          # Distribución estándar de letras y puntos
    └── generator.py        # Script auxiliar para generar subconjuntos de palabras
```

---

## 🧠 Arquitectura y TDAs

| TDA / Módulo | Estructura Subyacente | Responsabilidad |
| :--- | :--- | :--- |
| **`Dictionary`** | `std::set<std::string>` | Almacenamiento ordenado de palabras válidas, búsqueda binaria, rangos de prefijos e iteradores propios. |
| **`LettersSet`** | `std::map<char, LetterInfo>` | Mapeo de cada letra a su información (`LetterInfo`: repeticiones máximas y valor en puntos). |
| **`LettersBag`** | `std::vector<char>` | Bolsa con las letras de la partida; simula extracciones aleatorias sin reemplazo. |
| **`Solver`** | N/A | Evalúa palabras del diccionario contra las letras disponibles y encuentra las soluciones óptimas para la ronda. |
| **`Cifras`** | Búsqueda exhaustiva | Algoritmo recursivo que combina sumas, restas, productos y divisiones exactas sobre los números disponibles. |

---

## 💻 Requisitos Previos

- **Compilador C++**: Soporte para C++14 o superior (GCC 7+, Clang 6+, MSVC 2017+).
- **CMake**: Versión 3.13 o superior.
- **Generador de compilación**: `Ninja` o `Make` (`mingw32-make` en Windows).
- *(Opcional)* **Doxygen**: Versión 1.8+ para generar la documentación HTML.

---

## ⚙️ Compilación

El proyecto utiliza **CMake** para la compilación multiplataforma (Linux, macOS y Windows):

### En Linux / macOS
```bash
# 1. Crear el directorio de compilación y configurar
cmake -B build -DCMAKE_BUILD_TYPE=Release

# 2. Compilar todos los ejecutables
cmake --build build
```

### En Windows (PowerShell con MinGW/GCC)
```powershell
# Usando Ninja
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build

# O usando MinGW Makefiles
cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

Los binarios generados se ubicarán en `build/bin/`.

---

## 🎮 Guía de Uso

### 1. Juego de Letras (`letras`)
Inicia una partida interactiva contra la computadora:

```bash
# Sintaxis:
./build/bin/letras <diccionario> <fichero_letras> <num_letras> <modo: L/P>

# Ejemplo jugando por longitud (L) con 8 letras:
./build/bin/letras data/diccionario.txt data/letras.txt 8 L

# Ejemplo jugando por puntuación (P) con 9 letras:
./build/bin/letras data/diccionario.txt data/letras.txt 9 P
```

### 2. Juego de Cifras (`cifras`)
Ejecuta la búsqueda de operaciones para alcanzar el número objetivo:

```bash
./build/bin/cifras
```

### 3. Análisis de Frecuencias (`cantidad_letras`)
Calcula las frecuencias de aparición de cada letra en un diccionario y asigna puntuaciones ponderadas en escala logarítmica:

```bash
./build/bin/cantidad_letras data/diccionario.txt data/letras.txt salida_frecuencias.txt
```

### 4. Pruebas y Tests Unitarios
Para comprobar el correcto funcionamiento de cada componente:

```bash
# Tests de LettersSet
./build/bin/proof_letters_set

# Tests de LettersBag
./build/bin/proof_letters_bag

# Tests del motor Solver
./build/bin/proof_letras

# Pruebas interactivas del Diccionario
./build/bin/testdiccionario data/diccionario_small.txt
```

---

## 📚 Documentación Doxygen

Si tienes Doxygen instalado en tu sistema, puedes generar la documentación técnica completa del código en HTML:

```bash
cmake --build build --target doc_doxygen
```

La documentación generada estará disponible abriendo `build/doc_doxygen/html/index.html` en tu navegador.

---

## 👥 Contexto Académico

Proyecto desarrollado para la asignatura de **Estructuras de Datos** — Grado en Ingeniería Informática, **Universidad de Granada**.

---

## 📄 Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más información.
