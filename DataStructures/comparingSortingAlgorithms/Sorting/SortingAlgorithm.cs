using System;

namespace Sorting
{
    public abstract class SortingAlgorithm
    {
        public long Comparisons { get; set; }
        public long Swaps { get; set; }
        
        protected void Reset()
        {
            Comparisons = 0; Swaps = 0;
        }

        public abstract void Sort (int [] items);
        public void Swap(ref int d1, ref int d2)
        {
            Swaps++;
            int temp;
            temp = d1;
            d1 = d2;
            d2 = temp;
        }

        public int Compare(object x, object y)
        {
            Comparisons++;
            if (int.Parse(x.ToString()) > int.Parse(y.ToString()))
                return 1;
            if (int.Parse(x.ToString()) < int.Parse(y.ToString()))
                return -1;
            return 0;
        }

    }
}
