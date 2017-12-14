#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100
#define N 8

#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))

// 邻接矩阵
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph,*pG;

int count = 0;

typedef struct{
	char data[MAX];
	int front;
	int rear;
}SeQueue;

SeQueue* Q=(SeQueue*)malloc(sizeof(SeQueue));

int visited[N]={0,0,0,0,0,0,0,0};//辅助数组置零 

//返回ch在邻接矩阵中的位置
static int get_position(Graph g, char ch)
{
    int i;
    for(i=0; i<g.vexnum; i++)
        if(g.vexs[i]==ch)
            return i;
    return -1;
}

//创建邻接矩阵 
Graph* create_graph()
{
    char vexs[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g','h'};
    char edges[][2] = {
        {'a', 'b'}, 
        {'a', 'c'}, 
        {'b', 'd'}, 
        {'b', 'e'}, 
        {'c', 'd'}, 
        {'c', 'h'}, 
        {'d', 'f'},
		{'d', 'g'},
		{'e', 'f'},
		{'f', 'g'},
		{'g', 'h'}}; 
    int vlen = LENGTH(vexs);
    int elen = LENGTH(edges);
    int i, p1, p2;
    Graph* pG;
    
    // 输入顶点数和边数
    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL )
        return NULL;
    memset(pG, 0, sizeof(Graph));

    // 初始化顶点数和边数
    pG->vexnum = vlen;
    pG->edgnum = elen;
    // 初始化顶点
    for (i = 0; i < pG->vexnum; i++)
    {
        pG->vexs[i] = vexs[i];
    }
    // 初始化边
    for (i = 0; i < pG->edgnum; i++)
    {
        // 读取边的起始顶点和结束顶点
        p1 = get_position(*pG, edges[i][0]);
        p2 = get_position(*pG, edges[i][1]);

        pG->matrix[p1][p2] = 1;
        pG->matrix[p2][p1] = 1;
    }

    return pG;
}

//打印矩阵
void print_graph(Graph G)
{
    int i,j,k;

    printf("Graph:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%d ", G.matrix[i][j]);
        printf("\n");
    }
}

void DFSA(Graph G,int i)
{
	int j;
	printf("node: %c\n",G.vexs[i]);
	visited[i]=1;
	for(j=0;j<N;j++)
	{
		if((G.matrix[i][j]==1)&&(visited[j]==0))
			DFSA(G,j);
	}
	
}
void SetNULL(SeQueue *sq)
{
	sq->front=sq->rear=0;
}


int ENQUEUE(SeQueue *sq,int x)
{

		sq->rear=(sq->rear+1)%MAX;
		sq->data[sq->rear]=x;
		count++;
}

int DEQUEUE(SeQueue *sq,int x)
{

		sq->front=(sq->front+1)%MAX;
		x=sq->data[sq->front];
		count--;
		return x;
}


void BFSA(Graph G,int k)
{

	int i,j;
	SetNULL(Q);
	printf("node: %c\n",G.vexs[k]);
	visited[k]=1;
	ENQUEUE(Q,k);
	while(count)
	{
		i=DEQUEUE(Q,k);
		for(j=0;j<N;j++)
		{
			if((G.matrix[i][j]==1)&&(visited[j]!=1))
			{
				printf("node: %c\n",G.vexs[j]);
				visited[j]=1;
				ENQUEUE(Q,j);
			}
		}
	} 

}



int main()
{

    Graph* pG;
    int x,y;
    pG = create_graph();//创建矩阵
    print_graph(*pG);// 打印矩阵
    printf("请输出遍历起始位置(0代表a、1代表b，以此类推):\n");
    scanf("%d",&x);
    printf("请选择遍历方式：1.深度遍历\t2.广度遍历\n");
    scanf("%d",&y);
    if(y==1)
    DFSA(*pG,x);//深度遍历 
    else if(y==2)
	BFSA(*pG,x);//广度遍历
	else
	printf("Input Error\n");
}
