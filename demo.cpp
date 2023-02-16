#include<iostream>
#include<stdio.h>
#define N 1000000
using namespace std;

int a[N];
int n,m,kk,x1,x2;

int func1(int x)
{
    return x&(-x);
}

int func2(int x,int w)
{
    for(;x<n;x+=func1(x)) a[x] += w;
}

int func3(int x)
{
    int b = 0;
    for(;x;x-=func1(x)) b+=a[x];
    return b;
}

// struct mytype
// {
//     char a;
//     float b;
//     double c;
//     int d;
//     unsigned long long e;
//     char g;
//     int *h;
//     double *i;
// };


int main()
{
    cout<<func1(0);
    // scanf("%d%d\n",&n,&m);
    cin>>n>>m;
    while(--m)
    {
        // scanf("%d",&kk);
        cin>>kk;
        if(!kk)
        {
            cin>>x1>>x2;
            // scanf("%d%d",&x1,&x2);
            func2(x1+1,x2);
        }
        else 
        {
            cin>>x1>>x2;
            // scanf("%d%d",&x1,&x2);
            cout<<func3(x1+1)<<endl;
        }
    }
    return 0;
}