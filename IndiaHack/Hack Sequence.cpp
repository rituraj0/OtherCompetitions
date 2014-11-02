#include<iostream>
#include<cstring>
typedef long long l;
#define f(i,n) for(l i=0;i<n;i++)
#define d 1000000007
#define x [2][2]
l a x,C x,n,t;l m(l c x,l a x,l b x){l r x={{0,0},{0,0} };f(i,2)f(j,2)f(k,2)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%d;memcpy(c,r,sizeof(r));}l p(l e){if(e<1){f(i,2)f(j,2)C[i][j]=0;f(i,2)C[i][i]=1;}else if(e&1){p(e-1);m(C,C,a);}else{p(e/2);m(C,C,C);}}int main(){a[0][0]=2014;a[0][1]=69;a[1][0]=1;std::cin>>t;while(t--){std::cin>>n;p(n-2);std::cout<<(C[0][0]+C[0][1])%d<<'\n';}}
