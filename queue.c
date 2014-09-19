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
  Q.last = n - 1;

  // fill the queues with vertices
  for (int i=0; i<n ; i++)
  {
    Q.heap[i] = (vertex) {INFTY , i}; 
  }
  return Q;
}

//TODO: THIS SEEMS BAD PUT ON TOP YO
void heapify(queue* Q, int index);

void swap(vertex* v1, vertex* v2)
{
  vertex temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}


vertex delMin(queue* Q)
{
  vertex min = (Q->heap)[0];
  // passes into swap the address of the root of Q and the last leaf
  swap(&(Q->heap)[0],&(Q->heap)[Q->last]);
  Q->last -= 1;
  heapify(Q,0);
  return min;
}

void heapify(queue* Q, int index)
{
  // return if heap is empty
  if (Q->last < 0)
    return;


  int left;
  int right;
  int current = index;
  bool swapMade = true;

  while(swapMade)
  {
    // get indices of childre
    left = 2*index + 1;
    right = 2*index + 2;
    swapMade = false;
    
    // if our vertex has children and the left child is smaller
    if (left <= Q->last && (Q->heap)[left].dist < (Q->heap)[current].dist)
    {
      current = left;
      swapMade = true;
    }
    // if vertex has children and the right child is smaller
    if (right <= Q->last && (Q->heap)[right].dist < (Q->heap)[current].dist)
    { 
      current = right;
      swapMade = true;
    }
    // if we found a smaller value, put it at the top 
    if (swapMade)
    {
      swap(&((Q->heap)[index]),&((Q->heap)[current]));
      index = current;
    }
  }
  // if no switches were made, our heap is balanced
  return;

}

//technically fixHeap because the queue we're 'building' isn't really a heap
void buildHeap(queue* Q)
{
  for(int i = (Q->last)/2; i>=0; i--)
  {
    heapify(Q, i);
  }
}

//decrease key of vertex at index
void decKey(queue* Q, int index, float newDist)
{
  vertex v=(Q->heap)[index];  
  vertex u={newDist, v.val};
  (Q->heap)[index]= u;
}
