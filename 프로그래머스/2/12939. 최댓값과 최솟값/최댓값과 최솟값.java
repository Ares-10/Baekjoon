

import java.util.StringTokenizer;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringTokenizer st = new StringTokenizer(s, " ");
        int min = Integer.parseInt(st.nextToken());
        int max = min;
        while (st.hasMoreTokens()) {
            int n = Integer.parseInt(st.nextToken());
            min = n < min? n: min;
            max = n > max? n: max;
        }
        answer = min + " " + max;
        return answer;
    }
}