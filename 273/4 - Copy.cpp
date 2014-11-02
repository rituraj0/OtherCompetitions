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

const ll mod=1000000007LL;

ll memo[10][200005];

int req[1005];

int R,G;

int height(int h , int gd)//h th height pe rakhne ja rah ahai
{

    if( memo[h&][gd&1]!=-1)
         return memo[h&1][gd&1];

    int rd=req[h-1]-gd;

    int r_rem=R-rd;
    int g_rem=G-gd;

    cout<<h<<"  "<<gd<<"  "<<r_rem<<"  "<<g_rem<<endl;

    int ans=0;

    //keep r
    if( h <=r_rem)
    {
        ans=max(ans, height(h+1,gd)+1 );
    }

    if( h <= g_rem)
    {
        ans=max( ans, height( h+1, gd + h )+1 );
    }

        cout<<h<<"  "<<gd<<"  "<<r_rem<<"  "<<g_rem<<"   "<<ans<<endl;

    return memo[h][gd]=ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

 for(int i=0;i<=1000;i++)
 {
     req[i]=i*(i+1)/2;
 }

 fill(memo,-1);

 cin>>R>>G;

 cout<<height(1,0)<<endl;

 return 0;

}
