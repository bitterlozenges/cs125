#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*
 * n represents number of vertices
 */
queue init(int n)
{
  queue Q;
  Q.length = n;

  // fill the queues with vertices
  for (int i=0; i<n ; i++)
  {
    Q.heap[i] = INFTY;
  }
  Q.heap[0]= 0.0;
  return Q;
}



int delMin(queue* Q)
{
  // passes into swap the address of the root of Q and the last leaf
  float min = INFTY;
  int ind = -1;

  for(int i=0; i<Q -> length; i++)
  {
    if((Q->heap)[i]>=0.0 && (Q->heap)[i]< min)
    {
      min= (Q->heap)[i];
      ind = i;
    }
  }
  return ind;
}



//decrease key of vertex at index
void decKey(queue* Q, int index, float newDist)
{

  (Q->heap)[index]= newDist;
}
