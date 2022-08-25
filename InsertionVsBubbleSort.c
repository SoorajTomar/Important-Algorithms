#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void l(int arr[],int n)
{
    printf("\nINSERTION SORT\n");
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n************");
}
void b(int a[],int n)
{
    printf("\nBUBBLE SORT\n");
    for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++)
    if(a[j]>a[j+1])
    {
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
    }
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n************");
}
int main()
{
    srand(time(0));int n;
    printf("Enter size:");
    scanf("%d",&n);int a[n],b1[n];
    for(int i=0;i<n;i++)
    {a[i]=rand() % (999 + 1 - 1) + 1;
    b1[i]=a[i];}
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d ",b1[i]);
    clock_t t;
    t = clock();
    l(a,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    clock_t t1;
    t1 = clock();
    b(b1,n);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("\nBubble Sort took %f seconds to sort \n", time_taken1);
    printf("\nInsertion Sort took %f seconds to sort \n", time_taken);
    return 0;
}
