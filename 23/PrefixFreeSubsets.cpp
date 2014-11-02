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
#include<ctime>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back


typedef long long ll;

class PrefixFreeSubsets 
{
public:
	
vector<string> in;

ll memo[55][55];

int n;

bool pref( string a, string b )
{
	 if( a.size() > b.size() )
	   return false;
	   
	 string tp=b.substr(0 , a.size() );
	 
	 return (a==tp);	
}

ll solve(int curr , int prev )
{
	 if( curr==in.size() )
	   return 1;
	   
	 if( memo[curr][prev]!=-1)
	   return memo[curr][prev];
	   
	 ll ans=0;
	 
	 ans=solve(curr+1, prev );  
	 
	 if( !pref( in[curr] , in[prev] ) )
	   if( !pref( in[prev] , in[curr] ) )
	     {
	     	
//	       cout<<in[curr]<<"    "<<in[prev]<<endl;
	       ans+=solve( curr+1 , curr);
	     }
	    
	     
	    return memo[curr][prev]=ans;
	
}

long long  cantPrefFreeSubsets(vector <string> word) 
{
	 in.pb("$$$");
	 
	 sort( word.begin() , word.end() );
	 
	 for(int i=0;i<word.size();i++)
	  in.pb( word[i] );
	  
	  memset( memo , -1, sizeof(memo) );
	  
	   return solve(1,0);
	
}

};


double test0() {
	string t0[] = {"hello","hell","hi"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixFreeSubsets * obj = new PrefixFreeSubsets();
	clock_t start = clock();
	long long my_answer = obj->cantPrefFreeSubsets(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 6LL;
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
	string t0[] = {"a","b","c","d"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixFreeSubsets * obj = new PrefixFreeSubsets();
	clock_t start = clock();
	long long my_answer = obj->cantPrefFreeSubsets(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 16LL;
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
	string t0[] = {"a","ab","abc","abcd","abcde","abcdef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixFreeSubsets * obj = new PrefixFreeSubsets();
	clock_t start = clock();
	long long my_answer = obj->cantPrefFreeSubsets(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 7LL;
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
	string t0[] = {"a","b","aa","ab","ba","bb"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixFreeSubsets * obj = new PrefixFreeSubsets();
	clock_t start = clock();
	long long my_answer = obj->cantPrefFreeSubsets(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 25LL;
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
