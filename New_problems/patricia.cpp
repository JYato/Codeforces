#include <iostream>
using namespace std;


class PatriciaNode
{
public:
	int bitNumber;
	int data;
	class PatriciaNode *leftChild, *rightChild;
};


class PatriciaTrie
{
public:
	PatriciaNode *root;
	int MaxBits;
	PatriciaTrie()
	{
		MaxBits = 100;
		root = NULL;        
	}
	
	bool isEmpty()
	{
		return root == NULL;
	}

	void makeEmpty()
	{
		root = NULL;        
	}
	//retorna el ith bit de k
	bool bit(int k, int i)
	{
		if(k & 1 << (i - 1))
			return true;
		else
			return false;
	}
	bool search(int k)
	{

		PatriciaNode *searchNode = search(root, k);
		if (searchNode->data == k)
			return true;
		else
			return false;
	}
	
	PatriciaNode* search(PatriciaNode *t, int k)
	{
		PatriciaNode *currentNode, *nextNode;
		if (t == NULL)
		{
			return NULL;
		}
		nextNode = t->leftChild;
		currentNode = t;
		while (nextNode->bitNumber > currentNode->bitNumber)
		{
			currentNode = nextNode;
			nextNode = (bit(k, nextNode->bitNumber)) ? nextNode->rightChild : nextNode->leftChild;
		}
		return nextNode;
	}
	
	void insert(int ele)
	{
		root = insert(root, ele);        
	}
	PatriciaNode* insert(PatriciaNode* t, int ele)
	{
		PatriciaNode *current, *parent, *lastNode, *newNode;
		int i;
		cout << "new ele: " << ele << endl;
		
		if (t == NULL)
		{
			t = new PatriciaNode();
			t->bitNumber = 0;
			t->data = ele;
			t->leftChild = t;
			t->rightChild = NULL;    
			return t;        
		}
		
		lastNode = search(t, ele);
		
		if (ele == lastNode->data)
		{
			cout << "Error : el elemento ya se encuentra insertado" << endl;
			return t;
		}
		
		for (i = 1; bit(ele, i) == bit(lastNode->data, i); i++);
		
		cout << "i: " << i << endl;
		
		current = t->leftChild; parent = t;
		while (current->bitNumber > parent->bitNumber && current->bitNumber < i)
		{
			parent = current;
			current = (bit(ele, current->bitNumber)) ? current->rightChild : current->leftChild;
		}
		
		
		newNode = new PatriciaNode();
		newNode->bitNumber = i;
		newNode->data = ele;
		newNode->leftChild = bit(ele, i) ? current : newNode;
		newNode->rightChild = bit(ele, i) ? newNode : current;        
		
		if (current == parent->leftChild)
		{
			parent->leftChild = newNode;
			cout << "parent: (" << parent << ", data: " << parent->data << ", bit: " << parent->bitNumber << ")";
			cout << " Left-> (" << newNode << " data: " << newNode->data << ", bit: " << newNode->bitNumber << ")" << endl;
		}
		else
		{
			parent->rightChild = newNode;
			cout << "parent: (" << parent << ", data: " << parent->data << ", bit: " << parent->bitNumber << ")";
			cout << " Right-> (" << newNode << " data: " << newNode->data << ", bit: " << newNode->bitNumber << ")" << endl;
		}
		
		return t;
	}        
};

int main()
{
	
	PatriciaTrie *pt = new PatriciaTrie(); 
	
	int ch;
	int val;

	while(1)
	{
		cout << "Patricia Trie Operations" << endl;
		cout << "1. insertar " << endl;
		cout << "2. buscar" << endl;
		cout << "3. vaciar" << endl;
		cin >> ch;
		
		cout << ch << endl;
		
		switch (ch)
		{
		case 1 : 
			cout <<"Ingresa elemento en binario: ";
			cin >> val;
			pt->insert(val);                     
			break;                          
		case 2 : 
			cout <<"Ingresa elemento a buscar" << endl;
			cin >> val;
			cout <<"Resultado : " << pt->search(val)  << endl;
			break;  
		case 3 : 
			cout <<"Patricia Trie vacio" << endl;
			pt->makeEmpty();               
			break;                                        
			default : 
				cout <<"Entrada invalida" << endl;
				break;   
		}
	}
}
