# Comparing Sorting Algorithms

## Description
This project is all about comparing different sorting algorithms.

We would see diffrences by given form and given paramaters at a specific graph.

## How to use
1. Run project
2. Select number of elements of the array
3. Select type of array elements
    * Random
    * Sorted
    * Reversed
4. Select type of required visualization
    * Comparations made
    * Swaps made   
5. Click execute button

All supported sorts will be run with given paramaters and then a comparing graph will apear where x axis is the algorithm and y axis is number of actions (comparations/ swaps).

## Adding another sorting algorithm
First, Add a new class that extends the class **SortingAlgorithm**.    
Second, Implement the abstract function **Sort**.  
Third, Add an instance of the new class at **Form1** at lin **84**.

**Do not override functions Swap and Compare**

**Make sure to call Reset function before the actual sort function**

**Make sure to use functions Swap and Compare where necessary so the graph will have data to show...**
