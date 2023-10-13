import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[sc.nextInt()];
        int sum = 0;
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextInt();
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++)
            sum += arr[i] * (arr.length - i);
        System.out.println(sum);
    }
}