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

#define pii pair<int,int>


vector<pii> in;

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 int a,b;

 for(int i=0;i<n;i++)
 {
     cin>>a>>b;

     in.pb( mp(a,b));
 }


 sort( in.begin(),in.end());

 int ans=0;

 for(int i=0;i<n;i++)
 {
    if( min( in[i].X , in[i].Y) >= ans )
        ans=min( in[i].X , in[i].Y);
    else
        ans=max( in[i].X , in[i].Y);
 }

 cout<<ans<<endl;



 return 0;

}
