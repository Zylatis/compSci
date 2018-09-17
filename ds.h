/////////////////////////////////////////////////////
// DATA STRUCTURE IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////


// Custom swap function for heap and other bits
void swap( vector<int> &vec, int i, int j ){
	int t1(vec[i]), t2(vec[j]);
	vec[i] = t2;
	vec[j] = t1;
}

	
////////////////////////////////////////////////////////////
// Max heap class with heapify and insert methods only
////////////////////////////////////////////////////////////
class maxHeap {
	private:
		
	public:
		int size;
		int depth;
		vector<int> arr;
		
		////////////////////////////////////////////////////////////
		// default constructors
		maxHeap(){};
		maxHeap( vector<int> &vec ){
			size = vec.size();
			arr = vec;
			BuildHeap();
		}
		
		////////////////////////////////////////////////////////////	
		// Set of methods to get leaves of tree used in heap. Currently public
		// for debugging purposes
		
		int parent( int i ){ return (i-1)/2; }
		
		int left( int i ){ return 2*i+1; }
		
		int right( int i ){ return 2*i+2; }
		
	
		// heapify at a node, assuming sub-trees are already heaps
		// remember hard coding min heap for now
		void Heapify( int i ){
	
			int l(left(i)), r(right(i));
			int heapify(i);
			
			if((l<size) && (arr[l] > arr[i])){
				heapify = l;
			} else {
				heapify = i;
			}
			if((r<size) && (arr[r] > arr[heapify])){
				heapify = r;
			} 
			
			if(heapify != i){
				swap(arr,i,heapify);
				Heapify(heapify);
			}
			
		}
		
		
		////////////////////////////////////////////////////////////
		// Currently unused function to balance child nodes
		// Maybe useful for heapsort later
		void rebalance_leaves( int par ){
			int l(left(par)), r(right(par));
				if(arr[l]>arr[r] &&  r < size){
					cout<<"Rebalance positions "<<l<<","<<r<<" with vals "<<arr[l]<<", "<<arr[r]<<endl;
					swap(arr, l,r);
			}
		}
		
		////////////////////////////////////////////////////////////
		// Back propagate and heapify
		void BuildHeap(){
			for(int i = size-1; i>=0 ;i--){
				Heapify(i);
			}
		}
		
		////////////////////////////////////////////////////////////
		// Appropriately place final element in heap. Assumes heap
		// minus this element is correct
		void percolate( ){
			int k = size - 1;
			int par = parent(k);
			while( arr[k] > arr[par] ){
				
				swap(arr, k, par);
				
				k = par;
				par = parent(k);
			}
	
		}
		////////////////////////////////////////////////////////////
		// Add element to end of heap and then put it in correct spot
		void insert( int val ){
			cout<<"insert "<<val<<endl;
			arr.push_back( val );
			size = arr.size();
			percolate();
			
		}
		////////////////////////////////////////////////////////////
		// Lazy print heap to screen
		void print(){
			for(int i = 0; i<size; i++){
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
		}
		
};

////////////////////////////////////////////////////////////
// Basic graph class for testing Djikstra etc
// Uses adjacency matrix representation
////////////////////////////////////////////////////////////
class graph {
	private:
		vector<vector< int > > adj; 
		int nE,nV;
		
	public:
		//constructors
		graph(){};
		graph(vector<vector<int> > inp ){
			adj = inp;
			nV = inp.size();
			if(inp.size() != inp[0].size()){
				cout<<"Error: graph input is non-square matrix."<<endl;
				exit(0);
			}
		}
		
		////////////////////////////////////////////////////////////
		// Insert new node in matrix. Currently assuming no cycles	
		void insertVertex( vector<int> connections ){
			for(int i =0; i<nV;i++){
				adj[i].push_back(connections[i]);
			}
			
			nV++;
			adj.resize(nV);
			vector<int> row = connections;
			row.push_back(0); //assume no cycles
			
			adj[nV-1] = row;
			
		}
		
		////////////////////////////////////////////////////////////
		// Lazy print for adjacency matrix	
		void pg(){
			pm(adj);
		}
		
		////////////////////////////////////////////////////////////
		// Currently unused (and rather inefficient) method to count number of edges
		int countEdges(){
			vector<vector< int > > edges;
			edges.resize(nV);
			int edgeN = 0;
			for(int i =0; i<nV; i++){
				for(int j = i; j<nV; j++){
					int val = adj[i][j];
					if( val !=0 && i!=j && find(edges[i].begin(),edges[i].end(),j)==edges[i].end() && find(edges[j].begin(),edges[j].end(),i)==edges[j].end()){
						edges[i].push_back(j);
						edges[j].push_back(i);
						edgeN++;
					}
				}
			}
			cout<<"----"<<endl;
			for(int i =0; i<nV; i++){
				cout<<i<<": ";
				for(int j = 0; j<edges[i].size();j++){
					cout<<edges[i][j]<<"  ";
				}
				cout<<endl;
			}
			return edgeN;
		}
		
		////////////////////////////////////////////////////////////
		// Implementation of Dijkstra alg
		// Finds shortest distance from
		// starting node to all other nodes
		// 'Starting' is defined as first row
		// in adjacency matrix
		vector<int> dijkstra(){
			unordered_set<int> sptSet;
			
			vector<int> dist(nV,0);
			fill(dist.begin()+1,dist.end(),10000);
			int current = 0;
			for(int i =0;i<nV;i++){
				if(adj[current][i]!=0){
					dist[i] = adj[current][i];
				}
			}
			// Parent is used to keep track of actual path information
			vector<int> parent(nV,-1);
			sptSet.insert(0);
			while(sptSet.size() < nV){
				
				int next = findNext( current, dist, sptSet );
			
				sptSet.insert(next);
				
				for(int i = 0;i<nV;i++){
					int nD = dist[next] + adj[next][i];
					if( sptSet.find(i)==sptSet.end()  && adj[next][i] != 0 && (nD < dist[i]) ){
						dist[i] = nD;
						parent[i] = next;
					} 
				
				}
				current = next;

			}
			
			return dist;	
		}
};

/////////////////////////////////////////////
// Hash table implementation using basic hashing function
// Currently overloads [] operator to use key->val access
// in order to keep 'vals' private (contains empty bits)
class hashTableString {
	private:
		vector<string> vals;	
	public:
		int length;
		int nElements;
	
		vector<string> keys;
		
		hashTableString( ){
			length = 10;
			nElements = 0;
			vals.resize(length);
			
		};
		
	////////////////////////////////////////////////////////////
	// Insert new key-val pair
	void insert( string key, string val ){
		int index = getIndex(key);
		keys.push_back(key);
			
		vals[index] = val;
		
		nElements++;
		 
		if( (double) nElements/ (double) length > 0.5){
			vals.resize( length*2);
			length = length*2;
		}
	}
	
	////////////////////////////////////////////////////////////
	// Custom hashing function
	int hashFn( string s ){
		int hash(0);
		int l = s.length();
		for(int i = 0; i<l;i++){
			hash+= l*((int) s[i]%11)/length;
		}
		return hash;
	}

	////////////////////////////////////////////////////////////
	// Get index of given key using above hash function
	int getIndex( string key ){
		int hash = hashFn(key);
		int index = hash % (length);
		
		return index;
		
	}
	
	////////////////////////////////////////////////////////////
	// Operator overloading
	string operator[] (string key){
		int index = getIndex(key);
		return vals[index];
	}
};
