
void swap( vector<int> &vec, int i, int j ){
	int t1(vec[i]), t2(vec[j]);
	vec[i] = t2;
	vec[j] = t1;
}

int parent( int i ){ return (i-1)/2; }
		
int left( int i ){ return 2*i+1; }
		
int right( int i ){ return 2*i+2; }
		
		
class maxHeap {
	private:
		
	public:
		int size;
		int depth;
		vector<int> arr;
		// default constructors
		maxHeap(){};
		maxHeap( vector<int> &vec ){
			size = vec.size();
			arr = vec;
		}
		
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
		
		void rebalance_leaves( int par ){
			
			int l(left(par)), r(right(par));
				if(arr[l]>arr[r] &&  r < size){
					cout<<"Rebalance positions "<<l<<","<<r<<" with vals "<<arr[l]<<", "<<arr[r]<<endl;
					
					swap(arr, l,r);
					
			}
		}
		
		void BuildHeap(){
			for(int i = size-1; i>=0 ;i--){
				Heapify(i);
			}
		}
		void percolate( ){
			int k = size - 1;
			int par = parent(k);
			while( arr[k] > arr[par] ){
				
				swap(arr, k, par);
				// rebalance leaves
				
				k = par;
				par = parent(k);
				//~ rebalance_leaves( par );
				//~ rebalance_leaves( k );
			}
			//~ rebalance_leaves( par );

	
		}
		
		void insert( int val ){
			cout<<"insert "<<val<<endl;
			arr.push_back( val );
			size = arr.size();
			percolate();
			
		}
		
		void print(){
			for(int i = 0; i<size; i++){
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
		}
		
};
