#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

void bubbleSort(std::vector<int> &sortThisVector, int size) {
	auto start = high_resolution_clock::now();
	bool swapped = true;
	int lastSortedData = 0;
	int temp = 0;
	while (swapped) {
		swapped = false;
		lastSortedData++;
		for (int i = 0; i<size-lastSortedData; ++i) {
			if (sortThisVector[i]>sortThisVector[i + 1]) {
				temp = sortThisVector[i];
				sortThisVector[i] = sortThisVector[i + 1];
				sortThisVector[i + 1] = temp;
				swapped = true;
			}
		}

	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	std::cout << "Time taken for bubble sort: " << duration.count() << " seconds" << std::endl;

}

void print(std::vector<int> myVec) {
	std::vector<int>::iterator pos;
	for (pos = myVec.begin(); pos != myVec.end(); ++pos)
		std::cout << *pos << " " << std::endl;
}

void heapify(std::vector<int> &sortThisVector, int size, int calcParent) {
	int largest = calcParent;
	int lIndex = 2 * calcParent + 1;
	int rIndex = 2 * calcParent + 2;

	if (lIndex < size && sortThisVector[lIndex] > sortThisVector[largest])
		largest = lIndex;
	if (rIndex < size && sortThisVector[rIndex] > sortThisVector[largest])
		largest = rIndex;
	
	if (largest != calcParent) {
		std::swap(sortThisVector[calcParent], sortThisVector[largest]);
		heapify(sortThisVector, size, largest);
	}
}

void heapSort(std::vector<int> &sortThisVector, int size) {
	std::string sortType = "Heap Sort";
	auto start = high_resolution_clock::now();
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(sortThisVector, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		std::swap(sortThisVector[0], sortThisVector[i]);
		heapify(sortThisVector, i, 0);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	std::cout << "Time taken for heap sort: " << duration.count() << " seconds" << std::endl;
	
	
}

//DON'T FORGET TO CLOSE FILE WHEN YOU'RE DONE IMPLEMENTING SORTING METHODS 
int main()
{
	std::ifstream file;
	std::string fileName;
	int num = 0;
	int count = 0;
	std::vector<int> myVector;
	std::cout << "Please enter the name of the input file: " << std::endl;
	std::cin >> fileName;

	// opening file
	file.open(fileName.c_str());

	//if file cannot open
	if (!file) {
		std::cout << "Could not open file " << fileName << std::endl;
		exit(1);
	}

	//insert all ints into a vector 
	while (file >> num) {
		myVector.push_back(num);
		++count;
	}

	//working w vector now
	file.close();

	//sort vectors
	//bubbleSort(myVector, count);
	//print(myVector);
	heapSort(myVector, count);
	//print(myVector);
	//myVector.mergeSort();
	system("pause");

}