using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sorting
{
    public class HeapSort : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            int n = items.Length, i;

            for (i = n / 2 - 1; i >= 0; i--)
                Heapify(items, n, i);

            for (i = n - 1; i > 0; i--)
            {
                Swap(ref items[0], ref items[i]);
                Heapify(items, i, 0);
            }
        }

        private void Heapify(int[] items, int n, int i)
        {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && Compare(items[l], items[largest]) > 0)
            {
                largest = l;
            }                

            if (r < n && Compare(items[r], items[largest]) > 0)
            {
                largest = r;
            }                

            if (largest != i)
            {
                Swap(ref items[i], ref items[largest]);
                Heapify(items, n, largest);
            }
        }
    }
}
