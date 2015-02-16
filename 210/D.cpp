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

#define maxn 2009

ll in[maxn];
ll dp[maxn];
int n,can;

bool cool( ll dist)
{
     for(int i=1;i<=n;i++)
     {
         dp[i]=i-1;

         for(int j=1;j<i;j++)
             if( llabs(in[i]-in[j]) <= (i-j)*dist ) // in[j] , in[j]+x , in[j]+2*x upto x , including , i  not changed , only [j+1,i-1]
               dp[i]=min( dp[i] , dp[j] + i-j-1); //

         if( dp[i]+n-i <=can )//i k bad sabko same kar do n tak
             return true;
     }

     return false;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>can;

 for(int i=1;i<=n;i++)
     cin>>in[i];

 ll lo=0,hi= (1LL<<50);


 while( lo < hi)
 {
     ll mid = (lo+hi)/2;

     if( cool(mid) )
     {
         hi=mid;
     }
     else
     {
         lo= mid +1;
     }
 }

 cout<<hi<<endl;

 return 0;

}
