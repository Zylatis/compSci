#include "imports.h"

/////////////////////////////////////////////////////
// ALGORITHM IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Helper function for quicksort
int partition(vector<int> &vec, int start, int end ){
	
	int a,b;
	
	int li(start+1), ri(end);
	int pivot_val = vec[start];
	bool run = true;
	while(run){
		
		while(vec[li]<pivot_val && li<=ri ){
			li++;
		}
		
		while(vec[ri]>pivot_val  &&  li<=ri){
			ri--;
		}	
		
		if(ri<li){
			run = false;
		}
		
		else {
			a = vec[li];
			b = vec[ri];
			
			vec[li] = b;
			vec[ri] = a; 
		}
	}
	vec[start] = vec[ri];
	vec[ri] = pivot_val;
	
	return ri;
}

/////////////////////////////////////////////////////////////
// Implementation of quicksort 
// Seems possibly faster if random pivot chosen, future work
void quicksort(vector<int> &vec, int first, int last ){
	if(first<last){
		int split = partition(vec,first,last);
		quicksort(vec, first, split-1);
		quicksort(vec, split+1, last);
	}
}



/////////////////////////////////////////////////////////////
// Helper function for mergesort
// Merges two sorted arrays into a single correctly
// sorted array
void merge( vector<int> &arr, int l, int m, int r){
	int count = l;
	vector<int> out = arr;
	int i(l), j(m+1);
	
	while( i <= m && j <=r){
		
		if( arr[i] < arr[j] ){
			out[count] = arr[i];
			i++;
			
		} else {
			out[count] = arr[j];
			j++;
		}
		
		count++;
		
	}
	
	while(i<=m){
		out[count] = arr[i];
		count++;
		i++;
	}
	
	while(j<=r){
		out[count] = arr[j];
		count++;
		j++;
	}
	
	arr = out;

}

/////////////////////////////////////////////////////////////
// Mergesort function
void mergesort( vector<int> &vec, int l, int r ){
			
	if(l<r){
		int m  = l+( r- l )/2;
		mergesort( vec, l, m );
		mergesort( vec, m+1, r );
		merge(vec, l, m, r);
	}
}


/////////////////////////////////////////////////////////////
// Poor iterative solution of algorithm to find
// all permutations of a string
void addLetter( const string inp, char letter, vector<string> &outp){
	int len = inp.length()+1;
	string temp = inp;
	vector<string> out = {};
	for(int i =0; i<len; i++){ 
		temp.insert( i, 1, letter );
		temp = inp;
		outp.push_back(temp.insert( i, 1, letter ));
	}
}


void permute( string inp ){
	vector<string> perms = {inp.substr(0,1)};
	vector<string> temp = {};
	
	for(int i = 1; i<inp.length(); i++){
		temp = {};
		for(int j = 0; j<perms.size(); j++){
			addLetter( perms[j], inp.at(i), temp);
		}
		perms = temp;
	}
}

/////////////////////////////////////////////////////////////
// Much more elegant recursive implementation
// that i feel stupid for not getting the first time around
void perm2( string inp, int l ){
	int s = inp.length();
	if(l == s-1){
		cout<<inp<<endl;
	} else {
		for(int i = l; i<s; i++){
			swap(inp[l],inp[i]);
			perm2(inp, l+1);
		}
	}
}


/////////////////////////////////////////////////////
// Implementation of radix sort for linear time
// sorting of integers
void radixSort( vector<int> &vec ){
	int l = vec.size();
	int max = findMax(vec);// O(N)
	int nDig = findNDig( max ); //O(max) ?
	vector< vector<int> > buckets(10);
	vector<int> empty = {};
	int dig;
	int n = 0;
	
	while(n<nDig){
		fill(buckets.begin(),buckets.end(),empty);
		for( int i = 0; i<l; i++){
			dig = intIndex(vec[i],n);
			buckets[dig].push_back(vec[i]);
		}
		int buck = 0;
		int vecK = 0;
		int m;
		while(buck<10 ){
			m = 0;
			while( m < buckets[buck].size()){
				vec[vecK] = buckets[buck][m];
				vecK++;
				m++;
			}
			buck++;
		}
		n++;
		
	}
	
}
