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



typedef struct AdjListNode
{
	// index of vertex in Graph
    int self;
    float edgeLength;
    struct AdjListNode* next;
} AdjListNode;

typedef struct vertex
{
  float distFromS;
  AdjListNode* adjacentVertices;

} vertex;

typedef struct queue
{
  int last;
  // contains the indicies of vertex in Graph
  int heap[SIZE];
} queue;



/*
 * n represents number of vertices
 */
queue init(int n);

//TODO: THIS SEEMS BAD PUT ON TOP YO
void heapify(queue* Q, vertex* G, int index);

void swap(queue* Q, int v1, int v2);

vertex delMin(queue* Q, vertex* G);

//technically fixHeap because the queue we're 'building' isn't really a heap
void buildHeap(queue* Q, vertex* G);

//decrease key of vertex at index
void decKey(vertex* G, int index, float newDist);

AdjListNode* newAdjListNode(int s, float e);


#endif
