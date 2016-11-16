struct HashTableEntry{
	char* _key;
	char* _data;
	HashTableEntry* _next;
};

class HashTable {
	enum {TableSize = 2039};
	int _n;
	//make array of lists
	HashTableEntry ** _buckets;

public:
	HashTable();
	~HashTable();
	int hash(char* key);
	bool insert(char* key, char* data);
	bool remove(char* key);
	bool lookup(char* key, char*& data);
	void print();
};