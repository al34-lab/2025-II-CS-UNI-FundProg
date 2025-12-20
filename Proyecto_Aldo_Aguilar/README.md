# Motor de Búsqueda con Trie

Proyecto en C++ que implementa un motor de búsqueda de texto eficiente utilizando un Árbol Trie y un Índice Invertido.

## Características
* **Rápido:** Búsqueda instantánea de palabras clave.
* **Desde Cero:** Estructuras de datos (TrieNode, MiVector) implementadas manualmente sin depender de la STL.
* **Memoria:** Gestión manual de punteros y limpieza automática con destructores.

## Limitaciones
* **Búsqueda por Palabras:** El sistema está diseñado para buscar términos individuales (tokens). No soporta búsquedas de frases completas o oraciones compuestas.
* **Sin Autocompletado:** El motor valida si un prefijo existe en el índice, pero no despliega una lista de palabras sugeridas. Para lograr esta funcionalidad, sería necesario implementar un algoritmo de búsqueda en profundidad (DFS).