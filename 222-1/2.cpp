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
/*
Algo . first binary searhc on day  say len 
    student sorted by their cost  , assign as much as poosible  len 
         to assign taskes sorted on dificulty level 
           find best task for using upper boind the decrease in 
    						    

*/


typedef long long ll;


#define pll pair<ll,ll>
bool comp( pll a, pll b)
{
	  return (a.X < b.X);
}

void test()
{
	vector<pll> s;
	
	vector<pll>::iterator it=upper_bound( s.begin() , s.end() , mp(10,20) , comp );
}




#define maxn 100009

int bc[maxn];
int ac[maxn];
int ps[maxn];

vector<pll> stud;

set<pll> saved,task;

int ans[maxn];


bool cool( int d)
{
	   task.clear();
	   
	   
	 for( set<pll>::iterator it=saved.begin() ; it!=saved.end() ; it++)
	   {
           task.insert(*it);
	  }
	 
	for(int i=stud.size()-1;i>=0;i--)//pehle sabe bade wale skill kolete hai
	 {
//	 	  cout<<endl;
//	 	  cout<<stud[i].Y<<" st  "<<task.size()<<endl;
	 	  
	 	  if( task.size()==0)
	 	    break;
	 	
	 	  for(int j=0;j<d;j++)
	 	   {
	 	   	 
	 	   	  if( task.size()==0)
	 	    	   break;
	 	   	 
			   set<pll>::iterator it=upper_bound( task.begin(), task.end() , stud[i] , comp); 
			 

			      
			     if(it==task.begin()) 
			       break;			       
			       
			       it--;
			 
			     int ct=(*it).Y;  //d
			      
			      ans[ct]=stud[i].Y;
			      
//			      cout<<ct<<"  -  ";
			      
			      task.erase(it);	   	   	 	   	  	 	   	    			 
	 	   }
	 }
	 
	 if( task.size() )
	   return false;
	   
	   return true;
	
}


int main()
{
	 ios_base::sync_with_stdio(0);
	 
     ll n,m,s;
     
     cin>>n>>m>>s;
     
     for(int i=1;i<=m;i++)
       cin>>bc[i];
       
      for( int i=1;i<=n;i++) 
        cin>>ac[i];
        
      for(int i=1;i<=n;i++)  
        cin>>ps[i];
        
       //task
	   
	   for(int i=1;i<=m;i++) 
	     saved.insert( mp(bc[i],i) );
	     
	    //for stud
		
		for(int i=1;i<=n;i++)  
		   if( ps[i] <=s)
		     {
		      stud.pb( mp(ac[i],i) );
		     }
		     
		     
		 sort( stud.begin(), stud.end() ,comp ) ;
		 
		 
//		 //printing input
//		 
//	    cout<<"Stud info\n\n";
//	    
//	    for(int i=0;i<stud.size();i++)
//	      cout<<stud[i].X<<"-"<<stud[i].Y<<"     ";
//	      
//	     cout<<"\n\n";  
//		 
//		 cout<<"Task info \n";
//		 
//		 for( set<pll>::iterator it=saved.begin() ; it!=saved.end(); it++)
//		   cout<<(*it).X<<"-"<<(*it).Y<<"  ";
//		   
//		   cout<<"\n\n";
//		   
//		   
//		   cool(2);
		 
		  
		  
		 ll d=-1;
		 
		 ll lo=0,hi=m;
		 
		 while(lo <= hi)
		  {
		  	  ll mid=(lo+hi)/2;
		  	  
		  	  if( cool(mid) )
		  	   {
		  	   	 d=mid;
		  	   	 hi=mid-1;
		  	   }
		  	  else
				 {
				 	lo=mid+1;
				 } 
		  }
		  
		 if( d==-1) 
		  {
		  	cout<<"NO\n";
		  	
		  	return 0;
		  }
		 
		  cool(d);
		 
		 cout<<"YES\n";
		 
		 for(int i=1;i<=m;i++)
		   cout<<ans[i]<<" ";
		   
		   cout<<endl;
		 
	
 return 0;
 
}
