/**************************************************
 *                 INSERTION SORT                 *
 *                                                *
 * Implementation of a simple ascending insertion *
 * sort algorithm. The algorithm doesn't require  *
 * copying the entire array(in-place sort) and    *
 * it's time complexity is O(n^2). In the         *
 * best case time complexity is Ω(n).             *
 **************************************************/

#ifndef ALG_SORT_INSERTION_SORT_H_
#define ALG_SORT_INSERTION_SORT_H_

namespace alg_sort {
    template<typename T>
    void InsertionSort(T *arr, int size) {
        T key; 
        int j = 0;
        for (int i = 1; i < size; i++) {
            key = arr[i];
            j = i-1;
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }  
}

#endif
