import java.util.Arrays;

class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        int[] num1 = new int[10];
        int[] num2 = new int[10];
        Arrays.fill(num1, 0);
        Arrays.fill(num2, 0);
        
        int n = X.length(), m = Y.length();
        while (n-- > 0)
            num1[X.charAt(n) - '0']++;
        while (m-- > 0)
            num2[Y.charAt(m) - '0']++;
        
        int k = 9;
        for (; k >= 0; k--)
            if (num1[k] != 0 && num2[k] != 0)
                break;
        if (k == 0)
            return "0";
        else if (k == -1)
            return "-1";
        
        for (int i = 9; i >= 0; i--) {
            for (;num1[i] > 0 && num2[i] > 0;)
            {
                answer += i;
                num1[i]--;
                num2[i]--;
            }
        }
        
        return answer;
    }
}