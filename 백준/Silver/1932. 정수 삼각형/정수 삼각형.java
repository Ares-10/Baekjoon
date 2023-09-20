import java.util.*;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int answer = 0;
        int triangle[][] = new int[sc.nextInt()][];
        for (int i = 0; i < triangle.length; i++) {
            triangle[i] = new int[i + 1];
            for (int j = 0; j <= i; j++)
                triangle[i][j] = sc.nextInt();
        }

        for (int i = 0; i < triangle.length - 1; i++) {
            triangle[i + 1][0] += triangle[i][0];
            triangle[i + 1][i + 1] += triangle[i][i];
            for (int j = 1; j < triangle[i + 1].length - 1; j++) {
                triangle[i + 1][j] += max(triangle[i][j - 1], triangle[i][j]);
            }
        }
        answer = Arrays.stream(triangle[triangle.length - 1]).max().getAsInt();

        System.out.print(answer);
    }
}