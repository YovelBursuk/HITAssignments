using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sorting
{
    public class InsertionSort : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            int i, j, size = items.Length, key;

            for (i = 1; i < size; ++i)
            {
                key = items[i];
                j = i - 1;

                while (j >= 0 && Compare(items[j], key) > 0)
                {
                    Swap(ref items[j + 1], ref items[j]);
                    j--;
                }
                Swap(ref items[j + 1], ref key);
            }
        }
    }
}
