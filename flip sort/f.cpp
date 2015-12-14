#include <iostream>
#include <cstdio>
using namespace std ;

int bubbleSort(int arr[], int n) {
      bool swapped = true;
      int j = 0;
      int tmp;
      int k =0 ;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        k++ ;
                        swapped = true;
                  }
            }
      }
      return k ; 
}


int main ()
{
	int testcase ;
	while(cin >> testcase){
		int numbers[testcase] ; 
	for (int I = 0; I < testcase; I++)
	{
			cin >> numbers[I] ;
	}
	cout <<"Minimum exchange operations : "<<bubbleSort(numbers,testcase) << endl  ;

}
	return 0 ;
}
	
