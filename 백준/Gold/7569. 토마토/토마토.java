import java.util.*;

class Point {
    public int x, y, z;

    Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

public class Main {
    static int[][][] arr;
    static Stack<Point> stack1;
    static Stack<Point> stack2;
    static int time = -1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt(), N = scanner.nextInt(), H = scanner.nextInt();
        arr = new int[H + 2][N + 2][M + 2];
        stack1 = new Stack<>();
        stack2 = new Stack<>();
        for (int i = 0; i < H+2; i++)
            for (int j = 0; j < N+2; j++)
                for (int k = 0; k < M+2; k++)
                    arr[i][j][k] = -1;
        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= M; k++) {
                    arr[i][j][k] = scanner.nextInt();
                    if (arr[i][j][k] == 1) stack1.add(new Point(k, j, i));
                }
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            Spread();
            time++;
        }
        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= M; k++)
                    if(arr[i][j][k]==0) {
                        System.out.println(-1);
                        return;
                    }
        System.out.println(time);
    }

    static void Spread() {
        if (!stack1.isEmpty()) {
            while (!stack1.isEmpty()) {
                Point p = stack1.pop();
                AddStack2(p.x+1, p.y, p.z);AddStack2(p.x-1, p.y, p.z);
                AddStack2(p.x, p.y+1, p.z);AddStack2(p.x, p.y-1, p.z);
                AddStack2(p.x, p.y, p.z+1);AddStack2(p.x, p.y, p.z-1);
            }
        } else {
            while (!stack2.isEmpty()) {
                Point p = stack2.pop();
                AddStack1(p.x+1, p.y, p.z);AddStack1(p.x-1, p.y, p.z);
                AddStack1(p.x, p.y+1, p.z);AddStack1(p.x, p.y-1, p.z);
                AddStack1(p.x, p.y, p.z+1);AddStack1(p.x, p.y, p.z-1);
            }
        }
    }

    static void AddStack1(int x, int y, int z) {
        if (arr[z][y][x] == 0) {
            arr[z][y][x] = 1;
            stack1.add(new Point(x, y, z));
        }
    }
    static void AddStack2(int x, int y, int z) {
        if (arr[z][y][x] == 0) {
            arr[z][y][x] = 1;
            stack2.add(new Point(x, y, z));
        }
    }
}