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


#define maxn 100009

int in[maxn];
int n,t;
bool done[maxn];


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>t;

 for(int i=1;i<=n-1;i++)
    cin>>in[i];

  fill(done ,0);

  queue<int> Q;
  Q.push(1);
  cout<<in[n]<<endl;



 while( !Q.empty())
 {
      int curr = Q.front();
                    Q.pop();

          if( done[curr] )
            continue;

            //cout<<curr<<endl;

            done[curr]=true;

           int nx= curr + in[curr];

            Q.push(nx);
   }


   if( done[t])
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;



 return 0;

}
