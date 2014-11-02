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

vector<int> non( vector<int> in)
{
    vector<int> ans;

    for(int i=0;i<sz(in);i++)
         if( in[i])
          ans.pb( in[i]);

        return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n,cap;

 cin>>n>>cap;

 vector<int> in(n,0);

 int mx=0;

 for(int i=0;i<n;i++)
 {
     cin>>in[i];

     in[i]--;

     mx=max(mx,in[i]);
 }

 sort(in.begin(),in.end());

 int ans=0;

 //cout<<ans<<endl;

 while( sz(in) )
 {
        int mn=in[0];
        int all=sz(in);
        int trip=(all+cap-1)/cap;
        ans+=mn*2*trip;

//        for(int i=0;i<all;i++)
//             cout<<in[i]<<" ";
//
//        cout<<endl;

        for(int i=0;i<all;i++)
             in[i]-=mn;

        in=non(in);
 }

 cout<<ans<<endl;


 return 0;

}
