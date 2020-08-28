using System;


namespace Sorting
{
    public class BubbleSort  : SortingAlgorithm
    {
        public override void Sort(int[] items)
        {
            Reset();
            //int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };             
            for (int i = 0; i < items.Length; i++)
            {
                for (int sort = 0; sort < items.Length - 1; sort++)
                {
                    if (Compare( items[sort] , items[sort + 1] ) > 0 )
                    {
                        Swap(ref items[sort], ref items[sort+1]);                         
                    }
                }
                Console.Write("{0} ", items[i]);
            }
        }
    }
}
