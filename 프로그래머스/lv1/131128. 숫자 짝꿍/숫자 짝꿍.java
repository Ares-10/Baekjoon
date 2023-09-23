class Solution {
    public String solution(String X, String Y) {
        StringBuilder answer = new StringBuilder();
        int[] num1 = new int[10];
        int[] num2 = new int[10];
        
        for (char c : X.toCharArray()) num1[c - '0']++;
        for (char c : Y.toCharArray()) num2[c - '0']++;
        
        int k = 9;
        for (; k >= 0; k--)
            if (num1[k] != 0 && num2[k] != 0)
                break;
        if (k == 0)
            return "0";
        else if (k == -1)
            return "-1";
        
        for (int i = 9; i >= 0; i--) {
            int minCount = Math.min(num1[i], num2[i]);
            while(minCount-- > 0) {
                answer.append(i);
            }
        }
        
        return answer.toString();
    }
}