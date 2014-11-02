#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;



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
#define pii pair<int,int>
#define maxi 1000009

vector<pii> curr;

vector<pii> in[maxi];

int solve()
{
    if( curr.size() == 0)	
      return 0;
      
    sort( curr.begin() , curr.end() );
    
	int ans	=1;
	
	int ed=curr[0].X;
	
	for(int i=1;i<curr.size();i++)
	  if( curr[i].Y>=ed)
	  {
	  	 ans++;
	  	 ed=curr[i].X;	 	
	 }
	 
	 return ans;
}


void process()
{
	int n,k;
	
	cin>>n>>k;
     
	for(int i=0;i<maxi;i++) 	
	  in[i].clear();
	  
	map<int,int> mapa;
	
	int id=1;
	
	for(int i=1;i<=n;i++)
	 {
	    int s,f,c;
		
		cin>>s>>f>>c;
		
		if( mapa.count(c)==0 ) 	  
		   mapa[c]=id++;
		   
		 int tp=mapa[c];
		 
		 in[tp].pb( mp(f,s) );  
	 }
	 
	 int ans=0;
	 
	 for(int i=1;i<id;i++)
	  {
	  	  curr=in[i];
	  	  
	  	  ans+=solve();
	  }
	  
	  cout<<ans<<endl;
}

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 int test;
	 
	 cin>>test;
	 
	 while(test--)
	 {
	 	process();
	 }
	 	
	 	
 return 0;
 
}
