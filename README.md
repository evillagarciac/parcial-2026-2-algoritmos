# EXAMEN PARCIAL 2026-2  
**Curso:** Análisis y Diseño de Algoritmos

**Docente:** Josue Miguel Flores Parra

Código de apoyo para los problemas 2 y 4 del exámen.

El informe contiene los procedimientos, las explicaciones y las trazas. Estos programas permiten ejecutar los ejemplos y comprobar sus resultados.

## Archivos

| Archivo | Contenido |
| --- | --- |
| `problema 2.cpp` | Verificación recursiva de un arreglo ordenado de menor a mayor, permitiendo valores iguales. |
| `problema 4.cpp` | Insertion Sort, Merge Sort y Quick Sort sobre `[7, 4, 6, 2, 5]`, con pasos intermedios en consola. |

Cada archivo tiene su propio `main`, así que se compilan por separado. No se necesitan archivos de cabecera propios ni bibliotecas externas. Este repositorio solo incluye los problemas 2 y 4.

## Compilación y ejecución

Se necesita un compilador compatible con C++17. Por ejemplo, con g++:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic problema2.cpp -o problema2
g++ -std=c++17 -Wall -Wextra -pedantic problema4.cpp -o problema4
```

En Linux o macOS:

```sh
./problema2
./problema4
```

En Windows PowerShell, los ejecutables generados se ejecutan así:

```powershell
.\problema2.exe
.\problema4.exe
```

## Problema 2: arreglo ordenado

La función `ordenado` revisa primero los primeros `n - 1` elementos y después comprueba el último par. Con cero o un elemento devuelve verdadero.

| Entrada | Resultado esperado |
| --- | --- |
| `[1, 2, 3, 5, 8]` | `verdadero` |
| `[1, 2, 2, 5, 8]` | `verdadero` |
| `[1, 4, 2, 8]` | `falso` |

Salida:

```text
verdadero
verdadero
falso
```

## Problema 4: ordenamientos

Los tres algoritmos reciben copias independientes de `[7, 4, 6, 2, 5]`. El resultado esperado es `[2, 4, 5, 6, 7]`.

- Insertion Sort muestra el arreglo después de cada pasada.
- Merge Sort muestra las divisiones y las fusiones.
- Quick Sort muestra el pivote, las partes resultantes y el arreglo completo después de cada partición.

Al terminar, el programa compara cada resultado con el esperado e imprime `OK` o `ERROR`.

### Relación con los códigos de clase

Insertion Sort conserva el procedimiento de clase. Merge Sort conserva su división y fusión; los arreglos auxiliares se representan con `vector` para usar C++ estándar.

En la diapositiva de Quick Sort se toma el primer elemento como pivote. La práctica exige el último: por eso se conserva la estructura recursiva, pero se adapta la partición a Lomuto con pivote final, igual que en las trazas del informe. No es una copia literal de la partición de clase.

Las particiones esperadas son:

```text
Pivote 5: [4, 2] | 5 | [7, 6] -> [4, 2, 5, 7, 6]
Pivote 2: [] | 2 | [4]        -> [2, 4, 5, 7, 6]
Pivote 6: [] | 6 | [7]        -> [2, 4, 5, 6, 7]
```

No se incluyen ejecutables ni archivos temporales; cada programa se puede compilar a partir de su `.cpp`.
