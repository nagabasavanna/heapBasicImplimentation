#include<iostream>//it also does heapsort
#include<vector>
using namespace std;

class MaxHeap{
 public:
    vector<int> heapp;    //using vector
    //int *heapp;          //using dynamic arr
    int capacity;
    int size;
    

    MaxHeap(int cap){
        capacity=cap;
       // heapp = new int[capacity]; //using array
        heapp.resize(cap);  //using vector
        size=0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return i*2+1;
    }
    int rightChild(int i){
        return i*2+2;
    }
    bool isFull(){
        return size>=capacity;
    }

    bool isEmpty(){
        return size<=0;
    }

    void Insert(int x);//takes O(logn) time complexity as it need to rearrange heap

    void heapifyUp(int i);

    int getMax();//takes O(1) just to return root of heap

   
    int extractMax();//takes O(logn)
//these 2 functions are enough to heapsort by taking direct array input
//and heapifying from n/2-1 to 0th index 
    void heapifyDown(int i);//takes O(logn)


    void Printheap();//n(logn)

    void heapSort();
};

void MaxHeap::Insert(int x){
    if(isFull()){
        cout<<"couldn't insert "<<x<<"\nheap is full or some unexpected error occured"<<endl;
        return;
    }
    int i= size;
     size++;
    // cout<<"size = "<<size<<"\ni = "<<i;//to check error
    heapp[i]=x;
    cout<<"element inserted is: "<<heapp[i]<<endl;
    heapifyUp(i);
}

void MaxHeap::heapifyUp(int i){
    //cout<<"\n index is"<<i<<endl;//to check error
    if(i==0){
        return;
    }
    if(heapp[i]<heapp[parent(i)]){
        return;
    }
    if(heapp[i]>heapp[parent(i)]){
        swap(heapp[i],heapp[parent(i)]);
        i=parent(i);
    }
    heapifyUp(i);
    return;
}
//extractMax deletes top(max element),returns it and swaps with last element in tree
//to maintain complete binary tree property
int MaxHeap::extractMax(){
    if(isEmpty()){
        cout<<"already empty\n";
        return -1;
    }
    int top=heapp[0];
    swap(heapp[0],heapp[size-1]);
    // cout<<"heap top "<<heapp[0]<<"last element in array "<<heapp[3];
    size--;
    heapifyDown(0);
    return top;
}

//shiftdown is common function known as heapify
void MaxHeap::heapifyDown(int i){
    if(isEmpty() or i>=size/2 or size==1  ){
    //above i>=size/2 tells whether node i has child or not (important)
        return;
    }
    
    int swapId=i;
    if(leftChild(i)<size-1 and heapp[leftChild(i)]>heapp[i]){
       swapId=leftChild(i);
    }
    if(rightChild(i)<size-1 and heapp[rightChild(i)]>heapp[swapId]){
        swapId=rightChild(i);
    }
    
    if(swapId!=i){  
    swap(heapp[i],heapp[swapId]);
    i=swapId;
    heapifyDown(i); }
    return;
}

int MaxHeap::getMax(){
    if(isEmpty()){
        cout<<"heap empty\n";
        return -1;
    }
    return heapp[0];
}

void MaxHeap::Printheap(){
    if(isEmpty()){
        cout<<"heap empty\n";
        return;
    }
     
     cout<<"max heap in order"<<endl;
    for(int i=0;i<size;i++){
        cout<<heapp[i]<<" ";
    }
}

void MaxHeap::heapSort(){//heapsorting through this function and printing it
    for (int i = 0; i < capacity-1; i++)
    {
        extractMax();
    }
    cout<<"\nheapsorted list\n";
    for (int i = 0; i < capacity; i++)
    {
        cout<<heapp[i]<<" ";
    }
    }

int main(){
    MaxHeap h(10);
            cout<<"enter elements :";
            for(int i=0;i<10;i++){ 
            int a;
            cin>> a;
                h.Insert(a);
        }
                                   // h.heapp{2,35,3,5,6,7,44,1,55,0};
                                    //I should consider basics of cpp to deal with arrays and vectors
        
    h.Printheap();
   
   
    h.heapSort();
    return 0;
}