#include <stdio.h>
#include <stdlib.h>

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
			int distFromU = g[v.val][u.val];
			if(distFromU < v.dist)
				decKey(Q,i, distFromU);
		}
		buildHeap(Q);
	}
	return weight;
}	


