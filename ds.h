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

template <typename T> class hashTable {
	private:
		vector<T> vals;	
	public:
		int length;
		int nElements;
	
		vector<T> keys;
		
		hashTable( ){
			length = 10;
			nElements = 0;
			vals.resize(length);
			
		};
		
	////////////////////////////////////////////////////////////
	// Insert new key-val pair
	void insert( T key, T val ){
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
	// FNV hashing function as described in
	// http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
	unsigned int hashFn( T s ){
		unsigned int hash(0);
		hash = 2166136261;
		int l = s.length();
		for(int i = 0; i<l;i++){
			hash = (hash*16777619)^s[i];
		}
		return hash;
	}

	////////////////////////////////////////////////////////////
	// Get index of given key using above hash function
	int getIndex( T key ){
		unsigned int hash = hashFn(key);
		
		int index = hash % (length);
		
		return index;
		
	}
	
	////////////////////////////////////////////////////////////
	// Operator overloading
	T operator[] (T key){
		int index = getIndex(key);
		if(vals[index].size() == 0 ){
			return "DNE";
		} else {
			return vals[index];
		}
	}
};



////////////////////////////////////////////////////////////
// Linked list class with nested Node class
template <typename T> class linkedList {
	private:
		// single linked list node class
		class Node {
			public:
				int data;
				Node* next = NULL;
				Node(){};
				Node( int d ){
					data = d;
				};
		};
		
	////////////////////
	public:
		Node* head = new Node();
		Node* tail = head;
		int size;
		linkedList<T>( T d ){
			head->data = d;
			head->next = NULL; // IMPORTANT NOTE, CHANGED THIS FOR REVERSE CODE MAY HAVE BROKEN ALL THE OTHER STUFF
		}
		
		
	Node* reverse( Node* current ){
		if( current->next == NULL ){
			head = current;
			return current;
		}
		Node* x = reverse( current->next );
		x->next = current;
		return current;
	}
	
	// add element at front of list and reset head
	Node* addFirst( int d ){
		Node* temp = new Node(d);
		temp->next = head;
		head = temp;
		size++;
		return head;
	}
	
	// add element at end of list and reset head
	Node* addLast( int d ){
		Node* temp = new Node(d);
		tail->next = temp;
		tail = temp;
		size++;
		return tail;
	}
	
	T getFirst(){
		return head->data;
	}
	
	T getLast(){
		return tail->data;
	}
	
	T get( int i ){
		if(size == 0 || i>=size){
			throw invalid_argument( "Position out of bounds of linked list" );
		}
		
		if(i == 0 ){
			return head->data;
		}
		
		if(i == size-1 ){
			return tail->data;
		}
		
		int n = 0;
		Node* current = head;
		while(n<i  && current->next != NULL){
			current = current->next;
			n++;
		}
		
		return current->data;		
	}
	
	// method to delete node with given value and return head of LL
	Node* deleteNode( Node* head, int d ){
		Node *n = head;
		
		if( n->data == d ){
			Node* temp = n->next;
			delete n;
			return temp;
		}
		
		while( n->next != NULL ){
			if(n->next->data == d ){
				n->next = n->next->next;
				delete n->next;
				return head;
			}
			n = n->next;
		}
		return head;
	}

};


//~ Node* delDuplicates( Node* head ){
	//~ hashTable<string> ledger;
	//~ Node* n = head;
	//~ string d;
	//~ while( n-> next != NULL ){
		//~ d = to_string(n->data);
		//~ if( ledger[d] != "DNE"){
			//~ ledger.insert(d,"1");
		//~ } else {
			//~ n
		//~ }
		//~ n = n->next;
	//~ }
	
//~ }

/////////////////////////////////////////////
// adjacency list graph nodes
// good for memory/insertion/deletion, bad for search
// though can keep O(N) list somewhere
template <typename T> class graphNode {
	private:
	
	public:
		T dat;
		unordered_set<graphNode<T>* > connections;
		
		graphNode<T>(){};
		graphNode<T>( T inp ){
			dat = inp;
		}
		
		void addConnection( graphNode<T> &conn ){
			if(!isConnection(&conn)){
				connections.insert(&conn);
				conn.connections.insert(this);
			} else {
				cout<<"Already connected"<<endl;
			}
		}
	
		bool isConnection( graphNode<T>* node ){
			if(connections.find( node ) == connections.end()){
				return false;
			} else {
				return true;
			}
		}
};
