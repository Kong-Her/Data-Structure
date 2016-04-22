//Kong Her
//DoublyLinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DoublyLinkedList.h"
#include <string>
using std::string;

class DoublyLinkedList
{
  public:
      DoublyLinkedList();            //DLL constructor
      ~DoublyLinkedList();           //DLL destructor
      bool empty();                  //Checks to see if playlist is empty
      void append(string &s);        //inserts new song to the end of playlist
      void insertBefore(string &s);  //insert before the current song
      void insertAfter(string &s);   //insert after the current song
      void remove(string &s);        //remove the given song if found
      void begin();                  //make the current song the first song
      void end();                    //make the current song the last song
      bool next();                   //make the next song the current, if any
      bool prev();                   //make previous song the current, if any 
      bool find(string &s);          //find the given string, make it m_current
      const string& getData();       //return the current song

  private:
      class Node
      {
        public:
            Node(string data, Node *prev, Node *next) //Node constructor
            {
              m_data = data;
              m_prev = prev;
              m_next = next;
            }
            Node *m_next;
            Node *m_prev;
            string m_data;
      };
      Node *m_head;        
      Node *m_tail;          
      Node *m_current;
};

#endif
