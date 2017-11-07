#include<stdio.h>
#include<math.h>

void ColPivot(float *,int,float[]);

int main()
{
	int i;
	float x[3];
	float c[3][4] = {2,4,1,4,2,6,-1,10,1,5,2,2};
	ColPivot(c[0],3,x);
	for (i=0;i<=2;i++)
		printf("x[%d] = %f\n",i,x[i]);
	return 1;
}

void ColPivot(float *c,int n,float x[])
{
	int i,j,k,t;
	float p;
	for(i=0;i<=n-2;i++)
	{
		k = i;
		for(j=i+1;j<=n-1;j++)
			if ( fabs(*(c+j*(n-1)+i) )>(fabs(*((n+1)*k+c+i))) )
			k=j;
		if (k!=i)
			for (j=i;j<=n;j++)
			{
				p = *(c+i*(n+1)+j);
				*(c+i*(n+1)+j) = *(c+k*(n+1)+j);
				*(c+k*(n+1)+j) = p;
			}
		for (j=1+i;j<=n-1;j++)
		{
			p = (*(c+j*(n+1)+i))/(*(c+i*(n+1)+i));
			for (t=i;t<=n;t++)
				*(c+j*(n+1)+t) -= p*(*(c+i*(n+1)+t));
		}
	}
	for (i=n-1;i>=0;i--)
	{
		for (j=n-1;j>=i+1;j--)
			(*(c+i*(n+1)+n)) -= x[j]*(*(c+i*(n+1)+j));
		x[i] = (*(c+i*(n+1)+n))/(*(c+i*(n+1)+i));
	}
}
