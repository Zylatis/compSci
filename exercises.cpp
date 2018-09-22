/////////////////////////////////////////////////////
// EXAMPLE USAGE OF IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////
#include "imports.h"


// determine if string has all unique char
bool uniqueDet( string inp ){
	if(inp.length()>256){
		return false;
	} else {
		vector<int> counts(256,0);
		for(int i =0; i<inp.length();i++){
			int pos = (int) inp[i];
			if(counts[pos] != 0){
				return false;
			} else {
				counts[pos]++;
			}
		}
		return true;
	}
}

bool uniqueDet2( string inp ){
	if(inp.length()>256){
		return false;
	} else {
		sort(inp.begin(), inp.end());
		for(int i  =1; i<inp.size();i++){
			if(inp[i]==inp[i-1]){
				return false;
			}
		}
		return true;	
	}
	
}

// basis recursive fib
int fib( int n ){
	if(n==1||n==2){
		return 1;
	} else {
		return fib(n-1) + fib(n-2);
	}
}

//iterative fib using stack
int fibIS( int n ){
	stack<int> comp;
	comp.push(1);
	comp.push(1);
	for(int i = 2 ; i<n; i++){
		int a = comp.top();
		comp.pop();
		int b = comp.top();
		comp.pop();
		comp.push(a);
		comp.push(a+b);
	}
	return comp.top();
}


/////////////////////////////////////////////////////////////
int main ( int argc, char *argv[] ){
	cout<<fib(15)<<endl;

	cout<<fibIS(15)<<endl;;
	//~ cout<<uniqueDet("ab23jdfoie")<<endl;
	//~ cout<<uniqueDet2("ab23jdfoie")<<endl;
	return 0;
	
	
}

/////////////////////////////////////////////////////////////
