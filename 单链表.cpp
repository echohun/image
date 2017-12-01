#include<stdio.h>  
#include<malloc.h>  

typedef int DataType;  //int型数据 
typedef struct LNode   
{  
    DataType data;  
    struct LNode *next;  
} LinkList;


//显示结果 
void DispList(LinkList*L)  
{  
    LinkList *p=L->next;  
    while(p!=NULL)  
    {  
        printf("%d ",p->data);  
        p=p->next;  
    }  
    printf("\n");  
}  


//释放链表 
void DestroyList(LinkList *&L)  
{  
    LinkList*p=L->next,*pre=L;  
    while(p!=NULL)  
    {  
        free(pre);  
        pre=p;  
        p=pre->next;  
    }  
    free(pre);  
}  

//尾插法建表  
void CreatListR(LinkList *&L,DataType a[],int n)  
{  
    LinkList *s,*r;  
    L=(LinkList*)malloc(sizeof(LinkList));  //建立头节点 
    r=L;  									//r指针指向头节点 
    for(int i=0; i<n; i++)  
    {  
        s=(LinkList*)malloc(sizeof(LinkList));  
        s->data=a[i];  
        r->next=s;  
        r=s;  
    }  
    r->next=NULL;  
}  


 
//从小到大排序  
void sort(LinkList *&L)  
{  
    LinkList *pre,*p,*q;  
    p=L->next->next;  
    L->next->next=NULL;  
    while(p!=NULL)  
    {  
        q=p->next;  
        pre=L;  
        while(pre->next!=NULL&&pre->next->data<p->data)  
            pre=pre->next;  
        p->next=pre->next;  
        pre->next=p;  
        p=q;  
    }  
}  
///求集合的并  
void Union(LinkList *ha,LinkList*hb,LinkList*&hc)  
{  
    LinkList *pa=ha->next,*pb=hb->next,*pc,*s;  
    hc=(LinkList*)malloc(sizeof(LinkList));  
    pc=hc;  
    while(pa!=NULL &&pb!=NULL )  
    {  
        if(pa->data<pb->data)  
        {  
            s=(LinkList*)malloc(sizeof(LinkList));  
            s->data=pa->data;  
            pc->next=s;  
            pc=s;  
            pa=pa->next;  
        }  
        else if(pa->data>pb->data)  
        {  
            s=(LinkList*)malloc(sizeof(LinkList));  
            s->data=pb->data;  
            pc->next=s;  
            pc=s;  
            pb=pb->next;  
        }  
        else  
        {  
            s=(LinkList*)malloc(sizeof(LinkList));  
            s->data=pa->data;  
            pc->next=s;  
            pc=s;  
            pa=pa->next;  
            pb=pb->next;  
        }  
    }  
    if(pb!=NULL)  
        pa=pb;  
    while(pa!=NULL)  
    {  
        s=(LinkList*)malloc(sizeof(LinkList));  
        s->data=pa->data;  
        pc->next=s;  
        pc=s;  
        pa=pa->next;  
    }  
    pc->next=NULL;  
}  
///求两个有序集合的交用尾插法  
void InterSect(LinkList *ha,LinkList*hb,LinkList*&hc)  
{  
    LinkList *pa=ha->next,*pb,*pc,*s;  
    hc=(LinkList*)malloc(sizeof(LinkList));  
    pc=hc;  
    while(pa!=NULL)  
    {  
        pb=hb->next;  
        while(pb!=NULL&&pb->data<pa->data)  
            pb=pb->next;  
        if(pb!=NULL &&pb->data==pa->data)///B节点在A节点中复制A节点  
        {  
            s=(LinkList*)malloc(sizeof(LinkList));  
            s->data=pa->data;  
            pc->next=s;  
            pc=s;  
        }  
        pa=pa->next;  
    }  
    pc->next=NULL;  
} 

//输入 
int input(int *a)
{

	int n=0,i;
    for(i=0;;i++)
    {

        scanf("%d",&a[i]);
        n++;
        if(getchar()=='\n')break; //遇回车中断   
    }  
    return n;
} 

//删除重复数据 
int remove_repeat(int *a, int l)
{
    int i, j, k;
    
    for(i = 0; i < l; i ++)
    {
        for(j = i+1; j <l; j ++)//对后面每个元素比较，去重。
        {
            if(a[j] == a[i])//发现重复元素。
            {
                for(k = j+1; k<l; k ++)//依次前移一位。
                    a[k-1] = a[k];
                l--;//总长度减一。
            }
        }
    }
    
    return l;//返回新的长度值。
}		
	
int main()  
{  
    LinkList *ha,*hb,*hc,*hd;  	//分别存放 A  B  并  交 
    int num_a,num_b;
    DataType a[100],b[100];
	printf("Please input a:\n"); 
    num_a=input(a);				//输入a 
    printf("Please input b:\n");
	num_b=input(b);				//输入b 
	num_a=remove_repeat(a,num_a);	//删除a中重复 
	num_b=remove_repeat(b,num_b);	//删除b中重复 
    printf(" 集合的运算如下:\n");  
    CreatListR(ha,a,num_a);  		//创建链表 
    CreatListR(hb,b,num_b);  		//创建链表 
    printf(" 原集合A: ");  
    DispList(ha); 
    printf(" 原集合B: ");  
    DispList(hb);  
    sort(ha);  					//排序 
    sort(hb);  
    printf(" 有序集合A: ");  
    DispList(ha);  
    printf(" 有序集合B: ");  
    DispList(hb);  
    Union(ha,hb,hc);  			//并 
    printf(" 集合的并C: ");  
    DispList(hc);  				//交 
    InterSect(ha,hb,hd);  
    printf(" 集合的交C: ");  
    DispList(hd);  
    DestroyList(ha);  
    DestroyList(hb);  
    DestroyList(hc); 
    DestroyList(hd); 
    return 0;  
}  
