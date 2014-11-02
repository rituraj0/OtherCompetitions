#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

string in[1<<11];
int n,m;

bool done[1<<11][1<<11],visit[1<<11][1<<11];

int dist[1<<11][1<<11];

bool cycle=false;

int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};

int tc=0;
int len[1<<22];
int id[1<<11][1<<11];

void dfs( int x, int y)
{
      if( visit[x][y] )
      {
             if( !done[x][y])
             {
                 cycle=true;
             }
             return;
      }

      visit[x][y]=true;

      if( in[x][y] =='#')
      {
          dist[x][y]=0;
      }
      else
      {
            int f=0;
            if( in[x][y]=='<') f=1;
            if( in[x][y]=='>') f=2;
            if( in[x][y]=='^') f=3;

            int nx=x+dx[f] , ny=y+dy[f];

            dfs( nx ,ny);

            dist[x][y]=dist[ nx][ny]+1;

            if( dist[x][y] ==1)
            {
                len[tc]=1;
                id[x][y]=tc;
                tc++;

            }
            else
            {
                        /*
                        4 7
                        #######
                        #^>#<^#
                        #^<#>^#
                        #######
                        */

                 id[x][y]=id[nx][ny];

                 len[ id[x][y] ]=max(len[ id[x][y] ] , dist[x][y]);
            }
      }

      done[x][y]=true;


}


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>m;

 for(int i=0;i<n;i++)
    cin>>in[i];

 fill(done,0);
 fill( visit,0);
 fill(len,0);

 for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
         if( !visit[i][j])
              dfs(i,j);

     if( cycle)
     {
         cout<<"-1\n";
         return 0;
     }

    vector<int> ans;
    ans.pb(0); ans.pb(0);

    for(int i=0;i<tc;i++)
    {
         ans.pb( len[i] );

//         cout<<len[i]<<"-";

         sort( ans.bg,ans.en, greater<int>() );
         ans.pop_back();
    }

    int ret=0;

    ret=max( 2*ans[0]-1, ans[0]+ans[1] );

    cout<<ret<<endl;

    return 0;

}
