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


/////////////////////////////////////////////////////
// Basic DFS to find if one node is connected to another with a particular value, i.e.
// maze solving. Uses 'new' graph DS, the changes to which may have broken the
// Dijkstra part :/

// NOTE: implemented recursively here so is implicitly using a stack.
// Would be worth implementing iteratively with an explicit stack.
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

/////////////////////////////////////////////////////
// Doing sum of arbitrary precision integers using
// vectors. Motivated by Hackerrank question
// where result just needs to be printed to screen
// (so no conversion back to normal ints needed)

void arbSum( vector<int> &A, vector< int> &B ){
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	int s1(A.size()), s2(B.size());
	int resultLength = max(s1,s2);
	int remainder = 0;
	

	// assume for now we go left to right, then reverse later
	vector<int> result(resultLength,0);
	int val;
	for(int i = 0; i< resultLength;i++){
		cout<<A[i]<<"\t"<<B[i]<<"\t"<<remainder<<endl;
		val = A[i] + B[i] + remainder;
		if(val>=10){
			remainder = 1;
			result[i] = val - 10;
		} else { 
			remainder = 0;
			result[i] = val;
		}
		
	}

	if(remainder!=0){
		result.push_back(1);
	}

	for(int i = result.size()-1; i>=0; i--){
		cout<<result[i];
	}
	cout<<endl;
}

// Recursive coin change problem
// Is more concice than the DP one below but see comment,
// as most lines below are initialization steps
int numWays( vector<int> &arr, int i, int sum ){
	cout<<arr[i]<<endl;
	int s = arr.size();
	if(sum==0){
		return 1;
	}
	 if(sum<=0|| i == s){
		return 0;
	} else {
		return numWays(arr,i+1,sum) + numWays(arr, i, sum-arr[i]);
	}
}

// attempt way at DP coin change
// As with most DP cases here, most of the code is dedicated to initializing the first rows
// IMPORTANT: revisit these cases and devise a more succinct way to do this
void numWaysDP( const vector<int> &arr, int sum){
	int out = 0;
	int l = arr.size();	
	int val(0);
	vector<int> cols(sum,0);
	vector<vector<int> > table(l,vector<int>(sum, 0));
	for(int i = 0; i<l; i++){
		if( arr[i] > 1 ){
			table[i][0] = 0;
		} else if(arr[i] == 1 ){
			table[i][0] = 1;
		}
	}
	
	for(int j = 0; j<sum;j++){
		cols[j] = j+1;
		
		if( cols[j] <arr[0]){
			table[0][j] = 0;
		} else if( cols[j]%arr[0] == 0){
			table[0][j] = 1;
		}
	}
	
	for(int i = 1;i<l;i++){
			for(int j = 1; j<sum; j++){
				
				val = table[i-1][j];
				if( cols[j] == arr[i] ){
					val++;
				} else if(cols[j] > arr[i] ){
					int remainder = cols[j] - arr[i];
					val+= table[i][remainder-1];
				}
				table[i][j] = val;
		}
	}
	pm(table);
}

// brute force recursive knapsack
// can be improved with memoization but will run into stack memory issues (probably)
int knapsack( const vector<int> &values, const vector<int> &weights, int i, int w, int v, vector<int> config){
	int maxW =5	;
	if(i>values.size()){
		cout<<"w = "<<w<<", v = "<<v<<endl;
		pv(config);
		return 0;
	} 

	knapsack(values,weights, i+1, w, v, config);	
	if( w + weights[i] <= maxW){
		config[i] = 1;
		knapsack(values,weights, i+1, w + weights[i], v + values[i], config);
	}
	
	return 0;
}

// DP knapsack
void knapsackDP( const vector<int> &values, const vector<int> &weights, int maxW ){
	int l = values.size();
	vector<vector<int> > table(l+1,vector<int>(maxW, 0));
	for(int i = 1; i<l+1;i++){
		cout<<values[i-1]<<endl;
		for(int w = 0; w<maxW; w++){
			if( weights[i-1] > maxW ){
				table[i][w] = table[i-1][w];
			} else {
				table[i][w] = max( table[i-1][w - weights[i-1]]+values[i-1], table[i-1][w]);
			}
		}
	}
}


