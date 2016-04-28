//INCLUDE GUARD
#ifndef HEAP_H
#define HEAP_H

//INCLUDED DEPENDENCIES
#include <vector>
#include <unordered_map>

//FORWARDED DECLARED DEPENDENCIES
class realm;

//HEAP OBJECT. 
class minHeap {	
private:
	std::vector<realm*> heap;
	void bubbleDown(int n);
	void heapify(void);	
public:
	bool isHeapEmpty(void);
	bool isInHeap(void);
	realm* extractMin(void);	
	void bubbleUp(int n);	
	minHeap(std::vector<realm*>& vector);
};

void minHeap::bubbleDown(int n) {
	for(int i = 0; i < heap.size(); i++) {
		std::cout << heap[i]->heapindex << ' ';
	}
	int left = (2 * n + 1);
	int right = (2 * n + 2);
	int min = n;
	if(left >= this->heap.size()) {
		return;
	}
	if(this->heap[n]->getDistFromSrc() > this->heap[left]->getDistFromSrc()) {
		min = left;
	}
	if((right < this->heap.size()) && (this->heap[min]->getDistFromSrc() > this->heap[right]->getDistFromSrc())) {
		min = right;
	}
	if(min != n) {
		//SWAP POSITIONS
		int pos = this->heap[n]->heapindex;
		this->heap[n]->heapindex = this->heap[min]->heapindex;
		this->heap[min]->heapindex = pos;
		//SWAP NODES
		realm *temp = this->heap[n];
		this->heap[n] = this->heap[min];
		this->heap[min] = temp;
		bubbleDown(min);
	}
}

void minHeap::bubbleUp(int n) {
	int parent = ((n - 1) / 2);
	if(n == 0) {
		return;
	}
	if(this->heap[parent]->getDistFromSrc() > this->heap[n]->getDistFromSrc()) {
		//SWAP POSITIONS
		int pos = this->heap[parent]->heapindex;
		this->heap[parent]->heapindex = this->heap[n]->heapindex;
		this->heap[n]->heapindex = pos;
		//SWAP REALMS
		realm *temp = this->heap[parent];
		this->heap[parent] = this->heap[n];
		this->heap[n] = temp;
		bubbleUp(parent);
	}
}

void minHeap::heapify(void) { 
	for(int i = this->heap.size() - 1; i >= 0; i--) {
		bubbleDown(i);
	}
}


bool minHeap::isHeapEmpty(void) {
	if(this->heap.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

realm* minHeap::extractMin(void) {
	if(isHeapEmpty()) {
		return NULL;
	}
	realm* min = this->heap[0];
	this->heap[0] = this->heap[this->heap.size() - 1];
	this->heap[0]->heapindex = 0;
	this->heap.pop_back();
	this->bubbleDown(0);
	return min;
}

minHeap::minHeap(std::vector<realm*>& vector) : heap(vector) {
	heapify();
}

#endif