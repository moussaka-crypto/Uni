#pragma once

using Item = int;			// Item als alias f�r integer

// Datenstruktur Warteschlange implementiert mit einem Array als Ringpuffer
class Queue {
private:
	Item*	Q;				// Daten-Array der Queue
	int		n;				// Array-Gr��e
	int		tail;			// Schreibposition
	int		head;			// Leseposition
	int		size;			// Anzahl der aktuellen Elemente in der Queue
public:
	Queue(int capacity=8);  // Konstruktor mit default-Argument f�r die Kapazit�t
	~Queue();				// Destruktor: gibt Speicherplatz frei
	void enqueue(Item item);// F�ge Element hinzu 
	Item dequeue();			// Entfernt ein Element
	bool isEmpty();			// Abfrage, ob Queue leer
	bool isFull();			// Abfrage, ob Queue voll
	int	 getSize();			// Liefert aktuelle Anzahl Elemente in Queue
	int  calcSize();		// Berechnet aktuelle Anzahl Elemente in Queue (ohne Verwendung von dem Member size) 
};