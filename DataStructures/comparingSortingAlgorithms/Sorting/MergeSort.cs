using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sorting
{
    public class MergeSort : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            Sort(items, 0, items.Length - 1);
        }

        private void Sort(int[] items, int left, int right)
        {
            if (left < right)
            {
                int middle = (left + right) / 2;
                Sort(items, left, middle);
                Sort(items, middle + 1, right);
                Merge(items, left, middle, right);
            }
        }

        private void Merge(int[] arr, int left, int middle, int right)
        {
            int leftArraySize = middle - left + 1;
            int rightArraySize = right - middle;
            int i, j;
            int k = left;

            int[] L = new int[leftArraySize];
            int[] R = new int[rightArraySize];

            for (i = 0; i < leftArraySize; ++i)
            {
                Swap(ref L[i], ref arr[left + i]);
            }

            for (j = 0; j < rightArraySize; ++j)
            {
                Swap(ref R[j], ref arr[middle + 1 + j]);
            }

            i = 0;
            j = 0;

            while (Compare(i, leftArraySize) < 0 && Compare(j, rightArraySize) < 0)
            {
                if (Compare(L[i], R[j]) <= 0)
                {
                    Swap(ref arr[k++], ref L[i++]);
                }
                else
                {
                    Swap(ref arr[k++], ref R[j++]);
                }
            }

            while (Compare(i, leftArraySize) < 0)
            {
                Swap(ref arr[k++], ref L[i++]);
            }

            while (Compare(j, rightArraySize) < 0)
            {
                Swap(ref arr[k++], ref R[j++]);
            }
        }
    }
}
