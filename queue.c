#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*
 * n represents number of vertices
 */
queue init(int n, float** verts, float cutoff)
{
  queue Q;
  Q.last = n - 1;

  // fill the queues with vertices

    for (int i = 0; i < n; i++)
    {
      q.heap[i]=i;
    }

  return Q;
}

//TODO: THIS SEEMS BAD PUT ON TOP YO
void heapify(queue* Q, int index);

// swaps two elements in the heap at indices v1 and v2 
void swap(queue* Q, int v1, int v2)
{
  int temp = Q->heap[v1];
  Q->heap[v1] = Q->heap[v2];
  Q->heap[v2] = temp;
}

// deletes the root of the heap and returns the vertex the root points to
vertex delMin(queue* Q, vertex* G)
{
  vertex min = G[(Q->heap)[0]];
  // passes into swap the address of the root of Q and the last leaf
  // swap(&(Q->heap)[0],&(Q->heap)[Q->last]);
  swap(Q, 0, Q->last);
  Q->last -= 1;
  heapify(Q, G, 0);
  return min;
}

// balances heap assuming only the root violates the heap invariant
void heapify(queue* Q, vertex* G, int index)
{
  // return if heap is empty
  if (Q->last < 0)
    return;

  int left = 2*index + 1;
  int right = 2*index + 2;
  int current = index;

  // if our vertex has children and the left child is smaller
  if (left <= Q->last && G[Q->heap[left]]->distFromS < G[Q->heap[current]]->distFromS)
  // if (left <= Q->last && (Q->heap)[left]->distFromS < (Q->heap)[current]->distFromS)
    current = left;
  // if vertex has children and the right child is smaller
  if (right <= Q->last && G[(Q->heap)[right]]->distFromS < G[(Q->heap)[current]]->distFromS)
    current = right;
  // if we found a smaller value, put it at the top 
  if (current != index)
  {
    swap(Q, current, index);
    heapify(Q,G,current);
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
void decKey(vertex* Graph, int index, float newDist)
{
  Graph[index].distFromS = newDist;
}

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int s, float e)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->self = s;
    newNode->edgeLength = e;
    newNode->next = NULL;
    return newNode;
}
