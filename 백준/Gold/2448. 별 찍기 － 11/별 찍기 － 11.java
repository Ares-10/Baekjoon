import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[][] arr = new char[n + 1][2 * n];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(arr[i], ' ');
            for (int j = n - i + 1; j <= n + i - 1; j++) {
                arr[i][j-1] = '*';
            }
        }

        rmStar(arr, n, n, n / 3 * 2);

        for (int i = 1; i < n + 1; i++) {

            System.out.println(arr[i]);
        }
    }

    public static void rmStar(char arr[][], int n, int x, int y) {
        if (n < 3) return;
        if (n == 3) {
            for (int i = 0; i <= n / 3; i++) {
                for (int j = -n / 2 + (i + 1); j <= n / 2 - (i + 1); j++) {
                    arr[y + i][x + j-1] = ' ';
                }
            }
        } else
            for (int i = -n / 6 + 1; i <= n / 3; i++) {
                for (int j = -n / 2 + (i + n / 6); j <= n / 2 - (i + n / 6); j++) {
                    arr[y + i][x + j-1] = ' ';
                }
            }

        rmStar(arr, n / 2, x, y - n / 3);
        rmStar(arr, n / 2, x + n / 2, y + n / 6);
        rmStar(arr, n / 2, x - n / 2, y + n / 6);
    }
}