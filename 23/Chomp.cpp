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



class Chomp 
{
public:

bool done[2][105][105][105];
int memo[2][105][105][105];


int solve( int curr , int a, int b , int c)
{
	if(a==1 && b==0 && c==0)
	 return -1;
	 
    if( done[curr][a][b][c])	 
      return memo[curr][a][b][c];
      
     int ans=(1LL<<20);
	 bool win=false;
	 
	 int mx=0;
	 
	 //from lowet row
	 
	 for(int i=2;i<=a;i++) //remove i th
	  {
	  	 int tp=solve(1-curr , i-1 , min(i-1,b) , min(i-1,c) );
	  	 
	  	 if( tp < 0)
	  	  {
	  	  	 win=true;
	  	  	 ans=min( ans , -tp);
	  	  }
	  	else
		   {
		   	 mx=max( mx , tp );
		   }  
	  	  
	  }
	  
	  //from second row
	  
	  for( int i=1;i<=b;i++)
	   {
	   	   int tp=solve( 1- curr , a , i-1 , min(i-1 , c) );
	   	   
	   	    if( tp < 0)
	  	  {
	  	  	 win=true;
	  	  	 ans=min( ans , -tp);
	  	  }
	  	else
		   {
		   	 mx=max( mx , tp );
		   }  
	   	   
	   	   
	   }
	   
	   //from 3 rd row
	   
	   for(int i=1;i<=c;i++)
	    {
	    	 int tp=solve( 1-curr , a , b , i-1 );
	    	 
	    	  if( tp < 0)
	  	  {
	  	  	 win=true;
	  	  	 ans=min( ans , -tp);
	  	  }
	  	else
		   {
		   	 mx=max( mx , tp );
		   }  
	    }
	    
	    int final=-1;
	    
	    if( win ) 
	     {
	     	final=ans+1;	     	
	     }
	    else
		 {
		 	final=-mx-1;
		 }
		 
		 done[curr][a][b][c]=true;
		 
		 return memo[curr][a][b][c]=final; 
     
}

int  moves(int N) 
{
	 memset(done,0,sizeof(done));
	 
	
	         
	    return solve(0,N,N,N);
	
}

};


double test0() {
	int p0 = 1;
	Chomp * obj = new Chomp();
	clock_t start = clock();
	int my_answer = obj->moves(p0);
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
	int p0 = 2;
	Chomp * obj = new Chomp();
	clock_t start = clock();
	int my_answer = obj->moves(p0);
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
double test2() {
	int p0 = 4;
	Chomp * obj = new Chomp();
	clock_t start = clock();
	int my_answer = obj->moves(p0);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
