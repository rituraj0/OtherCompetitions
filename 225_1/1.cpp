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

typedef long long ll;

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 int n;
	 int in[200005];
	 
	 cin>>n;
	 
	 for(int i=1;i<=n;i++)
	   cin>>in[i];
	   
	   ll ans=(1LL<<60);
	   
	   //right most L
	        
	     ll tp=0;
		 
		 ll curr=0;
		 
		 for(int i=n;i>0;i--)   
		    if( in[i]==0)
		      curr++;
		    else
			  tp+=curr;
			  
			  ans=min( ans , tp);
	
	  //left most R
	  
	       tp=0;
	       curr=0;
	       
	       for(int i=1;i<=n;i++)
	         if( in[i]==1)
	           curr++;
	         else
			   tp+=curr;  
			   
			    ans=min( ans , tp);
			    
			    
			    cout<<ans<<endl;
		
	 
	
 return 0;
 
}
