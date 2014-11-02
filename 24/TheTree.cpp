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
#include<map>
#include<ctime>
#include<set>
using namespace std;

#define pb push_back


class TheTree 
{
public:
	
 vector<int> graf[200]; 
 vector<int> all[200];
 int dist[200];
 int ans;
 
void bfs(int st)
{ 	 
      queue<int>Q; 
	 
	 dist[st]=0;
	 Q.push(st);
	 
	 while(Q.size())
	  {
	  	 int curr=Q.front();
	  	 	       Q.pop();
	  	 
	  	 int d=dist[curr];	  		   	  	 
	  	 
	  	 for(int i=0;i<graf[curr].size();i++)
	  	  {
	  	  	 int temp=graf[curr][i];
	  	  	 
	  	  	 if(dist[temp]==-1)
	  	  	  {
	  	  	  	Q.push(temp);
	  	  	  	dist[temp]=d+1;	  	  	  	
	  	  	  	ans=max( ans , d+1 );
	  	  	  }
	  	  }
	  }	 
}

int  maximumDiameter(vector <int> cnt) 
{
	
	 int id=1;
	 
	 all[0].pb(0);
	 
	 for(int i=0;i<cnt.size();i++)
	   {
	   	  int cl=i+1;
	   	  	   	  	   	  
	   	  if(all[cl-1].size()==1)
	   	    {
	   	    	if(cnt[i]==1)
	   	    	 {
	   	    	 	int prev=all[cl-1][0];
	   	    	 	int curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);	   	    	 	
	   	    	 	all[cl].pb(curr);
	   	    	 }
	   	    	 
	   	    	
				if( cnt[i]>1)    
				 {
				 	int prev=all[cl-1][0];
	   	    	 	int curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);
	   	    	 	all[cl].pb(curr);
	   	    	 	
	   	    	     prev=all[cl-1][0];
	   	    	    curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);
	   	    	 	all[cl].pb(curr);
				 }
	   	    	
	   	    }
	   	    
	   	    if(all[cl-1].size()==2)
	   	    {
	   	    	if(cnt[i]==1)
	   	    	 {
	   	    	 	int prev=all[cl-1][0];
	   	    	 	int curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);	   	    	 	
	   	    	 	all[cl].pb(curr);
	   	    	 }
	   	    	 
	   	    	
				if( cnt[i]>1)    
				 {
				 	int prev=all[cl-1][0];
	   	    	 	int curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);
	   	    	 	all[cl].pb(curr);
	   	    	 	

	   	    	    prev=all[cl-1][1];
	   	    	    curr=id++;	   	    	 	
	   	    	 	graf[prev].pb(curr);
	   	    	 	graf[curr].pb(prev);
	   	    	 	all[cl].pb(curr);
				 }
	   	    	
	   	    }
	   	  
	   	  
	   }
	   
	   	ans=0;
	   
	   for(int i=0;i<id;i++)
	    {
	      memset( dist , -1 , sizeof(dist) ) ;
	      bfs(i);
	    }	    
	    
	    return ans;

}

};



double test0() {
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheTree * obj = new TheTree();
	clock_t start = clock();
	int my_answer = obj->maximumDiameter(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {2, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheTree * obj = new TheTree();
	clock_t start = clock();
	int my_answer = obj->maximumDiameter(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {4, 1, 2, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheTree * obj = new TheTree();
	clock_t start = clock();
	int my_answer = obj->maximumDiameter(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheTree * obj = new TheTree();
	clock_t start = clock();
	int my_answer = obj->maximumDiameter(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 21;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
