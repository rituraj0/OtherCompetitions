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


deque<ll> in;
int n;
ll L,R,ql,qr;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>L>>R>>ql>>qr;

 ll x;

 for(int i=0;i<n;i++)
 {
     cin>>x;
     in.push_back(x);
 }

 ll ans=0;
 int prev = -1;

 while( ! in.empty())
 {
    ll cost_left = in.front()*L + ( prev ==0 )*ql;

    ll cost_right = in.back()*R + (prev == 1 )*qr;

    if( cost_left == min(cost_left , cost_right) )
    {
        prev = 0;
        ans+=cost_left;
        in.pop_front();
    }
    else
    {
        prev =1 ;
        ans+=cost_right;
        in.pop_back();
    }

 }

 cout<<ans<<endl;

 return 0;

}
