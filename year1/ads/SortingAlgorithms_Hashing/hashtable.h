#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>

using std::vector;

class HashTable {
private:
	int st = 1;						//Hashing Strategie - Default: Quadr.
	int size;						// Gr��e der HashTable
	int elements;					// Anz. d. Elemente in HashTable
	int collisionCount;				// Anz. d. Kollisionen beim Einf�gen
	double threshold_rehashing;			// Schwellwert f�rs rehashing (size/elements)
	vector<int>* hashTable;				// HashTable
	int hashValue(int item);			// calculate hash value
	void rehashing();					// rehashing

public:
	HashTable(int s, double threshold = 0.6) : size{ s }, elements{ 0 }, collisionCount{ 0 }, 
											   st{1}, threshold_rehashing{threshold}
	{
		hashTable = new vector<int>;
		hashTable->resize(s, -1);
	}
	~HashTable() { delete hashTable; }
	int at(int i) { return hashTable->at(i); }	// Liefert das i-te Element der Hashtabelle zur�ck
	int getCollisionCount() { return this->collisionCount; } // Liefert die Anzahl der Kollisionen zur�ck
	int getSize() { return this->size; } // Liefert die Gr��e der Hashtabelle zur�ck
	int getElements() { return this->elements; }// Liefert die Anzahl der Elemente der Hashtabelle zur�ck
	int insert(int);			// f�gt ein Element der Hashtabelle hinzu
	void print();					// Ausgabe der Hashtable ind er Form: [0] -> 1

	void setStrategy(int str) { this->st = str; }

};

// Helper Funktion:
int get_next_prime(int);				// Gibt zu einer natuerlichen Zahl a, die n�chstgr��ere Primzahl zur�ck

#endif 