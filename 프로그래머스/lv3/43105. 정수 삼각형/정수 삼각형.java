import static java.lang.Math.*;
import java.util.Arrays;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        for (int i = 0; i < triangle.length - 1; i++) {
            triangle[i + 1][0] += triangle[i][0];
            triangle[i + 1][i + 1] += triangle[i][i];
            for (int j = 1; j < triangle[i + 1].length - 1; j++) {
                triangle[i + 1][j] += max(triangle[i][j - 1], triangle[i][j]);
            }
        }
        answer = Arrays.stream(triangle[triangle.length - 1]).max().getAsInt();
        return answer;
    }
}