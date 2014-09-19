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

#define SIZE 65536
#define INFTY 10.0

typedef struct queue
{
  int length;
  float heap[SIZE];
} queue;


/*
 * n represents number of vertices
 */
queue init(int n);

int delMin(queue* Q);

//decrease key of vertex at index
void decKey(queue* Q, int index, float newDist);


#endif
