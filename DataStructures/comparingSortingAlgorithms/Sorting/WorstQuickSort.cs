﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sorting
{
    public class WorstQuickSort : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            QuickSort(items, 0, items.Length - 1);
        }

        private void QuickSort(int[] items, int low, int high)
        {
            if (low < high)
            {
                int pivot = Partition(items, low, high);

                QuickSort(items, low, pivot - 1);
                QuickSort(items, pivot + 1, high);
            }
        }

        private int Partition(int[] items, int low, int high)
        {
            int pivot = items[high], i = low - 1, j;

            for (j = low; j < high; j++)
            {
                if (Compare(items[j], pivot) < 0)
                {
                    Swap(ref items[++i], ref items[j]);
                }
            }

            Swap(ref items[i + 1], ref items[high]);
      
            return i + 1;
        }
    }
}
