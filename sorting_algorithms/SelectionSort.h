/**************************************************
 *                 SELECTION SORT                 *
 *                                                *
 * Implementation of a simple ascending selection *
 * sort algorithm. The algorithm doesn't require  *
 * copying the entire array(in-place sort) and    *
 * it's time complexity is O(n^2).                *
 **************************************************/

#ifndef ALG_SORT_SELECTION_SORT_H_
#define ALG_SORT_SELECTION_SORT_H_

namespace alg_sort {
    template<typename T>
    void SelectionSort(T* arr, int size) {  
        for (int i = 0; i < size; i++) {
            // Min is index of the smallest element
            int min = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }   
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    } 
}
#endif
