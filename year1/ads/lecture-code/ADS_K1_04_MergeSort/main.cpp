#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>

using namespace std;

/**
 * Hilfsfunktion - Einlesen einer Zahlenfolge
 *
 * \return Benutzereingabe gespeichert in einem std::vector<int>
 */
std::vector<int> userInput() {
	std::cout << "Bitte Zahlen eingeben (in einer Zeile und mit Leerzeichen getrennt):\n";
	std::vector<int> input;
	std::string str;
	std::getline(std::cin, str);
	std::istringstream sstream(str);
	int n;
	while (sstream >> n) {
		input.push_back(n);
	}
	return input;
}

/**
 * Hilfsfunktion - Ausgabe eines std::vectors<int>
 *
 * \param[in] A Daten die ausgegeben werden sollen
 */
void print(std::vector<int> const& Vector) {
	for (auto const& elem : Vector) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

/**
 * Insertion-Sort Algorithmus
 *
 * \param[in/out] A	Eingabe: unsortierte Array-Werte,
 *					Ausgabe: sortierte Array-Werte
 **/
void InsertionSort (vector<int>& A)
{
	int j, key, i;
	for (j = 1; j < A.size(); j++) {// Schleife über alle Werte
		key = A[j];						// einzusortierender Wert
		i = j - 1;
		// Werte zwischen Index 0 und i sind sortiert
		// der einzusortierende Wert wird an der richtigen Stelle im sortierten Abschinitt eingefügt
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];			// Verschieben der größeren Werte von i nach i + 1
			i--;
		}
		A[i + 1] = key;					// Einfügestelle gefunden -> Werte zwischen Index 0 in j sind sortiert
	}
	return;
}

void InsertionSort2(vector<int>& A)
{
	int tmp, i, j;
	for (i = 1; i < A.size(); i++)
	{
		tmp = A[i];
		j = i;
		while (j > 0 && A[j-1] > tmp)
		{
			A[j] = A[j-1];
			j--;
		}
		A[j] = tmp;
	}

}

void SelectionSort(vector<int>& A)
{
	int i, j, min, tmp;
	int N = A.size();
	for (i = 0; i < N-1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
		{
			if (A[j] < A[min]) min = j;
		}
		tmp = A[min]; 
		A[min] = A[i]; 
		A[i] = tmp;
	}

}

void BubbleSort(vector<int>& A)
{
	int i, j, tmp;
	int N = A.size();
	for (int i=0; i < N-1; i++)
	{
		for (int j = N-1; j > i; j--)
		{
			if (A[j] < A[j-1])
			{
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

/**
 *	Merge - diese Funktion vereinigt zwei sortierte Arrays (Teile im Array)
 *
 */
void Merge(std::vector<int>& A, size_t l, size_t m, size_t r) {
	size_t i, j, k;
	const size_t n1 = m - l + 1;
	const size_t n2 = r - m;
	
	// linkes (L) und rechtes (R) Array füllen
	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for (i = 0; i < n1; i++) {
		L[i] = A[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = A[m +1+j];
	}
	// Zählervariablen zurücksetzen
	i = 0;
	j = 0;
	k = l;
	// Mergen der beiden Arrays (vector)
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	// Kopieren von restlichen Elementen aus L (wenn exsistent)
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	// Kopieren von restlichen Elementen aus R (wenn exsistent)
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}

/**
 *
 */
void MergeSort(std::vector<int>& A, size_t l, size_t r) {
	if (l < r) {
		size_t m = size_t(std::floor((l + r) / 2));
		MergeSort(A, l, m);
		MergeSort(A, m + 1, r);
		Merge(A, l, m, r);
	}
}

/**
 * Merge-Sort Algorithmus
 *
 * 	\param[in/out] A	Eingabe: unsortierte Array-Werte,
 *						Ausgabe: sortierte Array-Werte
 **/
void MergeSort(std::vector<int>& A) {
	MergeSort(A, 0, A.size()-1);
}


/*
	Hilfsfunktion - genertiert einen Vector mit Integern
	im Bereich von 0 bis N-1.
	Diese Vector wird danach in eine randomisierte Reihenfolge
	gebracht.
*/
std::vector<int> getRandomVector(size_t N) {
	std::vector<int> numbers(N);
	std::iota(numbers.begin(), numbers.end(), 0);
	std::shuffle(numbers.begin(), numbers.end(), std::mt19937{ std::random_device{}() });
	return numbers;
}

int main() {

	//std::vector<int> A = { 5,2,4,6,1,3 };	// unsortierte Werte
	std::vector<int> A = getRandomVector(20);

	// optional:	Benutzereingabe lesen
	//				folgende Zeile ein/auskommentieren
	//A = userInput();

	// Ausgabe des unsortierten Arrays
	std::cout << "Unsortiertes Array:\t";
	print(A);

	// sortieren mit Merge Sort + Zeitmessung
	auto start = std::chrono::high_resolution_clock::now();
	//InsertionSort(A);
	//InsertionSort2(A); 
	//SelectionSort(A);
	//BubbleSort(A);
	MergeSort(A);					
	auto finish = std::chrono::high_resolution_clock::now();
	
	// Ausgabe des sortierten Arrays
	std::cout << "Sortiertes Array:\t";
	print(A);

	// Ausgabe der Zeitmessung
	std::cout << "time: " << std::chrono::duration<double, std::milli>(finish - start).count() << "[ms]" << std::endl << std::endl;
	return 0;
}
