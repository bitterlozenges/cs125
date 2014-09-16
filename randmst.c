#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float dist(float a[], float b[], int dim);

// argv = ["randmst", 0, numpoints, numtrials, dimension]
int main(int argc, char **argv)
{	
	// ensure correct usage
	if (argc != 5)
	{
		printf("Usage: randmst 0 numpoints numtrials dimension");
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
		float verts[n][dimension]; 

		// initialize the weights matrix;
		float weights[n][n];

		// initialize the verticies array
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < dimension; j++)
			{
				verts[i][j] = rand();
			}
		}

		// populate the weights array with the euclidean distances
		for (int i=0; i < n; i++)
		{
			for(int j=0; j<=i; j++)
			{
				float v1[dimension] = verts[i];
				float v2[dimension] = verts[j];
				
				// calculate the distance 
				int distance = dist(v1,v2,dimension);

				// populate weights array
				weights[i][j] = distance;
				weights[j][i] = distance;
			}
		}

		// TODO: define prim
		int treeweight = prim(verts, weights);

		totalweight += treeweight;
	}

	printf("The average weight of a %i-dimensional minimum spanning tree with with %i verticies is: \n", dimension, n);
	printf("%f", totalweight / numtrials);


}


//calculates the euclidean distance between two points of dimension "dim"
float dist(float a[], float b[], int dim)
{
	float square_sum = 0;
	for (int k=0; k < dim; k++)
	{
		square_sum += (a[k] - b[k])^2;
	}

	return sqrt(square_sum);
}









