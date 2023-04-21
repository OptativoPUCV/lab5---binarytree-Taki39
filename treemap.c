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
  tree->lower_than = lower_than;
  return tree;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) 
{
  //aux para el padre
  TreeNode *nodo = createTreeNode(key, value);
  TreeNode *aux = (TreeNode *)malloc(sizeof(TreeNode));
  aux->parent = tree->root;
  if (tree->root == NULL)
  {
    tree->root = nodo;
    return;
  }
  tree->current = tree->root;
  while (tree->current != NULL)
    {
      if(tree->lower_than(nodo->pair->key, tree->current->pair->key))
      {
        if(tree->current->left == NULL)
        {
          tree->current->left = nodo;
          return;
        }
        aux->parent = tree->current;
        tree->current = tree->current->left;
      }
        
      else if (tree->lower_than(nodo->pair->key, tree->current->pair->key) ==0)
      {
        if (tree->current->right == NULL)
        {
          tree->current->right = nodo;
          return;
        }
        aux->parent = tree->current;
        tree->current = tree->current->right;
      }

      else
      {
        free(nodo);
        return;
      }
    }
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
    if (is_equal(tree, current->pair->key, key) == 1) 
    {
      tree->current = current;
      return current->pair;
    }
    else if (tree->lower_than(key, current->pair->key)) 
    {
      current = current->left;
    }

    else 
    {
      current = current->right;
    }
  }
  
  tree->current = current;
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
