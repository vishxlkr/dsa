
void heapify(int i , int arr[], int n){

    while(true){
        int left = 2*i;
        int right = 2*i +1;

        int smallest = i ;

        if(left <= n and arr[left] < arr[smallest] ){
            smallest = left;
        }
        if(right <= n and arr[right] < arr[smallest]){
            smallest= right;
        }

        if(i!=smallest){
            swap(arr[i],arr[smallest]);
            i = smallest;
        } else{
            break;
        }
    }
}

