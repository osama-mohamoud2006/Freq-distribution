#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// requirments_for_table {
//	int k; // number that is bigger than total numbers
//	int total; // the total of all numbers
//	int range; // max - min 
//	double width; // range / k ( if it is int number) or range+1 / k (if it is float number)
//};

///input numbers////////
// i didnot study the vectors yet so i will use array
// suppose we have 20 numbers to input //// 
void input_numbers(int arr[20]) {
	int i = 0;

	do {
		cout << "enter number " << i + 1 << ": ";
		cin >> arr[i];
		if (arr[i] <= 0) {
			cout << "enter number again ";
			continue;
		}
		i++;
	
	} while (i < 20 || i <= 0);
	
}

//bubble sort to order numbers (Ascending)( for no reason )
void sort_nums(int arr[20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
	cout << '\n' << '\n';

}
// ordered sort output
void output_sort_nums(int arr[20]) {
	sort_nums( arr); // called function to  sort 
	cout << "==================== the ordered numbers =======================================" << endl;
	for (int o = 0; o < 20; o++) {
		cout << arr[o] << " ";
	}
	cout << endl;
}

//get the range , Range = max - min 

// //get the max
int max(int arr[20]) {
	int max_value = arr[0];
	for (int fm = 0; fm < 20; fm++) {
		if (arr[fm] > max_value) max_value = arr[fm];
	}
	return max_value;
}

// get the min
int min(int arr[20]) {
	int min_value = arr[0];
	for (int m = 0; m < 20; m++) {
		if (arr[m] < min_value) min_value = arr[m];
	}
	return min_value;
}
 // return the range 
int Range(int arr[20]) {
	cout << '\n';
	return max(arr) - min(arr); 
}

// get the k ( k is 2'k that it is value bigger than 20 ) 
int get_k() {
	
	int k = 1;
	for ( k = 1; k < 10; k++) {
		if (pow(2, k) > 20)  return  k;
	}
	
	
}

// width = range/k if the result is int so no need for this another method
// width = range +1 / k if the result in first one is int 
int width(int arr[20]  ) {
// range , k
// first
	double range = Range(arr);
	double k = get_k();
	if( fmod(range , k)  ==0 ) return ceil( (range + 1) / k);
 // note : you should use float or int with ceil 
else return ceil (range / k);
	
} 

//void freq_for_each_lim(int arr[20], int k, int maxv, int minv, int widthv , int repeat[6]) {
//	int  newc = 0;
//
//	int rep = 0;
//	do {
//		// min = 1 
//		newc = minv + widthv;
//		// max = 9
//		for (int i = 0; i < 20; i++) {
//
//			// walk through array from 1 to 5 
//		// range
//			if (arr[i] >= minv && newc > arr[i]) rep++;
//
//		}
//		for (int k = 0; k < 5; k++)
//			arr[k] = rep;
//	}
//
//	
//	
//	
//		minv = newc; // min = 5
//		//max = minv + width 
//
//		rep = 0;
//
//	}while(minv < maxv); 
		

	


void table(int arr[20], int k, int maxv, int minv, int widthv) {
	float cf = 0;

	cout << "\n================= Frequency Distribution Table ==========================" << endl;
	cout << "| Interval # |     Range     | Frequency |    RF    |    CF    |" << endl;
	cout << "|------------|----------------|-----------|----------|----------|" << endl;

	int currentMin = minv;
	for (int i = 1; i <= k; i++) {
		int currentMax = currentMin + widthv;

		//freq
		int freq = 0;
		for (int j = 0; j < 20; j++) {
			if (arr[j] >= currentMin && arr[j] < currentMax) {
				freq++;
			}
		}

		float rf = (float)freq / 20;
		cf += freq;

		// print table
		cout << "|     " << setw(2) << i << "     |   ["
			<< setw(2) << currentMin << " - "
			<< setw(3) << currentMax << "]   |"
			<< setw(6) << freq << "    |"
			<< setw(7) << fixed << setprecision(2) << rf << " |"
			<< setw(8) << cf << " |" << endl;

		currentMin = currentMax;
	}

	cout << "=========================================================================" << endl;
}



int main() {
	int arr[20];
	input_numbers(arr);
	output_sort_nums(arr);
	int minv = min(arr);
	int maxv = max(arr);
    int k = get_k();
	int widthv = width(arr);
	cout << "the range is " << Range(arr) << endl;
	cout << "so the k value is " << get_k() << endl;
	cout << "the width " << width(arr) << endl;
		
		table(arr , k , maxv  , minv , widthv ) ;
}