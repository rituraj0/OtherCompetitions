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

string tost( int in)
{
    char ans[20];

    sprintf(ans,"%d",in);

    return ans;
}


bool valid(  string in , int base)
{
    for(int i=0;i<sz(in);i++)
          if( in[i]-'0' >= base)
             return false;

    return true;
}

ll  val( string in , int base)
{
    int ans=0;

    int ml=1;

    for(int i=sz(in)-1;i>=0;i--)
    {
        ans+=ml*(in[i]-'0');

        ml*=base;
    }

    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

// vector< pair<string,int> > all;

    vector<int> all;

 int d,m;

 cin>>n;

 for(int i=0;i<n;i++)
 {
     cin>>m>>d;

     string tp=tost(d);

     if( valid(tp,m))
         all.pb( val(tp,m) );
 }


 map<int,int> cont;

 for(int i=0;i<sz(all);i++)
    cont[ all[i] ]++;

 ll ans=0;

 for(int i=0;i<sz(all);i++)
 {
     ll tp=cont[ all[i] ];

     ans+=tp*(tp-1)/2;

     cont[ all[i] ]=0;
 }

 cout<<ans<<endl;


 return 0;

}
