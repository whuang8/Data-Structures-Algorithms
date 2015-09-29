class Heap{
	int* _heap;
	int _maxSize;
	int _last;
public:
	Heap(int maxSize);
	~Heap();
	bool insert(int data);
	bool removeMin(int &data);
};