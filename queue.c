#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


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

  int left = 2*index + 1;
  int right = 2*index + 2;
  int last = index;

  // if our vertex has children and the left child is smaller
  if (left <= Q->last && (Q->heap)[left].dist < (Q->heap)[Q->last].dist)
    last = left;
  // if vertex has children and the right child is smaller
  if (right <= Q->last && (Q->heap)[right].dist < (Q->heap)[Q->last].dist)
    last = right;
  // if we found a smaller value, put it at the top 
  if (last != index)
  {
    swap(&((Q->heap)[index]),&((Q->heap)[last]));
    heapify(Q,last);
  }
  // if no switches were made, our heap is balanced
  return;

}

//technically fixHeap because the queue we're 'building' isn't really a heap
void buildHeap(queue* Q)
{
  for(int i = (Q->last - 1)/2; i>=0; i--)
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
