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

int all[1<<20];
int cont[1<<20];
int cn=0;

map<int,int> ic;

bool prime[10000002];
bool pres  [10000002];

int n,x;
int mx=0;

ll dp[1<<20];

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 cin>>n;
	 
	 memset(pres,0,sizeof(pres));
	 
	 for(int i=1;i<=n;i++)
	  {
	  	cin>>x;
	  	ic[x]++;
	  	pres[x]=true;
	  	
	  	mx=max(x,mx);	  	
	  }
	  
	 
     memset(prime,1,sizeof(prime));
    
	 
	for(int i=2;i<=mx;i++)
     if(prime[i])
	  {
        all[cn]=i;
        
        int tp=ic[i];
        
        for(int j=2*i;j<=mx;j+=i)
		{
            prime[j]=false;   
			
			if( pres[j] )         
             tp+=ic[j];
        } 
        
        cont[cn]=tp;
        
        cn++;
     }
     
//     for(int i=0;i<all.size();i++)
//       cout<<all[i]<<"  "<<cont[i ]<<endl;
       
       
       memset(dp,0,sizeof(dp));
       
       n=cn;
       
       dp[n]=0;
       
       for(int i=n-1;i>=0;i--)
         dp[i]=dp[i+1]+((long long)cont[ i ] );
         
         int Q;
         
         cin>>Q;
         
         int a, b;
         
         for(int i=1;i<=Q;i++)
          {
          	cin>>a>>b;
          	
          	int lid=(int)( lower_bound (all, all+n, a) - all );
          	int uid=(int)( upper_bound (all, all+n, b) - all );
          	
          	cout<<max(dp[lid]-dp[uid],0LL)<<endl;
          }

	 
	
 return 0;
 
}
