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


float sq_dist(float a[], float b[], int dim);

void printMat(float** mat, int x_dim, int y_dim);

float Prim(float* Q, float **g, int n);

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

	// initialize the weights matrix;
	float** weights = malloc(n*sizeof(float*));

	for (int i = 0; i < n; i++)
	{
		weights[i] = malloc(n*sizeof(float));
	}

	// if dimension is 0, randomly generate the weights
	if (dimension==0)
	{

		for (int t = 0; t < numtrials; t++ )
		{
			// populate the weights array with the euclidean distances
			for (int i = 0; i < n; i++)
			{
				for(int j=0; j < i; j++)
				{
					float r = pow((float)rand()/(float)RAND_MAX, 2);
					weights[i][j] = r;
					weights[j][i] = r;
				}

				weights[i][i] = 0;
			}

			// TODO: define prim
			float* Q = (init(n));

			float treeweight = Prim(Q, weights, n);
			totalweight += treeweight;
		}

		printf("%f %i %i %i \n", totalweight / numtrials, n, numtrials, dimension);
		return 0;
	}


	// the array of verticies (each entry is an array)
	float** verts = malloc(n*sizeof(float*));

	for (int i = 0; i < n; i++)
	{
		verts[i] = malloc(dimension*sizeof(float));
	}

	// perform numtrials number of trials and add weight to totalweight
	for (int t = 0; t < numtrials; t++ )
	{
		


		// initialize the vertices array
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < dimension; j++)
			{
				verts[i][j] = (float)rand()/(float)RAND_MAX;;
			}
		}

		// for debugging
		// printf("\nprinting verticies:\n");
		// printMat(verts, n, dimension);

		// populate the weights array with the euclidean distances
		for (int i = 0; i < n; i++)
		{
			for(int j=0; j < i; j++)
			{
				float* v1 = verts[i];
				float* v2 = verts[j];
				
				// calculate the square of the distance 
				float sq_distance = sq_dist(v1,v2,dimension);

				// populate weights array
				weights[i][j] = sq_distance;
				weights[j][i] = sq_distance;
			}
			weights[i][i] = 0;
		}
		// for debugging
		// printf("\nprinting weights:\n");
		// printMat(weights, n, n);

		// TODO: define prim
		float* Q = (init(n));

		float treeweight = Prim(Q, weights, n);

		totalweight += treeweight;

		

	}

	// free willy
	for (int i = 0; i < n; i++)
	{
		free(weights[i]);
		free(verts[i]);
	}

	free(verts);
	free(weights);

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

float Prim(float* Q, float **g, int n)
{
	//initialize the weight of the MST so far to 0.
	float weight=0;

	//while the heap isn't empty, delete the minimum element and update the
	// remaining vertices distances from the working tree S
	for (int j=0; j< n;j++)
	{
		int ind = delMin(Q, n);

		// printf("ind: %d \n", ind);

		float min = Q[ind];
		Q[ind] = -1;
		weight += sqrt(min);

		// printf("%f \n", weight);

		for (int i=0; i<n; i++)
		{
			float distFromU = g[ind][i];
			if(distFromU < Q[i])
				//decKey(Q,i, distFromU);
				Q[i]=distFromU;
		}
	}
	return weight;
}	











