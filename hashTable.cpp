/*해시 테이블 구현 연습*/
#include<iostream>
#define MAX_HASH 10
//#define HASH_KEY(key) key%MAX_HASH  //해시 함수?
#define HASH_KEY(key) (key*(0.6180339887)-(int)(key*(0.6180339887)))*MAX_HASH
using namespace std;

typedef struct Node{
	int value;
	Node* hashNext;
}Node;

Node* hashTable[MAX_HASH];

void AddHashData(Node* node) {
	int hash_key;
	if (node->value >= 0) hash_key = HASH_KEY(node->value);
	else hash_key = HASH_KEY(node->value) + MAX_HASH;

	if (hashTable[hash_key] == NULL) hashTable[hash_key] = node;
	else {
		node->hashNext = hashTable[hash_key];
		hashTable[hash_key] = node;
	}
}

void DelhasData(int value) {
	int hash_key;
	if(value >= 0) hash_key = HASH_KEY(value);
	else hash_key = HASH_KEY(value) + MAX_HASH;
	Node* delNode = NULL;

	if (hashTable[hash_key] == NULL) return;
	if (hashTable[hash_key]->value == value) {
		delNode = hashTable[hash_key];
		hashTable[hash_key] = hashTable[hash_key]->hashNext;
	}
	else {
		Node* now = hashTable[hash_key];
		Node* next = hashTable[hash_key]->hashNext;
		while (next != NULL) {
			if (next->value == value) {
				delNode = next;
				now->hashNext = next->hashNext;
				break;
			}
			else {
				now = next;
				next = next->hashNext;
			}
		}
	}
	free(delNode);
}

void print_table() {
	cout << "-------Table-------" << '\n';
	for (int i = 0; i < MAX_HASH; i++) {
		Node* now_node = hashTable[i];
		cout << "[" << i << "] : ";
		while (1) {
			if (now_node != NULL) {
				cout << now_node->value << " -> ";
				now_node = now_node->hashNext;
			}
			else {
				cout << "NULL";
				break;
			}
		}
		cout << '\n';
	}
	cout << "-------------------" << '\n';
}

int main(){
	
	for (int i = 0; i < 5; i++) {
		Node* input = new Node;
		input->hashNext = NULL;
		cin >> input->value;
		AddHashData(input);
	}
	
	print_table();
	DelhasData(-11);
	print_table();

}

