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
#include<set>
#include<ctime>
using namespace std;

#define  pb push_back

class GooseTattarrattatDiv1 
{
public:

vector<int> comp[55];
bool path[55][55];
int cont[55];
bool visit[55];
int n;

void dfs(int curr , int cn)
{
	  if( visit[curr])
	   return;
	   
	   comp[cn].pb(curr);
	   
	   visit[curr]=true;
	   
	   
	   for(int i=0;i<26;i++)
	     if( path[curr][i])
	      {
	      	 dfs(i,cn);	      	 	      	  
	      }
	      
}

int  getmin(string in) 
{
	 n=in.size();
	 
	 memset( path , 0, sizeof(path)) ;
	 memset( cont , 0 , sizeof(cont));
	 
	 for(int i=0;i<n;i++)
	       {
	       	  int a=in[i]-'a';
	       	  int b=in[n-1-i]-'a';
	       	  
	       	    cont[a]++;
	       	    
	       	    path[a][b]=path[b][a]=true;	//conglict graph 
	       }
	       
	       
	   memset( visit, 0 , sizeof(visit))    ;
	   int cn=0;
	   
	   for(int i=0;i<26;i++)
	     if(cont[i])
	     if( !visit[i])
	      {
	      	dfs(i,cn);
	      	cn++;
	      }

	  
	  int ans=0;
	  
	  for(int i=0;i<cn;i++)
	    {
	    	int mx=0;
	    	int tt=0;
	    	
	    	 for(int j=0;j<comp[i].size();j++)
	    	   {
	    	   	int curr=comp[i][j];
	    	   	
	    	   	tt+=cont[curr];
	    	   	
	    	   	mx=max( mx , cont[curr]);
	    	   }
	    	   
	    	   ans+=tt-mx;
	    }
	  
	  	 return ans;
	
}

};




double test0() {
	string p0 = "geese";
	GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
	clock_t start = clock();
	int my_answer = obj->getmin(p0);
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
	string p0 = "tattarrattat";
	GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
	clock_t start = clock();
	int my_answer = obj->getmin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string p0 = "xyyzzzxxx";
	GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
	clock_t start = clock();
	int my_answer = obj->getmin(p0);
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
double test3() {
	string p0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
	GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
	clock_t start = clock();
	int my_answer = obj->getmin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
double test4() {
	string p0 = "abaabb";
	GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
	clock_t start = clock();
	int my_answer = obj->getmin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
