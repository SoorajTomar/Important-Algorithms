#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lins(int n,int x,int a[])
{
    int i;
    for(i=0;i<n;i++)
    if(a[i]==x)
    return i;
    return -1;
}
int bins(int a[],int st,int e,int x)
{
    int i,j;
    for(i=0;i<e-1;i++)
    for(j=0;j<e-i-1;j++)
    if(a[j]>a[j+1])
    {
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
    }
    e-=1;
    int m= st+(e-st)/2;
    while(st<=e){
    if(a[m]==x)
    return m;
    else if(a[m]<x)
    st=m+1;
    else if(a[m]>x)
    e=m-1;
    m=(st+e)/2;}
    return -1;
}
int main()
{
    int x,size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    srand(time(0));
    int a[size],i;
    for(i=0;i<size;i++)
    {a[i]=(rand() % (99 - 1 + 1)) + 1;
    printf("%d ",a[i]);}
    printf("\nEnter the value to be found:");
    scanf("%d",&x);
    clock_t t;
    t = clock();
    int l=lins(size,x,a);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nLinear Search took %f seconds to execute and %d found at=%d \n", time_taken,x,l);
    clock_t t1;
    t1 = clock();
    printf("xb=%d\n",x);
    int b=bins(a,0,size,x);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds
    printf("Binary Search took %f seconds to execute and %d found at=%d \n", time_taken,x,b);
    return 0;
}
