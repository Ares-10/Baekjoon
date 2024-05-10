import java.io.*;
import java.util.StringTokenizer;
import java.lang.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int	H = Integer.parseInt(st.nextToken());
		int	W = Integer.parseInt(st.nextToken());
		int arr[] = new int[W];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < W; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		if (W == 1) {
			System.out.print(0);
			return;
		}
		
		int leftAscendingStep[] = new int[W];
		for (int i = 0, leftHigh = 0; i < W; i++) {
			leftHigh = Math.max(leftHigh, arr[i]);
			leftAscendingStep[i] = leftHigh;
		}
		int rightAscendingStep[] = new int[W];
		for (int i = W - 1, rightHigh = 0; i >= 0; i--) {
			rightHigh = Math.max(rightHigh, arr[i]);
			rightAscendingStep[i] = rightHigh;
		}
		
		int	totalArea = 0;
		for (int i = 0; i < W; i++) {
			totalArea += Math.min(leftAscendingStep[i], rightAscendingStep[i]) - arr[i];
		}
		System.out.print(totalArea);
	}
}