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


float dist(float a[], float b[], int dim);

void printMat(float** mat, int x_dim, int y_dim);

float Prim(queue* Q, float **g);

// argv = ["randmst", 0, numpoints, numtrials, dimension]
int main(int argc, char **argv)
{	
	// ensure correct usage
	if (argc != 5)
	{
		printf("Usage: ./randmst 0 numpoints numtrials dimension \n");
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

	// perform numtrials number of trials and add weight to totalweight
	for (int t = 0; t < numtrials; t++ )
	{
		// the array of verticies (each entry is an array)
		float** verts = malloc(n*sizeof(float*));

		// initialize the weights matrix;
		float** weights = malloc(n*sizeof(float*));

		for (int i = 0; i < n; i++)
		{
			weights[i] = malloc(n*sizeof(float));
			verts[i] = malloc(dimension*sizeof(float));
		}


		// initialize the verticies array
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < dimension; j++)
			{
				verts[i][j] = (float)rand()/(float)RAND_MAX;;
			}
		}

		// populate the weights array with the euclidean distances
		for (int i=0; i < n; i++)
		{
			for(int j=0; j<i; j++)
			{
				float* v1 = verts[i];
				float* v2 = verts[j];
				
				// calculate the distance 
				float distance = dist(v1,v2,dimension);

				// populate weights array
				weights[i][j] = distance;
				weights[j][i] = distance;
			}
			weights[i][i] = 0;
		}

		// TODO: define prim
		queue q = (init(n));
		queue* Q = &q;

		float treeweight = Prim(Q, weights);

		totalweight += treeweight;

	}

	// printf("The average weight of a %i-dimensional minimum spanning tree with with %i verticies is: \n", dimension, n);
	printf("%f %i %i %i \n", totalweight / numtrials, n, numtrials, dimension);

	


}

//calculates the euclidean distance between two points of dimension "dim"
float dist(float a[], float b[], int dim)
{
	float square_sum = 0;
	for (int k=0; k < dim; k++)
	{
		square_sum += pow( a[k] - b[k] , 2.0);
	}

	return sqrt(square_sum);
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

float Prim(queue* Q, float **g)
{
	//Take seed to be the first vertex in heap array. Change its distance from the tree to be 0.
	decKey(Q, 0, 0);
	//delete this vertex from "v-s"
	delMin(Q);
	
	//initialize the weight of the MST so far to 0.
	float weight=0;

	//while the heap isn't empty, delete the minimum element and update the
	// remaining vertices distances from the working tree S
	while (Q->last >=0)
	{
		vertex u = delMin(Q);
		weight += u.dist;
		for (int i=0; i<=Q->last; i++)
		{
			vertex v=(Q->heap)[i];
			float distFromU = g[v.val][u.val];
			if(distFromU < v.dist)
				decKey(Q,i, distFromU);
		}
		buildHeap(Q);
	}
	return weight;
}	











