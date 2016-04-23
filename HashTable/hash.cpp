#include "hash.h"
#include <fstream>
#include <iostream>
using namespace std;

void Hash::remove(string word)
{
  int index;
  double newAvgListLen, newLen;
  index = hf(word);

  for (list<string>::iterator it = hashTable[index].begin();
       it != hashTable[index].end(); it++)
  {
    //checking to see if the word is found
    if (*it == word)
    {
      it = hashTable[index].erase(it);
      newLen = 0;
      for (int i = 0; i < HASH_TABLE_SIZE; i++)
      {
        newLen = (newLen + hashTable[i].size()); 
      }
      newAvgListLen = newLen / HASH_TABLE_SIZE; 
      avgLength = (newAvgListLen + avgLength) / 2.0;
    }
  }
}
void Hash::print()
{
  int count = 0;
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
  {
    count = 0;
    cout << i << ":\t";
    for (list<string>::iterator it = hashTable[i].begin();
         it != hashTable[i].end(); it++)
    {
      cout << *it << ", ";
      count++;
    }
    cout << endl;
  }
}
void Hash::processFile(string filename)
{
  int index, cur_long = 0; 
  double newAvgListLen, newLen;
  bool flag = true;
  string word;
  avgLength = collisions = longestList = 0;

  ifstream inputFile(filename.c_str());

  if (inputFile.is_open()) //if the given file exists, open it
  {
    while (getline(inputFile, word)) //input the words in the hashtable 
    {
      index = hf(word);
      //check to see if there's any element in the index 
      if (hashTable[index].empty())
      { 
        hashTable[index].push_back(word);
      }
      else //there is a collision in the hashtable
      {
        for (list<string>::iterator it = hashTable[index].begin();
             it != hashTable[index].end(); it++)
        {
          if (word == *it)//checking incase of duplicates
          {
            flag = false;
          }
        }
        if (flag) //there are no duplicates
        {
          hashTable[index].push_back(word);
          collisions++;
        }
      }
      cur_long = hashTable[index].size();
      if (cur_long > longestList)  //finding the longest list
      {
        longestList = cur_long;
      }
      newLen = 0;
      //count the total elements in the hashtable
      for (int i = 0; i < HASH_TABLE_SIZE; i++)
      {
        newLen = (newLen + hashTable[i].size());
      }
      //averaging the average list length
      newAvgListLen = newLen / HASH_TABLE_SIZE;
      avgLength = (newAvgListLen + avgLength) / 2.0;
    }
    inputFile.close();
  }
}
bool Hash::search(string word)
{
  int index;
  index = hf(word);
  
  //after calling the hash function,
  //searched through the index to see if input word is found
  for (list<string>::iterator it = hashTable[index].begin();
       it != hashTable[index].end(); it++)
  {
    if (word == *it)
    {
      return true;
    }
  }
  return false;
}
void Hash::output(string filename)
{
  //declare an output file
  ofstream outputFile(filename.c_str());

  if (outputFile.is_open())
  {
    //insert the values 
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
      outputFile << i << ":\t";
      for (list<string>::iterator it = hashTable[i].begin();
           it != hashTable[i].end(); it++)
      {
        outputFile << *it << ", ";
      }
      outputFile << endl;
    }
  }
}
void Hash::printStats()
{
  cout << "Total collisions = " << collisions << endl;
  cout << "Longest list = " << longestList << endl;
  cout << "Average list length = " << avgLength << endl; 
}
