class Solution {
    public int solution(int n) {
        n -= n % 2;
        return (n + 2) * (n / 2) / 2;
    }
}