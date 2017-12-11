#include<iostream>
using namespace std;

#define n 8
#define e 11

typedef char vextype;
typedef float adjtype;
typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
}graph;

void CreateAdjArray(gragh *G)	//´´½¨ÁÚ½Ó¾ØÕó 
{
	int i,j,k;
	float w;
	for(i=0;i<n;i++)
		G.vexs[i]=getchar();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G.arcs[i][j]=0;
	for(k=0;k<e;k++)
	{
		scanf("%d%d%f",&i,&j,&w);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
	}
}

void PrintGragh(gragh *G)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("%c\t",G.vexs[i]);
		for(j=0;j<n;j++)
		{
			printf("%f\t",G.arcs[i][j]); 
		}
		printf("\n");
	}
}

int main()
{
	gragh a;
	CreateAdjArray(a);
	PrintGragh(a);
} 
