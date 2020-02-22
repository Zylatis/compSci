/////////////////////////////////////////////////////
// HELPER FUNCTION IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// Print vector
template <typename T> 
void pv( const vector<T> &out ){
	int l = out.size();
	for(int i = 0; i<l; i++){
		cout<<out[i]<<"\t";
	}
	cout<<endl;
}

/////////////////////////////////////////////////////
// Print matrix
template <typename T> 
void pm( const vector<vector<T> > &out ){
	int l = out.size();
	for(int i = 0; i<l; i++){
		pv(out[i]);
	}
	cout<<endl;
}

/////////////////////////////////////////////////////
// Import integer data (for graph stuff mostly)
vector< vector<int> > FileRead( string filename){
    vector< vector<int> > vvv;
    int i = 0;
    string line;

    fstream in(filename.c_str());
    if(!in.is_open()){
		cout<<"Bugger: unable to open file "+filename+" - exiting."<<endl;
		exit(0);
	}
	while (std::getline(in, line))
    {
        int value;
        stringstream ss(line);

        vvv.push_back(vector<int>());

        while (ss >> value)
        {
            vvv[i].push_back(value);
        }
        ++i;
    }
    return vvv;
}

/////////////////////////////////////////////////////
// Misplaced function for Dijkstra
// Fi
int findNext(int current,  const vector<int> &dist, const unordered_set<int> &sptSet){
	int pos(-1), s(dist.size()),min(1000000);

	// find nearest node to starting node which is connected to current node, such that it has not been visited
	// need to check for zero because of way adj matrix works (and also check we don't return
	// current node)
	for(int i = 0; i<s;i++){
		
		
		if( dist[i]!=0 && i!= current && dist[i]<min && (sptSet.find(i)==sptSet.end())){
			
			min = dist[i];
			pos = i;
		}
	}
	
	// return nearest [to starting node!] directly connected neighbour
	// where we are basing distance on current best distance estimates
	return pos;
}

/////////////////////////////////////////////////////
// Get integer at particular power position in integer
// i.e. intIndex( 101, 1) = 0
template <typename T> 
int intIndex( T a, int n ){
	return ((int) floor(a/pow(10,n))%10);
}

/////////////////////////////////////////////////////
// Find max element in vector O(N)
int findMax( vector<int> &vec ){
	int max = 0;
	for(int i =0; i<vec.size(); i++){
		if(vec[i]>max){
			max = vec[i];
		}
	}
	return max;
}

/////////////////////////////////////////////////////
// Find number of digits in an integer
template <typename T>
int findNDig( T a ){
	int n = 0;
	T val;
	while( val<=a){
		val = pow(10,n);
		n++;
	}
	return n-1;
}

/////////////////////////////////////////////////////
// Factorial fn for use in a bunch of stuff	
int factorial(int n ){
	
	if(n == 1){
		return 1;
	}
	return n*factorial(n-1);
}

///////////////////////////////////////////////////// BIT MAGIC SECTION
// Can't seem to pass bitsize as par/template :/
// Fixed to 8 bit for now
void print_bit_string(int val ){
	cout << bitset< 8 >( val ) << ' '<<endl;
}


int set_bit( int x, int pos ){
	// make mask with '1' at position 'pos'
	int mask = 1 << pos;
	
	// will return original binary string with 1 at pos regardless
	// of original value (or)
	return x | mask;
}

int clear_bit( int x, int pos ){
	
	int mask = 1 << pos;
	
	
	// NOT mask gives 1's everywhere except bit to be cleared, 
	// so taking AND here clears just that one
	return x & ~mask;
}


int flip_bit( int x, int pos ){
	
	int mask = 1 << pos;
	// Look through XOR def:
	// if we want to output opposite of input
	// we just XOR with 1
	return x  ^ mask;
}

int is_bit_set( int x, int pos ){
	// Shift bit pos to first pos
	// and and with 1
	// remember: 0 & 0 = 0 so leading zeroes don't matter
	int shifted = x >> pos;
	return shifted & 1;
}


int modify_bit( int x, int pos, int val ){
	// First we clear the nth bit
	// then OR with mask of that value at that position
	
	int cleared = clear_bit(x, pos );
	int mask = val << pos;
	return cleared | mask;
	
}

int twos_comp( int x ){

	return (~x)+1;
}
