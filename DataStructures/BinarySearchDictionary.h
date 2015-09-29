struct BinSearchEntry
{
	char * _key;
	void * _data;
};

class BinarySearchDictionary{
	BinSearchEntry * _array;
	int _maxEntries;
	int _n; //current size of table
	bool _isSorted;
public:
	BinarySearchDictionary();
	~BinarySearchDictionary();
	void insert(char* key, void* data);
	void* lookup(char*key);
	bool remove(char*key);
	void print();
};