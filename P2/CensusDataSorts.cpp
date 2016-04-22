/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"

// formal parameter name commented out to avoid unused variable warning
void CensusData::insertionSort(int type) 
{
  int i;
  Record *key;

  for (int j = 1; j < getSize(); j++)
  {
    key = data[j];
    i = j-1;
    if (type == 0)
    {
      while (i >= 0 && data[i]->population > key->population)
      {
        data[i+1] = data[i];
        i--;
      }
      data[i+1] = key;
    }
    else
    {
      while(i >= 0 && *data[i]->city > *key->city)
      {
        data[i+1] = data[i];
        i--;
      }
    }
    data[i+1] = key;
  }
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::mergeSort(int type) 
{
  int size, start = 0; 
  size = getSize()-1;
  merge_Sort(type, start, size);
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::quickSort(int type) 
{
  int size;
  size = getSize()-1;
  quick_Sort(type, 0, size);
}
//private helper function for mergeSort
void CensusData::merge_Sort(int type, int start, int end)
{
  int middle;
  if (start < end)
  {
    middle = (start+end)/2;
    merge_Sort(type, start, middle);  //sorting the first half of the vector
    merge_Sort(type, middle+1, end);  //sorting the second half of the vector
    merge(type, start, middle, end);
  }
}
//merging of the sub vectors
void CensusData::merge(int type, int start, int middle, int end)
{
  int rNum, lNum, i, j;
  lNum = (middle-start)+1; 
  rNum = end-middle;
  vector<Record*> left;  //declaring new vectors to store data separately
  vector<Record*> right;
  for (int i = 0; i < lNum; i++)
  {
    left.push_back(data[start+i]);  //new vector hold first half of objects
  }
  for (int j = 0; j < rNum; j++)
  {
    right.push_back(data[middle+j+1]);  //new vector holding the second half 
  }
  left[lNum] = NULL;    //initalizing the last element to NULL
  right[rNum] = NULL;   //so we know when we reached the end
  i = 0;
  j = 0;
 
  for (int k = start; k <= end; k++)
  {
    if (type == 0)
    {
      //checking to see if the left or right is at the last element yet
      //if one of the two is at the last index of the vector (NULL)
      //data will equal to the one that is not NULL

      //mergeSort by population
      if (left.back() != left[i-1] && (right.back() == right[j-1] 
      || left[i]->population <= right[j]->population))
      {
        data[k] = left[i];
        i++;
      }
      else
      {
        data[k] = right[j];
        j++;
      }
    }
    else
    {
      //mergeSort by city
      if (left.back() != left[i-1] && (right.back() == right[j-1] 
      || *(left[i]->city) <= *(right[j]->city)))
      {
        data[k] = left[i];
        i++;
      }
      else 
      {
        data[k] = right[j];
        j++;
      }
    }
  }
}
//private helper function for quickSort
void CensusData::quick_Sort(int type, int start, int end)
{
  int pIndex;
  
  if (start < end)
  {
    pIndex = partition(type, start, end);
    quick_Sort(type, start, pIndex-1); 
    quick_Sort(type, pIndex+1, end);
  }
}
int CensusData::partition(int type, int start, int end)
{
  int i;
  Record *pivot;
  pivot = data[end]; 
  i = start-1;
  for (int j = start; j <= end-1; j++)
  {
    //quickSort by population
    if (type == 0)
    {
      if (data[j]->population <= pivot->population)
      {
        i++;
        std::swap(data[i], data[j]);
      }
    }
    else
    {
      //quickSort by city
      if (*(data[j]->city) <= *(pivot->city))
      {
        i++;
        std::swap(data[i], data[j]);
      }
    }
  }
  std::swap(data[i+1], data[end]);
  return i+1;
}
