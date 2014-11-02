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


ll in[200];
bool auc[200];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,a;

 fill(in,0);
 fill(auc,0);

  cin>>n>>a;

 for(int  i=1;i<=n;i++)
     cin>>in[i];

     vector<ll> curr;

 for(int i=1;i<=a;i++)
     {
        int x;
        cin>>x;
        auc[x]=true;
        curr.pb(in[x]);
     }

  sort(curr.bg,curr.en);

  ll ans=0;

  for(int i=1;i<=n;i++)
     if(!auc[i])
        ans+=in[i];


  int i=0,j=curr.sz-1;

  while(i<=j)
  {
        if( ans > curr[i])
        {
            ans=2*ans;
            i++;
        }
       else
       {
           ans+=curr[j];
           j--;
       }
  }

   cout<<ans<<endl;




 return 0;

}
