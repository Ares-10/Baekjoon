import java.io.*;
import java.util.StringTokenizer;
import java.lang.*;

class Main {
	
	public static int unzip(String S, int i) {
		int len = 0;
		int multi = S.charAt(i - 2) - '0';
		int count;
		while (i < S.length()) {
			if (S.charAt(i) == '(') {
				i++;
				len += unzip(S, i) - 1;
				count = 1;
				while (count > 0) {
					if (S.charAt(i) == '(')
						count++;
					else if (S.charAt(i) == ')')
						count--;
					i++;
				}
			}
			else if (S.charAt(i) == ')') {
				i++;
				break;
			}
			else {
				len++;
				i++;
			}
		}
		return len * multi;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String S = br.readLine();
		int i = 0;
		int totalLen = 0;
		int count;
		while (i < S.length()) {
			if (S.charAt(i) == '(') {
				i++;
				totalLen += unzip(S, i) - 1;
				count = 1;
				while (count > 0) {
					if (S.charAt(i) == '(')
						count++;
					else if (S.charAt(i) == ')')
						count--;
					i++;
				}
			}
			else {
				totalLen++;
				i++;
			}
		}
		System.out.print(totalLen);
	}
}