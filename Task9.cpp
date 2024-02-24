#include <iostream>

enum Sorting {BUBBLE_SORT, SELECTION_SORT};

typedef struct 
{

    Sorting sort;
    void (*func) (int*, int);    

}SortingOption;

void bubble (int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size-1; ++j)
        {
 
            if (arr[j] > arr[j + 1])
            {
                std::swap (arr[j], arr[j+1]);
                
            }

        }
    }
}

void selection (int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int min = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min])
            {
                if (j != i)
                {
                    std::swap (arr[j], arr[i]);
                }
            }
        }
    }
}

int main ()
{
    const int size = 5;
    int arr[size] = {4, 3, 2, 1, 0};

    SortingOption sorting;
    
    int algo = 0;
    std::cout << "Choose sorting algorithm (0 for bubble, 1 for selection): ";
    std::cin >> algo;

    if (algo < 0 || algo > 1)
    {
        std::perror ("Wrong argument");
    }

    sorting.sort = static_cast<Sorting>(algo);

    switch (sorting.sort)
    {
    case BUBBLE_SORT:
        sorting.func = bubble;
        sorting.func(arr, size);
        break;

    case SELECTION_SORT:
        sorting.func = selection;
        sorting.func(arr, size);
        break;

    default:
        break;
    } 

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

}   