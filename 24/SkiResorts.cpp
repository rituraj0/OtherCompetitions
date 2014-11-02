#include<algorithm>
#include<iomanip> 
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
#include<ctime>
#include<map>
#include<set>
using namespace std;


typedef long long ll;
ll inf=(1LL<<55);

struct node
{
	ll dist;//toatl cost to reach 	
	int x,y;// at node x with current height y
};

bool operator<( node a, node b)
{
	return (a.dist > b.dist);
}



class SkiResorts 
{
public:
	
 	bool path[51][51]; 
	int n;	

long long  minCost(vector <string> road, vector <int> altitude) 
{
	  n=road.size();
	
	 memset( path , 0, sizeof(path));
	
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	    if( road[i][j]=='Y')
	      path[i][j]=true;
	    
	
	 // all availbale height options in data[][]	  
	  ll data[51];
	  
	  for(int i=0;i<n;i++)   
	   data[i]=altitude[i];
	   
	    sort( data , data + n);
	   
	   int cn=1;
	   
	   for(int i=1;i<n;i++)
	     if( data[i]!=data[i-1])
	        data[cn++]=data[i];
	        
	    
		//now overhead   calculation
		
		ll wt[51][51]; 
		
		for(int i=0;i<n;i++)    
		  for(int j=0;j<cn;j++)
		   {
		   	wt[i][j]=abs( altitude[i]- data[j]);
		   }
		   
		   //now dijstra
		   
		   priority_queue<node> Q;
		   
		   ll dist[51][51] ; 
		   
		   for(int i=0;i<n;i++)
		     for(int j=0;j<cn;j++)
		       {
		       	 if(i==0)
		       	  {
		       	  	dist[i][j]=wt[i][j];
		       	  	Q.push( (node){dist[i][j],i,j} );		       	  	
		       	  }
		       	 else
					 {
					 	dist[i][j]=inf;
					 } 
		       }
		       
		       
		       bool done[51][51]; memset(done,0,sizeof(done));
		       
		       while( Q.size() > 0)
		        {
		        	 node tp=Q.top(); Q.pop();
		        	 
		        	 int x=tp.x , y=tp.y;
		        	 
		        	 if( done[x][y])
		        	  continue;
		        	  
		        	  done[x][y]=true;
		        	  
		        	  for(int i=0;i<n;i++)
		        	    if( path[x][i])
		        	     {
		        	     	 for(int j=0;j<=y;j++)// (j<=y) bcz for a pth from i to j , ht[i] >=j 
		        	     	  {
		        	     	  	 if( dist[x][y] + wt[i][j] < dist[i][j] )
		        	     	  	  {
		        	     	  	  	dist[i][j]=dist[x][y] + wt[i][j];
		        	     	  	  	Q.push( (node){dist[i][j] ,i,j	} );
		        	     	  	  }
		        	     	  }
		        	     }
		        	  
		        }       		        
		        
		        ll ans=inf;
		        
		        for(int i=0;i<cn;i++)
		           ans=min( ans , dist[n-1][i] );
		           
		           
		         if(ans==inf)   
		           return -1;
		           
		           return ans;		     	   	    	    
	
}

};


double test0() {
	string t0[] = {"NYN",
 "YNY",
 "NYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {30, 20, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SkiResorts * obj = new SkiResorts();
	clock_t start = clock();
	long long my_answer = obj->minCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"NY",
 "YN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {10, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SkiResorts * obj = new SkiResorts();
	clock_t start = clock();
	long long my_answer = obj->minCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 10LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"NYN",
 "YNN",
 "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {573, 573, 573};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SkiResorts * obj = new SkiResorts();
	clock_t start = clock();
	long long my_answer = obj->minCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = -1LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SkiResorts * obj = new SkiResorts();
	clock_t start = clock();
	long long my_answer = obj->minCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 12LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
