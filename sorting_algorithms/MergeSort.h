/**************************************************
 *                  MERGE SORT                    *
 *                                                *
 * Implementation of a simple ascending merge     *
 * sort algorithm. The algorithm require          *
 * copying the entire array(not in-place sort)    *
 * and it's time complexity is O(nlog(n)).        *
 **************************************************/

#ifndef ALG_SORT_MERGE_SORT_H_
#define ALG_SORT_MERGE_SORT_H_

namespace alg_sort {
    template<typename T>
    void Merge(T *A, int begin, int mid, int end) {
	    int i = 0, j = 0, A_i = 0;
	    int size_l = mid - begin + 1;
	    int size_r = end - mid;
	    T *arr_l = new T[size_l];  // Temporary left half
	    T *arr_r = new T[size_r];  // Temporary right half

	    // Copy left part of A into arr_l
	    for (i = 0; i < size_l; i++) {
		    arr_l[i] = A[begin + i];
	    }

	    // Copy right part of A into arr_r
	    for (j = 0; j < size_r; j++) {
		    arr_r[j] = A[j + mid + 1];
	    }

	    i = 0, j = 0, A_i = begin;
	    while (i < size_l && j < size_r)
	    {
		    if (arr_l[i] <= arr_r[j])
		    {
			    A[A_i] = arr_l[i];
			    i++;
		    } else {
			    A[A_i] = arr_r[j];
			    j++;
		    }
		    A_i++;
	    }

	    // Copy the remaining elements from the left temporary array into A
	    while (i < size_l)
	    {
		    A[A_i] = arr_l[i];
		    i++;
		    A_i++;
	    }

	    // Copy the remaining elements from the right temporary array into A
	    while (j < size_r)
	    {
		    A[A_i] = arr_r[j];
		    j++;
		    A_i++;
	    }
	    delete[] arr_l;
	    delete[] arr_r;
    }

    template<typename T>
    void MergeSort(T *A, int begin, int end) {
	if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(A, begin, mid);
        MergeSort(A, mid + 1, end);
        Merge(A, begin, mid, end);
    }
}

}

#endif