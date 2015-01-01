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
#define pii  pair<int,int>

double len[maxn];
double cont[maxn];

bool done[maxn];

vector<pii> graf[maxn]; //(tar,edgeid);
int N;


double dfs(int x , int p , int id)
{
    if( done[x] )
         return 0;

     ll ans=1;

     for(int i=0;i<sz(graf[x]);i++)
     {
         int nx= graf[x][i].X;

         if( nx != p)
         {
             ans+=dfs( nx , x , graf[x][i].Y);
         }
     }

     if(id!=-1)//roor wala case
       cont[id]=ans*(N-ans)*2.0;

     return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);


 fill(cont,0);

 cin>>N;

 double sm =0;

 int a,b;

 for(int i=1;i<N;i++)
    {
        cin>>a>>b>>len[i];

        graf[a].pb( mp(b,i) );
        graf[b].pb( mp(a,i) );
    }

  dfs(1,-1,-1);

 int Q;

 cin>>Q;

 double ans=0;

 for(int i=1;i<N;i++)
 {
     ans+=cont[i]*len[i];
 }

 ans=ans*3;

 double down = 1.0;
         down = down * N ;
         down = down * (N-1);

 int id;
 double wt;

 std::cout << std::fixed;

 for(int i=1;i<=Q;i++)
 {
     cin>>id>>wt;

     double diff = (len[id]-wt)*cont[id];
            diff = diff*3.0;

     ans-=diff;

     len[id]=wt;

     std::cout << std::setprecision(10) << (ans/down) << endl;
 }






 return 0;

}