/////////////////////////////////////////////////////
// Homegrown attempt at edit distance using DP
// Developed by guessing that one can somehow
// do this using a DP table, doing some examples
// and seeing the pattern - nothing too fancy!
// (i.e. as of writing this still not entirely sure
// why this works...well sort of)
int editDist( const string &s1, const string &s2){
	int l1(s1.length()), l2(s2.length());
	vector<vector<int> > table(l1,vector<int>(l2, 0));
	
	if( s1[0] == s2[0] ){
		table[0][0] = 0;
	} else {
		table[0][0] = 1;
	}
	
	for(int j = 1; j<l2; j++){
		if(s1[0] == s2[j]){
			table[0][j] = table[0][j-1];
		} else {
			table[0][j] = table[0][j-1]+1;
		}
	}
	for(int i = 1 ; i<l1;i++){
		if(s1[i] == s2[0]){
			table[i][0] = table[i-1][0];
		} else {
			table[i][0] = table[i-1][0] + 1;
		}
	}

	int best;
	vector<int> options(3);
	for(int i = 1; i<l1; i++){
		for(int j = 1; j<l2; j++){
			if( s1[i] == s2[j] ){
				options[0] = table[i-1][j-1];
			} else {
				options[0] = table[i-1][j-1] + 1;
			}
			
			options[1] = table[i][j-1] + 1;
			options[2] = table[i-1][j] + 1;
			best = *min_element(options.begin(), options.end());
			table[i][j] = best;
			pm(table);
			cout<<"-----------"<<endl;
		}
		
	}
	return table[l1-1][l2-1];
}

// Question 8.2 from CTCI - robot maze!
// Logic is to simply compare correct adjacent tiles, take one with min steps
// and have the blocked ones be infinite steps
void robotMaze( vector<vector < int> > maze ){
	vector<vector< int > > table = maze;
	int r(maze.size()), c(maze[0].size());
	for(int i=0;i<r;i++){
		table[i][0] = i;
	}
	
	for(int j =0;j<c;j++){
		table[0][j] = j;
	}
	for(int  i =1;i<r;i++){
		for(int j  = 1;j<c;j++){
			if(maze[i][j] == INT_MAX){
				maze[i][j] = INT_MAX;
			} else {
				table[i][j] = min(table[i-1][j],table[i][j-1])+1;
			}
		}
	}
	pm(table);
	
}


// DP attempt for all subsets of a set (can do recursively with memoization too
// no real advantage here, stuck with 2^N complexity, would be neater to do recursively probably
void allSubs( vector<int> arr ){
	int n  = arr.size();
	int c  =0;
	vector<vector<vector<int> > > collection = {{{ arr[0]}}};
	vector<vector<int> > temp, t2;
	
	for(int i = 1; i<n; i++){
		temp = collection[i-1];
		t2 = temp;
		for(int j = 0; j<t2.size(); j++){
			t2[j].push_back(arr[i]);
			temp.push_back(t2[j]);
			c++;
		}
		temp.push_back({{arr[i]}});
		collection.push_back(temp);
	}
	// commented out bit to confirm O(2^N) behaviour
	//~ cout<<c<<"\t"<<pow(n,2)<<"\t"<<pow(2,n)<<endl;
	for(int i = 0;i<collection.size(); i++){
		pm(collection[i]);
		cout<<"--"<<endl;
	}
}


// redid string perm given came across it in book again
// still hurts my brain - muddled through it sans error in recursive sp call
// (called on j+1 not i+1)
// Not sure i'll ever get my brain to work this way properly!
// also passed by reference, oops...
int sp(string str, int i){
	int s = str.length();
	if(i==s-1){
		cout<<str<<endl;
	}

	for(int j = i;j<s;j++){
		swap(str[i],str[j]);
		sp(str,i+1);
	}
	
	return 0;
}

// Tower of Hanoi
// Almost got it solo, but did it arse backwards
// Also failed to pick up on the intuition about the ordering, i.e.
// having the role of aux/dest change appropriately (not in a line!)
void move( int n, stack<int> &src, stack<int> &aux, stack<int> &dest){
	
	int v = src.top();
	if(n == 1){
		src.pop();
		dest.push(v);
	} else {
		move( n-1, src, dest,aux);
		
		src.pop();
		dest.push(v);
		
		move( n-1,aux,src,dest);
	}	
	cout<<src.size()<<"\t"<<aux.size()<<"\t"<<dest.size()<<endl;
}


