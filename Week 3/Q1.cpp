#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;
using namespace chrono;

namespace sort
{
    void BubbleSort(int* arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Function to merge two subarrays using a single temporary array
    void merge(int arr[], int temp[], int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= right)
        {
            temp[k++] = arr[j++];
        }
    }

    // Iterative Merge Sort Function with pointer swapping
    void MergeSort(int arr[], int n)
    {
        int* temp = new int[n];
        int* src = arr;
        int* dest = temp;

        for (int currSize = 1; currSize < n; currSize *= 2)
        {
            for (int left = 0; left < n; left += 2 * currSize)
            {
                int mid = std::min(left + currSize - 1, n - 1);
                int right = std::min(left + 2 * currSize - 1, n - 1);
                merge(src, dest, left, mid, right);
            }
            std::swap(src, dest); // Swap the pointers instead of copying elements
        }

        if (src != arr)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = src[i];
            }
        }
        delete[] temp;
    }

    void QuickSort(int* arr, int n)
    {
        using namespace std;
        stack<pair<int, int>> s;
        s.push({ 0, n - 1 });

        while (!s.empty())
        {
            int low = s.top().first;
            int high = s.top().second;

            s.pop();

            if (low >= high)
                continue;

            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++)
            {
                if (arr[j] < pivot)
                {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            int p = i + 1;

            // Push right and left subarrays to stack
            s.push({ low, p - 1 });
            s.push({ p + 1, high });
        }
    }

    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;

            // Move elements that are greater than key one position ahead
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

}

void printArray(int arr[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to generate a random array
vector<int> generate_random_array(int size)
{
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1000000);
    generate(arr.begin(), arr.end(), [&]()
        { return dist(gen); });
    return arr;
}

// Function to measure the execution time of a sorting algorithm
using SortFunction = void (*)(int*, int);

double measure_sort_time(SortFunction sort_func, int size, int trials = 3)
{
    double total_time = 0.0;
    for (int i = 0; i < trials; i++)
    {
        vector<int> arr = generate_random_array(size);
        auto start = high_resolution_clock::now();
        sort_func(arr.data(), size);
        auto end = high_resolution_clock::now();
        total_time += duration<double, milli>(end - start).count();
    }
    return total_time / trials;
}

int main()
{
    vector<SortFunction> algorithms = { sort::QuickSort, sort::MergeSort, sort::BubbleSort , sort::insertionSort};
    vector<string> algorithm_names = { "QuickSort", "MergeSort", "BubbleSort", "InsertionSort"};

    int min_size = 100;     // Minimum number of elements
    int max_size = 100000; // Maximum number of elements
    int steps = 3;         // Number of points between min and max

    ofstream file("sorting_results.csv");
    file << "Elements";
    for (const auto& name : algorithm_names)
        file << "," << name;
    file << endl;

    for (int i = 0; i <= steps; i++)
    {
        int size = min_size * pow(max_size / min_size, (double)i / steps);
        file << size;
        cout << "Testing size: " << size << endl;

        for (auto& sort_func : algorithms)
        {
            double avg_time = measure_sort_time(sort_func, size);
            file << "," << avg_time;
        }
        file << endl;
    }
    file.close();

    cout << "Results saved in sorting_results.csv" << endl;
    return 0;
}
