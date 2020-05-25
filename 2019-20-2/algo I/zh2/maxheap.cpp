#include <iostream> 
#include <climits> 
#include <string>

using namespace std; 

void swap(int *x, int *y); 

class MaxHeap 
{ 
	private:
		int *harr;
		int capacity;
		int heap_size;
	public: 
		MaxHeap(int capacity); 
		void MaxHeapify(int ); 
		int parent(int i) { return (i-1)/2; } 
		int left(int i) { return (2*i + 1); } 
		int right(int i) { return (2*i + 2); } 
		int extractMax(); 
		void incKey(int i, int new_val); 
		int getMax() { return harr[0]; } 
		void deleteKey(int i); 
		void insertKey(int k); 

		friend std::ostream& operator<<(std::ostream& o, const MaxHeap& h)
		{
			for(int i=0;i<h.heap_size;i++) o << h.harr[i] << " ";
			return o << "\n";
		}
}; 

MaxHeap::MaxHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new int[cap]; 
} 

void MaxHeap::insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	while (i != 0 && harr[parent(i)] < harr[i]) 
	{ 
		swap(&harr[i], &harr[parent(i)]); 
		i = parent(i); 
	} 
} 

void MaxHeap::incKey(int i, int new_val) 
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] < harr[i]) 
	{ 
		swap(&harr[i], &harr[parent(i)]); 
		i = parent(i); 
	} 
} 

int MaxHeap::extractMax() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MaxHeapify(0); 

	return root; 
} 


void MaxHeap::deleteKey(int i) 
{ 
	incKey(i, INT_MIN); 
	extractMax(); 
} 

void MaxHeap::MaxHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] > harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] > harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MaxHeapify(smallest); 
	} 
} 

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	int n,inp;
	string line;
	MaxHeap h(20);
	cout << "n: "; cin >> n; cout << "Add meg a listat: \n";
	for(int i=0;i<n;i++)
	{ cin >> inp; h.insertKey(inp); }

	cout << "remMax | insert: "; cin >> line;
	if(!line.compare("remMax"))
		h.extractMax();
	if(!line.compare("insert"))
	{
		cout << "Ird be a szamot: "; cin >> inp;
		h.insertKey(inp);
	}

	cout << h;
	return 0; 
} 
