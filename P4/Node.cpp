//Her, Kong
//Node.cpp
//Program 4 - Binary Search Tree

#include "Node.h"

Node::Node(Node *, string *key, string *data)
{
  //initializing the objects and variables
  m_left = NULL;
  m_right = NULL;
  m_parent = NULL;
  m_key = key;
  m_data = data;
}
Node::~Node()
{
  delete m_key;
  delete m_data;
}
