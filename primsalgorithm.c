#include <stdio.h>
#include <stdlib.h>

float Prim(vertex *q, g)
{
	deckey(q, 0, 0);
	delmin(q);

	int qsize= m-1;
	
	float weight=0;

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

void deckey(q, int index, float newDist)
{
	vertex v=q[index];	
	vertex u={newDist, v.val};
	q[index]= u;
}
