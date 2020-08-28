using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sorting
{
    public class SelectionSort : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            int size = items.Length, i, j, minIndex;

            for (i = 0; i < size - 1; i++)
            {
                minIndex = i;
                for (j = i + 1; j < size; j++)
                    if (Compare(items[j], items[minIndex]) < 0)
                        minIndex = j;

                Swap(ref items[minIndex], ref items[i]);
            }
        }
    }
}
