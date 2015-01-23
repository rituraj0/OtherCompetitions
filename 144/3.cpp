#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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

#define maxn 205
int sum[maxn];
int ht[maxn];

int memo[maxn][maxn*maxn][2];

int a,b;

int solve( int curr , int a_rem , int pc)
{
    if( curr == 0)
         return 0;

     if( memo[curr][a_rem][pc]!=-1 )
             return memo[curr][a_rem][pc];

     memo[curr][a_rem][pc] = 0;

    int all_spent =  sum[curr+1];
    int a_spent = a - a_rem ;
    int b_spent = all_spent - a_spent;
    int b_rem = b - b_spent;

    int ans = (1<<25);

    int diff = min( ht[curr] , ht[curr+1] );

    if( a_rem >= ht[curr])
    {
       int tp =  solve( curr - 1 , a_rem - ht[curr] , 0 );

       if( pc !=0 )
         tp+=diff;

       ans=min( ans , tp );
    }

    if( b_rem >= ht[curr] )
    {
        int tp=solve( curr -1 , a_rem , 1);

        if( pc != 1)
             tp+=diff;

        ans=min( ans , tp);
    }

    return memo[curr][a_rem][pc]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fi;fo;

 int n;

 cin>>n;

 cin>>a>>b;

 for(int i=1;i<=n;i++)
     cin>>ht[i];

 sum[n+1]=0;

 for(int i=n; i>=0; i--)
     sum[i]=sum[i+1] + ht[i];


 fill( memo , -1 );


 for(int curr=1;curr<=n-1;curr++)
     for(int ar=0;ar<=a;ar++)
      {
        solve(curr,ar,0);
        solve(curr,ar,1);
      }

 int ans = (1<<25) ;

 if( a >= ht[n] )
    ans = min( ans ,solve( n-1 , a - ht[n] , 0) );

 if( b >= ht[n] )
     ans = min( ans , solve( n-1 , a , 1) );


 if( ans == (1<<25) )
    ans=-1;

 cout<<ans<<endl;

 return 0;

}
