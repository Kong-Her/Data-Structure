/* This assignment originated at UC Riverside.*/
 
#include <string>
#include "hash.h"

using namespace std;

//I used Dan Bernstein's prime number(5381) that he found that was worked well
//for hash functions. I converted each string character by character into ASCII
//After testing it many times, this worked well for me.
//Most of the collisions are pretty much evenly divided 
//into the hashtable.
//Here is a link below where I found the information.
//http://www.cse.yorku.ca/~oz/hash.html

int Hash::hf(string ins)
{
  unsigned int h = 5381;
  for (unsigned int i = 0; i < ins.size(); i++)
  {
    h = h + (int)ins[i]; 
  }
  return h % HASH_TABLE_SIZE; 
}
