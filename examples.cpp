#include "imports.h"
#include "algs.h"
#include "ds.h"

/////////////////////////////////////////////////////////////
int main ( int argc, char *argv[] ){
	
	vector<double> vals = {54,26,93,17,77,31,44,55,20};
	cout<<"Starting vec:"<<endl;
	//~ for(int i = 0; i<vals.size(); i++){
			//~ cout<<vals[i]<<"\t";
	//~ }
	//~ cout<<endl;
	
	vector<int> mv = {54,26,93,17,77,31,44,55,20};
	maxHeap test(mv);
	//~ for(int i =0; i<mv.size();i++){
		//~ test.insert(mv[i]);
		//~ test.print();
		//~ cout<<"---"<<endl;
	//~ }
	
	test.BuildHeap();
	test.print();
	test.insert(34);
	test.print();
	
	//~ swap(test.arr, 0,test.size-1);
	//~ test.print();
	//~ test.rebalance_leaves(1);
	//~ test.print();
	//~ cout<<(test.arr[parent(1)]>test.arr[1])	<<endl;
	//~ vector<double> qs = vals;
	//~ vector<double> ms = vals;
	
	//~ quicksort(qs, 0, qs.size()-1);
	//~ mergesort(ms, 0, ms.size()-1);
	//~ pv(ms);
	//~ pv(qs);
	return 0;
	
	
}

/////////////////////////////////////////////////////////////