// Function to insert "()" into every position in every string
// in a vector of strings.  Uses hash map to keep track of 
// strings already processed
vector<string> insertPar( const vector<string> &in, unordered_set<string> &tracker ){
	int l = in.size();
	vector<string> out;
	for( int i = 0; i < l; i++ ){
		string temp = in[i];
		if( tracker.find(temp) == tracker.end()){
		cout<<"temp = "<<temp<<endl;
			tracker.insert(temp);
			for( int j = 0; j < in[i].length(); j++ ){
				string t2 = temp;
				t2.insert(j,"()");
				out.push_back( t2 );
			}
		} else {
			cout<<"Already done " + temp<<endl;
		}
	}
	
	return out;
}

// Lazy recursive implementation to generate all valid strings with 
// N sets of parentheses. Makes use of the above utility funciton
// but should probably somehow implement with swap ala permutation question
vector<string> validPar( int n ){
	vector<string> out;
	unordered_set<string> tracker;
	if(n == 1){
		return {"()"};
	}
	
	vector<string> prev = validPar(n-1);
	out = insertPar(prev,tracker);
	
	cout<<"X"<<endl;
	pv(out);
	return out;
}


void fill( vector<vector< int> > &grid, int x, int y, unordered_set<string > &tracker, int colour){
	int h(grid.size()), w(grid[0].size());
	vector<vector<int > > connections = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
	
	for( int k = 0; k<4; k++){
		vector<int> conn = connections[k];
		int a(conn[0]),b(conn[1]);
		string temp = to_string(conn[0]) + to_string(conn[1]);
		cout<<"at "<< x<<","<<y<<" visiting "<<temp<<endl;
		if( a < 0 || a == h || b <0 || b == w ){
			continue;
		} else {
			if( tracker.find(temp) == tracker.end()){
				//~ cout<<"have not yet visited "<<temp<<endl;
				tracker.insert( temp );
				if( grid[a][b] == 0 || grid[a][b] == colour){
					grid[a][b]  = colour;	
					fill(grid, a,b,tracker,colour);
				}
			
			}	
		}
	}
}

// Find contiguous subarray with sum equal given integer
// Runs in O(N) (only does single loop, i.e. each iterator
// only increases, no backtracking
vector<int> printSubArrSub( const vector<int> &arr, int s ){
	int currSum = 0;
	int val;
	int l = arr.size();
	int i(0),j(0);
	bool found = false; 
	while( i< l && j < l && !found){
		val = currSum + arr[j];
		if( val < s ){
			currSum+=arr[j];
			j++;
			
		} else if (val > s){
			currSum-=arr[i];
			i++;
		} else if (val == s){
			found = true;
			cout<<"sum reached at i = "<<i<<", j = "<<j<<endl;
			return {i,j};
		}
	}
	
	cout<<"Not found!"<<endl;
}

// Max index question
// Find max j-i such that arr[i]<=arr[j]
// Brute force soln O(N^2) where we iterate i,j and
// restart j=i when  test fails/reach end
// Better way (I *think* O(N)?) is start j at end
// and reset to position equal to last max before proceeeding

void maxIndex( const vector<int> &arr ){
	int l = arr.size();
	int i(0), j(l-1);
	int diff = 0;
	int a, b;
	while( i < j && j<l ){
	
		if( arr[i] >= arr[j] ){
			j--;
		} else {
			diff = max(diff,j-i);
			a = i;
			b = j;
			i++;
			if(j<l-1){
				j++;
			}
		}
	}
	cout<<diff<<endl;
	cout<<a<<"\t"<<b<<endl;
}

// Interleave question 	
// https://practice.geeksforgeeks.org/problems/interleaved-strings/1
// Did before with 2 queues but doesn't work because it lacks backtracking
// (possible could include this but would be clunky, also prob. equiv to full
// recursive solution but without elegance
bool interleave( string &a, string &b, string &c ){
	int la(a.length()), lb(b.length()), lc(c.length());
	vector<vector< bool > > table(la+1, vector<bool>(lb+1,false));
	bool prev1, prev2;
	table[0][0] =  true;
	for(int i = 0; i<la; i++){
		table[i+1][0] =  ( table[i][0] && c[i] == a[i] );
	}
	
	for(int j = 0; j<lb; j++){
	
		table[0][j+1] =  ( table[0][j] && c[j] == b[j] );
	}
	
	for(int i = 0; i<la; i++){
		for(int j = 0; j<lb; j++){
			prev1 = table[i+1][j];
			prev2 = table[i][j+1];
			table[i+1][j+1] = ( (prev1 || prev2 ) && (c[i+j+1] == a[i] || c[i+j+1] == b[j]) );
		}
	}
	//~ cout<<"---"<<endl;
	//~ pm(table);	
	
	return table[ la ][ lb ];
	
}
