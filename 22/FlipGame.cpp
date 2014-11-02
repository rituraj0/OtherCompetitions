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


class FlipGame 
{
public:

int  minOperations(vector <string> in) 
{
  int ans=0;
  
  int row=in.size();
  int col=in[0].size();
  
  while(1)
   {
       int curr=0;
       
       for(int i=0;i<row;i++)
        {
             for(int j=curr;j<col;j++)
                if( in[i][j]=='1')
                  curr=j+1;
                  
                for(int j=0;j<curr;j++)
                   if( in[i][j]=='1')
                     in[i][j]='0';
                   else
                     in[i][j]='1';
         }
         
               if(curr==0)
                 break;
               else
                 ans++;
       }
       
        return ans;                                                                                                   
	
}

};


double test0() {
	string t0[] = {"1000",
 "1110",
 "1111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FlipGame * obj = new FlipGame();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"1111",
 "1111",
 "1111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FlipGame * obj = new FlipGame();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"00",
 "00",
 "00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FlipGame * obj = new FlipGame();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FlipGame * obj = new FlipGame();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FlipGame * obj = new FlipGame();
	clock_t start = clock();
	int my_answer = obj->minOperations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 29;
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

//Powered by [KawigiEdit] 2.0!
