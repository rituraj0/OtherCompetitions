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



/*Solution code starts here */

typedef long long ll;


class LittleElephantAndXor 
{
public:
	
vector<int> A,B,C;

vector<int> getBit(int in)
{
	 vector<int> ans(35,0);
	 
	 for(int i=0;i<31;i++)
	   if( in&(1<<i))
	    ans[i]=1;
	    
	    return ans;
}

ll memo[35][2][2][2];

ll solve( int curr , int a , int b, int c)
{	 
	 if( memo[curr][a][b][c]!=-1 )
	   return memo[curr][a][b][c];
	   
	 if(curr==0)
	  return 1;
	   
	  ll ans=0;
	  
	  for(int x=0;x<2;x++) 
	    for(int y=0;y<2;y++)
	     {
	     	 int z=(x^y);
	     	 
	     	 if( !a  || (x<=A[curr-1]) )
	     	   if( !b || (y<=B[curr-1]) )
	     	     if( !c || (z<=C[curr-1]) )
	     	       {
	     	       	int ta = a&&(x==A[curr-1]);
	     	       	int tb = b&&(y==B[curr-1]);
	     	       	int tc = c&&(z==C[curr-1]);
	     	       	
	     	       	ans+=solve(curr-1,ta,tb,tc);
	     	       }
	     	 
	     }
	     
	     return memo[curr][a][b][c]=ans;
}

long long  getNumber(int a, int b, int c) 
{
 A=getBit(a);
 B=getBit(b);
 C=getBit(c);
 
 memset( memo, -1, sizeof(memo));
 
 return solve(31,1,1,1);
   
	
}

};


double test0() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	LittleElephantAndXor * obj = new LittleElephantAndXor();
	clock_t start = clock();
	long long my_answer = obj->getNumber(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 4;
	int p1 = 7;
	int p2 = 3;
	LittleElephantAndXor * obj = new LittleElephantAndXor();
	clock_t start = clock();
	long long my_answer = obj->getNumber(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 20LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 10;
	int p1 = 10;
	int p2 = 5;
	LittleElephantAndXor * obj = new LittleElephantAndXor();
	clock_t start = clock();
	long long my_answer = obj->getNumber(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 57LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 774;
	int p1 = 477;
	int p2 = 447;
	LittleElephantAndXor * obj = new LittleElephantAndXor();
	clock_t start = clock();
	long long my_answer = obj->getNumber(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 214144LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 1000000000;
	int p1 = 1000000000;
	int p2 = 500000000;
	LittleElephantAndXor * obj = new LittleElephantAndXor();
	clock_t start = clock();
	long long my_answer = obj->getNumber(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 468566946385621507LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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

//Powered by [KawigiEdit] 2.0!
