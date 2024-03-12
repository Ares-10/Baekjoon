import java.util.*;

class Point {
    public int x, y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int[][] arr;
    static Stack<Point> stack1;
    static Stack<Point> stack2;
    static int time = -1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt(), N = scanner.nextInt();
        arr = new int[N + 2][M + 2];
        stack1 = new Stack<>();
        stack2 = new Stack<>();
        for (int j = 0; j < N + 2; j++)
            for (int k = 0; k < M + 2; k++)
                arr[j][k] = -1;
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= M; k++) {
                arr[j][k] = scanner.nextInt();
                if (arr[j][k] == 1) stack1.add(new Point(k, j));
            }
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            Spread();
            time++;
        }

        // 남은 토마토가 있는지 검사
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= M; k++)
                if (arr[j][k] == 0) {
                    System.out.println(-1);
                    return;
                }
        System.out.println(time);
    }

    static void Spread() {
        if (!stack1.isEmpty()) {
            while (!stack1.isEmpty()) {
                Point p = stack1.pop();
                AddStack2(p.x + 1, p.y);
                AddStack2(p.x - 1, p.y);
                AddStack2(p.x, p.y + 1);
                AddStack2(p.x, p.y - 1);
            }
        } else {
            while (!stack2.isEmpty()) {
                Point p = stack2.pop();
                AddStack1(p.x + 1, p.y);
                AddStack1(p.x - 1, p.y);
                AddStack1(p.x, p.y + 1);
                AddStack1(p.x, p.y - 1);
            }
        }
    }

    static void AddStack1(int x, int y) {
        if (arr[y][x] == 0) {
            arr[y][x] = 1;
            stack1.add(new Point(x, y));
        }
    }

    static void AddStack2(int x, int y) {
        if (arr[y][x] == 0) {
            arr[y][x] = 1;
            stack2.add(new Point(x, y));
        }
    }
}