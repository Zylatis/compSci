/////////////////////////////////////////////////////
// EXAMPLE USAGE OF IMPLEMENTATIONS
// G. Gossel 2018
/////////////////////////////////////////////////////


#include "imports.h"
#include "fns.h"
#include "threading.h"
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
	
	// TEST DATASTRUCTURE
	//~ cout<<"======MaxHeap======"<<endl;
	//~ Heap<int> test(vals, greater<int>());
	//~ test.print();
	
	//~ vector<int> stlH(vals);
	//~ make_heap(stlH.begin(),stlH.end());
	//~ pv(stlH);
	
	//~ vector<vector< int > > temp = {{1,1},{3,2},{5,3}};
	// compare key uses [0] as value and [1] as key
	//~ Heap< vector<int>  > test( temp, CompareKey<vector<int> >()  );
	//~ pm(test.arr);
	//~ test.decreaseKey(2,1);
	//~ pm(test.arr);
	
	//~ test.print();
	
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
	//~ Graph g(9);	
	//~ g.addEdge(0, 1, 4); 
	//~ g.addEdge(0, 7, 8); 
    //~ g.addEdge(1, 2, 8); 
    //~ g.addEdge(1, 7, 11); 
    //~ g.addEdge(2, 3, 7); 
    //~ g.addEdge(2, 8, 2); 
    //~ g.addEdge(2, 5, 4); 
    //~ g.addEdge(3, 4, 9); 
    //~ g.addEdge(3, 5, 14); 
    //~ g.addEdge(4, 5, 10); 
    //~ g.addEdge(5, 6, 2); 
    //~ g.addEdge(6, 7, 1); 
    //~ g.addEdge(6, 8, 6); 
    //~ g.addEdge(7, 8, 7); 
	//~ auto minTree = g.dijkstra();
	//~ pv(minTree);
	
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
	//~ cout<<"----"<<endl;
	//~ validPar2( "", 3, 3);
	
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
	//~ vector<int> arr = {15, 2, -4, 8, -9, 5, 10, 23}; 
	//~ printSubArrSub( arr, 23);
	
	// same as above but with negs
	//~ printSubArrSubNeg(arr,-5);	
	
	// FIND MAX INDEX
	//~ vector<int> arr = {3,5,4,2};
	//~ maxIndex(arr);
	
	// STRING INTERLEAVE
	// Examples taken from GFG
	//~ interleave("XXY", "XXZ", "XXZXXXY"); 
    //~ interleave("XY" ,"WZ" ,"WZXY"); 
    //~ interleave ("XY", "X", "XXY"); 
    //~ interleave ("YX", "X", "XXY"); 
    //~ interleave ("XXY", "XXZ", "XXXXZY"); 
    
    // LONGEST VALID SECTION OF PARS (GFG)
	//~ validPar("(()()(()");
	//~ string s="((((((((((((((((()()()()()()((((()()()()()()()))()()))))(((()()(()(((((((((((((((((((()()()()()()((((((((((((((((()()()()()()()))()()))))(((()()(()()))()()))))(((()()(()(((((((((((((()()()()()()()))()()))))(((()()(()";
	//~ validPar(s);
	//~ SOvalidPar(s);
	
	// I/D SETS
	// recursive works, working on smarter one
	// Unclear if this can be done with bottom up DP
	// Given the uniqueness of elements, possibly no advantage
	// nor to memoization
	// ( check if recomputation is occuring)
	//~ largestIDSeq2("DDI");


	// LONGEST COMMON SUBSEQUENCE
	//~ LCS("AEDFHR","ABCDGH");
	
	// FLOOD FILL VARIANT FROM GFG
	//~ vector<vector< int > > grid( 3, vector<int>(5,1));
	//~ grid[0][3] = 2;
	//~ grid[0][4] = 2;
	//~ grid[1][0] = 2;
	//~ grid[1][2] = 3;
	//~ grid[1][3] = 2;
	//~ grid[1][4] = 3;
	//~ grid[2][0] = 2;
	//~ grid[2][1] = 2;
	//~ grid[2][2] = 3;
	//~ grid[2][3] = 3;
	//~ grid[2][4] = 3;
	
	//~ unordered_set<string> t1;
	//~ cout<<gridArea(grid, 0, 0, 1, t1)<<endl;
	//~ t1 = {};
	//~ cout<<gridArea(grid, 0, 4, 2, t1)<<endl;
	//~ t1 = {};
	//~ cout<<gridArea(grid, 1, 2, 3, t1)<<endl;
	
	
	// PLAYING WITH BITSHIFTING
	// Generate all subsets of a set of length N
	//~ int nE = 3;
	//~ int n = pow(2,3);
	//~ for( int i = 0; i<n; i++){
		//~ vector<int> temp = {};
		//~ for(int j = 0; j<nE; j++){
			//~ if( (i & (1<<j))!=0){ // does number have 1 in jth bit
				//~ temp.push_back(j);
			//~ }
		//~ }
		//~ pv(temp);
	//~ }
	
	
	// KTH LARGEST ELEMENT IN LARGE SET K<<N
	//~ vector<int> arr = {40, 151, 333,10,343,1,746, 945, 976, 1106, 1233, 1250, 1335, 1338, 1434, 1435, 1505, 1516, 1536, 1649, 1679, 2095, 2191, 2346, 2378, 2782, 2860, 2883, 3110, 3126, 3190, 3195, 3244, 3512, 3528, 3763, 3918, 3927, 3970, 4064, 4239, 4347, 4374, 4387, 4437, 4499, 4550, 4682, 4773, 4804, 4841, 4863, 4958, 4998, 5171, 5349, 5382, 5497, 5629, 5822, 5875, 5901, 6042, 6193, 6216, 6295, 6302, 6328, 6402, 6454, 6516, 6552, 6579, 6612, 6644, 6774, 6883, 6955, 7024, 7044, 7273, 7325, 7451, 7454, 7951, 8355, 8368, 8374, 8537, 8582, 8621, 8720, 8722, 8824, 8887, 8923, 8985, 9018, 9055, 9116, 9389, 9554, 9673};
	//~ kth_largest(arr,4);
	//~ cout<<arr.size()<<endl;
	//~ quicksort(arr, 0, arr.size()-1);
	//~ pv(arr);
	
	// BINARY SEARCH (recursive)
	//~ pv(arr);
	//~ int v = binary_search(arr, 0, arr.size()-1, 1250,0);
	//~ cout<<binary_search_iter(arr,1250)<<endl;
    
    // WORD COUNT IN TEXT BLOB
    // Idea is to tokenize then shove in hash table, should be O(N + M) where N is char number
    // and M is word number so really O(N). Not sure if there is a faster way to extract the words
    // (bit mask or something fancy?)
	//~ string temp = "Ive done a bunch of work in galactic dynamics, atomic physics, quantum chemistry, and a smattering of other things, and *all* had at least 50% coding component. As mentioned in some answers, this is largely (at least in the aforementioned cases) because most of the interesting equations out";// there cannot be solved in closed form, or similarly phrased does not have an 'analytic solution',  which can loosely be thought of as 'pen and paper' but in reality lots of closed form solutions can be gotten but only with symbolic algebra packages like Mathematica and so forth, but I digress...Its actually worse than you think. As noted in other comments, in school and maybe undergrad you learn that all equations, usually ordinary differential equations (ODEs) or partial differential equations (PDEs) have analytic solutions. You then learn, as explained in this thread, that most cases only have numerical solutions, done in a computer, which are by their nature approximate. Nevertheless we label these as 'exact' solutions because the only approximations used are in the numeric method to solve them, rather than simplifying the equations in some way first. *But* loads of interesting cases cannot even be solved exactly, in the way described before. An example of this is the many electron atom, i.e. "interesting stuff". Here you simply cannot solve the equations of motion exactly in a computer. Johnson has a fun back of the envelope calculation in his book which points out that in order to even store the wavefunction of iron, which has 26 electrons, you need more bits of information than there are particles in the solar system, or something to that effect. This leads to the Hartree Fock approach, which amounts to a mean field approach. Basically you assume each electron moves in the mean electric potential created by the other electrons, and solve this self consistently, which means loop";
	//~ tokenize(temp);

	//16.6
	//~ vector<int> v1 ={ 1,3,15,11};
	//~ vector<int> v2 = {2};
	//~ smallest_diff(v1,v2);
	
	// 16.7
	//~ find_max(-1,12);
	
	// 16.8 parse number english
	//~ parse_number( 1223);
	
	// 16.18 pattern matching
	//~ check_pattern( "catcatgocatgo", "ba");
	
	// 16.20 Trie implementation and use
	//~ vector<string> words = { "animal", "aplomb", "apple", "bear", "bare"};	
	//~ Trie_node* words_root = new Trie_node( words );
	
	//~ words_root->words_starting_with( words_root, "b", 0 );	
	//~ words_root->words_starting_with( words_root, "a", 0 );	
	//~ words_root->print_trie(words_root);
	///////////////////////// 
	
	//~ find_pair_swap( {1,3,5,9,7,2}, {3,2,2,4,5,5});
	//~ print_bit_string(10);
	//~ int x = clear_bit(10,3);
	//~ print_bit_string(x);
	//~ x = set_bit(10,3);
	//~ print_bit_string(x);
	//~ x = modify_bit(10,1,1);
	//~ print_bit_string(x);
	
	//~ iterative_pars(4);
	//~ fizzbuzz(40);
	
	//~ thread t1(thread_spinner,1,0);
	//~ thread t2(thread_spinner,1,1);
	//~ thread t3(thread_spinner,1,2);
	//~ thread t4(thread_spinner);
	
	//~ for(int i = 0; i<1000; i++){
		//~ cout<<"main woo"<<endl;
	//~ }
	//~ thread t2(print_thread,"hello", 1);
	//~ t1.join();
	//~ t2.join();
	//~ t3.join();
	//~ t4.join();
	//~ t2.join();
	
	
	//~ vector<vector< int > > A = {
		//~ {1,2,3, 4,-1,11,12,13},
		//~ {5,6,7,8,-2,14,15,16},
		//~ {9,10,11,12,-3,17,18,19},
		//~ {13,14,15,16,-4,20,21},
		//~ {-5,-6,-7,-8,-9}};
	//~ vector<vector< int > > A = {{1,0,2},{0,0,0},{4,0,3}};
	//~ vector<vector<int > > A = {{1,2},{3,4}};
	//~ vector<vector<int > >  A = {
	
  //~ {27, 35, 36, 47, 94, 133, 163, 164, 235, 253, 280, 310, 339},
  //~ {46, 72, 77, 95, 144, 149, 158, 174, 242, 243, 317, 371, 378},
  //~ {13, 14, 80, 83, 121, 157, 158, 163, 215, 220, 308, 325, 388},
  //~ {11, 38, 45, 84, 105, 132, 134, 145, 184, 219, 282, 298, 380},
  //~ {23, 27, 42, 118, 120, 139, 168, 225, 243, 271, 274, 349, 393},
  //~ {22, 27, 49, 85, 103, 167, 175, 234, 241, 258, 283, 296, 352},
  //~ {24, 78, 117, 119, 137, 147, 173, 189, 193, 216, 281, 304, 332},
  //~ {27, 71, 108, 109, 112, 133, 137, 145, 150, 171, 195, 225, 260},
  //~ {5, 56, 65, 114, 123, 200, 220, 222, 248, 264, 285, 317, 350},
  //~ {2, 20, 60, 72, 75, 130, 136, 149, 189, 254, 264, 295, 315},
  //~ {23, 35, 68, 77, 104, 129, 153, 165, 248, 253, 290, 316, 321},
  //~ {34, 127, 129, 154, 186, 202, 203, 210, 235, 269, 331, 344, 376},
  //~ {11, 98, 99, 118, 119, 183, 250, 252, 277, 280, 291, 307, 360}};
	//~ rotate_matrix(A);
	
	//~ cout<<majority_element( { 5,4,5,3,5,6,5,7,5})<<endl;
	//~ cout<<majority_element( { 5,4,5,3,5,6,5,7,2})<<endl;
	
	//~ pascal_k(10);
	//~ merged_median( {1,9,11,45,90,99,100,120,130	},{20,30});
	
	//~ missing_digit_thrice({1,2,7,3,3,2,2,3,1,1});
	//~ vector<vector<string> > all;
	//~ vector<string> current;
	//~ palindrome_partitions(all,current, "nitin",0);
	//~ pm(all);

	// WORD BREAK
	//~ unordered_set<string> words =  { "i", "like", "sam", "sung", "samsung", "mobile", "ice",   "cream", "icecream", "man", "go", "mango"};
	//~ string s = "ilikesamsung";
	//~ vector<string> curr_set;
	//~ vector<vector<string > > master_set;
	//~ word_break(words, s, 0, curr_set, master_set);
	//~ pm(master_set);
	
	// MORE GENERAL PATTERN MATCHING - needs work!
	//~ unordered_map<char,string> pattern_dict;
	//~ pattern_matching_gen("aba", "XXYXX", pattern_dict, 0, 0);

	// BINARY SEARCH ROTATED ARRAY
	//~ vector<int> arr = {2, 4, 5, 6, 7, 0, 1};
	//~ cout<<search_rotated(arr, 6)<<endl;
	
	// INTERSECTION OF TWO SORTED ARRAYS
	//~ auto A = {1, 2, 3, 3, 4, 5, 6};
	//~ auto B = {3,3,5};
	//~ sorted_arr_intersection(A,B);


	// WORD LADDER i
	//~ unordered_set<string> dict = { "hot","dot","dog","lot","log", "cog"};
	//~ word_ladder( "hit", "cog", dict);
	//~ vector<long int> B ={ 69953237, 59183787, 16962742, 53647827, 80157178, 51106992, 58228227, 45131842, 70499719, 70765861, 43961028, 6698667, 99911553, 79107222, 67571988, 39721137, 78088316, 3759045, 19395856, 29387266, 68084358, 62564561, 24736359, 13212412, 66665326, 38724565, 61088241, 21263259, 89291805, 88650356, 58518225, 86449553, 78979492, 39596282, 43927666, 35451400, 80068197, 23391371, 25433080, 5888423, 67042527, 15586432, 57608751, 75903078, 95593533, 15702947, 39691466, 92690796, 18015358, 95172428, 72245309, 15424690, 41199673, 71322081, 27606512, 2347516, 1354382, 9924819, 63458285, 13170098, 40075662, 31237137, 45236128, 74375452, 92722404, 80087546, 23399482, 86945189, 3780890, 1963037, 76980637, 41676736, 74194802, 64788125, 88954508, 95737994, 21365859, 71092491, 67365387, 62345424, 77276892, 53193048, 30131824, 5365626, 66817225, 64511810, 46917019, 80497257, 20853093, 26175229, 85887940, 85764880, 78262084, 609284, 92269014, 46385693, 53718740, 17486900, 98427277, 92911988, 32225164, 72512163, 88678886, 65347756, 40460802, 33132933, 88603373, 26890724, 87077147, 99305881, 55925130, 83289365, 54166373, 50920143, 4427534, 29179799, 91572049, 95103705, 56304651, 69828935, 76914922, 33694020, 15575017, 77664401, 91393916, 96189668, 82107391, 95777779, 22244308, 65701218, 23227429, 98614556, 43407558, 67137144, 34515594, 89248417, 47520685, 14084016, 91725069, 94236666, 61860638, 82315091, 88113674, 31949150, 11718471, 51617813, 41754631, 15588021, 8130184, 52515921, 20663946, 70850137, 85578292, 93271926, 46273611, 27972346, 16865457, 94763722, 28780820, 52198047, 39535546, 9854737, 56888868, 82035778, 88667377, 71915993, 23061619, 71237088, 38215964, 99455111, 84338139, 9438659, 87387886, 35325804, 36964271, 40598041, 83828315, 30761279, 26893177, 19907874, 70129736, 62700567, 91806797, 11958671, 98578052, 8205009, 47197783, 53336153, 36819554, 47426225, 60695466, 55323353, 23435249, 16782401, 37928333, 19599390, 39797644, 9436396, 69658044, 45212110, 48265238, 14183162, 74865579, 58521415, 21894773, 65729368, 91458346, 39977875, 42236097, 12766362, 92049518, 13196912, 18064381, 89025324, 18154460, 77179251, 84814940, 3021813, 25547069, 65821055, 64653709, 94102131, 68518939, 46556175, 82058200, 80932197, 46454512, 62876026, 59675187, 4157064, 56677982, 76761579, 58446935, 51180436, 16416645, 65330136, 39435329, 81388109, 15522197, 78011106, 67617066, 34445170, 75555584, 87940550, 29128931, 61824105, 63418827, 21298249, 19352955, 91556471, 92675461, 888811, 61724633, 69153235, 83033789, 60689257, 54479401, 27546578, 66335535, 38378169, 6852142, 76001740, 64337900, 84778273, 7063943, 20469454, 8897942, 81095011, 89277538, 89473685, 13442135, 54332314, 99428305, 49227963, 1550084, 58626108, 3149845, 9592847, 63553909, 64442175, 52746464, 71731610, 68109474, 12014994, 28405025, 342244, 77415207, 6554496, 29199336, 24816541, 86021818, 93254912, 70091579, 24906579, 50431415, 92218181, 96921595, 70001355, 69278435, 48183386, 4909222, 9784895, 59239264, 82952057, 54807579, 85365017, 10747717, 36328910, 99503949, 25462804, 1948980, 54007615, 93059997, 96143890, 87526013, 36668467, 6585021, 59026699, 42437483, 49977217, 10735602, 29201394, 54519214, 94548380, 46479340, 50083557, 9899537, 43429844, 62002345, 57109791, 15539611, 37100828, 96624737, 58882555, 18287280, 73908899, 58094409, 31628808, 7279505, 87539497, 35968234, 73051936, 9182618, 6399914, 85644731, 13422910, 6027207, 40194013, 49063637, 47973273, 98583990, 4494264, 54221620, 99760871, 52094275, 44298611, 98771831, 39244836, 20234483, 63104483, 17667669, 77220658, 97536077, 67203516, 9567573, 96789571, 6954478, 9245869, 82742448, 72371341, 57459624, 25406080, 52099423, 49750024, 77497879, 16327199, 39571526, 14570597, 76246637, 93751329, 86339423, 97188050, 48457113, 52455837, 77244782, 81308324, 74575702, 31144906, 30685803, 21269958, 31958563, 20917120, 52658082, 33778983, 85532378, 6177062, 35138461, 27377273, 68310047, 27164914, 24236293, 90140894, 26903650, 31650250, 45975378, 10537609, 11918603, 92943222, 77479401, 42865540, 50885917, 57892395, 55161914, 82804155, 16502312, 25439804, 2105003, 52617639, 69471748, 48335908, 17352118, 36510341, 55222894, 6319593, 79662620, 37402118, 68949184, 48515926, 12224685, 8095432, 36227103, 37292769, 79979610, 78482598, 23728343, 26166144, 41593189, 44829841, 44241275, 43522523, 63777807, 3827324, 2683674, 3824814, 35307572, 1837804, 12651831, 24382914, 44014481, 16990793, 41894672, 33681016 };
	//~ vector<long int> A = {  52221101, 45173234, 89990173, 32822606, 39203535, 12805599, 75320887, 78964163, 5776889, 55392502, 50046400, 84026416, 51994515, 18626649, 94623943, 28374236, 37376590, 48296932, 74190041, 79883865, 44105851, 81347626, 51918104, 85381330, 82785019, 67557739, 1613616, 83810918, 57298877, 37627522, 87537450, 15607149, 4423948, 64023764, 42659329, 76554223, 1969313, 87347502, 39798228, 34669950, 22743085, 80391490, 85824638, 1543767, 77646821, 24628099, 15979707, 4626336, 51662609, 91130292, 56917683, 23731969, 7412725, 95878078, 40181555, 50214164, 35847918, 6781415, 44548964, 40188651, 33753971, 85460093, 57695691, 76337034, 62059350, 27100381, 82227676, 98625370, 23783034, 74059024, 50555325, 23779193, 22786314, 98544449, 12602856, 21564488, 57080314, 80886296, 16980625, 33903009, 54765667, 31944391, 31733958, 76670844, 1251836, 25521000, 12261106, 95032647, 66918978, 78185192, 76073486, 3760298, 60759426, 37320495, 52991914, 6928599, 65900672, 88880357, 39709871, 92251365, 54645083, 62545016, 84335989, 64906765, 52247029, 84455841, 35286393, 42371640, 65033737, 8705121, 96232955, 8256578, 71320452, 95341776, 54199810, 33200201, 97496828, 76709041, 56511792, 35976029, 94290235, 70591665, 32895971, 950333, 44730529, 79990624, 45425786, 36153632, 68878296, 12981801, 95525809, 70444257, 77702830, 91161894, 18889029, 4591176, 23630402, 69539624, 26225927, 29572382, 43752878, 21458021, 45249757, 13210321, 19614334, 90961452, 66707450, 67007032, 90320724, 47317744, 84938946, 49479274, 7927079, 92675388, 74471368, 9668749, 79847621, 26556099, 99224158, 43173293, 16415739, 27663306, 78564095, 10242110, 41809626, 39888986, 85230188, 10329471, 17107375, 70598387, 56404758, 62859417, 832123, 25763105, 52765171, 91026292, 80288440, 21651334, 69217389, 73177622, 60820596, 82198373, 65521051, 51041151, 99122187, 645453, 78481576, 6551589, 99270364, 98077714, 2241808, 96018783, 23939467, 92842895, 33881026, 32781033, 1252748, 66039516, 37849731, 83117310, 9921635, 21852352, 57645754, 25138320, 18123154, 46133176, 94860549, 21951539, 40099929, 22298918, 49330818, 30234069, 44101740, 42330714, 48489212, 78660753, 65609648, 67416751, 78136525, 36447396, 11202550, 8941663, 26445991, 50014424, 22790674, 92127368, 50323105, 36129346, 57192783, 35576687, 50190714, 66914300, 7958890, 10529177, 68066690, 85922884, 5280642, 9789894, 55165012, 29986108, 94028195, 60077257, 73801682, 4957359, 55921541, 60067129, 18998652, 87633735, 96157763, 15803391, 674526, 83905175, 86971207, 64880526, 1475890, 20044394 };
	//~ cout<<A.size()<<endl;
	//~ cout<<B.size()<<endl;
	//~ cout<<maxIndex2(A)<<endl;
	//~ vector<int> A = { 247, 240, 303, 9, 304, 105, 44, 204, 291, 26, 242, 2, 358, 264, 176, 289, 196, 329, 189, 102, 45, 111, 115, 339, 74, 200, 34, 201, 215, 173, 107, 141, 71, 125, 6, 241, 275, 88, 91, 58, 171, 346, 219, 238, 246, 10, 118, 163, 287, 179, 123, 348, 283, 313, 226, 324, 203, 323, 28, 251, 69, 311, 330, 316, 320, 312, 50, 157, 342, 12, 253, 180, 112, 90, 16, 288, 213, 273, 57, 243, 42, 168, 55, 144, 131, 38, 317, 194, 355, 254, 202, 351, 62, 80, 134, 321, 31, 127, 232, 67, 22, 124, 271, 231, 162, 172, 52, 228, 87, 174, 307, 36, 148, 302, 198, 24, 338, 276, 327, 150, 110, 188, 309, 354, 190, 265, 3, 108, 218, 164, 145, 285, 99, 60, 286, 103, 119, 29, 75, 212, 290, 301, 151, 17, 147, 94, 138, 272, 279, 222, 315, 116, 262, 1, 334, 41, 54, 208, 139, 332, 89, 18, 233, 268, 7, 214, 20, 46, 326, 298, 101, 47, 236, 216, 359, 161, 350, 5, 49, 122, 345, 269, 73, 76, 221, 280, 322, 149, 318, 135, 234, 82, 120, 335, 98, 274, 182, 129, 106, 248, 64, 121, 258, 113, 349, 167, 192, 356, 51, 166, 77, 297, 39, 305, 260, 14, 63, 165, 85, 224, 19, 27, 177, 344, 33, 259, 292, 100, 43, 314, 170, 97, 4, 78, 310, 61, 328, 199, 255, 159, 185, 261, 229, 11, 295, 353, 186, 325, 79, 142, 223, 211, 152, 266, 48, 347, 21, 169, 65, 140, 83, 156, 340, 56, 220, 130, 117, 143, 277, 235, 59, 205, 153, 352, 300, 114, 84, 183, 333, 230, 197, 336, 244, 195, 37, 23, 206, 86, 15, 187, 181, 308, 109, 293, 128, 66, 270, 209, 158, 32, 25, 227, 191, 35, 40, 13, 175, 146, 299, 207, 217, 281, 30, 357, 184, 133, 245, 284, 343, 53, 210, 306, 136, 132, 239, 155, 73, 193, 278, 257, 126, 331, 294, 250, 252, 263, 92, 267, 282, 72, 95, 337, 154, 319, 341, 70, 81, 68, 160, 8, 249, 96, 104, 137, 256, 93, 178, 296, 225, 237 };
	//~ A = {5,1,4,6,3,2,1	};
	//~ cout<<duplicates(A)<<endl;
	
	// LONGEST SUBSTRING WITH NO REPEATING CHARS
	string str = "abcdabcbb";
	cout<<no_repeat( str )<<endl;
	return 0;
	
}

/////////////////////////////////////////////////////////////
