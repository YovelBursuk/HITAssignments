using Sorting;
using System;
using System.Windows.Forms;

namespace SortingVisualizer
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        //static void Main()
        //{
        //    int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };
        //    SortingAlgorithm s = new MergeSort();
        //    s.Sort(arr);

        //    for (int i = 0; i < arr.Length; i++)
        //    {
        //        Console.WriteLine(arr[i]);
        //    }
        //}
    }
}
