/****************************************************************************
 * queue.h
 *
 * Computer Science 125
 * Problem Set 2
 *
 * Declares a queue's functionality.
 ***************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 65356
#define INFTY 10.0


typedef struct vertex
{
  float dist;
  int val;
} vertex;

typedef struct queue
{
  int last;
  vertex heap[SIZE];
} queue;


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

void swap(vertex* v1, vertex* v2);

vertex delMin(queue* Q);

void heapify(queue* Q, int index);

//technically fixHeap because the queue we're 'building' isn't really a heap
void buildHeap(queue* Q);

//decrease key of vertex at index
void decKey(queue* Q, int index, float newDist);


#endif
