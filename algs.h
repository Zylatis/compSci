#include "imports.h"
#include "ds.h"
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



/////////////////////////////////////////////////////
// Largest sum contiguous subarray (Kadengesdasd alg)
// My hacky attempt first. First do brute force

vector<int> K1(vector<int> &in){
	int l = in.size();
	vector<int> temp;
	vector<int> out;

	int sum;
	int max = in[0];
	for(int i = 0; i<l; i++){
		for(int j = i; j<l; j++){
			temp.resize( j - i+1);
			copy(in.begin()+i, in.begin()+j+1, temp.begin());
			sum = accumulate(temp.begin(),temp.end(),0);
			if(sum>max){
				max = sum;
				out = temp;
			}
		}
		
	}
	return out;
}


/////////////////////////////////////////////////////
// Better version of above (hopefully)
vector<int> K2(vector<int> &in ){
	vector<int> out;
	int max = in[0];
	int sum = 0;
	int i(0), j(0);
	int l = in.size();
	int a(0),b(0);
	while( j<l ){
		sum += in[j];
		
		if( sum > max ){
			max = sum;
			a = i;
			b = j;
		}
		
		if(  sum<0) {
			sum =  0;
			i = j+1;//need to think carefully about +1 here...
		}
		j++;
	}
	out.resize( b - a+1);
	copy(in.begin()+a, in.begin()+b+1, out.begin());
	return out;
}

/////////////////////////////////////////////////////
// check if string with pars is balanced
bool isBalanced( string str  ){
	
	stack<string> par;
	string c;
	for(int i = 0; i<str.length(); i++){
		c = str[i];
		if( c == "(" ){
			par.push(c);
		}
		
		if( c==")" && par.size() !=0){
			par.pop();
		} else if(c==")" && par.size() ==0){
			return false;
		}
	}
	
	if(par.size() == 0){
		return true;
	}
		
	return false;
}

/////////////////////////////////////////////////////
// Remove invalid parentheses using BFS
vector<string> remIP( string str ){
	int l = str.length();
	int n = 0;
	string temp;
	string s;
	queue<string> nodes;
	nodes.push(str);
	bool current;
	int count(0);
	unordered_set<string> visited;
	bool found = false;
	vector<string> valid;
	while( !nodes.empty()){
		s = nodes.front();
		current = isBalanced(s);
		if(current){
			valid.push_back(s);
			found = true;
		} else if (!current and !found) { 
			for(int i = 0; i<s.length();i++){
				temp = s;
				temp.erase(i,1);
				if(visited.find(temp) == visited.end()){
					nodes.push(temp);
					visited.insert(temp);
				} 
			}
			
		}
		nodes.pop();
		count++;
	}
	return valid;
}



void dfs( graphNode<int>* head, int target, unordered_set<graphNode<int>*> &visited ){
	visited.insert(head);
	cout<<head->dat<<endl;	
	unordered_set<graphNode<int>* > connections;
	int val;
	for(auto i = head->connections.begin(); i!=head->connections.end(); i++){
		val = (*i)->dat;
		
		if(val == target){
			cout<<"found!"<<endl;
			exit(0);
		} else if( visited.find((*i)) == visited.end()){
			dfs( *i, target, visited);
		}
		
	}
	
}
