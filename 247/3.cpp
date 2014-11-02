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


#define mod 1000000007
ll memo[105][2];

int n,k,d;

ll solve( int wt, int done)
{
     if( wt==0)
     {
          if(!done)
             return 0;

          return 1;
     }

     if( wt < 0)
         return 0;

     if( memo[wt][done]!=-1)
         return memo[wt][done];

       ll ans=0;

       for(int i=1;i<=k;i++)
           if( i >=d)
              ans=(ans+solve(wt-i,1) )%mod;
            else
                 ans=(ans+solve(wt-i,done) )%mod;


            return memo[wt][done]=ans;


}


int main()
{
 ios_base::sync_with_stdio(0);

 fill(memo,-1);

 cin>>n>>k>>d;

 cout<<solve(n,0)<<endl;

 return 0;

}
