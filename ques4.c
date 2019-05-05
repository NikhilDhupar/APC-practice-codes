//printing the tree formed by matrix
#include<stdio.h>
#include<stdlib.h>
void tree(int **a,int i,int j,int r,int c,int **storage,int *index,int level)
{
    if((i<r)&&(j<c)&&(j>=0))
    {
        for(int x=0;x<index[level];x++)
        {
            if(a[i][j]==storage[level][x])
            {
                return;
            }
        }
        storage[level][index[level]]=a[i][j];
        index[level]+=1;
        tree(a,i+1,j-1,r,c,storage,index,level+1);
        tree(a,i+1,j+1,r,c,storage,index,level+1);
    }
}
int main()
{
    int r,c;
    printf("Enter rows\n");
    scanf("%d",&r);
    printf("Enter columns\n");
    scanf("%d",&c);
    //printf("rows = %d , columns = %d\n",r,c);
    //int a[r][c];
    int **a;
    a=(int**)malloc(r*sizeof(int*));
    for(int k=0;k<r;k++)
    {
        a[k]=(int*)malloc(c*sizeof(int));
    }
    printf("Enter values\n");
    int count=1;
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        //scanf("%d",&a[i][j]);
        a[i][j]=count;
        count++;
    }
    //  int b=sizeof(int);
    //  int v=sizeof(int*);
    // printf("Size of integer is %d and pointer is %d\n",b,v);
    printf("printing 2d array\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Enter index values to start the tree\n");
    int i,j;
    printf("enter index i\n");
    scanf("%d",&i);
    printf("Enter index j\n");
    scanf("%d",&j);
    int length=r-i;
    int **storage;
    storage=(int**)malloc(sizeof(int*)*(r-i));
    for(int k=0;k<r-i;k++)
    {
        storage[k]=(int*)malloc(sizeof(int)*(k+1));
    }
    int index[r-i];
    for(int k=0;k<length;k++)
    {
        index[k]=0;
    }
    int level=0;
    tree(a,i,j,r,c,storage,index,level);
    printf("printing tree\n");
    for(i=0;i<r;i++)
    {
        printf("length is %d\n",index[i]);
        for(j=0;j<index[i];j++)
        {
            printf("%d ",storage[i][j]);
        }
        printf("\n");
    }   
    free(a);
    free(storage);
    return 0;
}

    