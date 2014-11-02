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
 ios_base::sync_with_stdio(0);

 ll all, t;

 cin>>all>>t;

 ll mx=0;
 ll rem=(all-t+1);
  mx=rem*(rem-1)/2LL;

 ///
 ll mn=0;

 ll n1=(all/t)+1LL;
 ll c1=(all%t);

 ll n2=(all/t);
 ll c2=t-c1;

 mn+=c1*n1*(n1-1)/2LL;
 mn+=c2*n2*(n2-1)/2LL;

 cout<<mn<<"  "<<mx<<endl;

 return 0;

}
