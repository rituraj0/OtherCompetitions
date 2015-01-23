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

ll a,b;

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>a>>b;

 ll ser = a/b;

 ll add =0;

 if( a%b !=0 )
 {
     add = b;
 }

 cout<<ser+add<<endl;

 return 0;

}
