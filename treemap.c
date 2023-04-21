#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap * tree = (TreeMap *)malloc(sizeof(TreeMap));
  tree->root = NULL;
  
  tree->lower_than = lower_than;
  return tree;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {

}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) 
{
  TreeNode* current = tree->root;
  while (current != NULL) 
  {
// Si la clave actual es igual a la clave buscada, devuelve el par clave-valor correspondiente
    if (current->pair->key == key) 
    {
      Pair* pair = (Pair*)malloc(sizeof(Pair));
      pair->key = current->pair->key;
      pair->value = current->pair->value;
      return pair;
    }
        // Si la clave buscada es menor que la clave actual, busca en el subárbol izquierdo
    else if (tree->lower_than(key, current->pair->key)) 
    {
      current = current->left;
    }
    // Si la clave buscada es mayor que la clave actual, busca en el subárbol derecho
    else 
    {
      current = current->right;
    }
  }
    // Si la clave no está en el árbol, devuelve NULL
  return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
