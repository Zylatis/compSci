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
	int c  = 0;
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

// Alternative implementation for allSubs 
// noted in CTCI solutions

void allSubsBinary( vector<int> arr ){
	int n = arr.size();
	int l = pow(2,n);
	vector<int> bits(l,0);
	for(int i = 0; i < l; i++ ){
		// need bitshifting stuff, tbd
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
// I.e. generate all strings with N parentheses which are valid
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
// Uses above (clunky) helper function
vector<string> validPar( int n ){
	vector<string> out;
	unordered_set<string> tracker;
	if(n == 1){
		return {"()"};
	}
	
	vector<string> prev = validPar(n-1);
	out = insertPar(prev,tracker);
	
	pv(out);
	return out;
}

// Better solution to all valid pars, unfortunately not intuited
// but taken from solutions.
// Idea here is to keep adding "(" until we run out
// then backtrack and add ")" until we run out of those
// The key here is that the first recursive call adding "("
// runs out of "(" to give "(())" so we end up back at 
// "(" and start adding ")" and so on
int validPar2( string str, int n_left, int n_right ){
	// First consider how to deal with invalid states
	if( n_left < 0 || n_right < 0){
		return 0;
	}
	
	// if we have run out of pars and they are balanced,
	// we have reached a solution so print it
	if( n_left == 0 && n_right == 0){
		cout<<str<<endl;
	}
	
	// if we can add "(", then do so
	if( n_left > 0 ){
		string temp = str + "(";
		validPar2( temp, n_left - 1, n_right );
	}
	
	// Similarly with right pars
	// HOWEVER need to make sure we always have unclosed "("
	// otherwise will end up with "(" at the end
	if( n_right > 0 && n_left < n_right ){
		string temp = str + ")";
		validPar2( temp, n_left , n_right - 1 );
	}
	
}

// Attempt at iterative solution for inserting everywhere
void validPar3( int n ){
	
	vector<string> current_result, temp;	
	current_result.push_back("()");
	int i = 1;
	while( i < n ){
		temp = {};
		for( int j = 0; j<current_result.size(); j++){
			string curr_string = current_result[j];
			
			
		}
		
	}

}

// Flood fill alg, recursive (DFS)
// Seems to be correct/optimal soln?
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
// Assumes only positive integers, and a unique soln
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


// Same as above but with negative numbers now, requiring a hashmap
// and so O(n) space whereas before was O(1)
vector<int> printSubArrSubNeg(const vector<int> &vec, int s ){
	int l = vec.size();
	unordered_map<int,int> sums;
	int curr_sum = 0;
	int start = 0;
	for(int i = 0; i<l; i++){
		
		curr_sum += vec[i];
		cout<<curr_sum<<endl;
		if(curr_sum == s){
			cout<<0<<","<<i<<endl;
			return {0,i};
		} 	
		
		if( sums.find(curr_sum - s) != sums.end()){
			start = sums[curr_sum-s]+1; // don't forget the +1 here! We need to move to next element to get start of 'new sum'
			cout<<start<<","<<i<<endl;

			return {start,i};
		} 
		
		sums[curr_sum] = i;
			
	}
	
	return {-1,-1};
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

// Make two arrays: L - max of elements to left, R - max of elements to right
// Iterate through these lists checking if we can find indicies such that
// the largest item on the left is less than the largest item on the right
// Logic: if i can find item on RHS which is > LHS item then I know that's the first
// case of that (say) then i'm necessarily at max index, because that's the first time it was
// large enough to satisfy the condition
// (point is this isn't sorted and we're trying to do it in linear time)
long int maxIndex2( const vector<long int> &arr ){
	int n = arr.size();
   
    long int lmax(0), rmax(0);
    vector<long int> L(n,0), R(n,0);
    
    if(arr[0]<= arr[n-1]){
        return n-1;
    }
    L[0] = arr[0];
    R[n-1] = arr[n-1];
   
	int i(1), j(n-2);
    while(i<n && j>=0){
		 
        L[i] = min(L[i-1], (long int) arr[i] );
       
        i++;
        R[j] = max(R[j+1], (long int) arr[j] );
       
        j--;
    }
    cout<<L[0]<<"t"<<L[1]<<"\t"<<L[2]<<endl;
    cout<<R[n-3]<<"t"<<R[n-2]<<"\t"<<R[n-1]<<endl;
	 i = 0;
    j = n-1;
    while(  i>=0 && i<=j && j<n &&  L[i]>R[j]){
		//~ cout<<i<<"\t"<<j<<endl;
        if( L[i+1] < R[j] ){
            i++;
        } else if(L[i] < R[j-1]){
            j--;
        } else if(L[i+1] <L[i]){
            i++;
        } else if(R[j-1] > R[j]){
            j--;
        } else {
            i++;
        }
      
        if(L[i]<=R[j]){
			
			return j-i;
		}
       
    }
    return j-i;
}

//~ cout<<i<<"\t"<<j<<endl;
		//~ if( L[i+1] < R[j]  ){
			//~ i++;
		//~ } else if(L[i] < R[j-1]){
			//~ j--;
		//~ } else if(L[i+1] <L[i]){
			//~ i++;
		//~ } 
			//~ cout<<i<<"\t"<<j<<endl;
	//~ }

// Interleave question 	
// https://practice.geeksforgeeks.org/problems/interleaved-strings/1
// Did before with 2 queues but doesn't work because it lacks backtracking
// (possible could include this but would be clunky, also prob. equiv to full
// recursive solution but without elegance
void interleave( string a, string b, string c ){
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
	if(table[ la ][ lb ]){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
	
}


// Longest substr with valid parentheses
// Search for ')' then work backwards until find '(' not already visited
// Store positions in hash map then work out largest contiguous part
// (last part TBD)

// Counter suggests O(N) but this is misleading because of the while loops
// so added in counters to be more explicit. Worth noting the outer while loop is actually
// irrelevent , just checking edge case basically 
// So this goes as O(N) + O(M) where M is total length of valid sections checked
// This explains why the complexity of the SO solution is *identical*: the pop operations
// there correspond to the backwards steps here
string validPar( string str ){
	string out;
	int l = str.length();
	
	char closed = ')';
	int pos = 0;
	unordered_set<int> bestSpots;
	int start = 0;
	int counter = 0;
	while( pos < l ){
		
		
		for(int i = 0; i<l; i++){
			if(str[pos] == closed){
				break;
			}
			pos++;
			counter++;
		}
		//~ while( str[pos] != closed ){
			//~ pos++;
			//~ counter++;
		//~ }s
		start = pos+1;
		
		//~ while(str[pos] == closed && bestSpots.find(pos) == bestSpots.end() ){
			//~ bestSpots.insert(pos);
		
			//~ pos--;
			//~ counter++;
		//~ }
		
		
		for(int i =0; i<l; i++){
			counter++;
			if(str[pos] == closed && bestSpots.find(pos) == bestSpots.end()){
				bestSpots.insert(pos);
				pos--;
				
			} else {
				break;
			}
			
		}
		bestSpots.insert(pos);

		pos = start;
		
	}
			
	//~ for(const auto& elem: bestSpots){
		//~ cout<<elem<<endl;
	//~ }
	cout<<l<<endl;	
	cout<<counter<<endl;
	return out;
}




// Pinched this longest valid substr from SO answer
// Is very nice and contains the bit i was missing to make the
// soln with stack work. Very clearly O(N) and better than my dict
// soln above
void SOvalidPar( string str ){
	int l = str.length();
	int last = -1;
	int maxLen = 0;	
	int count= 0;
	stack<int> stack;
	for(int i = 0; i<l; i++){
		if(str[i] == '('){
			stack.push(i);
			count++;
		} else {
			if(stack.empty()){
				last = i;
				count++;
			} else {
				stack.pop();
				count++;
				if(stack.empty()){
					maxLen = max(maxLen,i-last);
					count++;
				} else {
					maxLen = max(maxLen, i - stack.top());
					count++;
				}
			}
			
		}
		
	}
	cout<<l<<endl;
	cout<<count<<endl;
	cout<<maxLen<<endl;
	
}

// Given a sequence of I,D (increasing, decreasing) and using only digits
// 1-9 without repeats, find the smallest number satisfying that sequence
// from GFG google interview repo.
// Lots of aux functions and brute force took longer than it should have to write...
// also needs more extensive edge testing
bool compare( vector<int> num, string str){
	int n = num.size()-1;
	
	//~ bool out = true;
	for(int i = 0; i<n;i++){
		if( ( str[i] == 'I' && num[i+1] - num[i] < 0 )|| ( str[i] == 'D' && num[i+1] - num[i] > 0 )){
			return false;
		}
	}
	
	return true;
}

vector< vector<int> > aux(string str, int n ){
	if(n == 1){
		return {{1},{2},{3},{4},{5},{6},{7},{8},{9}};
	}
	int l = str.length();
	vector<vector<int > > temp = aux(str,n-1);
	vector<vector< int > > temp2;
	for(int i = 0; i<temp.size(); i++){
		vector<int> current = temp[i];
		
		for(int j = 1; j<10; j++){
			vector<int> newV = current;
			if( find(current.begin(), current.end(), j) == current.end() ){ // if integer not in use
				newV.push_back(j);
				if( compare(newV,str) ){
					temp2.push_back(newV);
				}
			}
		}
	}
	
	return temp2;
}

// uses above helper functions
int largestIDSeq( string str ){
	int l  = str.length();
	vector<vector<int > > allSets = aux(str,l+1);	
	pv(allSets[0]);
	return 0;
}

// shifts all elements in vector by val
void modifyV( vector<int> &in, int val ){
	for(int i = 0;i<in.size(); i++){
		in[i] + val;
	}
}

// 2nd round largest ID seq solution
// 9oct incomplete
int largestIDSeq2( string str ){
	int l  = str.length();
	vector<int> num(l+1,0);
	unordered_set<int> used;
	num[0] = 1;
	used.insert(1);
	int lastS = 1;
	for(int i = 0; i<l;i++){
		char c = str[i];
		if( c == 'D' && num[i+1] - num[i] >0){
			for(int j = lastS+1; j<10; j++){
				if( used.find( j )==used.end()){
					
				}
			}
		}
	}

	return 0;
}


// Longest common subsequence
// Again need to come back and think more carefully about
// more concisely inputting initial conditions (9oct seems okay?)
int LCS( string a, string b ){
	int out;
	string LCS = ""; // store LCS string
	int l1(a.length()), l2(b.length());
	vector<vector< int > > table( l1+1, vector<int>(l2+1,0));
	
	int val = 0;
	for(int  i =0; i<l1; i++){
		for(int j = 0; j<l2; j++){
			int val =  max(table[i][j+1], table[i+1][j] );
			if( a[i] == b[j] ){
				table[i+1][j+1] =val + 1;
				LCS+=a[i];

			} else {
				table[i+1][j+1] = val;
			}
		}
		
	}
	cout<<LCS<<endl;
	pm(table);
	return table[l1][l2];
}

// From https://www.youtube.com/watch?v=IWvbPIYQPFM
// 12 Oct Note: more or less correct solution, can possibly do better with stacks and stuff,
// will return to this, also video advised assuming methods to get valid neighbours to save time
// so do that in future, maybe. Also should do iteratively at some point along with other recursive DFS alg
int gridArea( vector<vector< int > > &grid, int x, int y, int colour, unordered_set<string> &tracker ){
	int out, h(grid.size()), w(grid[0].size());
	vector<vector<int> > adjList = {{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
	
	for(int k = 0; k<4; k++){
		vector<int> connection = adjList[k];
		int a(connection[0]), b(connection[1]);
		string coord = to_string(a)+to_string(b);
		
		if( a <0 || a == h || b <0 || b==w){
			continue;
		}
		else if( grid[a][b] == colour &&  tracker.find( coord ) == tracker.end() ){
			tracker.insert(coord);
			gridArea( grid, a, b, colour, tracker);
		}
	}

	return tracker.size();
}	


// K-th largest element using heap
// Can also be used to generate the first k largest elements
// (which I think cannot be done with quickselect)

// Heapify is O(n), removal of element and reshuffle is log(n)
// so overall complexity is O(n + k logn) = O(n)
void kth_largest( const vector<int> &vec, int k ){
	int l = vec.size();
	vector<int> k_heap(vec.begin(),vec.end());
	make_heap(k_heap.begin(), k_heap.end());
	
	for(int i = 0; i<k-1; i++){
		
		pop_heap(k_heap.begin(),k_heap.end());
		k_heap.pop_back();
	}
	cout<<k_heap.front()<<endl;
}

// Binary search (recursive) of sorted array in log(n) time 
int binary_search( const vector<int> &vec, int start, int end, int val, int c ){
	int mid =  start + floor(end - start)/2; // return to subtleties here
	int result = -1;
	
	if(start == end){
		if(val==vec[start]){
			cout<<"found at "<<mid<<endl;
			cout<<"search completed in "<<c<<" steps"<<endl;
			result = start;
		} else {
			result = -1; // doubling up a bit here but meh
		}
		return result;
	}
	
	if(val > vec[mid]){

		result = binary_search(vec,mid+1,end,val, c+1);
	} else {
	
		result = binary_search(vec,start,mid,val, c+1);
	}
	
	return result;
}


// Binary search (iterative - seems nicer actually!)
// TODO: pathological test cases
int binary_search_iter( const vector<int> &vec, int val ){
	
	int start(0), end(vec.size()-1), mid;
	
	while( start<=end){
		mid = (start+end)/2;
		if(vec[mid] == val){
			return mid;
		}
		if(vec[mid] < val){
			start = mid+1;
		} else {
			end = mid;
		}
		
	}
	
	return -1;
}

// 16.5
// Tokenize, ish, string
// Needs helper functions (tests for separators)
void tokenize(string str){
	int l = str.length();
	vector<string> text;
	unordered_map<string,int> counts;
	int i = 0;
	string word;
	
	while( i < l ){
		word = "";
		while( str[i] != ' ' && str[i] != ','  && i < l ){
			word+=str[i];
			i++;
		}
		text.push_back( word );
		if( counts.find( word ) == counts.end() ){
			counts[word] = 1;
		} else {
			counts[word]++;
		}
	
		i++;
	}
	
	//~ pv(text);
	//~ cout<<counts.size()<<endl;
	//~ cout<<text.size()<<endl;
}

// 16.6 Smallest diff problem
// Given two lists of ints compute pair with smallest non neg difference
// Soln: sort both then start comparing largest element with smallest of other one while difference decreases, 
// then once neg, increment starting point in both 
// NOTE: how to deal with multiples of same diff?
// Need an 'equals' case and add to a list probably
void smallest_diff( vector<int> v1, vector<int> v2 ){
	int l1(v1.size()), l2(v2.size());
	quicksort(v1,0,l1-1);
	quicksort(v2,0,l2-1);
	
	int diff_best = INT_MAX;
	int diff;
	vector<int> best_coords = {0,0};
	vector<int> best_vals = {0,0};
	int i(0), j(0);
	while(i < l1 && j<l2 ){
	
		diff = abs(v2[j] - v1[i]);
		if(diff < diff_best){
			diff_best = diff;
			best_coords = {i,j};
			best_vals = {v1[i],v2[j]};
		}
		
		
		if( v1[i] < v2[j] ){
		
			i++;
		} else {
		
			j++;
		}
	}
	pv(best_vals);
}


// 16.7
// Find max without using comparator operator
// NOTE: This works but probably not for negative numbers...
// ALSO will overflow if b > a is INTMAX

// Return to this and think about the 32 bit nature of things!
void find_max( int a, int b ){
	int val  = floor(a/b)*a + floor(b/a)*b;
	cout<<val<<endl;
	
}


// 16.8 Word number parser
// NOTE come back and get # digits using floor log10()
void parse_number( int val ){
	vector<int> digits, d2;
	int n = 0;
	while( pow(10,n)<val ){
		
		digits.push_back(intIndex(val,n));
		n++;
		
	}
	
	n = digits.size();
	d2.resize(n);
	for(int i = 0; i<n;i++){
		d2[i] = digits[ n- i-1];
	}
	
	unordered_map<int,string> single  = { {1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, };
	unordered_map<int,string> teens  = { {1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, };
	pv(d2);
	// will come back to this
}

int count_letts( const string &str, char lett){
	
	int s = str.length();
	int count = 0;
	for(int  i = 0 ; i < s; i++){
		if(str[i] == lett ){
			count++;
		}
	}
	return count;
}



// 16.18 - Pattern matching
// Check if input string matches pattern string
// Example 'catcatgocatgo' matches 'aabab'
// Logic: we know length of string and of pattern, so work through possible lengths of pattern component 
// (assuming only allowed two pattern components 'a' and 'b'
// NOTE: not very optimal for something like 'ba' because it looks for 'a' first so gets to the end,
// i.e. it's starting with a_len = 1 and that is the only solution, whereas a heuristic to start a_len
// or b_len at 1 would be better
int check_pattern(string str, string ptn ){
	// Get lengths of inputs
	int str_l = str.length();
	int ptn_l = ptn.length();

	// count number of each letter in input pattern
	int nA = count_letts(ptn,'a');
	int nB = count_letts(ptn,'b');
	
	// Print to screen useful things
	cout<<str<<endl;
	cout<<ptn<<endl;
	cout<<"---"<<endl;
	
	// consider all lengths for 'a' less than string length
	// As noted above, starting with a_len = 1 may not always be optimal
	for(int  a_len = 1; a_len<=str_l; a_len++){
		// Assume valid pattern unless we find a conflict
		bool valid  = true;
		
		// compute the b_len associated with current a_len
		float b_len;
		// if we have no 'b's, force b_len to be zero (otherwise we get inf below)
		// NOTE: remember this to think about edge checks without advantage of actual test!
		if(nB == 0){
			b_len = 0;
		} else {
			 b_len = (str_l-a_len*nA)/(1.*nB);
		 }
	
		// check if integer, if so can potentially use this configuartion
		if( floor(b_len) == b_len && b_len>=0){
				
			// initialize strings to keep track of current matched patterns
			string aStr(""), bStr("");
			
			// start at start of string to be matched
			int str_pos = 0;
			
			// iterative over characters in the input pattern
			for(int i  = 0; i< ptn_l; i++){
				char lett = ptn[i];
							
				
				if( lett == 'a' ){
					// if we are at the first case of 'a' (if aStr = "") OR
					// we find that the previous match we found is the same as the current match,
					// keep going, and advance the iterator in the main string by one a_length
					if(aStr == "" || aStr ==  str.substr( str_pos,  a_len)){
						aStr =  str.substr( str_pos,  a_len);
						str_pos += a_len;
					} else {
						// if we find the current match isn't the same as the previous one, we have
						// found an inconsistency for this value of a_len, so no need to continue
						valid = false;
						break;
					}
					
				
				// Same as above but for letter b
				// could potentiall refactor this to be nicer
				// Tempting to think we could do this for arbitrary number of pattern variables
				// but then the logic of the deducing the size of b_len fails (non-unique)
				} if( lett == 'b' ){
					if(bStr == "" || bStr ==  str.substr( str_pos,  b_len)){
						bStr =  str.substr( str_pos,  b_len);
						str_pos += b_len;
					} else {
						valid = false;
						break;
					}
				}	
			}
			
			// We have a valid patter if none of the above gave false
			// AND we checked the entire string
			if(valid && (nA*aStr.length() + nB*bStr.length()) == str_l){
				cout<<"valid pattern with patterns: "<<aStr<<", "<<bStr<<endl;
				return 1;
			}
		}
	
	}
	
	// Otherwise, couldn't match
	cout<<"No valid pattern found"<<endl;
	return -1;
}

// 16.21 Given two arrays find pair, one from each, we can swap
// so both arrays now have same sum
// Logic: put elements in HT (maybe don't need both, will return to this)
// Compute sum of both arrays
// For one array, compute sum as if we lost that element, and compute sum of
// other one as if it gained that element.
// In order for the sums of both to be the same, there must be an element that the 2nd one
// can lose and the first gain to get the same sum
// This new sum must be the average of the two intermediate sums, i.e. need to find
// new element x such that x/2 is the difference between the new sums, so do HT
// lookup to see if that exists in 2nd array

void find_pair_swap( vector<int> A, vector<int> B){
	int sumA, sumB;
	int lA(A.size()), lB(B.size());
	
	sumA = accumulate(A.begin(), A.end(), 0);
	sumB = accumulate(B.begin(), B.end(), 0);
	
	
	unordered_set<int> HT(B.begin(), B.end());
	
	for(auto el : A ){
		int a_sum_temp = sumA - el;
		int b_sum_temp = sumB + el;
		float middle = ( b_sum_temp - a_sum_temp)/2.;
		if( middle == floor(middle)){
			if( HT.find( middle ) != HT.end()){
				cout<<"Can swap A:"<<el<<" and B:"<<middle<<endl;
			}
			
		}
		
	}
}

void iterative_pars( const int n ){
	int nopen(0), nclose(0);
	string pars(2*n, ' ') , end_state(2*n, ' ');
	int i;
	stack<char> stack;
	for(int i = 0; i<2*n; i++){
		if((i+1)%2 == 0 ){
			end_state[i] = ')';
		} else {
			end_state[i] = '(';
		}
		if( i+1 <=n ){
			pars[i] = '(';
			stack.push('(');
		} else {
			pars[i] = ')';
			stack.push(')');
		}
	}
	int j = 0;
	while( pars != end_state ){
		while( nopen > 0 && pars.length() != 2*n){
			stack.push('(');
			pars+='(';
			nopen--;
			//~ cout<<"add ("<<endl;
		}
		
		while(nclose > 0){
			stack.push(')');
			pars+=')';
			//~ cout<<"add )"<<endl;
			nclose--;
		}
		cout<<pars<<endl;

		if(pars==end_state){
			break;
		}
		
		i = 2*n;
		char temp;
		while(i>=0 ){
			i--;
			
			temp = pars[i];
			if( temp == '('){
				//~ cout<<"return ("<<endl;
				nopen++;
			} else {
				nclose++;
				//~ cout<<"return )"<<endl;
			}
			
			stack.pop();
			pars.pop_back();
			
			if(  temp == '(' && i != 2*n-2){
				// basically need to come back here and fiddle backtracking so it knows
				// if swapping this position would make it impossible to satisfy later conditions
				// i.e. needs to know if everything prior to this position is valid, if so cannot swap
				break;
			}
			
		}
		
		//~ while(stack.top() != '(' && !stack.empty()){
			
			//~ stack.pop();
			//~ pars.pop_back();
			//~ nclose++;
			//~ i--;
		//~ }
		
		
		//~ exit(0);
		if(nclose>0 && nclose > nopen ){
			//~ stack.pop();
			//~ pars.pop_back();
			//~ nopen++;
			stack.push(')');
			pars+=')';
			nclose--;
		}
		
		//~ cout<<pars<<endl;
		//~ cout<<nopen<<"\t"<<nclose<<endl;
		//~ exit(0);
		//~ exit(0);
		if(j>8){
			exit(0);
		}
		j++;
		//~ cout<<pars<<endl;
		//~ cout<<nopen<<"\t"<<nclose<<endl;
	
	}
	
}

// apparently lots of real coders can't do this, 
// so here I go...
// A bit sloppy because I am not using any 'elses'
// so not optimal run time but at least clear!
void fizzbuzz( int n ){
	
	for(int i = 0; i<n; i++){
		if(i%3 == 0){
			cout<<"fizz";
		} 
		
		if(i%5 == 0){
			cout<<"buzz";
		}
		
		if(i%5 != 0 && i%3 != 0){
			cout<<i;
		}
		cout<<endl;
	}
}

// Print k-th row pascal triangle
// Done in O(k) space (prefactor 2, possible to do with 1 but...)	
void pascal_k( int k ){
	int l = k;
	vector<int> vec(l,0);
	vector<int> temp(l,0);
	vec[0] = 1;
	vec[1] = 1;
	
	for(int i = 2; i<k; i++){
		temp[0] = 1;
		temp[i] = 1;
		for(int j = 1; j<k;j++){
			temp[j] = vec[j-1]+vec[j];
		}
		vec = temp;
	}
	pv(vec);
}


// rotate (square) matrix in place
void rotate_matrix( vector<vector< int > > &A ){
	int N(A.size());
	// check if square
	if(A[0].size() != A.size()){
		cout<<"Not square matrix :("<<endl;
		exit(0);
	}

	// Rotate by doing swaps and considering concenctric shells as we move in.
	// Easiest to see looking at corner points of matrix, a bit harder for other parts
	
	// First we swap the required elements in first and 2nd row, then go back counter clockwise swapping
	// So (1,2),(4,3) -> (2,1),(4,3) -> (4,1),(2,3) -> (4,1),(3,2) which is rotated (it just doesn't look like it when flat)
	pm(A);
	for( int j = 0; j<2; j++){
		for(int k = j; k<N-1 -j; k++){
			cout<<j<<"\t"<<k<<endl;
			cout<<"swap ("<<j<<", "<<k<<") and ("<<k<<", "<<N-1-j<<")"<<endl;
			cout<<"swap ("<<j<<", "<<k<<") and ("<<N-1-k-j<<", "<<j<<")"<<endl;
			cout<<"swap ("<<N-1-k-j<<", "<<j<<") and ("<<N-1-j<<", "<<N-1-k-j<<")"<<endl;
			
			swap(A[0 + j ][k  ], A[k ][N-1 - j]);
			swap(A[0 +  j][k], A[N-1-k - j][0 + j]);
			swap(A[N-1-k - j][0 + j], A[N-1 - j][N-1-k - j]);
		
		
			pm(A);
		}
	}
	pm(A);
}


int majority_element( const vector<int> &arr ){
	int counter = 1;
	int el = arr[0];
	int l = arr.size();

	for(int i = 1; i<l; i++){
		
		if( arr[i] == el ){
			counter++;
		} else {
			counter--;
		}
		if(counter == 0){

			el = arr[i];
			counter = 1;
		}
		
	}
	
	// had to cheat a bit to find out how to show if it exists!
	// simply loop back over and count # of instances
	
	counter = 0;
	for(int i = 0; i < l; i++){
		if(arr[i] == el){
			counter++;
		}
	}
	if(counter> l/2){
		return el;
	} else {
		return -1;
	}
}

int missing_digit_thrice( const vector<int> &arr ){
	vector<int> bits(5,0); // need way to determine max bit length
	int l = arr.size();
	for(int i = 0; i<l; i++){
		for(int j = 0; j<5; j++){
			if( arr[i]>>j & 1 == 1){
				bits[4-j]++;
			}
		}
	}
	
	pv(bits);
	for(int i = 0; i<bits.size(); i++){
		bits[i] = bits[i]%3;
	}

	pv(bits);
	return 0;
}

int BS( const vector<int> &vec, int val ){
	int l = vec.size();
	int i(0), j(l-1);
	int pivot;
	
	while(i<l && j>= i){
		pivot = (j-i)/2 + i;
		
		if( i + 1 == j){
			return i;
		}
		
		if( vec[pivot] < val ){
			i = pivot;
		}
		
		if( val< vec[pivot] ){
			j = pivot;
		}
			
	}
	
	return pivot;
}


// Compute median of array made by merging two sorted arrays
// First iterates through one array looking (with binary search) at where to insert
// elements in other array, keeping track of total position

// NOTE SURE HOW TO DO IN LOG(M+N)?
int merged_median( const vector<int> &A, const vector<int> &B ){
	int n(A.size()), m(B.size());
	int i = 0;
	int j = 0;
	pv(A);
	pv(B);
	cout<<"---"<<endl;
	for(int k = 0; k<m;k++){
		i = BS(A, B[k]);
		j+=i;
		if( j>= floor((n+m)/2)){
			cout<<B[k]<<endl;
		}	
	}
	
	return A[( m+n)/2 - m];
}

bool is_palindrome(string str, int lo, int hi ){
	int l = str.length();

	int i(lo), j(hi);
	while( i<j ){
		if(str[i] != str[j]){
			return false;
		}
		i++;
		j--;
	}
	
	return true;
	
}
// For the love of god draw recursion diagrams when doing this shit!
// This one is a bit cantankerous though just because of the need to keep track of lots of outputs
// Think about going until finding a subsystem that matches condition, storing it, then checking rest starting from that end point
// so 'check first block' then rest etc
void palindrome_partitions( vector< vector<string> > &all_pars, vector<string> &curr_par, string str, int start ){
	if( start >= str.length()){
		all_pars.push_back(curr_par);
		return ;

	}
	
	int n = str.length();
	for(int end = start; end < n; end++){
		//~ cout<<start<<"\t"<<end<<endl;
		if(is_palindrome(str, start,end)){
			//~ cout<<start<<"\t"<<end<<endl;
			curr_par.push_back(str.substr(start, end - start + 1));
			
			palindrome_partitions(all_pars,curr_par, str, end + 1);
			//~ pv(curr_par);

			curr_par.pop_back(); // this is the backtracking part
			// it only turns on once we hit the end of the string with base case
			// after which it rolls back up testing for PDs of length 2, 3 etc...
			// Basically ditch the last block and now iterate the start point to start
			// going through that block, breaking it up
			//~ pv(curr_par);
			//~ cout<<"----"<<endl;
		}	
		//~ cout<<"finish "<<start<<"\t"<<end<<endl;
		
	}	
}
 
// Word break problem
// Given a valid sentence without any spaces between the words and a dictionary of valid English words,
// find all possible ways to break the sentence in individual dictionary words.
// e.g. dict = { i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango}
// str = ilikeicecreamandmango
// Same as other backtracking problems: find first instance then recurse on rest, then go back and keep increasing
// subsystem counter to see if can find other instances starting from that first part

void word_break( const unordered_set<string> &dict, string str, int start,  vector<string> &current_set, vector<vector< string> > &master_set ){
	int l = str.length();
	
	// remember base case here is hitting end of string which means pushing back
	// whole lot to the master set, not just adding final char.
	// The final char will be dealt with elsewhere, and only added if a valid move
	if( start >= l){
		master_set.push_back(current_set);
		return ;
	}
	
	for(int end = start; end<l; end++){
		string sub = str.substr(start, end-start+1);
		if( dict.find(sub)!= dict.end()){
			current_set.push_back( sub );
			word_break( dict, str, end+1, current_set, master_set );
			
			// now backtrack, meaning we go back up the recursion tree
			// but the way we do that here is not just to return out of these calls
			// but to undo the adds we've done to our temp array
			current_set.pop_back();
		}
		
	}
	
}

template< typename T1, typename T2>
void print_dict( unordered_map<T1,T2> &dict){
	for(auto&kv : dict){
		cout<<kv.first<<"\t"<<kv.second<<endl;
	}
}
// Do more general pattern matching
// Previous one assumed only 2 components to pattern and used this
// to cheat a bit but if more than 2 then case of diminishing returns
// (cannot immediately infer length of all remaining components)
// However a similar logic applies: essentially the search space is the length of 
// each of the pattern components. So we pick len 1 for first, recurse on rest starting from that spot
// (having stored that pattern in a dict to check against)
// If a pattern element already seen, check that against the next L letters and reject that branch
// if doesn't match AND reset that pattern component (alternatively keep local dicts to feed directly as local copies for each branch?)
// This makes the backtracking automatic as the dict is local for each instance, no need to 'rewind' manually
// ALSO beware it may not be unique
void pattern_matching_gen( string patt, string target, unordered_map<char,string> &dict, int start_target, int patt_el){
	int n = target.length();
	// if all bits are in the dict and we're at the end of the string,
	// we're done (might need to check total length but should be done auto
	// in rest?)
	//~ cout<<"par "<<patt[patt_el]<<", start_target"<<start_target<<"\t"<<patt_el<<endl;
	//~ print_dict(dict);
	//~ cout<<"---"<<endl;

	
	// veeeerry clunky, maybe wrong too
	if( dict.size() == 2 && start_target == n ){
		
		//~ cout<<temp<<endl;
		string temp = "";

		for( int i = 0; i < patt.length();i++){
			temp+=dict[patt[i]];
		}
		
		if(temp == target){
			cout<<"return"<<endl;	
			print_dict(dict);
			cout<<temp<<endl;
			return;
		}
	}
	string substr;
	int substr_l;
	char patt_char = patt[patt_el];
	
	if( start_target == n && patt_el != 2){
		dict.erase(patt_char);
		return;
	}
	
	if( dict.find(patt_char) != dict.end() ){
		
		// check next m chars
		substr = dict[patt_char];
	
		substr_l = substr.length();
		string target_substr = target.substr( start_target, substr_l);
		//~ cout<<substr<<"\t"<<target_substr<<endl;
		if( substr == target_substr){
			// if we can re-use this saved pattern at current location,
			// keep this pattern and move on
		
			pattern_matching_gen( patt, target, dict, start_target + substr_l, patt_el+1 );
			
			//~ cout<<"backtrack on "<<patt_char<<endl;
			dict.erase( patt_char ); // backtrack needed here too i guess? seems clunky...
			
		} else {
			// otherwise, this pattern for patt_el is invalid, remove from dict and backtrack (return)
			//~ cout<<"backtrack on "<<patt_char<<endl;
			
			dict.erase( patt_char );

			return;
		}
		
	} else {
		for(int end = start_target; end<n;end++){
			substr = target.substr(start_target, end-start_target+1);
			substr_l = substr.length();
		
			dict[patt_char] = substr;
		
			pattern_matching_gen( patt, target, dict, start_target + substr_l, patt_el+1);
			//~ cout<<"backtrack on "<<patt_char<<endl;

			dict.erase( patt_char );
		}
	}
	
	
	
}

// Rotated array search - Interviewbit
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
// You are given a target value to search. If found in the array, return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

// Approach: we can split in to two parts and deduce the position of the pivot and go from there
// In the above example, we split in to 5 parts (cuz odd): middle, and start/end of other sections
// If start<end then that section is sorted and does not contain the first element in original unrotated list
// If both are in order, then the middle pivot element must be the first element (or middle/one of middle ones - even v odd)

// Above stuff might not actually be needed if all we are doing is doing a search..
// We can do same logic based on the start/end above: only need to test one half, don't care where first element is
// i.e. search for 1 in above example. s_1 = 4, e_1 = 6, s2 = 0, e2 = 2
// so clearly it is in 2nd part
// Or a slightly harder example:
// 2 4 5 6 7 0 1  so
// s1 = 2, e1 = 5, s2 = 7, e2 = 1
// searching for 0: definitely not in LHS so must be RHS
int search_rotated( const vector<int> &arr, int val ){
	int n = arr.size();
	int pivot = (n-1)/2;
	int i(0), j(n-1);
	int lmin( arr[i] ), lmax(arr[pivot-1]), rmin(arr[pivot+1]), rmax(arr[j]);
	
	while( i<j ){
		
		if( val == arr[i] ){
			return i;
		}
		
		if( val == arr[j] ){
			return j;
		}
		
		if( val == arr[pivot] ){
			return pivot;
		}
		
		if( lmin <= val && val <= lmax){
	
			j = pivot;
			pivot = (pivot-i)/2;
			lmax = arr[pivot-1];
			rmin = arr[pivot + 1];
			rmax = arr[j];	
		} else {
			cout<<"X"<<endl;
			i = pivot;
			pivot = (j-pivot)/2 + pivot;
			lmin = arr[i];
			lmax = arr[pivot-1];
			rmin = arr[pivot+1];
			
		}
		
	}
	
	return 0;
} 

// think of edge cases
// duplicates!
// had error in terms of advancing both arrays at once REMEMBER THIS!
void sorted_arr_intersection( const vector<int> &A, const vector<int> &B ){
	int len_A(A.size()), len_B(B.size());
	vector<int> out;
	int i(0), j(0);
	while( i < len_A && j < len_B){
		if(A[i] == B[j] ){
			out.push_back(A[i]);
			i++;
			j++;
		}
		
		else if( A[i] < B[j] ){
			i++;
		} else {
			j++;
		}
	}
	pv(out);
}

bool single_change( string s1, string s2){
	int count = 0;
	for(int i = 0; i<s1.length(); i++){
		if(s1[i] != s2[i] ){
			count++;
		}
		if(count>1){
			return false;
		}
	}
	// doesn't deal with edge case where they are the same, but should't be
	// if dict 
	return true;
}

// don't erase things from dict while inside, duh!
int word_ladder( string source, string target, unordered_set<string> &dict){
	int l(source.length());
	int count(0);

	if(l != target.length()){
		cout<<"length mismatch"<<endl;
		return -1;
	}
	
	stack<string> stack;
	stack.push( source );
	string current;
	// source not in dict so no need to erase
	// do DFS using explicit stack to store nodes which are
	// distance 1 from current nodes
	while( stack.size() != 0 ){
		count++;
		current = stack.top();
			
		cout<<"pop "<<current<<endl;
	
		stack.pop();
		if( current == target ){
			cout<< count<<endl;
		}
	
		vector<string> removals = {};
		for( const auto &k : dict ){
			//~ cout<<"check "<<current<<" "<<k<<endl;
			if( single_change( current, k ) ){
				cout<<"push "<<k<<endl;
				stack.push( k );
				//~ cout<<"erase "<<k<<endl;
				//~ dict.erase(k);
				removals.push_back(k);
			}
		}
		
		cout<<"--"<<endl;
		for(auto &el : removals){
			dict.erase(el);
		}
		
		
		//~ exit(0);
	}
	
	return 0;
	
}


int duplicates( const vector<int> &A){
	 // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int a(0), b(0);
    int aVal(A[a]), bVal(A[A[b]]);
    // can't modify array in place, have to do some other funky cycle detectin
    // 5 1 4 6 3 2 1 
	cout<<aVal<<endl;
	cout<<bVal<<endl;
    while(aVal != bVal){
		
		
		//~ cout<<a<<"\t"<<b<<endl;
		//~ cout<<aVal<<"\t"<<bVal<<endl;
		//~ cout<<"---"<<endl;
		   exit(0);
    }
    
    return aVal;
}


// helper function to check if element exists in unordered set

template< typename T>
bool in_set( const unordered_set<T> &set, const T &el){
	if(set.find(el)!=set.end()){
		return true;
	}
	return false;
}

int no_repeat( const string &str ){
	int n = str.length();
	int l(0);
	int i(0), j(0);

	unordered_set<char> seen;
	
	while(i<=j && j<n){
		if(!in_set( seen, str[j] ) ){
			seen.insert(str[j]);
			j++;	
		} else {
			seen.erase(str[i]);
			i++;
		}
		
		l = max(l, j-i);
	}

	return l ;
	
}
