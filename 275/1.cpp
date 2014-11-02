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

vector<int> solve( int k)
{
   vector<int> ans;

   int a=1,b=k;

   for(int i=1;i<=k;i++)
     if(i&1)
        {
            ans.pb(a);
            a++;
        }
     else
     {
         ans.pb(b);
         b--;
     }


     return ans;
}

void go( vector<int> x)
{
    for(int i=0;i<sz(x);i++)
        cout<<x[i]<<" ";

     cout<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n,k;

 cin>>n>>k;

 vector<int> tp=solve(k+1);

  for(int i=k+2;i<=n;i++)
    tp.pb(i);

   go(tp);




 return 0;

}
