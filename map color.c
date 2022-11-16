#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph


void printSolution(string *c,int V,int color[]);
// check if the colored
// graph is safe or not
bool isSafe(int V,bool graph[10][10], int color[])
{
	// check for every edge
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

/* This function solves the m Coloring
problem using recursion. It returns
false if the m colours cannot be assigned,
otherwise, return true and prints
assignments of colours to all vertices.
Please note that there may be more than
one solutions, this function prints one
of the feasible solutions.*/
bool graphColoring(string *c,int V,bool graph[10][10], int m, int i,
				int color[])
{
	// if current index reached end
	if (i == V) {
	
		// if coloring is safe
		if (isSafe(V,graph, color)) {
		
			// Print the solution
			printSolution(c,V,color);
			return true;
		}
		return false;
	}

	// Assign each color from 1 to m
	for (int j = 1; j <= m; j++) {
		color[i] = j;

		// Recur of the rest vertices
		if (graphColoring(c,V,graph, m, i + 1, color))
			return true;

		color[i] = 0;
	}

	return false;
}

/* A utility function to print solution */
void printSolution(string *c,int V,int color[])
{
	cout << "Solution Exists:" " Following are the assigned colors \n";
	for (int i = 0; i < V; i++)
	{cout<<c[i]<<" -> ";
	    if(color[i]==1)
		cout<<"red\n";
		else if(color[i]==2)
		cout<<"yellow\n";
		else
		cout<<"blue\n";
	}
	
}

// Driver code
int main()
{
	/* Create following graph and
	test whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	int V,E;
	int v1,v2;
	cout<<"Enter number of states (verices)";
	cin>>V;
	cout<<"enter number of boundaries between states (edges)";
	cin>>E;
	bool graph[10][10];
	for(int i=1;i<=E;i++)
	{cout<<"enter "<<i<<"th edge vertices";
	cin>>v1>>v2;
	v1=v1-1;
	v2=v2-1;
	graph[v1][v2]=1;
	graph[v2][v1]=1;
	}
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	if(graph[i][j]!=1)
	graph[i][j]=0;
	
	cout<<"enter states\n";
	string c[V];
	for(int i=0;i<V;i++)
	{cout<<"enter "<<(i+1)<<"th state ";
	cin>>c[i];
	}
	
	int m = 3; // Number of colors

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(c,V,graph, m, 0, color))
		cout << "Solution does not exist";
	return 0;
}

// This code is contributed by shivanisinghss2110