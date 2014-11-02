#include<algorithm>
#include<iostream>
#include <sstream>
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


class PillarsDivTwo {
public:
	double maximalLength(vector <int>, int);
};

double PillarsDivTwo::maximalLength(vector <int> ht, int w)
 {
     int n=ht.size();
     
     double dp[55][120];
     
     memset( dp , 0, sizeof(dp) );
     
     for(int i=0;i<=ht[0];i++ )
       dp[0][i]=0;
       
      double wd=w;
       
     for(int i=1;i<n;i++)
      {
          for(int j=1;j<=ht[i];j++)
             {
                 double mx=0;
                 
                 for(int k=1;k<=ht[i-1];k++)
                    {
                       double a1=j;
                       double a2=k;
                       
                       mx=max( mx  , dp[i-1][k] + sqrt( wd*wd + (a1-a2)*(a1-a2)  )  );
                     }  
                     
                     dp[i][j]=mx;         
                     
             }        
     }  
     
     double mx=0;
     
     for(int i=1;i<=ht[n-1];i++)
       mx=max( mx  , dp[n-1][i] );
       
       return mx;     
	
}


double test0() {
	int t0[] = {3,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	PillarsDivTwo * obj = new PillarsDivTwo();
	clock_t start = clock();
	double my_answer = obj->maximalLength(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 5.656854249492381;
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
	int t0[] = {1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 100;
	PillarsDivTwo * obj = new PillarsDivTwo();
	clock_t start = clock();
	double my_answer = obj->maximalLength(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 300.0;
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
	int t0[] = {100,2,100,2,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	PillarsDivTwo * obj = new PillarsDivTwo();
	clock_t start = clock();
	double my_answer = obj->maximalLength(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 396.32310051270036;
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
	int t0[] = {2,1,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	PillarsDivTwo * obj = new PillarsDivTwo();
	clock_t start = clock();
	double my_answer = obj->maximalLength(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 3.82842712474619;
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
