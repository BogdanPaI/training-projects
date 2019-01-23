/*****************************************************
 *                    QUICKSORT                      *
 *                                                   *
 * Implementation of ascending quicksort algorithm   *
 * with Lomuto partition scheme. This is an in-place *
 * sorting algorithm and its time complexity is      *
 * O(nlog(n)) in average or best case, but           *
 * in the worst case time complexity is O(n^2).      *
 *****************************************************/

#ifndef ALG_SORT_QUICKSORT_H_
#define ALG_SORT_QUICKSORT_H_

namespace alg_sort {
    template<typename T>
    int Partition(T *A, int begin, int end) {
        int i = begin;
        for (int j = begin; j < end; j++) {
            // A[end] is a pivot.
            if (A[j] <= A[end]) {
                T temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
            }
        }
        T temp = A[i];
        A[i] = A[end];
        A[end] = temp;
        return i;
    }

    template<typename T>
    void QuickSort(T *A, int begin, int end) {
        if (begin < end) {
            int q = Partition(A, begin, end);
            QuickSort(A, begin, q - 1);
            QuickSort(A, q + 1, end);
        }
    }

}

#endif