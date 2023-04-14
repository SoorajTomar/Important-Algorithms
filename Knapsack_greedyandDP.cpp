#include <bits/stdc++.h>
using namespace std;
float fractionalKnapsack(int *p,int *w,int n,int s){
    float pperw[n];
    for(int i=0;i<n;i++){
        pperw[i]=float(p[i]/w[i]);
    }
    for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++){
        if(pperw[j]>pperw[j+1]){
            float t=pperw[j];
            pperw[j]=pperw[j+1];
            pperw[j+1]=t;
            int r=w[j];
            w[j]=w[j+1];
            w[j+1]=r;
        }
    }
    float profitval=0.0;
    for(int i=n-1;i>=0;i--){
        if(s==0)
        break;
        else if(w[i]>s){
        profitval+=pperw[i]*s;
        s=0;
        }
        else{
        profitval+=pperw[i]*w[i];
        s-=w[i];}
    }
    return profitval;
}
int Knapsack01(int *p,int *w,int n,int s){
    int dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=0;j<=s;j++)
    dp[0][j]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=s;j++)
    {
        if(w[i]<=j){
            dp[i][j]=max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
        }
        else
        dp[i][j]=dp[i-1][j];
    }
    return dp[n][s];
}
int main()
{
    int w[]={10,20,30};
    int p[]={60,100,120};
    int s=50;
    int n=3;
    cout<<"0/1 Knapsack Solution:"<<Knapsack01(p,w,n,s)<<endl;
    cout<<"Fractional Knapsack Solution:"<<fractionalKnapsack(p,w,n,s);
    return 0;
}
