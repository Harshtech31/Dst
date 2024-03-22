#include<stdio.h>
int partition(int a[],int l,int h)
{
  int p=a[l];
  int i=l+1;
  int j=h,temp;
  while(i<j)
  {
    while(a[i]<p)
    i++;
    while(a[j]>p)
    j--;
    if(i<j)
    {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  if(i>j)
  {
    a[l]=a[j];
    a[j]=p;
  }
  return j;
}
void Quicksort(int a[],int l,int h)
{
  if(l<h)
  {
    int j=partition(a,l,h);
    Quicksort(a,l,j-1);
    Quicksort(a,j+1,h);
  }
}
int main()
{
    int i,n;
    printf("Enter the size ");
    scanf("%d",&n);
    int a[n],l=0,h=n-1;
    printf("Enter elements ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Quicksort(a,l,h);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}