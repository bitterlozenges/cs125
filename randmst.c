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


float dist(float a[], float b[], int dim);

float prim(float** verts, float** weights, int numpoints, int dimension); 

void printMat(float** mat, int x_dim, int y_dim);

// argv = ["randmst", 0, numpoints, numtrials, dimension]
int main(int argc, char **argv)
{	
	// ensure correct usage
	if (argc != 5)
	{
		printf("Usage: ./randmst 0 numpoints numtrials dimension");
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
		float treeweight = prim(verts, weights, n, dimension);

		totalweight += treeweight;

	}

	printf("The average weight of a %i-dimensional minimum spanning tree with with %i verticies is: \n", dimension, n);
	printf("%f", totalweight / numtrials);

	


}

float prim(float** verts, float** weights, int numpoints, int dimension)
{
	float sum = 0;
	for (int i=0; i < numpoints ; i++)
	{	
		for(int j=0; j < numpoints; j++)
		{
			sum+= weights[i][j];
		}
	}
	return sum;
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









