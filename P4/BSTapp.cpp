//Her, Kong
//BSTapp.cpp
//Program 4 - Binary Search Tree

#include "BSTapp.h"
#include "BST.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  BSTapp bstapp;
  bstapp.processCommand();
  return 0;
}
void BSTapp::processCommand()
{
  BST bst;
  string command, key, data;

  //while the user keeps on inputting command
  while (cin >> command)
  {
    //if command is "insert", get the key and data
    if (command == "insert")
    {
      cin >> key;
      cin.ignore(); //ignore a whitespace
      getline(cin, data);
      bst.insert(key, data);
    }
    //if command is "find", get the key from user input 
    else if (command == "find")
    {
      cin >> key;
      bst.search(key);
    }
    //if command is "delete", get both key and data
    else if (command == "delete")
    {
      cin >> key;
      cin.ignore(); //ignore whitespace
      getline(cin, data);
      bst.remove(key, data);
    }
    //if command is "print", print the whole tree
    else if (command == "print")
    {
      bst.print();
    }
    //if command is "quit", exit out of the program
    else if (command == "quit")
    {
      exit(1); 
    }
    //if the command reaches here, then the command was not valid 
    else
    { 
      //if there is a bad command, ignore the whole line following bad command
      while (cin.peek() != '\n')
      {
        cin.ignore();
      }
    }
  }
}
