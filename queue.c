#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*
 * n represents number of vertices
 */
float* init(int n)
{
  float Q[n]={};

  // fill the array with distance from S
  for (int i=0; i<n ; i++)
  {
    Q[i] = INFTY;
  }
  Q[0]= 0.0;
  return Q;
}



int delMin(float* Q)
{
  // passes into swap the address of the root of Q and the last leaf
  float min = INFTY;
  int ind = -1;

  for(int i=0; i<Q -> length; i++)
  {
    if(Q.[i]>=0.0 && Q.[i]< min)
    {
      min= Q.[i];
      ind = i;
    }
  }
  return ind;
}



//decrease key of vertex at index
void decKey(float* Q, int index, float newDist)
{

  Q[index]= newDist;
}
