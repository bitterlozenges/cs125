#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 65356
#define INFTY 10


typedef struct vertex
{
  float dist;
  int val;
  int left;
  int right;
}
  vertex;

typedef struct queue
{
  int last;
  vertex heap[SIZE];
}
  queue;

void swap(vertex* v1, vertex* v2)
{
  vertex temp = *v1;
  *v1 = *v2;
  *v2 = temp;

}

queue* init()
{
  queue Q;
  Q.last = SIZE - 1;

  // ask tiffany if she's zero-indexing
  for (i=0;i<SIZE;i++)
  {
    Q.heap[i] = {INFTY,i,2*i+1,2*i+2}; 
  }

  return &Q;
}


bool is_empty(queue* Q)
{
  return (Q.last < 0);
}

vertex delmin(queue* Q)
{
  min = Q.heap[0];
  swap(Q.heap[0],Q.heap[Q.last]);
  Q->last -= 1;
  heapify(Q,0);
  return min;
}

void heapify(queue* Q, int index)
{
  // think of better var name than last (which is NOT the same as Q.last)
  // also fix syntax and shit
  if (is_empty(Q))
    return;

  Q[index].left = 2*index + 1;
  Q[index].right = 2*index + 2;
  last = index;

  // if our vertex has children and the left child is smaller
  if (left <= Q.last && Q.heap[left] < Q.heap[Q.last])
    last = left;
  // if vertex has children and the right child is smaller
  if (right <= Q.last && Q.heap[right] < Q.heap[Q.last])
    last = right;
  // if we found a smaller value, put it at the top 
  if (last != index)
  {
    swap(Q.heap[index],Q.heap[last]);
    heapify(Q,last);
  }
  // if no switches were made, our heap is balanced
  return;

}
