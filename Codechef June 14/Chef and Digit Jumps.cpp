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

string in;
int n;
int dist[100009];
vector<int> col[10];
queue<int> Q;


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>in;

 fill(dist,-1);

 n=in.sz;

 for(int i=0;i<n;i++)
     col[ in[i]-'0'].pb(i);

 Q.push(0);
 dist[0]=0;

 int cn=1;

 while( Q.size() )
 {
     int curr=Q.front(); Q.pop();

     ll d=dist[curr];

           if(curr-1>=0)
           {
               if( dist[curr-1]==-1)
               {
                   dist[curr-1]=d+1;
                   Q.push(curr-1);
                   cn++;
               }
           }

          if(curr+1<n)
           {
                if( dist[curr+1]==-1)
                {
                    dist[curr+1]=d+1;
                    Q.push(curr+1);
                    cn++;
                }
           }

           int cc=in[curr]-'0';

           for(int i=0;i<col[cc].sz;i++)
           {
                int el=col[cc][i];

                if( dist[el]==-1)
                {
                    Q.push(el);
                    dist[el]=d+1;
                    cn++;
                }
           }

           col[cc].clear();
 }

// print(cn);

 cout<<dist[n-1]<<endl;

 return 0;

}
