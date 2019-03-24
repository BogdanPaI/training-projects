/**************************************************
 *                   SHELL SORT                   *
 *                                                *
 * Implementation of an ascending shell sort      *
 * algorithm. The algorithm doesn't require       *
 * copying the entire array(in-place sort).       *
 *                                                *
 * For more info see:                             *
 *    https://en.wikipedia.org/wiki/Shellsort     *
 **************************************************/
#ifndef ALG_SORT_SHELL_SORT
#define ALG_SORT_SHELL_SORT

namespace alg_sort {
    template<typename T>
        void ShellSort(T *arr, size_t size) {
            int h = 1;
                 
            while (h < size / 3) { 
                // Compute the gap
                h = 3 * h + 1;
            }

            while (h >= 1) {
                // Insertion sort with "h"
                for (size_t i = h; i < size; i++) {
                    for (size_t j = i; j >= h && arr[j] <= arr[j - h]; j -= h) {
                        T swap = arr[j];
                        arr[j] = arr[j - h];
                        arr[j - h] = swap;
                    }
                }
                h = h / 3;
            }
        }
}

#endif
