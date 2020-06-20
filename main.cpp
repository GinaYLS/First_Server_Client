#include<stdlib.h> 
#include"Alloc.h"
#include"CellTime.hpp"
#include<iostream>
#include<thread>
#include<mutex>
#include<memory>
using namespace std;

mutex m;
const int tCount = 4;
const int nCount = 1000000 / tCount;
void workRun(int n) {
	char* data[nCount];
	for (int i = 0; i <nCount; i++) {
		data[i] = new char[1 + (rand() % 128)];
	}
	for (int i = 0; i <nCount; i++) {
		delete[] data[i];
	}
}

class A
{
public:
	A() {
		cout << "A"<<num << endl;
	}
	~A() {
		cout << "~A"<<num << endl;
	}

	int num = 100;
};

int main() {
	//thread t[tCount];
	//for (int i = 0; i < tCount; i++)
	//	t[i] = thread(workRun, i);
	//CELLTimestamp time;
	//for (int i = 0; i < tCount; i++)
	//	//t[i].detach();
	//	t[i].join();
	//cout << time.getElapsedMilliSec() <<endl;
	//return 0;

	shared_ptr<A> b = make_shared<A>();//a kind of smart point
	b->num = 1;
	return 0;
}
