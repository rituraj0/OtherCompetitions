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



#define mod 1000000007
typedef  long long ll;

class Skyscrapers 
{
public:
	
	ll memo[105][105][105];
	
	ll solve(int n , int l , int r)
	 {
	 	 if( n==1)
	 	 {
	 	  
	 	   if( l==1 && r==1)
	 	    return 1;
	 	    
	 	    return 0;
	     }
	     
	     if(memo[n][l][r]!=-1)
	       return memo[n][l][r];
	     
	     ll ans=0;
	     
	     //smallest to left
	       ans=(ans + solve(n-1,l-1,r) )%mod;
	  
	     //samleet to right
		   ans=(ans + solve( n-1 , l , r-1  ) )  %mod;
		   
		 //smmlaest bich me
		    if( n > 2)
		   ans=(ans  + solve( n-1, l , r)*( (ll)(n-2) ) )  %mod;
		   
		   return memo[n][l][r]=ans;
	 }
	
	
	

int  buildingCount(int N, int l, int r) 
{
	memset(memo,-1,sizeof(memo));
	
	return solve(N,l,r);
	
}

};


double test0() {
	int p0 = 3;
	int p1 = 2;
	int p2 = 2;
	Skyscrapers * obj = new Skyscrapers();
	clock_t start = clock();
	int my_answer = obj->buildingCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int p0 = 3;
	int p1 = 2;
	int p2 = 1;
	Skyscrapers * obj = new Skyscrapers();
	clock_t start = clock();
	int my_answer = obj->buildingCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int p0 = 5;
	int p1 = 3;
	int p2 = 2;
	Skyscrapers * obj = new Skyscrapers();
	clock_t start = clock();
	int my_answer = obj->buildingCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 18;
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
	int p0 = 12;
	int p1 = 1;
	int p2 = 1;
	Skyscrapers * obj = new Skyscrapers();
	clock_t start = clock();
	int my_answer = obj->buildingCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int p0 = 8;
	int p1 = 3;
	int p2 = 2;
	Skyscrapers * obj = new Skyscrapers();
	clock_t start = clock();
	int my_answer = obj->buildingCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4872;
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
