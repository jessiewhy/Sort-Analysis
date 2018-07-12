#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;

void bubbleSort(std::vector<int> sortThisVector, int size) {
	auto start = high_resolution_clock::now();
	bool swapped = true;
	int currentIndexOfArray = 0;
	int temp = 0;
	while (swapped) {
		swapped = false;
		currentIndexOfArray++;
		for (int i = 0; i<size-currentIndexOfArray; ++i) {
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
	std::cout << "Time taken for bubble sort: " << duration.count() << " seconds." << std::endl;

	//used for check
	/*std::vector<int>::iterator pos;
	for (pos = sortThisVector.begin(); pos != sortThisVector.end(); ++pos)
		std::cout << *pos << " " << std::endl;*/
}

/*void print(std::vector<int> myVec) {
	std::vector<int>::iterator pos;
	for (pos = myVec.begin(); pos != myVec.end(); ++pos)
		std::cout << *pos << " " << std::endl;
}*/


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
	bubbleSort(myVector, count);
	//myVector.mergeSort();
	//myVector.heapSort();
	system("pause");

}