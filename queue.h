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
#define INFTY 10.0

/*
 * n represents number of vertices
 */
queue init(int n);

int delMin(float* Q);

//decrease key of vertex at index
void decKey(float* Q, int index, float newDist);


#endif
