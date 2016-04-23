//Her, Kong
//Node.h
//Program 4 - Binary Search Tree

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{

  public:
      //friend class BST so class BST can access 
      //class Node's member variables
      friend class BST;
      Node(Node *, string *key, string *data);
      ~Node();

  private:
      Node *m_left;
      Node *m_right;
      Node *m_parent;
      string *m_key;
      string *m_data;


};

#endif
