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

struct node
{
    int id,admi,mon;
    node()
    {

    }

    node( int a, int b, int c)
    {
        id=a;admi=b;mon=c;
    }
};

bool comp( node a, node b)
{
    return ( a.mon > b.mon);
}

node in[1005];
int tab;
int cust;
int capi[1005];
int match[1005];

bool done[1005];

vector<int> graf[1005];

bool dfs(int u)
{
	if(done[u] )
		return false;

	 done[u] = true;

	for(int v = 0; v < graf[u].size(); v++)
	 {
		int x=graf[u][v];

		   if( match[x]==-1)
		     {
			    match[x] = u;
			    return true;
			 }
	}

	for(int v=0;v< graf[u].size();v++)
	  {
            int x=graf[u][v];

	  	    if(  dfs( match[x] ) )
	  	      {
	  	      	match[x]=u;
	  	      	return true;
	  	      }

	  }

	  return false;
}



int solve()
{

	memset(match, -1, sizeof(match));

	int ans=0;

	for(int i = 0; i < cust; i++)
	{
        memset(done,0,sizeof(done));

		if( dfs(i) )
		   ans++;
	}

	return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>cust;

 int x,y;

 for(int i=0;i<cust;i++)
 {
     cin>>x>>y;
     in[i]=node(i+1,x,y);
 }

 sort( in,in+cust,comp);


// for(int i=0;i<cust;i++)
//     cout<<in[i].id<<"  "<<in[i].admi<<" "<<in[i].mon<<endl;

 cin>>tab;

 for( int i=0;i<tab;i++)
     cin>>capi[i];

  for(int i=0;i<cust;i++)
      for(int j=0;j<tab;j++)
        if( in[i].admi <= capi[j])
           graf[i].pb(j);


  solve();

  int cont=0,ans=0;

  vector<pair<int,int> > all;

  for( int i=0;i<tab;i++)
      if( match[i]!=-1)
  {
     int lf=match[i];

      cont++;
      ans+=in[lf].mon;

      all.pb( mp(in[lf].id,i+1) );
  }

  cout<<cont<<" "<<ans<<endl;

  for(int i=0;i<all.sz;i++)
    cout<<all[i].X<<" "<<all[i].Y<<endl;

 return 0;

}
