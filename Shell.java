class ShellSort {
    public void sort(int arr[]) {
        int n = arr.length;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];

                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];

                arr[j] = temp;
            }
        }
    }
}

public class Shell {
    public static void main(String[] args) {
        int arr[] = {12, 34, 54, 2, 3};
        ShellSort ss = new ShellSort();
        ss.sort(arr);

        System.out.println("Sorted array is");
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
    }
}
