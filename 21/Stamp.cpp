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



#define maxi  999999999

class Stamp {
public:
       
     

int getMinimumCost(string  in, int sc, int pc)
{
    


long long  ans=maxi;

int val[255];
val['*']=7;
val['R']=4;
val['G']=2;
val['B']=1;

int n=in.size();

long long cost[55];

in='$'+in;

for(int len=1;len<=n;len++)
{
  cost[0]=0;
  
  for(int i=1;i<=n;i++)
   cost[i]=maxi;
  
   for(int i=0;i<=n;i++)
    {
           
            int tp=7;
            
            for(int j=i+1;j<=n;j++)
             {
                 tp=tp & val[in[j]];
                  if(tp==0)
                    break;
                    
                 int seg=j-i; //seg starts from  i +1  
                 
                 if( seg < len )
                   continue;
                   
                   
               cost[j]=min( cost[j] , cost[i]+( ( seg+len-1)/len  )*pc );
                   
               }  
               
    }    
    
    ans=min( ans , cost[n]+sc*len);
    
}         
   return ans;           
                   
                            
        
  
    
	
}

};



double test0() {
	string p0 = "RRGGBB";
	int p1 = 1;
	int p2 = 1;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string p0 = "R**GB*";
	int p1 = 1;
	int p2 = 1;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string p0 = "BRRB";
	int p1 = 2;
	int p2 = 7;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 30;
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
	string p0 = "R*RR*GG";
	int p1 = 10;
	int p2 = 58;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 204;
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
	string p0 = "*B**B**B*BB*G*BBB**B**B*";
	int p1 = 5;
	int p2 = 2;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 33;
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
double test5() {
	string p0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
	int p1 = 7;
	int p2 = 1;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 30;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
