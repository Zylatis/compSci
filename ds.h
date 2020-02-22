/////////////////////////////////////////////////////
// DATA STRUCTURE IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////

template <typename T> struct CompareKey { // for min heap
	bool operator() (const T &v1, const T &v2) const {return v1[0] < v2[0];}
};


// Custom swap function for heap and other bits
template <typename T>
void swap( vector<T> &vec, int i, int j ){
	T t1(vec[i]), t2(vec[j]);
	vec[i] = t2;
	vec[j] = t1;
}

	
////////////////////////////////////////////////////////////
// Max heap class with heapify and insert methods only
////////////////////////////////////////////////////////////
template<typename T>
class Heap {
	private:
		
	public:
		int size;
		int depth;
		vector<T> arr;
		unordered_map<int,int> locator;
		function<bool(T,T)> comparator;	 // NEED TO UNDERSTAND THIS SYNTAX BETTER
		//	 and also why it was a pain with templates
		////////////////////////////////////////////////////////////
		// default constructors
		Heap(){};
		
		Heap( vector<T> &vec,  function<bool(T,T)> cmp ){
            comparator = cmp;
			size = vec.size();
			arr = vec;			
			
			buildHeap();
		}
		
		////////////////////////////////////////////////////////////	
		// Set of methods to get leaves of tree used in heap. Currently public
		// for debugging purposes
		
		int parent( int i ){ return (i-1)/2; }
		
		int left( int i ){ return 2*i+1; }
		
		int right( int i ){ return 2*i+2; }
		
	
		// heapify at a node, assuming sub-trees are already heaps
		// remember hard coding min heap for now
		// Floyd alg, should run in worst case O(n), as opposed
		// to continued bubble up, which would be nlogn
		void Heapify( int i ){
	
			int l(left(i)), r(right(i));
			int heapify(i);
			
			//~ if((l<size) && ( arr[l] > arr[i]) ){
			if((l<size) && comparator( arr[l] , arr[i]) ){
				heapify = l;
			} else {
				heapify = i;
			}
			if((r<size) && comparator(arr[r] , arr[heapify])){
				heapify = r;
			} 
			
			if(heapify != i){
				swap(arr,i,heapify);
				locator[ arr[i][1] ] = i;
				locator[ arr[heapify][1] ] = heapify;
				Heapify(heapify);
			}
			
		}
		
		void decreaseKey(int target, int newVal ){
			int index = locator[target];
			arr[index][0] = newVal;
			bubbleUp( index );
			
		}
		
		//~ ////////////////////////////////////////////////////////////
		//~ // Currently unused function to balance child nodes
		//~ // Maybe useful for heapsort later
		//~ void rebalance_leaves( int par ){
			//~ int l(left(par)), r(right(par));
				//~ if(arr[l]>arr[r] &&  r < size){
					//~ cout<<"Rebalance positions "<<l<<","<<r<<" with vals "<<arr[l]<<", "<<arr[r]<<endl;
					//~ swap(arr, l,r);
			//~ }
		//~ }
		
		////////////////////////////////////////////////////////////
		// Back propagate and heapify
		void buildHeap(){
			for(int i = size-1; i>=0 ;i--){
				locator[arr[i][1]] = i;
				Heapify(i);
			}
		}
		
		////////////////////////////////////////////////////////////
		// Assumes all elements after 'k' are in a valid heap, and bubbles
        // this element up so that the whole thing is a heap
		void bubbleUp( int  k ){
			//~ int k = size - 1;
			int par = parent(k);
			while( comparator( arr[k] , arr[par] ) ){
				
				swap(arr, k, par);
				
				k = par;
				par = parent(k);
			}
	
		}
		////////////////////////////////////////////////////////////
		// Add element to end of heap and then put it in correct spot
		void insert( T val ){
			cout<<"insert "<<val<<endl;
			arr.push_back( val );
			size = arr.size();
			bubbleUp( size - 1);
			
		}
		////////////////////////////////////////////////////////////
		// Lazy print heap to screen
		void print(){
			//~ for(int i = 0; i<size; i++){
				//~ cout<<arr[i]<<"\t";
			//~ }
			//~ cout<<endl;
		}
};

////////////////////////////////////////////////////////////
// Basic graph class for testing Djikstra etc
// Uses adjacency matrix representation
// 14OCT now storing as adjacency list using pairs<>
////////////////////////////////////////////////////////////

class Graph {
	private:
		vector< vector< pair< int, int > > > adj; 
		int nE,nV;
		
	public:
		//constructors
		Graph(){};
		Graph(int n){
			nV = n;
			adj.resize(nV);
		}
		
