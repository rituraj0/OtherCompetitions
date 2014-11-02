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


int main()
{
 ios_base::sync_with_stdio(0);

 int a[4];

 for(int i=0;i<4;i++)
     cin>>a[i];

 string in;
 cin>>in;

 int ans=0;

 for(int i=0;i<in.sz;i++)
     ans+=a[ in[i]-'1' ];

 cout<<ans<<endl;


 return 0;

}
