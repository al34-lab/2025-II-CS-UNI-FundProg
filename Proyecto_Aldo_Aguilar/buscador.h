#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <fstream>
#include <cctype>
#include "mivector.h"
#include "trienode.h"

class Buscador {
private:
    TrieNode* raiz; 
    //mapear ID de documento a su nombre de archivo
    Mivector<std::string> registroArchivos; 

    //todo minusculas
    std::string limpiarPalabra(std::string sucia) {
        std::string limpia = "";
        for (char c : sucia) {
            if (isalpha(c)) { 
                limpia += tolower(c);
            }
        }
        return limpia;
    }

    // inserta la palabra en el Trie y registra el ID del documento
    void insertarPrivado(std::string palabra, int idDoc) {
        TrieNode* actual = raiz; 

        for (char c : palabra) {
            int index = c - 'a';

            if (index < 0 || index > 25) continue;

            //crea el nodo si no existe.
            if (actual->hijos[index] == nullptr) {
                actual->hijos[index] = new TrieNode();
            }
            actual = actual->hijos[index];
        }

        //marca el final de la palabra e inserta el ID del documento.
        actual->esFinal = true;

        if (actual->idsDocs == nullptr) {
            actual->idsDocs = new Mivector<int>();
        }
        
        //evita registrar el mismo ID
        bool yaExiste = false;
        for(int i = 0; i < actual->idsDocs->size(); i++) {
             if ((*actual->idsDocs)[i] == idDoc) {
                 yaExiste = true; 
                 break;
             }
        }
        
        if (!yaExiste) {
            actual->idsDocs->push_back(idDoc);
        }
    }

public:
    Buscador() {
        raiz = new TrieNode(); //inicializa el nodo raíz del Trie
    }

    ~Buscador() {
        delete raiz; //llama al destructor recursivo del TrieNode
    }

    //indexa un archivo de texto en el motor de búsqueda.
    void indexarLibro(std::string nombreArchivo) {
        std::ifstream archivo(nombreArchivo);
        
        if (!archivo.is_open()) {
            std::cerr << "[Error] No se pudo abrir: " << nombreArchivo << "\n";
            return;
        }

        registroArchivos.push_back(nombreArchivo);
        int nuevoID = registroArchivos.size() - 1;

        std::cout << "Indexando archivo: " << nombreArchivo << " (ID: " << nuevoID << ")... ";

        std::string palabraLeida;
        while (archivo >> palabraLeida) {
            std::string palabraLimpia = limpiarPalabra(palabraLeida);
            
            if (palabraLimpia.length() > 0) {
                insertarPrivado(palabraLimpia, nuevoID);
            }
        }

        archivo.close();
        std::cout << "[Completado]\n";
    }

    //busca un término y reporta los archivos que lo contienen
    void buscar(std::string consulta) {
        std::string termino = limpiarPalabra(consulta);
        std::cout << "\n>>> Buscando: '" << termino << "'\n";

        TrieNode* actual = raiz;

        //navegación por el Trie
        for (char c : termino) {
            int index = c - 'a';
            
            //sii el camino se interrumpe, la palabra no existe.
            if (index < 0 || index > 25 || actual->hijos[index] == nullptr) {
                std::cout << "Resultados: 0 coincidencias.\n";
                return;
            }
            actual = actual->hijos[index];
        }

        //extracción de resultados
        if (actual->esFinal && actual->idsDocs != nullptr) {
            std::cout << "Encontrado en " << actual->idsDocs->size() << " archivo(s):\n";
            
            for (int i = 0; i < actual->idsDocs->size(); i++) {
                int id = (*actual->idsDocs)[i];
                std::string nombre = registroArchivos[id];
                
                std::cout << "   -> " << nombre << " [ID: " << id << "]\n";
            }
        } else {
            std::cout << "Resultados: La palabra existe como prefijo, pero no por si sola.\n";
        }
    }
};

#endif