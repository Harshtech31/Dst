#include<stdio.h>
void shell_sort(int a[],int n)
{
    int i,j,temp,gap;
    for(gap=n/2;gap>0;gap=gap/2)
    {
      for(i=gap;i<n;i++)
      {
        j=i;
        temp=a[i];
        while(temp<a[j-gap] && j>=gap)
        {
          a[j]=a[j-gap];
          j=j-gap;
        }
        a[j]=temp;
      }
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
void main()
{
  int n,i;
  printf("Enter size ");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  shell_sort(a,n);
}