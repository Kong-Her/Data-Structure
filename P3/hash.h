/* This assignment originated at UC Riverside. The hash table size
 should be defined at link time. Use -D HASH_TABLE_SIZE=X */

#ifndef __HASH_H
#define __HASH_H

#include <string>
#include <list>

using namespace std;

class Hash 
{
  public:
      void remove(string word);
      void print();
      void processFile(string filename);
      bool search(string word);
      void output(string word);
      void printStats();

  private:
      list<string> hashTable [HASH_TABLE_SIZE];
      int collisions;
      int longestList;
      double avgLength;
   
  private:
      int hf(string);

// put additional variables/functions below
// do not change anything above!

};

#endif
