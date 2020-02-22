#include <thread>
#include <mutex>
#include <condition_variable>

mutex m;
mutex sm;


//~ conditional_variable condvar;

void print_thread( string msg, int id){
	cout<<id<<"\t"<<msg<<endl;
	
}

void thread_spinner( int n, int id  ){
	sm.lock();
	cout<<"Starting thread "<<id<<endl;
	cout<<"Attempting lock: "<<id<<endl;
	sm.unlock();

	m.lock();
	sm.lock();

	cout<<"Mutex locked,running "<<id<<endl;
	sm.unlock();
	int c = 0;
	double val = 0;
	while(val < n){
		val = val + pow(10,-5);
		c++;
		if((c%10000)==0){
			cout<<c<<endl;
		}
		//~ cout<<val<<endl;
	}
	cout<<val<<endl;
	sm.lock();

	cout<<"Unlocking mutex "<<id<<endl;
	sm.unlock();

	m.unlock();
}


//~ void thread_spinner( int n, int id  ){
	
	//~ sm.lock();
	//~ cout<<"Starting thread "<<id<<endl;
	//~ cout<<"Waiting for lock release: "<<id<<endl;
	
	//~ sm.unlock();
	//~ unique_lock<mutex> mlock(m);

	//~ sm.lock();

	//~ cout<<"Mutex locked,running "<<id<<endl;
	//~ sm.unlock();
	//~ int c = 0;
	//~ double val = 0;
	//~ while(val < n){
		//~ val = val + pow(10,-5);
		//~ c++;
		//~ if((c%10000)==0){
			//~ cout<<c<<endl;
		//~ }
		//~ cout<<val<<endl;
	//~ }
	//~ cout<<val<<endl;
	//~ sm.lock();

	//~ cout<<"Unlocking mutex "<<id<<endl;
	//~ sm.unlock();


//~ }
