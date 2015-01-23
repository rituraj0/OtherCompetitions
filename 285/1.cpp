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

#define maxn (1<<16)+10
#define pii pair<int,int>

int rem_deg[maxn];
int xor_all[maxn];
int xor_done[maxn];//is done

set< pii > Q;

vector< pii > ans;

int main()
{
 ios_base::sync_with_stdio(0);

 fill(rem_deg, 0);
 fill(xor_all, 0);
 fill(xor_done, 0);

 int n;

 cin>>n;

 for(int i=0;i<n;i++)
     {
          cin>>rem_deg[i]>>xor_all[i];

          if( rem_deg[i] > 0 )
              Q.insert( mp(rem_deg[i],i) );
     }

  while( sz(Q) )
  {
      pii top = *Q.begin();
                  Q.erase(Q.find(top));

      int curr_node = top.Y;
      int  rem_d = top.X;

      if( rem_d == 0)
        continue;

      assert( rem_d == 1 );

      int other = xor_all[curr_node] xor xor_done[curr_node];

      ans.pb( mp(curr_node,other));

     // cout<<curr_node<<"  "<<other<<endl;

      pii todel = mp( rem_deg[other] , other );
                  Q.erase( Q.find(todel) );

      rem_deg[curr_node]=0;
      rem_deg[other]--;


      xor_all[curr_node] =0;

      xor_all[other]= xor_all[other] xor curr_node;

      if(rem_deg[other] > 0 )
        Q.insert( mp( rem_deg[other] , other ) );
  }


  cout<<sz(ans)<<endl;


  for(int i=0;i<sz(ans);i++)
    cout<<ans[i].X<<" "<<ans[i].Y<<endl;

 return 0;

}
