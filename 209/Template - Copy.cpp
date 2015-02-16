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

int main()
{

  int n=50;

   vector<int> all;


   for(int i=0;i<2*n;i++)
     all.pb(i+1);

  random_shuffle(all.begin(),all.end());

  vector<int> a,b;

  for(int i=0;i<n;i++)
    a.pb( all[i]);

  for(int i=n;i<2*n;i++)
     if( rand()&1)
       b.pb( all[i]);
     else
      b.pb( -1 );


   for(int i=0;i<sz(a);i++)
    cout<<a[i]<<"  ";


   cout<<"\n\n\n";

   for(int j=0;j<sz(b);j++)
     cout<<b[j]<<" ";



}
