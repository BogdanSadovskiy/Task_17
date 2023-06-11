using namespace std;
#include <iostream>
#include<time.h>

void coutarr(int* arr, int size) {
	cout << "\nYour patients date base:________\n";
	for (int i = 0; i < size; i++) {
		cout << "Patient #" << i+1 << " with number " << arr[i] << endl;
		
	}
	cout << "________________________________\n\n";
}
void add(int*& arr, int& size) {
	size++;
	int* arr2 = new int[size];
	int k = 1;
	
	for (int i = 0; i < size ; i++) {
		if (i <= size - 2) {
			arr2[i] = arr[i];
		}
		else {
			arr2[size - 1] = rand() % 60 + 1;
			if (i > 0) {
				for (int j = i - 1; j >= 0; j--) {
					if (arr2[j] == arr2[i]) {
						i--;
					}
				}
			}
		}
	}
	cout << "You have registered a patient with number " << arr2[size - 1] << endl;
	delete[] arr;
	arr = arr2;
	coutarr(arr, size);
}
// deleting patient
void deletearr(int*& arr, int& size) {
startdelete:
	cout << "  What patient you want to delete?\n";
	cout << "  By index (input 1)\n";
	cout << "  By number (input 2)\n";
	cout << "  Back to menu (input 0)\n";
	int q; cin >> q;
	// deleting by index
	if (q == 1) {
		startindex:
		if (size > 1) {
			cout << "Input index from 1 to " << size << endl;
		}
		else {
			cout << "You have only one patient with index " << size << endl;
		}
		cout << "Back (input 0)\n";
		cin >> q;
		if (q == 0) {
			goto startdelete;
		}
		else if (q > 0 && q <= size) {
			int index = q;
			startdelindex:
			cout << "You want delete " << index << " indexed patient with number " << arr[index - 1] << "?\n";
			cout << "Yes  - 1\n";
			cout << "Back - 0\n";
			cin >> q;
			if (q == 0) {
				goto startindex;
			}
			else if (q == 1) {
				int* arr2 = new int[size-1];
				int k = 0;
				
				for (int i = 0; i < size-1; i++) {
					if (i < index - 1) {
							arr2[i] = arr[i];
					}
					else {
							arr2[i] = arr[i + 1];
					}
				}
				size--;
				delete[] arr;
				arr = arr2;
				
			}
			else {
				cout << "Wrong inputting\n";
				goto startdelindex;
			}
		}
		else {
			cout << "Wrong inputting. Try again\n";
			goto startindex;
		}
	}
	// deleting by number
	else if (q == 2) {
	delbynumb:
		coutarr(arr, size);
		cout << "What number of patient you want to delete?\n";
		cout << "Back (input 0)\n";
		cin >> q;
		short n = 0;
		if (q == 0) {
			goto startdelete;
		}
		else if (q>0){
			for (int i = 0; i < size; i++) {
				if (arr[i] == q) {
					n++;
				}
		    }
		}
		else {
			cout << "Wrong inputting\n";
			goto delbynumb;
		}
		if (n == 0) {
			cout << "There is no patient with number " << q << ". Try again\n";
			goto delbynumb;
		}
		else {
			cout << "You want to delete patient with number " << q << "?\n";
			cout << "Yes  - 1\nBack - 0\n";
			int number = q;
			cin >> q;
			if (q == 0) {
			   goto delbynumb;
			}
			else if (q == 1) {
				int* arr2 = new int[size - 1];
				int k = 0;
				for (int i = 0; i < size-1; i++) {
					if (arr[i] == number) {
						k++;
					}
					if (k == 0) {
						arr2[i] = arr[i];
					}
					else if (k > 0) {
						arr2[i] = arr[i + 1];
					}
				}
				size--;
				delete[] arr;
				arr = arr2;
			}
		}
	}
}
int prequicksort(int* arr, int left, int right) {
	int p = arr[left];
	int c = 0;
	for (int i = left + 1; i <= right; i++) {
		if (arr[i] <= p) {
			c++;
		}
	}
	int pi = left + c;
	int n = arr[pi];
	arr[pi] = arr[left];
	arr[left] = n;
	int i = left;
	int j = right;
	while (i<pi && j>pi) {
		while (arr[i] <= p) {
			i++;
		}
		while (arr[j] > p) {
			j--;
		}
		if (i<pi && j>pi) {
			n = arr[i];
			arr[i] = arr[j];
			arr[j] = n;
			i++; j--;
		}
	}
	return pi;
}
void quicksort(int* arr, int left, int right) {
	
	if (left >= right) {
		return;
	}
	int n = prequicksort(arr, left, right);
	quicksort(arr, left, n - 1);
	quicksort(arr, n + 1, right);
}
void bogosort(int* arr, int size) {
	int sorted = 0;
	while (sorted == 0) {
		for (int i = 0; i < size; i++) {
			int r = rand() % size;
			int a = arr[i];
			arr[i] = arr[r];
			arr[r] = a;
		}
		for (int i = 1; i < size; i++) {
			if (arr[i] >= arr[i - 1]) {
				sorted++;
			}
			else { sorted = 0;
			break;
			}
		}
	}
}
void line_search(int* arr, int size, int value )		//лінійний пошук
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			cout << "Found  by line search " << value << " as " << i + 1 << " element\n";
			return;
		}
	}
	cout << "Not found\n";
}
void binary_search(int* arr, int size, int value) {
	int left = 0;
	int right = size - 1;
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (arr[middle] == value) {
			cout << "Found by binary search " << value << " as " << middle + 1 << " element\n";
			return ;
		}
		if (arr[middle] < value) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	cout << "Not found\n";
}
void move(int* arr,int firstI, int secondI) {
	int n = arr[firstI];
	arr[firstI] = arr[secondI];
	arr[secondI] = n;
}
int main()
{
	clock_t time1, time2;
	int size = 0;
	int* arr = new int[size];
	int q;
	int sorted = 0;
start:
	cout << endl;
	cout << "*********************************\n";
	cout << "  Add patient (input 1)\n";
	cout << "  Delete date of patient (input 2)\n";
	cout << "  Sort (input 3)\n";
	cout << "  Search patient (input 4)\n";
	cout << "  Move patients (input 5)\n";
	cout << "                 exit (input 0)\n";
	cout << "*********************************\n";
	cin >> q;
	if (q == 2 && size == 0) {
		cout << "You have not any patient\n";
		goto start;
	}
	else if (q == 3 && size <2) {
		if (size == 0) {
			cout << "You can not sort. You  have not any patient\n";
		}
		else {
			cout << "You have only one patient with number " << arr[0];
			cout << ", so there is nothing to sort\n";
		}
		goto start;
	}
	else if (q == 4 && size == 0) {
		cout << "Nothing to search\n";
		goto start;
	}
	else if (q == 5 && size == 0) {
		cout << "Add the patient first\n";
		goto start;
	}
	else if (q == 5 && size == 1) {
		cout << "You have only one patient\nYou can not move him\n";
		goto start;
	}
	else if (q == 0) {
		cout << "Good bye\n";
		return 0;
	}
	// adding the patient
	else if (q == 1) {
	add:
		add(arr, size);
		sorted = 0;
	addst:
		cout << "  Add another patient (input 1)\n";
		cout << "  Back to menu (input 2)\n";
		cout << "  Exit program (input 0)\n";
		cin >> q;
		if (q == 1) {
			goto add;
		}
		else if (q == 2) {
			goto start;
		}
		else if (q == 0) {
			cout << "Good bye\n";
			return 0;
		}
		else {
			cout << "Wrong inputting. Try again\n";
			goto addst;
		}
	}
	//_deleting the patient
	else if (q == 2 && size > 0) {
		deletearr:
		deletearr(arr, size);
		cout << "Deleted\n";
		coutarr(arr, size);
		if (size > 0) {
		moredel:
			cout << "Want to delete one more? (input 1)\n";
			cout << "Exit to main menu (input 0)\n";
			cin >> q;
			if (q == 1) {
				goto deletearr;;
			}
			else if (q == 0) {
				goto start;
			}
			else {
				cout << "Wrong inputting\n";
				goto moredel;
			}
		}
		else {
			cout << "You have not anyone patient now\n";
			goto start;
		}
	}
	//Sorting
	else if (q == 3 && size > 1) {
		if (sorted == 1) {
			cout << "You already sorted\n";
			goto start;
		}
		startsort:
		cout << "Quick sort (input 1)\n";
		cout << "Bogosort (input 2)\n";
		cout << "Back (input 0)\n";
		cin >> q;
		float time = 1;
		float time2 = 1;
		
		if (q == 1) {
			
			time = (float)clock();
			
			quicksort(arr, 0, size - 1);
			time2 = (float)clock();
			
			time = time2 - time;
		}
		else if (q == 2) {
			time = (float)clock();
			cout << clock();
			bogosort(arr, size);
			time2 = (float)clock();
			cout << clock();
			time = time2 - time;
		}
		else if (q == 0) {
			goto start;
		}
		else {
			cout << "Wrong inputting\n";
			goto startsort;
		}
		coutarr(arr, size);
		cout << "Sorted\n";
		if (q == 1) {
			cout << "Quick Sort time - " << (float)time / CLOCKS_PER_SEC << " sec\n";
			cout << "________________________________\n";
		}
		else if (q == 2) {
			cout << "Bogosort time - " << (float)time / CLOCKS_PER_SEC << " sec\n";
			cout << "________________________________\n";
		}
		
		sorted = 1;
		goto start;
	}
	//Search patient
	else if (q == 4 && size > 0) {
		startfind:
		cout << "Input number you want to find\n";
		cout << "Back (input 0)\n";
		cin >> q;
		int value = q;
		if (q == 0) {
			goto start;
		}
		if (sorted == 1) {
			cout << "Line search (input 1)\n";
			cout << "Binary search (input 2)\n";
			cout << "Back (input 0)\n";
			cin >> q;
			if (q == 1) {
				goto linefind;
			}
			else if (q == 2) {
				time1 = clock();
				binary_search(arr, size, value);
				time2 = clock();
			}
			else if (q == 0) {
				goto startfind;
			}
		}
		else {
		linefind:
			time1 = clock();
			line_search(arr, size, value);
			time2 = clock();
		}
		time1 = time2 - time1;
		cout << "Time spending for search is " << (float)time1 / CLOCKS_PER_SEC << " sec\n";
		q1:
		cout << "Search again? (input 1)\n";
		cout << "Go to main menu (input 0)\n";
		cin >> q;
		if (q == 1) {
			goto startfind;
		}
		else if (q == 0) {
			goto start;
		}
		else {
			cout << "Wrong inputting\n";
			goto q1;
		}
	}
	// move patient
	else if (q == 5 && size > 2) {
		startmove:
		cout << "Input index of patient you want ot move (1 - "<< size<<")\n";
		cout << "Back (input 0)\n";
		cin >> q;
		if (q == 0) {
			goto start;
		}
		else if (q > 0 && q <= size) {
			startmove2:
			int index1 = q;
			cout << "Input index you want to move patient to (1 - " << size << ")\n";
			cout << "Back (input 0)\n";
			cin >> q;
			if (q == 0) {
				goto startmove;
			}
			else if (q > 0 && q <= size) {
				startmove3:
				int index2 = q;
				cout << "You want to move the patient indexed as " << index1 << " with number " << arr[index1 - 1];
				cout << " to " << index2 << " (number " << arr[index2 - 1] << ")?\n";
				cout << "yes - 1\n";
				cout << "back to start of moving (input - 0)\n";
				cin >> q;
				if (q == 0) {
					goto startmove;
				}
				else if (q == 1) {
					move(arr, index1-1, index2-1);
					coutarr(arr, size);
					cout << "Moved\n";
					sorted = 0;
					startmove4:
					cout << "Want to move again? (1 - yes)\n";
					cout << "0 - back to main menu\n";
					cin >> q;
					if (q == 0) {
						goto start;
					}
					else if (q == 1) {
						goto startmove;
					}
					else {
						cout << "Wrong inputting\n";
						goto startmove4;
					}
				}
				else {
					cout << "Wrong inputting\n";
					goto startmove3;
				}
			}
			else {
				cout << "Wrong inputting\n";
				goto startmove2;
			}
		}
		else {
			cout << "Wrong inputting\n";
			goto startmove;
		}

	}

	else {
		cout << "Wrong inputting. Try again\n";
		goto start;
	}
	


}