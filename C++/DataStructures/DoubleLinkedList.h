struct DoubleLinkedListNode
{
	DoubleLinkedListNode *_next;
	DoubleLinkedListNode *_previous;
	char* _key;
	int _value;
};

class DoubleLinkedList
{
	DoubleLinkedListNode* _sentinel;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void insertFront(char* key, int value);
	void insertEnd(char* key, int value);
	bool removeFront();
	bool removeEnd();
	void printList();
};