		void addEdge( int u, int v, int w){
			
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		
		////////////////////////////////////////////////////////////
		// Lazy print for adjacency matrix	
		//~ void pg(){
			//~ pm(adj);
		//~ }
		
		////////////////////////////////////////////////////////////
		// Implementation of Dijkstra alg. Finds shortest distance from
		// starting node to all other nodes. 'Starting' is defined as first row
		// in adjacency matrix. Runs in O(E +V ) as we have to check each node and edge once,
		// but we only check them once (edges are checked only once if nodes are checked only oncec)
		vector<int> dijkstra(){
			typedef pair<int,int> iPair;
			pair<int,int> node = {-1,-1};
			priority_queue<iPair, vector<iPair> ,greater<iPair>  > pq;
			
			
			vector<int> dist(nV,0);
			fill(dist.begin()+1,dist.end(),INT_MAX); // initialise distances to inf
			
			
			// Make initial distance to neighbours of starting node to the distances 
			// from adj matrix (currently assuming starting node is first row, not very good!)
			int u(0),v,w;
			for(int i = 0; i< adj[u].size();i++){
				v = adj[u][i].first;
				w = adj[u][i].second;
				dist[v] = w;
				pq.push( {dist[v], v });
			}
			
			//~ for( int i = 0; i < nV; i++ ){
				//~ if(adj[current][i]!=0){
					//~ dist[i] = adj[current][i];
					//~ pq.push( { dist[i],i } );
				//~ }
			//~ }
			// Parent is used to keep track of actual path information
			vector<int> parent(nV,-1);
			
			//~ // While we still have suboptimal node distances to process
			//~ // (less clear condition than what we had before with the hash table, but is prob
			//~ // equivalent?) Assumes all the easy ones have been processed, so won't end up with
			//~ // weird disjoint stuff I think?
			//~ // Basically question is: is looking for lowest dist out of CURRENTLY adjacent nodes the
			//~ // same as just looking at the GLOBALLY closest (to start) nodes even if not connected to current
			//~ // node? 

			while(!pq.empty()){
				// find next node to visit based on distances in PQ
				int next = pq.top().second;
				pq.pop();
				
			
				u = next; // 12oct moved this here from after for loop, not rerun though
				
				//~ // update distances by looping over all nodes (we check if connected in 'if' below)
				//~ // This is where having an adjacency map/set/thing would be advantageous
				vector<pair<int,int> > node = adj[u];
				for(int i = 0; i< node.size();i++){
					int v = node[i].first;
					int nD = dist[u] + node[i].second;
					if( nD<dist[v]) {
						dist[v] = nD;
						parent[v] = next;
						pq.push({nD,v});
					}
			
				}
				//~ for(int i = 0;i<nV;i++){
					//if a given node is quicker to get to via the current node, vs whatever
					// the path was before, then u	pdate this node to be the parent and update the best
					// distance
					//~ int nD = dist[next] + adj[next][i];
					//~ if( adj[next][i] !=0 && nD<dist[i]) {
						//~ dist[i] = nD;
						//~ parent[i] = next;
						//~ pq.push({nD,i});
					//~ }
				
				//~ }
				
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


// Attempt at implementing a trie for word autocomplete
class Trie_node {
	public:
		bool terminator = false; // is this the end of a valid word?
		char value;
		string terminal_word = ""; // letter contained in this node
		//~ Trie_node *parent; // assuming for now each node has one parent? 
		unordered_map<char, Trie_node*> leaves; // each node has a set of child letters, mapping to nodes
	
		Trie_node( vector<string> words ){
			for(int i = 0; i<words.size(); i++){
				this->insert_word( this,  words[i]);
				}
			};
		Trie_node(){};
		Trie_node( char letter ){
				value = letter;
		};
		
		void insert_word( Trie_node* root, string word ){
			string builder = "";
			Trie_node* current = root;
			char lett;
			int l = word.length();
			for(int i = 0; i < l; i++){
				lett = word[i];
				if( current->leaves.find( lett ) != current->leaves.end()){
					current = current->leaves[ lett ];
				} else {
		
					Trie_node* new_node = new Trie_node( lett );

					current->leaves[lett] = new_node;
					current = new_node;
					
				}
			}
			current->terminator = true;
			current->terminal_word = word;
			
		}
		
		void print_trie( Trie_node *node ){
			
			if(node->terminator){
				cout<<node->terminal_word<<endl;
				
			} else {
			
				auto current_leaves = node->leaves;
				Trie_node* next = new Trie_node();
				for(auto kv : current_leaves ){
					next = kv.second;
					print_trie(next);
				}	
			}
					
		}
		
		void words_starting_with( Trie_node *node, string str, int pos ){
			
			if( pos == str.length() ){
				print_trie( node );
				
			} else {
				char lett = str[pos];
				auto curr_leaves = node->leaves;
				if( curr_leaves.find(lett) != curr_leaves.end()){
					words_starting_with( curr_leaves[lett], str, pos + 1);
				}
			}
		}
};

// building expression tree stuff
class Exp_node {
	public:
		Exp_node* left = NULL;
		Exp_node* right = NULL;
		string val;
		
		Exp_node( string v ){
			val = v;
		}
		
};


int eval( Exp_node* root ){
	
	int lval = eval(root->left);
	int rval = eval(root->right);
	
	string op = root->val;
	
	if( op == "+"){
		return lval + rval;
	} else if(op == "-"){
		return lval-rval;
	} else if(op=="/"){
		return lval/rval;
	} else if(op=="*"){
		return lval*rval;
	}
	
	cout<<"no valid operator found"<<endl;
	
	return 0;
}
