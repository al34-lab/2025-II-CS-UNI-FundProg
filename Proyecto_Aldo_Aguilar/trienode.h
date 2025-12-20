#ifndef __TRIENODE_H__
#define __TRIENODE_H__

#include <cstddef> //nullptr
#include "MiVector.h"

struct TrieNode{
    TrieNode* hijos[26]; 
    bool esFinal; 
    Mivector<int>* idsDocs;
    TrieNode(){
        esFinal = false;
        idsDocs = nullptr;
        for(int i=0; i<26; i++){
            hijos[i] = nullptr;
        }
    } 
    ~TrieNode(){
        if(idsDocs!=nullptr){
            delete idsDocs;
        }
        //borrar hijos recursivamente
        for(int i=0; i<26; i++){
            if(hijos[i]!=nullptr){
                delete hijos[i];
            }
        }
    }
};

#endif