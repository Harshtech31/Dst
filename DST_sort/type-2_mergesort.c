#include<stdio.h>
void merge(int ar[],int low,int mid,int high);
void merge_sort( int ar[],int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(ar,low,mid);
        merge_sort(ar,mid+1,high);
        merge(ar, low,mid,high);
    }
}
void merge(int ar[],int low,int mid,int high)
{
    int i,k,j;
    int c[20];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high)
    {
        if(ar[i]<=ar[j])
        {
            c[k++]=ar[i++];
        }
        else
        {
            c[k++]=ar[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=ar[i++];
    }
    while(j<=high)
    {
        c[k++]=ar[j++];
    }
    for(k=low;k<=high;k++)
    {
        ar[k]=c[k];
    }
}
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<=size-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,size-1);
    printf("After sorting");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}