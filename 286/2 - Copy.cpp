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

#define maxn  100009

vector<int>  dir[maxn],undirec[maxn];

//list all memmebr in compnent assming underiected graf
vector<int> ccmem[maxn];
int cc=0;
bool done_un[maxn];

int n;

void dfs( int v)
{
    if( done_un[v] )
         return;

    done_un[v]=true;

    ccmem[cc].pb(v);

    for(int i=0;i<sz(undirec[v]);i++)
    {
        int ch = undirec[v][i];

        dfs(ch);
    }
}

void  build_undirec()
{
  fill( done_un,0);

   cc=0;

  for(int i=0;i<n;i++)
    if( ! done_un[i])
    {
      dfs(i);
      cc++;
    }

    print(cc);

    for(int i=0;i<cc;i++,cout<<endl)
         for(int j=0;j<sz( ccmem[i] );j++)
             cout<<ccmem[i][j]<<" . ";
}

//now scc section
int inscc[maxn];
int countmem[maxn];

bool instack[maxn];

stack<int> st;

int low[maxn];
int index[maxn];

int id=0;
int sccid=0;

void targen( int v)
{
     if(  index[v] !=-1 )
        return;

     low[v]=index[v]=id;
     id++;

     st.push(v);
     instack[v]=true;

     for(int i=0;i<sz(dir[v]);i++)
     {
         int ch = dir[v][i];

         if( index[ch] != -1 )
         {
             if( instack[ch])
                low[v]= min( low[v] , index[ch] );
         }
         else
         {
            targen(ch);

            low[v]= min( low[v] , low[ch] );
         }
     }

     cout<<v<<"  "<<low[v]<<"  "<<index[v]<<endl;

     if( low[v] == index[v])
     {
         while(!st.empty())
         {
             int curr = st.top() ; st.pop();

             instack[curr]=false;

             countmem[sccid]++;
             inscc[curr]=sccid;

             cout<<curr<<"  sid: "<<sccid<<" "<<countmem[sccid]<<endl;

             if( curr == v)
                break;
         }

         //cout<<" count in   "<<sccid<<"  "<,

         sccid++;
     }
}

void start_scc()
{
  fill( inscc,-1);

  fill( countmem,0);

  fill( instack,0);
  fill( index,-1);

  for(int i=0;i<n;i++)
  {
      if( index[i] == -1)
      {
          targen(i);
      }
  }

}



int main()
{
 ios_base::sync_with_stdio(0);

 int m;

 cin>>n>>m;

 int a,b;

 for(int i=0;i<m;i++)
 {
     cin>>a>>b;

     a--;
     b--;

     dir[a].pb(b);

     undirec[a].pb(b);
     undirec[b].pb(a);
 }

 build_undirec();

 start_scc();

 int ans = 0;

 for(int cp=0;cp<cc;cp++)
 {
     bool cycle=false;

     for(int j=0;j<sz(ccmem[cp]);j++)
     {
         int ch = ccmem[cp][j];

         if( countmem[ inscc[ch] ] > 1)
            cycle = true;
     }

     int add = sz( ccmem[cp] );

     print(add);

     if(!cycle)
        add--;

     ans+=add;
 }

 print(ans);

 return 0;

}
