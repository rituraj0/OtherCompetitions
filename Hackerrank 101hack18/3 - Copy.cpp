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

#define maxn 50009

const ll mod=1000000009LL;

int aage[maxn];

ll memo[maxn][130];//maxn[(1<<7)]

vector< pair<int,int> > in;

int n,k;

ll solve (int curr , int mask)
{
    if( curr==n)
    {
       print(mask);

        if( mask == (1<<k)-1)
             return 1;

        return 0;
    }

    if( memo[curr][mask]!=-1)
         return memo[curr][mask];

    ll ans=0;

    memo[curr][mask]=ans;

    //take current one , to maintian strictly increaing move forwas

    ans=solve( aage[curr] ,mask|(1<< in[curr].Y) );


    //dont take this , try  next one, oleave mask as it is

    ans=( ans + solve( curr+1  , mask) )%mod;

    return memo[curr][mask]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

  cin>>n>>k;

  int a,b;

  for(int i=0;i<n;i++)
  {
      cin>>a>>b;

      b--;

      in.pb( mp(a,b) );
  }


  sort( in.begin() , in.end() );

  aage[n-1]=n;

  for(int i=n-2;i>=0;i--)
     if( in[i].X==in[i+1].X)
        aage[i]=aage[i+1];
      else
         aage[i]=i+1;

   for(int i=0;i<n;i++)
     cout<<in[i].X<<"  "<<in[i].Y<<"  "<<aage[i]<<endl;

   cout<<"Hello world\n";

  fill( memo, -1 ) ;

  cout<<solve(0,0)<<endl;

 return 0;

}
