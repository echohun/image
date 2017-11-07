#include <stdio.h>
#include <math.h>
#define N 500
int main()
{
	int i;
	float x[3];
	float c[3][4]={10,-2,-1,3,-2,10,-1,15,-1,-2,5,10};
	void GS(float *,int,float[]);
	GS(c[0],3,x);
	for (i=0;i<=2;i++)
	printf("x[%d]=%f\n",i,x[i]);
}
void GS(float *a,int n,float x[])
{
	int i,j,k=1;
	float d,dx,eps;
	for(i=0;i<=n-1;i++)
	  x[i]=0.0;
	while(1)
	{
		eps=0;
		for(i=0;i<=n-1;i++)
		{
			d=0;
			for(j=0;j<=n-1;j++)
			{
				if(j==i)
				continue;
				d+=*(a+i*(n+1)+j)*x[j];
			}
			dx=(*(a+i*(n+1)+n)-d)/(*(a+i*(n+1)+i));
			eps+=fabs(dx-x[i]);
			x[i]=dx;
		}
		if(eps<1e-6)
		{
		
		   printf("迭代次数为：%d\n",k);
     	   return;
		}
		if(k>N)
		{
			printf("迭代发散\n");
			return;
		}
		k++;	
	}
}
