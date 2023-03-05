#include<iostream>
#include<iomanip>
 
using namespace std;
 
// A function to print the matrix.
void PrintMat(int **mat, int n)
{
	int i, j;
 
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(3)<<"("<<i+1<<")";
	cout<<"\n\n";
 
	// Print 1 if the corresponding vertexes are connected otherwise 0.
	for(i = 0; i < n; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < n; j++)
		{
			cout<<setw(4)<<mat[i][j];
		}
		cout<<"\n\n";
	}
}
 
int main()
{
	int i, v, e, j, v1, v2;
 
	// take the input of the number of edges.
	cout<<"Enter the number of vertexes of the graph: ";
	cin>>v;
 
	// Dynamically declare graph.
	int **graph;
	graph = new int*[v];
 
	for(i = 0; i < v; i++)
	{
		graph[i] = new int[v];
		for(j = 0; j < v; j++)graph[i][j] = 0;
	}
 
	cout<<"\nEnter the number of edges of the graph: ";
	cin>>e;
 
	// Take the input of the adjacent vertex pairs of the given graph.
	for(i = 0; i < e; i++)
	{
		cout<<"\nEnter the vertex pair for edge "<<i+1;
		cout<<"\nV(1): ";
		cin>>v1;
		cout<<"V(2): ";
		cin>>v2;
 
		graph[v1-1][v2-1] = 1;
		graph[v2-1][v1-1] = 1;
	}
 
	// Print the 2D array representation of the graph.
	PrintMat(graph, v);
}