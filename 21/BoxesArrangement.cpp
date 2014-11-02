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



class BoxesArrangement 
{
public:
	
	int cont[3];
	
	int memo[4][4][51][51][51];
	
	string in;
	
int solve(int col , int cn , int a , int b , int c)
{
	  if( cn >= 3)
	    return -(1<<20);
	    
	    if( a > cont[0])
	       return -(1<<20);
	       
	     if( b > cont[1])  
	        return -(1<<20);
	       
		  if( c > cont[2] )  
		     return -(1<<20);
		  
	    
	   if( memo[col][cn][a][b][c]!=-1) 
	     return memo[col][cn][a][b][c];
	     
	  
	  int curr=a+b+c;
	  
	  if(curr==in.size() )
	    return 0;
	    
	  int ans=-(1<<20);
	  
	  for(char i='A' ; i<='C' ; i++ )   
	    {
	    	 int nc=1;
	    	 
	    	 if(i=='A'+col-1)
	    	     nc=cn+1;
	    	    
	    	int tp=solve( i-'A'+1 , nc , a + (i=='A') , b + (i=='B') , c + (i=='C') );
	    	
	    	if( i==in[curr]  )
	    	 tp++;
	    	 
	    	 ans=max( ans , tp);
	    }
	    
	    return memo[col][cn][a][b][c]=ans;	    	 	    
}

int  maxUntouched(string boxes) 
{
	
	in=boxes;
	
	cout<<in<<endl;
	
	memset(cont,0,sizeof(cont));
	
	for(int i=0;i<in.size();i++)
	 cont[ in[i] - 'A'  ]++;
	 
	 memset(memo, -1 , sizeof(memo));
	 
	 int ans=solve( 0 , 0 ,0 , 0 , 0);
	 
	 if( ans >=0)
	   return ans;
	   
	  return -1;  
	
}

};


double test0() {
	string p0 = "AAABBBCCC";
	BoxesArrangement * obj = new BoxesArrangement();
	clock_t start = clock();
	int my_answer = obj->maxUntouched(p0);
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
double test1() {
	string p0 = "AAAAAAAACBB";
	BoxesArrangement * obj = new BoxesArrangement();
	clock_t start = clock();
	int my_answer = obj->maxUntouched(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string p0 = "CCCCCB";
	BoxesArrangement * obj = new BoxesArrangement();
	clock_t start = clock();
	int my_answer = obj->maxUntouched(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string p0 = "BAACAABAACAAA";
	BoxesArrangement * obj = new BoxesArrangement();
	clock_t start = clock();
	int my_answer = obj->maxUntouched(p0);
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
double test4() {
	string p0 = "CBBABA";
	BoxesArrangement * obj = new BoxesArrangement();
	clock_t start = clock();
	int my_answer = obj->maxUntouched(p0);
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
