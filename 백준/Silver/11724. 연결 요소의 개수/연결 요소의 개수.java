import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static boolean booleans[];
    static List<Integer> connection[];

    public static void func(int x) {
        booleans[x] = true;
        for (int i : connection[x])
            if (!booleans[i])
                func(i);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        booleans = new boolean[sc.nextInt()];
        connection = new List[booleans.length];
        int n = sc.nextInt();
        for (int i = 0; i < connection.length; i++)
            connection[i] = new ArrayList<>();
        while (n-- > 0) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            connection[a].add(b);
            connection[b].add(a);
        }
        int count = 0;
        for (int i = 0; i < booleans.length; i++) {
            if (!booleans[i]) {
                func(i);
                count++;
            }
        }
        System.out.println(count);
    }
}