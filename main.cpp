#include <iostream>
using namespace std;

// max heap
class heap{
  public:
    int arr[100];
    int size;

  public:
    heap(){
      size = 0;
      arr[0] = -1;
    }
    void insert(int data){
      size = size + 1;
      int index = size;

      arr[index] = data;
      while(index > 1){
        int parent = index/2;
        if(arr[parent] < arr[index]){
          swap(arr[parent], arr[index]);
          index = parent;
        }
        else{
          return ;
        }
      }
    }

void print(){
      for(int i = 1; i <= size; i++){
        cout << arr[i] << " ";
      }
      cout<<endl;
    }

/*    void deleteinHeap(){
      if(size == 0){
        cout<<"Nothing to delete"<<endl;
      }
      // step 1: put last element into first index
      arr[1] = arr[size];

      // step 2: remove last element
      size--;

      // step 3: take root node to correct place
      int i = 1;
      while(i < size){
        // child compare
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if(leftIndex < size && arr[i] < arr[leftIndex]){
          swap(arr[i], arr[leftIndex]);
          i = leftIndex; 
        }

        else if (rightIndex < size && arr[i] < arr[rightIndex]){
          swap(arr[i], arr[rightIndex]);
          i = rightIndex;
        }

        else{
          return ;
        }
      }
    }    */

  void deleteinHeap(){
    if(size == 0){
      cout<<"Nothing to delete"<<endl;
      return;
    }
    // Step 1: Put last element into the root
    arr[1] = arr[size];

    // Step 2: Remove last element
    size--;

    // Step 3: Adjust the heap by comparing the root with its children
    int i = 1;
    while(i <= size){
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;
      int largest = i; // Assume the current node is the largest

      // Compare with left child
      if(leftIndex <= size && arr[leftIndex] > arr[largest])
        largest = leftIndex;

      // Compare with right child
      if(rightIndex <= size && arr[rightIndex] > arr[largest])
        largest = rightIndex;

      // If the current node is already the largest, break the loop
      if(largest == i)
        break;

      // Otherwise, swap with the largest child
      swap(arr[i], arr[largest]);
      i = largest; // Update the index to continue comparing down the heap
    }
  }    

};

void heapify(int arr[], int n, int i){
  int largest = i;

  int left = 2 * i;
  int right = 2 * i + 1;

  if(left <= n && arr[largest] < arr[left]){
    largest = left;
  }
  if(right <= n && arr[largest] < arr[right]){
    largest = right;
  }
  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n){
  int size = n;
  
  while(size > 1){
    swap(arr[1], arr[size]);
    size--;
    heapify(arr, size, 1);
  }
  
}

int main() {
  heap h1;
  h1.insert(50);
  h1.insert(55);
  h1.insert(53);
  h1.insert(52);
  h1.insert(54);
  h1.insert(56);
  h1.print();

  h1.deleteinHeap();
  h1.print();
  h1.deleteinHeap();
  h1.print();

  int arr[6] = { -1, 54, 53, 55, 52, 50 };
  int n = 5;
  for(int i = n/2; i > 0; i--){
    heapify(arr, n, i);
  }
  cout<<"Printing the array now"<<endl;
  for(int i = 1; i <= n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  heapSort(arr, n);
  cout<<"Printing the sorted array now"<<endl;
  for(int i = 1; i <= n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}