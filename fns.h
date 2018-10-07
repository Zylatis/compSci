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
int findNext(int current,  const vector<int> &vec, const unordered_set<int> &sptSet){
	int pos(-1), s(vec.size()),min(1000000);

	for(int i = 0; i<s;i++){
		
		if( vec[i]!=0 && i!= current && vec[i]<min && (sptSet.find(i)==sptSet.end())){
			
			min = vec[i];
			pos = i;
		}
	}
	
	
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



