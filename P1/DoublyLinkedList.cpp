//Kong Her
//DoublyLinkedList.cpp

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
  m_head = NULL;
  m_tail = NULL;
  m_current = NULL;
}
DoublyLinkedList::~DoublyLinkedList()
{
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    Node *tmp = ptr;
    ptr = ptr->m_next;
    delete tmp;
  }
}
bool DoublyLinkedList::empty()
{
  //if the pointers are NULL then the playlist is empty
  if (!m_head || !m_tail || !m_current)
  {
    return true;
  }
  return false;
}
void DoublyLinkedList::append(string &s)
{
  //if there is no songs in the playlist
  if (!m_head)
  {
    m_head = new Node(s, NULL, m_head);
    m_tail = m_current = m_head;
  }
  else
  {
    //the song is being inserted at the end of the playlist
    m_tail->m_next = new Node(s, m_tail, m_tail->m_next); 
    m_current = m_tail = m_tail->m_next;
  }
}
void DoublyLinkedList::insertBefore(string &s)
{
  //if there is no element in the playlist, do nothing
  if (!m_head)
  {
    return;
  }
  //if the current song is the first song
  else if (m_head == m_current)
  {
    m_head = new Node(s, NULL, m_head); 
    m_current->m_prev = m_head;
    m_current = m_head;
  }
  //search through the playlist to find the current song
  else
  {
    Node *ptr = m_head;
    while (ptr->m_next != NULL && ptr->m_next != m_current)
    {
      ptr = ptr->m_next;
    }
    //checking to see if the next song is the current song
    if (ptr->m_next == m_current)
    {
      ptr->m_next = new Node(s, ptr, ptr->m_next);
      m_current->m_prev = ptr->m_next; //linking the new song to the previous
      m_current = m_current->m_prev;   //update the current song to the new one
    }
  }
}
void DoublyLinkedList::insertAfter(string &s)
{
  //if there is no song in the playlist
  if (!m_head)
  {
    return;
  }
  //if the first song of the playlist is the current song
  else if (m_head == m_current) 
  {
    //check to see if there's only one song in the playlist
    //if there's only one song, the song being inserted is m_tail
    if (!m_head->m_next)
    {
      Node *ptr = m_head;
      ptr->m_next = new Node(s, m_head, ptr->m_next);
      m_current = ptr->m_next;
      m_tail = m_current;  
    }
    //if there is more than one song in the playlist,
    //update the m_prev and m_next pointers with the new song
    else  
    {
      Node *ptr = m_head;
      m_current = ptr->m_next;
      ptr->m_next = new Node(s, m_head, ptr->m_next);
      m_current = m_current->m_prev = ptr->m_next;
    }
  }
  else
  {
    //search through the playlist to find the current song
    Node *ptr = m_head;
    while (ptr->m_next != NULL && ptr != m_current)
    {
      ptr = ptr->m_next;
    }
    if (ptr == m_current)
    {
      //checking to see if the the current pointer 
      //is pointing at the last song in the playlist
      //if it is, the new song being inserted will be m_tail
      if (!ptr->m_next)
      {
        ptr->m_next = new Node(s, ptr, ptr->m_next);
        m_tail = m_current = ptr->m_next;
      }
      //insert the new song in the playlist 
      //then update the pointers so they are linked together
      else
      {
        Node *tmp = ptr->m_next;
        ptr->m_next = new Node(s, ptr, ptr->m_next);   
        tmp->m_prev = ptr->m_next;
        m_current = ptr->m_next;
      }
    }
  }
}
void DoublyLinkedList::remove(string &s)
{
  //checking to see if the playlist is empty
  if (!m_head)
  {
    return;
  }
  //if the first song is the one we want to remove
  else if (m_head->m_data == s)
  {
    //if this is true, there's only one song in the playlist
    //the playlist will become empty once the song is removed
    if (!m_head->m_next)
    {
      Node *tmp = m_head;
      m_head = NULL;
      m_current = NULL;
      delete tmp;
    }
    //there is more than one song
    //the next song will become the current song
    else 
    {
      Node *tmp = m_head;
      m_head = m_head->m_next;
      m_head->m_prev = NULL;
      m_current = m_head;
      delete tmp;
    }
  }
  else
  {
    //search through the playlist to find the song we want to remove
    Node *ptr = m_head;
    while (ptr->m_next != NULL && ptr->m_data != s)
    {
      ptr = ptr->m_next;
    }
    if (ptr->m_data == s)
    {
      //checking to see if there is a next song
      //if there is, the next song will be the current song
      //link the songs together 
      if (ptr->m_next)
      {
        Node *tmp = ptr;
        Node *holder = ptr->m_prev;
        ptr = ptr->m_next;
        m_current = ptr;
        delete tmp;
        m_current->m_prev = holder;
        holder->m_next = m_current;
      }
      //checking to see if there's a previous song
      //if not then do nothing
      else
      {
        if (ptr->m_prev)
        {
          Node *tmp = ptr;
          ptr = ptr->m_prev;
          m_current = ptr;
          delete tmp;
        }
      }
    }
  }
}
void DoublyLinkedList::begin()
{
  //do nothing if there is no song in the beginning
  if (!m_head)
  {
    return;
  }
  //the current song now is the first song 
  //pointing to the same place as m_head is pointing to
  else 
  {
    m_current = m_head;
  }
}
void DoublyLinkedList::end()
{
  //do nothing if there is no song at the end
  if (!m_tail)
  {
    return;
  }
  //the current song now becomes the last song in the playlist
  else
  {
    m_current = m_tail;
  }
}
bool DoublyLinkedList::next()
{
  //checking to see if there is a next song
  if (!m_head || !m_current->m_next)
  {
    return false;
  }
  //set the current song to the next song
  else
  {
    m_current = m_current->m_next;
    return true;
  }
}
bool DoublyLinkedList::prev()
{
  //checking to see if there is a previous song
  if (!m_head || !m_current->m_prev) 
  {
    return false;
  }
  //set the current song to the previous song
  else
  {
    m_current = m_current->m_prev;
    return true;
  }
}
bool DoublyLinkedList::find(string &s)
{
  //do nothing, if nothing is in the playlist
  if (!m_head)
  {
    return false;
  }
  else
  {
    //search through the playlist to find the song we want
    Node *ptr = m_head;
    while (ptr->m_next != NULL && ptr->m_data != s)
    {
      ptr = ptr->m_next;
    }
    //if we found the song we want,
    //set the current pointer to the song we want
    if (ptr->m_data == s)
    {
      m_current = ptr;
      return true;
    }
    //if we didn't find the song we want
    //the current pointer still remains at the same place
    return false;
  }
}
const string& DoublyLinkedList::getData()
{
  //return the song title that the current pointer is at
  return m_current->m_data;
}

