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

bool mila[5005];
bool memo[5005][5005];
bool done[5005][5005];

string in;
int n;

bool solve( int i , int j)
{
	  if( j-i+1 < 4 )
	    return false;
	    
	 if( done[i][j])
	   return memo[i][j];
	   
	   
	   bool ans=false;
	   
	 if( mila[i] )  
	      ans=true;
	      
	   ans=ans||solve(i+1,j) ;
	   
	   done[i][j]=true;
	   
	   return memo[i][j]=ans;
	   
	 
}

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 cin>>in;
	 
	 n=in.size();
	 
 
      memset( mila , 0, sizeof(mila));
	 
	 for(int i=0;i<=n-4;i++)
	   if( in.substr(i,4)=="bear")
	      mila[i]=true;
	 
	 	 int ans=0;
	 	 
	 	 memset( done , 0, sizeof(done));
	 	 memset( memo,0,sizeof(memo));
	 	 
	 	 for(int i=0;i<=n-4;i++)
	 	    for(int j=i+3;j<n;j++)
	 	       if( solve(i,j) )
	 	          ans++;
	 	          
	 	          
	 	          cout<<ans<<endl;
	
 return 0;
 
}
