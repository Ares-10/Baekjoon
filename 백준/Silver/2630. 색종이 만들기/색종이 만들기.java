import java.util.Scanner;

public class Main {
    static int arr[][];
    static int blue = 0;
    static int white = 0;

    static boolean isOneColor(int x, int y, int n) {
        int color = arr[y][x];
        for (int i = y; i < y + n; i++)
            for (int j = x; j < x + n; j++)
                if (color != arr[i][j])
                    return false;
        if (color == 1) blue++;
        else white++;
        return true;
    }

    static void split(int x, int y, int n) {
        if (isOneColor(x, y, n))
            return;
        split(x, y, n / 2);
        split(x, y + n / 2, n / 2);
        split(x + n / 2, y, n / 2);
        split(x + n / 2, y + n / 2, n / 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        arr = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                arr[i][j] = sc.nextInt();
        split(0, 0, N);
        System.out.println(white);
        System.out.println(blue);
    }
}