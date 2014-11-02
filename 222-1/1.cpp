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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

#define maxn 505
int row , col ,k;
string in[maxn];
int id[maxn][maxn];

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 cin>>row>>col>>k;
	 
	 for(int i=0;i<row;i++)
	   cin>>in[i];

	
	    int sx=0,sy=0;
	    
	    for(int i=0;i<row;i++)
	      for(int j=0;j<col;j++)
	        if( in[i][j]=='.')
	          {
	          	sx=i;
	          	sy=j;
	          	break;
	          }
	          
	      	   
	   queue<int> Q;
	   
	   memset(id,-1,sizeof(id));
	   
	   int cn=1;
	   
	   id[sx][sy]=cn++;
	       
	       
	    Q.push(sx) ; Q.push(sy);
	       
	     while( Q.size() > 0)  
	      {
	      	  int x=Q.front() ; Q.pop();
	      	  int y=Q.front() ; Q.pop();
	      	  
	      	   for(int i=0;i<4;i++)
	      	    {
	      	    	  int tx=x+dx[i];
	      	    	  int ty=y+dy[i];
	      	    	  
	      	    	   if( tx < 0  || tx >=row || ty <0 || ty >=col )
	      	    	     continue;
	      	    	     
	      	    	    if( in[tx][ty]=='#') 
	      	    	      continue;
	
	      	    	     
	      	    	     if( id[tx][ty]==-1)
	      	    	      {
	      	    	      	  id[tx][ty]=cn++;
	      	    	      	  
	      	    	      	  Q.push(tx);
	      	    	      	  Q.push(ty);
	      	    	      }
	      	    }
	      }
	      
	      
	      int all=0;
	      
	      for(int i=0;i<row;i++)
	        for(int j=0;j<col;j++)
	          if( in[i][j]=='.')
	            all++;
	            
	            
//	        cout<<all<<"  "<<cn<<endl;    
//	        
//	        for(int i=0;i<row;i++,cout<<endl)
//	          for(int j=0;j<col;j++)
//	            cout<<id[i][j]<<" ";
	            
	      
	      int cool=all-k;
	      
	      for(int i=0;i<row;i++)
	        for(int j=0;j<col;j++)
	          if( id[i][j]>cool)
	            in[i][j]='X';
	            
	            
	       for(int i=0;i<row;i++)     
	         cout<<in[i]<<endl;
	   
	       
	       
	  
             return 0; 
 
}
