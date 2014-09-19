/*
 * Let's first represent each point as an array of floats.
 * Feel free to modify this file as needed. 
 *
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "queue.h"
#define INFTY 100.0


float sq_dist(float a[], float b[], int dim);

void printMat(float** mat, int x_dim, int y_dim);

float Prim(queue* Q, vertex* Graph);

// argv = ["randmst", 0, numpoints, numtrials, dimension]
int main(int argc, char **argv)
{	
	// ensure correct usage
	if (argc != 5)
	{
		printf("Usage: ./randmst 0 numpoints numtrials dimension\n");
		return -1;
	}

	//TODO: check to see these are integers
	int dimension = atoi(argv[4]);

	// the number of verticies
	int n = atoi(argv[2]);

	int numtrials = atoi(argv[3]);

	// seed random number generator
	srand(time(NULL));

	// store the sum of the weights, to be divided by numtrials later
	float totalweight = 0;

	float cutoff= 9.0*((float)dimension)/((float) n+1);

	// perform numtrials number of trials and add weight to totalweight
	for (int t = 0; t < numtrials; t++ )
	{
		// the array of vertices (each entry is an array)
		float** verts = malloc(n*sizeof(float*));

		// initialize the vertices array
		for (int i = 0; i < n; i++)
		{
			verts[i] = malloc(dimension*sizeof(float));
			for(int j = 0; j < dimension; j++)
			{
				verts[i][j] = (float)rand()/(float)RAND_MAX;
			}
		}



		// TODO: define prim
		queue q = init(n);
		queue* Q = &q;

		// populate graph Graph
		vertex* Graph= malloc(n*sizeof(vertex));

		for (int i = 0; i < n; i++)
		{
			vertex v = {INFTY, NULL};
			Graph[i]=v;

			for(int j = 0; j < i; j++)
			{
				float squareDistance = sq_dist(verts[i], verts[j], dimension);
				if(squareDistance<cutoff)
				{
					AdjListNode* jNodePtr= newAdjListNode(j, squareDistance);
					AdjListNode* iNodePtr= newAdjListNode(i, squareDistance);
					if(!Graph[i].adjacentVertices)
					{
						Graph[i].adjacentVertices=jNodePtr;

					}
					else
					{
						jNodePtr -> next = Graph[i].adjacentVertices;
						Graph[i].adjacentVertices= jNodePtr;
					}
					if(!Graph[j].adjacentVertices)
					{
						Graph[j].adjacentVertices=iNodePtr;

					}
					else
					{
						iNodePtr -> next = Graph[j].adjacentVertices;
						Graph[j].adjacentVertices=iNodePtr;
					}
				}
			}
		}


		// populate the weights array with the euclidean distances
		// also build adjacency lists

		float treeweight = Prim(Q, Graph);
		totalweight += treeweight;

		// free willy
		for (int i = 0; i < n; i++)
		{
			free(verts[i]);
		}

		free(verts);
		free(Graph);

	}
	printf("%f\n", totalweight);
	// printf("The average weight of a %i-dimensional minimum spanning tree with with %i verticies is: \n", dimension, n);
	printf("%f %i %i %i \n", totalweight / numtrials, n, numtrials, dimension);

	
}

//calculates the euclidean distance between two points of dimension "dim"
float sq_dist(float a[], float b[], int dim)
{
	float square_sum = 0;
	for (int k=0; k < dim; k++)
	{
		square_sum += pow( a[k] - b[k] , 2.0);
	}

	return square_sum;
}

void printMat(float** mat, int x_dim, int y_dim)
{
	for (int i = 0; i < x_dim; i++)
	{
		for (int j=0; j < y_dim; j++)
		{
			printf("%f, ", mat[i][j]);
		}
		printf("\n");
	}
}

void printHeap(queue* Q, vertex* Graph)
{
	printf("[");
	for (int i =0; i <= Q->last; i++)
	{
		printf("%f, ", Graph[Q->heap[i]].distFromS);
	}
	printf("]");
}

float Prim(queue* Q, vertex* Graph)
{
	//Take seed to be the first vertex in heap array. Change its distance from the tree to be 0.
	decKey(Graph, 0, 0);
	
	// initialize the weight of the MST so far to 0.
	float weight=0;

	// while the heap isn't empty, delete the minimum element and update the
	// remaining vertices distances from the working tree S
	while (Q->last >= 0)
	{
		// printHeap(Q,Graph);
		// printf("%i", Q->last);
		vertex min = delMin(Q, Graph);
		// printf("\ndelMin happening. returns %f\n", sqrt(min.distFromS));
		// printHeap(Q,Graph);
		weight += sqrt(min.distFromS);
		// printf("\nweight:%f\n\n", weight);

		// grab the ptr to the adjacent verticies
		AdjListNode* adjVerts = min.adjacentVertices;

		// update verticies in adjVerts
		while(adjVerts!=NULL)
		{	
			// distance from min
			float e = adjVerts->edgeLength;
			// index of the neighbor
			int ind = adjVerts->self;
			if(e < Graph[ind].distFromS)
			{
				decKey(Graph,ind,e);
			}
			adjVerts = adjVerts->next;
			buildHeap(Q, Graph);
		}
	}
	return weight;
}	











