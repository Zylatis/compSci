/////////////////////////////////////////////////////
// EXAMPLE USAGE OF IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////


#include "imports.h"
#include "fns.h"

#include "algs.h"

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
	// wl replace with inline def to make
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
	
	// LINKED LISTS AND STUFF
	//~ Node* test = new Node(1);;
	//~ test->appendToTail(2);
	//~ cout<<test<<endl;
	//~ cout<<test->next<<endl;
	//~ cout<<deleteNode( test, 1)<<endl;

	
	// make linked list and hack in cycle
	//~ linkedList<int> test(1);
	//~ test.addLast(2);
	//~ test.addLast(3);
	//~ test.addLast(4);
	//~ cout<<test.head->next<<endl;
	//~ test.reverse(test.head);
	
	//~ test.head->next->next->next->next = test.head->next->next;
	//~ cout<<test.get(0)<<endl;
	//~ cout<<test.get(1)<<endl;
	//~ cout<<test.get(2)<<endl;
	//~ cout<<test.get(3)<<endl;
	//~ cout<<test.get(4)<<endl;
	
	// now try to detect cycle with runners
	// have 'back' and 'forward' pointers
	// when forward has next as back, are at cycle point
	
	//~ auto p1 = test.head;
	//~ auto p2 = test.head->next;
	//~ while( p2->next != p1 ){
		//~ p2 = p2->next;
		//~ p1 = p1->next;
	//~ }
	//~ cout<<p1->next->data<<"\t"<<p2->next->data<<endl;
	
	
	
	// MAXIMUM CONTIGUOUS SUBSEQUENCE
	//~ vector<int> arr = {-2,-3,4,-1,-2,1,5,-30,1,5,10};
	//~ vector<int> LS = K1(arr);
	//~ vector<int> LS2 = K2(arr);
	//~ pv(LS);
	//~ pv(LS2);

	// BREADTH FIRST SEARCH FOR BALANCING OF STRING
	// PARENTHESES
	//~ cout<<isBalanced("()())()")<<endl;
	//~ pv(remIP("()v)"));
	
	
	// test graph ds using adjacency lists
	//~ graphNode<int> a(1),b(2),c(3),d(4),e(5);
	//~ a.addConnection(e);
	
	//~ a.addConnection(b);
	//~ b.addConnection(c);
	//~ c.addConnection(d);

	// do dfs on graph to see if number is reachable from initial node.
	//~ unordered_set<graphNode<int>*> visited;
	//~ dfs( &a,7,visited);
	
	
	// TEST ARBITRARY PRECISION INTEGER ADDITION
	//~ vector<int> a= { 4,5,8,2,0,8,9,6,3,8,3,0,4,7,3,0,0,6,4,9,4,8,7,4,4,1,9,0,6,1,5,5,2,5,2,0,2,7,4,2,9,0};
	//~ vector<int> b = {9,0,0,8,5,5,6,2,4,6,8,7,6,2,4,6,3,6,4,9,4,1,8,6,3,7,8,5,5,9,8,5,7,4,0,7,5,0,8,4,2,6};
	//~ a = {3,5};
	//~ b = {5};
	//~ cout<<2*271<<endl;
	//~ arbSum(a,b);	
	
	
	// COIN CHANGE DP PROBLEM
	//~ vector<int> x = {1,2};
	//~ int s = 4;
	//~ int xx = numWays(x,0,s);
	//~ cout<<"---"<<endl;
	//~ cout<<xx<<endl;
	//~ numWaysDP(x,s);
	// KNAPSACK PROBLEM
	//~ vector<int> w = {1,4,2};
	//~ vector<int> v = {1,2,5};
	//~ vector<int> config(w.size(),0);
	//~ cout<<"i \t weight \t value"<<endl;
	//~ knapsack(v,w,0,0,0, config);
	//~ knapsackDP(v, w, 5);
	
	// EDIT DISTANCE (I actually got this one first try!)
	//~ string s1 = "aaaaaaaback";
	//~ string s2 = "back";
	//~ int d = editDist(s1,s2);
	//~ cout<<d<<endl;
	
	// ROBOT MAZE
	//~ int r(3),c(5);
	//~ vector<vector<int> > maze( 3,vector<int>(c,0));
	//~ maze[1][1] = INT_MAX;
	//~ maze[2][2] = INT_MAX;
	//~ robotMaze(maze);
	
	
	// ALL SUBSETS (DP)
	//~ vector<int> set = {1,3,4,6};
	//~ allSubs(set);


	// string perm again
	//~ string s = "ABC";
	//~ sp(s,0);
	
	
	// Tower of Hanoi
	//~ stack<int> s, a, d; // source, auxillary, destination stacks
	//~ s.push(3);
	//~ s.push(2);
	//~ s.push(1);
	//~ move(3,s,a,d);
	
	// make string with N valid parentheses pairs
	//~ validPar(3);
	
	// Paint fill
	//~ unordered_set<string> tracker;
	//~ vector<vector< int > > canvas(4,vector<int>(4, 1));
	//~ canvas[0][0] = 0;
	//~ canvas[1][0] = 0;
	//~ canvas[2][0] = 0;
	//~ canvas[3][0] = 0;
	//~ canvas[3][1] = 0;
	//~ canvas[3][2] = 0;
	//~ canvas[3][3] = 0;

	//~ pm(canvas);
	//~ cout<<"X"<<endl;
	//~ fill( canvas, 0,0, tracker,2);

	//~ pm(canvas);
	
	// FIND SUBARRAY WITH SUM = S
	//~ vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23}; 
	//~ printSubArrSub( arr, 23);
	
	// FIND MAX INDEX
	//~ vector<int> arr = {3,5,4,2};
	//~ maxIndex(arr);
	
	// STRING INTERLEAVE
	
	interleave("XXY", "XXZ", "XXZXXXY"); 
    interleave("XY" ,"WZ" ,"WZXY"); 
    interleave ("XY", "X", "XXY"); 
    interleave ("YX", "X", "XXY"); 
    interleave ("XXY", "XXZ", "XXXXZY"); 
	/////////////////////////
	return 0;
	
}

/////////////////////////////////////////////////////////////
