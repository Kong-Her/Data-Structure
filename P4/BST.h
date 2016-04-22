//Her, Kong
//BST.h
//Program 4 - Binary Search Tree

#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>

class BST 
{
  public:
      BST();
      void search(string key);
      void remove(string key, string data);
      void print();
      void insert(string key, string data);

  private:
      Node *m_root; 
      void transplant(Node *, Node *);
      Node *tree_minimum(Node *);
      //helper functions
      void tree_search(Node *root, string key); 
      void tree_insert(string key, string data);
      void tree_delete(Node *root, string key, string data);
      void tree_print(Node *);
      Node *find_node(Node *target, string key, string data);
      int edges(Node*);

};

#endif
