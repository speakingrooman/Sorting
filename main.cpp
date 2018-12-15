#include <iostream>
#include <fstream>
using namespace std;
int *temp;
void insertionSort(int *arr,int n)
{
    int i, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i-1;
        for (; j >= 0 && arr[j] > key; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

void Swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int *arr, int start, int end)
{
    int index = start;
    int pivot = arr[end];
    for(int i = start; i <= end - 1; i++)
        if(arr[i] <= pivot)
            Swap(arr[index++], arr[i]);
    
    Swap(arr[index], arr[end]);
    
    return index;
}

void QuickSort(int *arr, int start, int end)
{
    if(end <= start)
        return;
    
    int index = Partition(arr, start, end);
    
    QuickSort(arr, start, index - 1);
    QuickSort(arr, index + 1, end);
}

void print(int *arr,int size){
    cout<<"Sorted array size "<<size<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void originalArr(int *arr,int size){
    for(int i=0;i<size;i++){
        arr[i]=temp[i];
    }
}

void merge(int A[], int low, int high, int mid)
{
    int i, j, k,
    temp[high-low+1];
    for ( i = low, k = 0, j = mid + 1; i <= mid && j <= high; k++)
        temp[k] = A[i] < A[j] ? A[i++] : A[j++];
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];
    for (i = low; i <= high; i++)
        A[i] = temp[i-low];
}

void JazzSort(int A[], int low, int high,int size)
{
    if(size<30){
        insertionSort(A,size);
    }
    
    if (high <= low)
        return;
    int mid = (low+high)/2;
    JazzSort(A, low, mid,size);
    JazzSort(A, mid+1, high,size);
    merge(A, low, high, mid);
}

ifstream &cat(ifstream &ifs)
{
    int *array;
    int size;
    string s;
    while (getline(ifs, s))
    {
        s=s.substr(0,s.length()-1); //it will trim the last character
        size=stoi(s); //size of array
        
        array=new int[size];
        temp=new int[size];
        
        for(int i=0;i<size;i++)
            ifs>>array[i];
        
        
        for(int i=0;i<size;i++)
            temp[i]=array[i];
        
        insertionSort(array,size);
        cout<<"insertionSort"<<endl;
        print(array,size);
        cout<<endl;
        originalArr(array,size);
        
        QuickSort(array,0,size-1);
        cout<<"QuickSort"<<endl;
        print(array,size);
        cout<<endl;
        originalArr(array,size);
        
        JazzSort(array,0,size-1,size);
        cout<<"JazzSort"<<endl;
        print(array,size);
        cout<<endl;
        originalArr(array,size);
        
        
        //             cout<<"UnSorted array size "<<size<<endl;
        // for(int i=0;i<size;i++){
        //     cout<<array[i]<<" ";
        // }
        // cout<<endl;
        
        delete array;
        ifs.ignore();
        ifs.ignore();
    }
    return ifs;
}

int main()
{
    ifstream unsorted7("unsorted7.txt");
    
    if (unsorted7.fail())
        return 7;
    
    cat(unsorted7);
    unsorted7.close();
    
    return 0;
}



