#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

int dp[110][250];
int sum[110][250];
int cont[110];

int n;
int in[200009];


int mod= 1000000007;

void solve()
{
     fill(cont,0);
     fill(sum,0);

     scanf("%d",&n);

     for(int i=1;i<=n;i++)
         scanf("%d",&in[i]);

       int ans=n+1;

     for(int i=1;i<=n;i++)
     {
            int curr=in[i];

            for(int prev=1;prev<=100;prev++)
            {
                int d=in[i]-prev;
                dp[curr][d+100]=0;
                dp[curr][d+100]=sum[prev][d+100]+cont[prev];

                sum[curr][d+100]=sum[curr][d+100]+ dp[curr][d+100];

                  if( sum[curr][d+100]>=mod)
                     sum[curr][d+100]-=mod;

                ans=  ans + dp[curr][d+100] ;
                  if( ans>=mod)
                     ans-=mod;
            }

            cont[curr]++;
     }

     int all=1;

     for(int i=1;i<=n;i++)
        {
            all=all*2;

            if(all>=mod)
                 all-=mod;
        }


     all=all-ans;

     if(all>=mod)
         all-=mod;
     if(all<0)
         all+=mod;

     printf("%d\n",all);

}

int main()
{

 int test;

 scanf("%d",&test);

 while(test--)
 {
     solve();
 }

 return 0;

}
