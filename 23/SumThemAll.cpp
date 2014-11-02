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

#define pll pair<long long , long long >
#define X first
#define Y second
#define mp make_pair

string tost( ll in)
{
	 char ans[25];
	 
	 sprintf(ans,"%lld",in);
	 
	 return ans;
}

class SumThemAll 
{
public:
	
string in;
int n;

pll memo[20][2];
bool done[20][2];



pll solve( int curr , int eq )	
{
	 if( curr==n)
	   return mp(0,1);
	   
	  if( done[curr][eq] )  
	    return memo[curr][eq];
	   	    
	   ll ans=0;
	   ll cont=0;
	   
	   for(int i=0;i<=9;i++)
	     if( !eq || ( i<= in[curr]-'0') )
	       {
	       	pll tp=solve(curr+1, eq && ( i==in[curr]-'0' ) ) ;
	       	
	       	ans+=tp.X;
	       	ans+=tp.Y*( (long long)(i) );
	       	
	       	cont+=tp.Y;
	       }
		 
		done[curr][eq]=true; 
	   	   	    
	    return memo[curr][eq]=mp(ans,cont);
}	
	
	
long long  getSum(int lo, int up) 
{
	  	  	   
	   //first
	   
	   in=tost(up);
	   n=in.size();
	   
	   
	   memset( done,0,sizeof(done));
	   
	   ll all=solve(0,1).X;
	   
	   if(lo==0)  
	    return all;
	    
	   //
	    in=tost(lo-1) ;
	    n=in.size();
	    	    
	    memset( done , 0 , sizeof(done) );
	    
	    ll sub=solve(0,1).X;
	    
	    
	    return (all-sub);
	   
	 
}

};


double test0() {
	int p0 = 0;
	int p1 = 3;
	SumThemAll * obj = new SumThemAll();
	clock_t start = clock();
	long long my_answer = obj->getSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 6LL;
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
	int p0 = 10;
	int p1 = 14;
	SumThemAll * obj = new SumThemAll();
	clock_t start = clock();
	long long my_answer = obj->getSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 15LL;
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
	int p0 = 0;
	int p1 = 0;
	SumThemAll * obj = new SumThemAll();
	clock_t start = clock();
	long long my_answer = obj->getSum(p0, p1);
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
double test3() {
	int p0 = 14;
	int p1 = 53;
	SumThemAll * obj = new SumThemAll();
	clock_t start = clock();
	long long my_answer = obj->getSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 296LL;
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
double test4() {
	int p0 = 24660;
	int p1 = 308357171;
	SumThemAll * obj = new SumThemAll();
	clock_t start = clock();
	long long my_answer = obj->getSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 11379854844LL;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
