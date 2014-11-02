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



class BinPackingEasy 
{
public:

int  minBins(vector <int> in) 
{
	 int ans=0;
	  
	  vector<int> tp;
	   
	  for(int i=0;i<in.size();i++)
	    if( in[i] >= 200)
	      ans++;
	    else
		  tp.pb( in[i] );
		  	
 	  
 	  sort( tp.begin() , tp.end() );
 	  
	     int dn=0; 	   
 	  
 	    int i=0,j=tp.size()-1;
 	    
 	    while( i < j)
 	    {
 	    	  if( tp[i]+ tp[j] > 300)
 	    	   j--;
 	    	  else
			    {
			    	 ans++;
			    	 dn+=2;
			    	 i++;
			    	 j--;
			    } 
 	    }

 	   
         ans+=tp.size()-dn;
 	   
 	   
	    return ans;
	  
	
}


};


double test0() {
	int t0[] = {150, 150, 150, 150, 150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BinPackingEasy * obj = new BinPackingEasy();
	clock_t start = clock();
	int my_answer = obj->minBins(p0);
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
double test1() {
	int t0[] = {130, 140, 150, 160};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BinPackingEasy * obj = new BinPackingEasy();
	clock_t start = clock();
	int my_answer = obj->minBins(p0);
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
double test2() {
	int t0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BinPackingEasy * obj = new BinPackingEasy();
	clock_t start = clock();
	int my_answer = obj->minBins(p0);
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
	int t0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BinPackingEasy * obj = new BinPackingEasy();
	clock_t start = clock();
	int my_answer = obj->minBins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	int t0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BinPackingEasy * obj = new BinPackingEasy();
	clock_t start = clock();
	int my_answer = obj->minBins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
