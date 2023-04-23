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
  tree->current = tree->root;
  TreeNode* parent = NULL;
  
  while (tree->current != NULL) 
  {
    if (is_equal(tree->current->pair->key, key) == 1) 
    {
      return;
    }

    parent = tree->current
      
    if (tree->lower_than(key, tree->current->pair->key)) 
    {
      current = current->left;
    }
      
    else
    {
      current = current->right;
    }
  }

  
}


TreeNode * minimum(TreeNode * x)
{
  while (x->left != NULL) 
  {
    x = x->left;
  }
  return x;
}

TreeNode* EncontrarParent(TreeNode* root, TreeNode* node) 
{
  TreeMap *tree = NULL;
    if (root == NULL || root == node) {
        return NULL;
    }
    if (root->left == node || root->right == node) {
        return root;
    }
    if (tree->lower_than(node->pair->key, root->pair->key)) {
        return EncontrarParent(root->left, node);
    } else {
        return EncontrarParent(root->right, node);
    }
}

void removeNode(TreeMap * tree, TreeNode* node) 
{
  if (node == NULL) 
  {
    return;
  }
  
  if (node->left == NULL && node->right == NULL) 
  {
    if (node == tree->root) 
    {
      tree->root = NULL;
    } 
    else 
    {
      TreeNode* parent = EncontrarParent(tree->root, node);
      if (parent != NULL) 
      {
        if (parent->left == node) 
        {
          parent->left = NULL;
        } 
        
        else 
        {
          parent->right = NULL;
        }
      }
    }
    free(node);
    
  } 
    
  else if (node->left != NULL && node->right != NULL) 
  {
    TreeNode* sucesor = minimum(node->right);
    node->pair->key = sucesor->pair->key;
    removeNode(tree, sucesor);
    
  } 

  else 
  {
    TreeNode* hijo = node->left != NULL ? node->left : node->right;
    if (node == tree->root) 
    {
      tree->root = hijo;
    } 
    else 
    {
      TreeNode* parent = EncontrarParent(tree->root, node);
      if (parent != NULL) 
      {
        if (parent->left == node)
        {
          parent->left = hijo;
        } 
        else 
        {
          parent->right = hijo;
        }
      }
    }
    free(node);
  }
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


Pair * upperBound(TreeMap * tree, void* key) 
{
  
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) 
{
  TreeNode *nodo = tree->root;
  while (nodo != NULL && nodo->left != NULL)
  {
    nodo = nodo->left;
  }

  if (nodo == NULL)
  {
    return NULL;
  }
  else
  {
    Pair *pair = (Pair *)malloc(sizeof(Pair));
    pair->key = nodo->pair->key;
    pair->value = nodo->pair->value;
    return pair;
  }
}

Pair * nextTreeMap(TreeMap * tree) 
{
  TreeNode *nodo = tree->current;
  
  if (nodo == NULL)
  {
    return NULL;
  }

  if(nodo->right != NULL)
  {
    nodo = nodo->right;
    while(nodo->left != NULL)
      {
        nodo = nodo->left;
      }
    Pair *pair = (Pair *)malloc(sizeof(Pair));
    pair->key = nodo->pair->key;
    pair->value = nodo->pair->value;
    return pair;
  }

  else
  {
    while (nodo->parent != NULL && nodo->parent->right == nodo)
      {
        nodo = nodo->parent;
      }
    if(nodo->parent == NULL)
    {
      return NULL;
    }
    else
    {
      Pair *pair = (Pair *)malloc(sizeof(Pair));
      pair->key = nodo->parent->pair->key;
      pair->value = nodo->parent->pair->value;
      return pair;
    }
  }
  
  
}
