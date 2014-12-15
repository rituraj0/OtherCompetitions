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

vector< pair<ll,ll> > cantake;
int main()
{
 ios_base::sync_with_stdio(0);

  ll n,r,avg;

  cin>>n>>r>>avg;

  ll req= n*avg;

   ll mila=0;

  ll x,y;

  for(int i=0;i<n;i++)
  {
      cin>>x;

      mila+=x;

      cin>>y;

      cantake.pb( mp(y,r-x));
  }


  sort( cantake.begin() , cantake.end() );

  ll ans=0;

  for(int i=0;i<sz(cantake);i++)
  {
      ll take=min( cantake[i].Y , max(0LL,req-mila) );

      ans+= take*cantake[i].X;

      mila+=take;
  }

  cout<<ans<<endl;


 return 0;

}
