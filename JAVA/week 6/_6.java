// Write a Java program to create an interface Sortable with a method sort() that sorts an array
// of integers in ascending order. Create two classes BubbleSort and SelectionSort that
// implement the Sortable interface and provide their own implementations of the sort()
// method.

interface Sortable {
    public int[] sort(int[] arr);
}

class BubbleSort implements Sortable {
    public int[] sort(int[] arr) {
        int n = arr.length;
        int temp = 0;
        for(int i=0; i < n; i++){
            for(int j=1; j < (n-i); j++){
                if(arr[j-1] > arr[j]){
                    //swap elements
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }

            }
        }
        return arr;
    }
}

class SelectionSort implements Sortable {
    public int[] sort(int[] arr) {
        int n = arr.length;
        int temp = 0;
        for(int i=0; i < n; i++){
            int min = i;
            for(int j=i+1; j < n; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        return arr;
    }
}