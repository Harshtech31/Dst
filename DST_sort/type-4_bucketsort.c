#include<stdio.h>
void insert_sort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        j=i-1;
        t=a[i];
        while(t>a[j] && j>=0)
        {
          a[j+1]=a[j];
          j=j-1;
        }
        a[j+1]=t;
    }
}
int main()
{
int i,j,size,buckets,a,b,c,start,end;
printf("Enter size ");
scanf("%d",&size);
int ar[size];
printf("Enter elements ");
for(i=0;i<size;i++)
scanf("%d",&ar[i]);
printf("Enter no. of buckets ");
scanf("%d",&buckets);
int bu[buckets][size];
for(a=0;a<buckets;a++)
{
  for(b=0;b<size;b++)
  {
    bu[a][b]=0;
  }
}
int k=0;
for(i=0;i<buckets;i++)
{
  printf("Enter range ");
  scanf("%d %d",&start,&end);
  k=0,c=0;
  for(j=0;j<size;j++)
  {
    if(ar[k]>=start && ar[k]<=end)
    bu[i][c++]=ar[k];
    k++;
  }
  insert_sort(bu[i],c);
}
printf("After sorting \n");
for(i=0;i<buckets;i++)
{
  for(j=0;j<size;j++)
  {
    if(bu[i][j]!=0)
    printf("%d ",bu[i][j]);
  }
}
}