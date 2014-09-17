#include <stdio.h>
#include <stdlib.h>

float Prim(queue* q, float **g)
{
	//Take seed to be the first vertex in heap array. Change its distance from the tree to be 0.
	decKey(q, 0, 0);
	//delete this vertex from "v-s"
	delMin(q);
	
	//initialize the weight of the MST so far to 0.
	float weight=0;

	//while the heap isn't empty, delete the minimum element and update the
	// remaining vertices distances from the working tree S
	while (q->last >=0)
	{
		vertex u = delMin(q);
		weight += u.dist;
		for (i=0; i<q->last; i++)
		{
			vertex v=(q->heap)[i];
			int distFromU = g[v.val][u.val];
			if(distFromU < v.dist)
				decKey(q,i, distFromU);
		}
		buildHeap(q);
	}
	return weight;
}	

//change the distance of the vertex at index to newDist
void deckey(queue* q, int index, float newDist)
{
	vertex v=(q->heap)[index];	
	vertex u={newDist, v.val};
	(q->heap)[index]= u;
}
