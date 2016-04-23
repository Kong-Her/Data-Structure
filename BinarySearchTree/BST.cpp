//Her, Kong
//BST.cpp
//Program 4 - Binary Search Tree

#include "Node.h"
#include "BST.h"
using namespace std;

BST::BST()
{
  m_root = NULL;
}
void BST::insert(string key, string data)
{
  tree_insert(key, data); //calling helper function
}
void BST::tree_insert(string key, string data)
{
  Node *y = NULL;
  Node *x = m_root;
  
  while (x) 
  {
    y = x;
    if (key < *(x->m_key))
    {
      x = x->m_left;
    }
    else
    {
      x = x->m_right;
    }
  }
  if (y == NULL)
  {  //this will be the first node, which will be the root
    m_root = new Node(y, new string(key), new string(data));
  }
  else if (key < *(y->m_key))
  {  //insert on the left side if the key is smaller
    y->m_left = new Node(y, new string(key), new string(data));
    y->m_left->m_parent = y;
  }
  else
  { //insert on the right side
    y->m_right = new Node(y, new string(key), new string(data));
    y->m_right->m_parent = y;
  }
}
void BST::search(string key)
{
  tree_search(m_root, key); //calling search's helper function
}
void BST::tree_search(Node *root, string key) 
{
  Node *ptr = root;
  if (ptr)
  {
    //comparing the key we want with the current pointer key
    if (key == *(ptr->m_key))
    {
      cout << key << " " << *(ptr->m_data) << endl; 
    }
    tree_search(ptr->m_left, key);  //traverse through the whole tree
    tree_search(ptr->m_right, key); //and print out if the keys are equal
  }
}
void BST::remove(string key, string data)
{
  Node *target = find_node(m_root, key, data);
  tree_delete(target, key, data); //calling helper function
}
void BST::tree_delete(Node *target, string key, string data)
{
  while (target) 
  {
    if (target->m_left == NULL)
    {
      transplant(target, target->m_right);
    }
    else if (target->m_right == NULL)
    {
      transplant(target, target->m_left);
    }
    else
    { //the target has two children
      Node *y = tree_minimum(target->m_right);
      if (y->m_parent != target)
      {
        transplant(y, y->m_right);
        y->m_right = target->m_right;
        y->m_right->m_parent = y;
      }
      transplant(target, y);
      y->m_left = target->m_left;
      y->m_left->m_parent = y;
    }
    delete target;
    //finding the target again incase there are duplicates
    target = find_node(m_root, key, data);
  }
}
Node *BST::find_node(Node *ptr, string key, string data)
{
  //checking to see if the node we want is found
  if (ptr == NULL || (*(ptr->m_key) == key && *(ptr->m_data) == data))
  {
    return ptr;
  }
  //call the left subtree becuause the key is smaller
  if (*(ptr->m_key) > key)
  {
    return find_node(ptr->m_left, key, data);
  }
  //call the right subtree
  return find_node(ptr->m_right, key, data);
}
void BST::transplant(Node *u, Node *v)
{
  if (u->m_parent == NULL)
  {
    m_root = v;
  }
  else if (u == u->m_parent->m_left)
  {
    u->m_parent->m_left = v;
  }
  else
  {
    u->m_parent->m_right = v;
  }
  if (v != NULL)
  {
    v->m_parent = u->m_parent;
  }
}
Node *BST::tree_minimum(Node *ptr)
{
  while (ptr->m_left) //find the smallest node and return it
  {
    ptr = ptr->m_left;
  }
  return ptr;
}
void BST::print()
{
  tree_print(m_root); //calling helper function
}
void BST::tree_print(Node *root)
{
  int edge; 
  Node *ptr = root;
  if (ptr)
  {
    tree_print(ptr->m_left);
    edge = edges(ptr); //counting the edges from root to the current pointer
    cout << edge << " " << *(ptr->m_key) << " " << *(ptr->m_data) << endl;
    tree_print(ptr->m_right);
  }
}
int BST::edges(Node *ptr)
{
  Node *p = m_root;
  int count = 0;

  //counting the number of edges
  //from the root to the target (the node we want)
  while (p != NULL && p != ptr)
  {
    if (*(ptr->m_key) < *(p->m_key))
    {
      p = p->m_left;
    }
    else
    {
      p = p->m_right;
    }
    count++;
  }
  return count;
}
