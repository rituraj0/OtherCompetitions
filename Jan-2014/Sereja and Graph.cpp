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

#define maxn  105

bool graf[maxn][maxn];

int cont[maxn];
bool done[maxn];


int n;

bool next()
{
   memset( cont , 0, sizeof(cont) );
   
   for(int i=1;i<=n;i++)
     for(int j=i+1;j<=n;j++)
        if( graf[i][j])
       {
       	 cont[i]++;
       	 cont[j]++;
       }
       
     int one=-1;
     
//     cout<<"Check is "<<endl;
//     for(int i=1;i<=n;i++)
//       cout<<cont[i]<<"  ";
//       
//       cout<<"\n\n";
	 
	 for(int i=1;i<=n;i++)  
	    if( cont[i]==1)
	      one=i;
	      
	   if(one==-1)   
	     {
	     	return false;
	     }
	     

	     
	     int jodi=-1;
	     
	   for(int i=1;i<=n;i++)   
	     if(i!=one)
	       if( graf[one][i])
	         jodi=i;
	       
		 if( jodi==-1)    
		  {
		  	return false;
		  }
	   
//	   cout<<one<<" "<<jodi<<endl;;   
	   
	   done[one]=done[jodi]=true;
	         
	     for(int i=1;i<=n;i++)    
	       for(int j=1;j<=n;j++)
	         if( i==one || j==one || i==jodi || j==jodi )
	            graf[i][j]=false;
	            
	            
	            return true;
	            	            
} 



void process()
{
	int ed;
	
	cin>>n>>ed;
	
	memset( graf , 0, sizeof(graf) );
	
	for(int i=1; i<=ed ; i++)
	 {
	 	  int s,t;
	 	  
	 	  cin>>s>>t;
	 	  
	 	  graf[s][t]=graf[t][s]=true;
	 }
	 
	 
//	 if(n&1)
//	  {
//	  	cout<<"NO\n";
//	  	return;
//	  }
	  	  
	  	  
	 memset(done,0,sizeof(done));
	  	  
	  int ans=0;
	  
	  while( next() )
	   {
          ans++;
	   }
	   
	   int dn=0;
	   
	   if( ans*2==n)
	     {
	       cout<<"YES\n";
	       return ;
	     }
	     
	     bool cool=true;
	     
	     for(int i=1;i<=n;i++)
	       if( !done[i])
	         if( !cont[i])
	           cool=false;
	           
	      if(cool)  
	        cout<<"YES\n";
	      else
		   cout<<"NO\n";  
	  	  	    
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
