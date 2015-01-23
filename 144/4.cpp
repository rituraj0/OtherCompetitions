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

vector<int> ans[1005];

int ele=0;

void solve( int l , int r , int ht )
{
     if( r-l+1 < 2)
        return;

    int mid=(l+r)/2;

    ele = max(ele , ht );

    for(int i=l;i<=mid;i++)
        ans[ht].pb(i);

    solve( l ,mid ,ht +1);
    solve( mid+1,r , ht+1);
}

int main()
{
 ios_base::sync_with_stdio(0);

 fi;fo;

 int n;

 cin>>n;


 solve(0,n-1,0);

 cout<<ele+1<<endl;

 for(int i=0;i<=ele;i++)
     {
            cout<<sz( ans[i] )<<" ";

            for(int j=0;j<sz( ans[i] );j++)
                cout<<ans[i][j]+1<<" ";

            cout<<endl;
     }

 return 0;

}
