#ifndef DSNAME_H
#define DSNAME_H
#include <map>


/*
	WICHTIGER HINWEIS:
	Die Klasse DSName repr�sentiert in diesem Beispiel eine allgemeine 
	Datenstruktur und soll die folgenden Eigenschaften einer Datensturktur
	verdeutlichen:
	* Einf�gen von Daten
	* Zugriff auf Daten
	* Suchen von Elementen
	* L�schen von Elementen
	
	Die Implementierung ist f�r Sie in diesem Beispiel NICHT relevant.

	Lassen Sie sich bitte nicht durch die folgenden beiden Zeilen 
	Programmcode verwirren:
		class Item;							
		using Data = std::map<int, Item>;

	Ignorieren Sie die Implementierung und konzentrieren sich bitte nur
	auf die Verwendung der Datenstruktur in der Datei main.cpp
*/
class Item;							// Vorw�rtsdeklaration (forward declaration)
using Data = std::map<int, Item>;	// moderne Version eines typedef's 

class Item {
public:
	int key;	// Eindeutige ID f�r die Datenstruktur
	int Data;	// Daten
	Item(int key = 0, int Data = 0) { // Konstruktor
		this->key = key;
		this->Data = Data;
	}
	~Item() {}; // Destruktor
};


class DSName {
private:
	// ... (nicht f�r User sichtbare Attribute und Methoden)
	Data Data; // eigentliche Daten der Datenstruktur

public:
	// ... (f�r den User sichtbare Attribute und Methoden)
	DSName();					 // default Konstruktor
	~DSName();					 // default Destruktor
	void insertItem(Item value); // Daten einf�gen
	Item getItem(int key);		 // Daten auslesen
	bool findItem(int key);		 // Daten suchen
	bool deleteItem(int key);	 // Daten l�schen
	// ...
	void printAllItems(); // Hilfsmethode: alle Elemente ausgeben

};

#endif