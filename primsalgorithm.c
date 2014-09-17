#include <stdio.h>
#include <stdlib.h>

float Prim(vertex *q, float **g)
{
	//Take seed to be the first vertex in heap array. Change its distance from the tree to be 0.
	deckey(q, 0, 0);
	//delete this vertex from "v-s"
	delmin(q);

	//initialize the queue size to the number of remaining vertices.
	int qsize= m-1;
	
	//initialize the weight of the MST so far to 0.
	float weight=0;

	//while the heap isn't empty, delete the minimum element and update the
	// remaining vertices distances from the working tree S
	while (!isEmpty (q))
	{
		struct vertex u = delmin(q);
		weight = u.dist;
		for (i=0; i<qsize; i++)
		{
			struct vertex v=q[i];
			int distFromU = g[v.val, u.val];
			if(distFromU < v.dist)
				deckey(q,i, distFromU);
		}
		heapify(q);
		qsize--;
	}
	return weight;
}	

//change the distance of the vertex at index to newDist
void deckey(q, int index, float newDist)
{
	vertex v=q[index];	
	vertex u={newDist, v.val};
	q[index]= u;
}
