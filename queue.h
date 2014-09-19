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



typedef struct vertex
{
  float distFromS;
  AdjListNode* adjacentVertices;

} vertex;

typedef struct queue
{
  int last;
  // contains the indicies of vertex in verts[]
  int heap[SIZE];
} queue;

typedef struct AdjListNode
{
	// contains the index of vertex in verts[]
    int self;
    float edgeLength;
    struct AdjListNode* next;
};


/*
 * n represents number of vertices
 */
queue init(int n);

//TODO: THIS SEEMS BAD PUT ON TOP YO
void heapify(queue* Q, int index);

void swap(vertex* v1, vertex* v2);

vertex delMin(queue* Q);

void heapify(queue* Q, int index);

//technically fixHeap because the queue we're 'building' isn't really a heap
void buildHeap(queue* Q);

//decrease key of vertex at index
void decKey(queue* Q, int index, float newDist);

AdjListNode* newAdjListNode(int dest)


#endif
