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
using namespace std;


typedef long long ll;

 
class ForbiddenStrings 
{
public:
	
bool cool( string in)	
{
	 if( in.size() < 3)
	   return true;
	   
	 bool cont[3]  ; memset( cont , 0, sizeof(cont));
	 
	 cont[ in[0]-'A']++;
	 cont[ in[1]-'A']++;
	 cont[ in[2]-'A']++;
	 
	 if( cont[0]*cont[1]*cont[2] )
	   return false;
	   
	   return true;	 	 
}

int N;

map< pair<int,string> ,long long> memo;

#define mp make_pair
#define pis pair<int,string>

ll solve( int curr ,string prev )
{
	  if( curr==N)
	    return 1;
	    
	  pis in=mp(curr,prev);
	  if( memo.count(in) )  
	    return memo[in];
	    
	  ll ans=0;  
	  
	  for(char x='A';x<='C';x++)
	    if( cool(prev+x) )
	      {
              string nw=prev+x;
			  
			  if(nw.size() > 2)	      	
			   nw=nw.substr( nw.size()-2);
	      
	       ans+=solve( curr+1, nw );
	     }
	      
	    return memo[in]=ans;
}
long long  countNotForbidden(int n) 
{
	N=n;
    return 	solve(0,"");
	
}

};


double test0() {
	int p0 = 2;
	ForbiddenStrings * obj = new ForbiddenStrings();
	clock_t start = clock();
	long long my_answer = obj->countNotForbidden(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 9LL;
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
	int p0 = 3;
	ForbiddenStrings * obj = new ForbiddenStrings();
	clock_t start = clock();
	long long my_answer = obj->countNotForbidden(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 21LL;
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
	int p0 = 4;
	ForbiddenStrings * obj = new ForbiddenStrings();
	clock_t start = clock();
	long long my_answer = obj->countNotForbidden(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 51LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
