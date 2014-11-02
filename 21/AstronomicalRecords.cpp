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

#define pb push_back


typedef long long  ll;

class AstronomicalRecords 
{
public:

int memo[55][55];

vector<ll> ta,tb;

int solve(int x, int y )
{
   if( x ==ta.size() || y == tb.size() )
    {
      return 0;
    }
    
    if( memo[x][y]!=-1)
      return memo[x][y];
      
    int ans=0;
    
     if( ta[x]==tb[y] )
       {
         int tp=1+solve(x+1,y+1);
         ans=max( ans , tp );
      }
     
        ans=max( ans , solve(x+1,y) );
        ans=max( ans , solve(x, y+1 ) );
        
           return memo[x][y]=ans;                                                                                                                                                                              

}

int  minimalPlanets(vector <int> A, vector <int> B) 
{

 int ans=A.size()+B.size();
 
 for(int i=0;i<A.size();i++)
   for(int j=0;j<B.size();j++)
     {
        vector<ll> X,Y;
        
         for(int k=0;k<A.size();k++)
           X.pb( (ll)A[k]*(ll)B[j] );
           
          for(int k=0;k<B.size();k++)
            Y.pb( (ll)A[i]*(ll)B[k] );
            
            int tp=1;
            
            
            //left part 
            ta.clear();
            tb.clear();
            
            for(int k=0;k<i;k++)
                ta.pb( X[k] );
            for(int k=0;k<j;k++)
                tb.pb( Y[k] );
                    
            memset( memo , -1, sizeof(memo) );  
            
            tp+=solve(0,0);
            
            //right part 
            
            ta.clear();
            tb.clear();
            
            for(int k=i+1;k<A.size();k++)
                ta.pb( X[k] );
            for(int k=j+1;k<B.size();k++)
                tb.pb( Y[k] );
                    
                memset( memo , -1, sizeof(memo) );  
            
                tp+=solve(0,0);
                
                tp=A.size()+B.size()-tp;
                
                ans=min( ans , tp );
	
	}

return ans;

}

};


#include<ctime>

double test0() {
	int t0[] = {1,2,1,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,1,2,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecords * obj = new AstronomicalRecords();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,4,6,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecords * obj = new AstronomicalRecords();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int t0[] = {2,3,2,3,2,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {600,700,600,700,600,700,600};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecords * obj = new AstronomicalRecords();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	int t0[] = {1,2,3,4,5,6,7,8,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6,7,8,9,10,11,12};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecords * obj = new AstronomicalRecords();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int t0[] = {100000000,200000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {200000000,100000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecords * obj = new AstronomicalRecords();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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

//Powered by [KawigiEdit] 2.0!
