/////////////////////////////////////////////////////
// EXAMPLE USAGE OF IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////


#include "imports.h"
#include "fns.h"
#include "algs.h"
#include "ds.h"
/////////////////////////////////////////////////////////////
int main ( int argc, char *argv[] ){
	
	// array of values to test things with
	vector<int> vals = {54,26,93,17,77,31,44,55,20};
	
	// TEST SORTING ALGORITHMS
	//~ cout<<"======Sorting======"<<endl;
	//~ vector<int> qs(vals), ms(vals), rs(vals);
	//~ cout<<"Quicksort:"<<endl;
	//~ quicksort(qs, 0, qs.size()-1);
	//~ pv(qs);
	//~ cout<<"Mergesort:"<<endl;
	//~ mergesort(ms, 0, ms.size()-1);
	//~ pv(ms);
	//~ cout<<"Radixsort:"<<endl;
	//~ radixSort(rs);
	//~ pv(rs);	
	
	// TEST MAXHEAP DATASTRUCTURE
	//~ cout<<"======MaxHeap======"<<endl;
	//~ maxHeap test(vals);
	//~ test.print();
	
	//~ cout<<"Compare with STL maxheap"<<endl;
	//~ vector<int> stlH(vals);
	//~ make_heap(stlH.begin(),stlH.end());
	//~ pv(stlH);
	
	//~ cout<<"Test insert:"<<endl;
	//~ test.insert(34);
	//~ test.print();
	
	//~ stlH.push_back(34);
	//~ push_heap(stlH.begin(),stlH.end());
		
	//~ pv(stlH);
	
	// TEST GRAPH ALGORITHMS AND DS
	//~ cout<<"Test graph DS"<<endl;
	//~ int n = 8;
	//~ vector<vector<int > > GM(n);
	//~ for(int i = 0; i<n;i++){
		//~ GM[i].resize(n);
	//~ }
	// Reading adjacency matrix from file
	// will replace with inline def to make
	// self contained at somepoint
	// (i.e. from GeeksForGeeks)
	//~ GM = FileRead("G.dat");
	//~ graph G(GM);
	//~ auto minTree = G.dijkstra();
	//~ cout<<G.countEdges()<<endl;
	
	
	// RECURSIVE PERMUTATION ALG
	//~ perm2("ABC",0);
	
	
	// HASH TABLE TEST
	//~ hashTable<string> stringTable;
	//~ stringTable.insert("a", "1");
	//~ stringTable.insert("badsf3wfsdfvfvff23efvfv", "f");
	//~ stringTable.insert("c", "d");
	//~ stringTable.insert("asdfa3rd", "3");
	//~ stringTable.insert("e", "s");
	//~ cout<<stringTable["x"]<<endl;
	
	//~ Node* test = new Node(1);;
	//~ test->appendToTail(2);
	//~ cout<<test<<endl;
	//~ cout<<test->next<<endl;
	//~ cout<<deleteNode( test, 1)<<endl;
	
	//~ vector<int> arr = {-2,-3,4,-1,-2,1,5,-30,1,5,10};
	//~ vector<int> LS = K1(arr);
	//~ vector<int> LS2 = K2(arr);
	//~ pv(LS);
	//~ pv(LS2);

	//~ cout<<isBalanced("()())()")<<endl;
	pv(remIP("()v)"));
	
	return 0;
	
	
}

/////////////////////////////////////////////////////////////
