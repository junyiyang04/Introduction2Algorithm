#include "chapter1.h"


// merge
template <typename T>
void merge(T* A, int p , int q, int r)
{
    // copy the value from A to [p-q] and [q-r]
    int l_len = q - p + 1;
    int r_len = r - q;
    T* left = new T[l_len];
    T* right = new T[r_len];
    for(int i = 0; i < l_len; i++){
        left[i] = A[p + i];
    }
    for(int i = 0; i < r_len; i++){
        right[i] = A[q + i + 1];
    }

    // sort ordered array 
    int l_cnt = 0;
    int r_cnt = 0;
    for(int i = 0; i < r - p + 1; i++){
        if(l_cnt < l_len && r_cnt < r_len){ 
            if(left[l_cnt] < right[r_cnt]){
                A[p + i] = left[l_cnt++];
            }
            else if(r_cnt < r_len){
                A[p + i] = right[r_cnt++];
            }            
        }
        else{ // put left number in array
            if(l_cnt < l_len){
                A[p + i] = left[l_cnt++];
            }
            else{
                A[p + i] = right[r_cnt++];
            }
        }
    }
    delete [] right;
    delete [] left;
}

int layer_cnt = 0;

// mergre sort 
template <typename T>
void mergeSort(T* A, int p, int r)
{
    int q = p + (r - p) / 2; // split into longer former array and shorter latter array
    for(int i = 0; i < layer_cnt + 1; i++) 
    {
        std::cout << "===";
    }
    std::cout << "layer_cnt: " << layer_cnt << std::endl;
    if(r - p > 1)
    {
        layer_cnt++;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);        
        layer_cnt--;
    }
    std::cout << "[p, q, r] = [" << p << ", " << q << ", " << r << "]" << std::endl;
    merge(A, p, q, r);
    for(int i = p; i <= r; i++)
    {
        std::cout << A[i] << ",";
    }
    std::cout << std::endl;
    for(int i = 0; i < layer_cnt + 1; i++) 
    {
        std::cout << "+++";
    }
    std::cout << "layer_cnt: " << layer_cnt << std::endl;
}

void callMergeSort() // template function need implement
{
    int size = 50;
    float* array = new float[size];
    for(int i = 0; i < size; i++)
    {
        if(i < (size + 1) / 2)
            array[i] = 8 - i;
        else
            array[i] = i;
        std::cout << array[i] << std::endl;
    }
    mergeSort(&(*array), 0, size - 1);
    for(int i  = 0; i < size; i++)
    {
        std::cout << i << " sorted: " << array[i] << std::endl;
    }
    delete [] array;
}