#include <iostream>

using namespace std;

void PrintArr(int* arr, int S){;
    for(int i=0;i<S;i++){
        cout << '[' << arr[i] << ']';
    }
    cout << endl;
}
void Merge(int A[], int l, int c, int r){
    int sizel = c - l + 1;  //tamanho da primeira parte
    int sizer = r - c;      //tamanho da segunda parte
    int L[sizel]={};
    int R[sizer]={};

    for(int i = 0; i<sizel; i++){
        L[i] = A[l+i];//preenche a metade esquerda
    }
    for(int j = 0; j<sizer;j++){
        R[j] = A[c+j+1];//preenche a metade direita
    }
    int i=0;
    int j=0;
    int k = l;
    while(i < sizel && j < sizer){  //Arruma do menor pro maior
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while (i < sizel) {    //restante
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < sizer) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int l, int r){
    if(l<r){
        int c = (l+r)/2;
        MergeSort(arr, l, c);
        MergeSort(arr, c+1, r);
        Merge(arr, l, c, r);
    }
}
int Partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l;
    //cout << "Pivot: " << pivot << endl;
    for(int j = l; j<r; j++){
                /*//teste:
                cout << "i: " << i << endl;
                cout << "j: " << j << endl;
                PrintArr(arr,5);
                cout << "-------------------------------" << endl;*/
        if(arr[j] <= pivot){
            if(i!=j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}
void QuickSort(int arr[], int l, int r){
    if(l<=r){
        int p = Partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}
int main()
{
    int arr1[10]={1,-2,7,9,10,15,-29,30,9,10};
    int arr2[10]={-1,9,-10,0,2, 84, 57, -7, 3, 4};

    PrintArr(arr1, 10);
    MergeSort(arr1, 0, 9);
    PrintArr(arr1, 10);
    PrintArr(arr2, 10);
    QuickSort(arr2, 0, 9);
    PrintArr(arr2, 10);

    return 0;
}
