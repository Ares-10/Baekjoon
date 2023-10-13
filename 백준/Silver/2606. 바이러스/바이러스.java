import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static boolean computers[];
    static List<Integer> connection[];

    public static void func(int x) {
        computers[x] = true;
        for (int i : connection[x])
            if (!computers[i])
                func(i);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        computers = new boolean[sc.nextInt()];
        connection = new List[computers.length];
        int n = sc.nextInt();
        for (int i = 0; i < connection.length; i++)
            connection[i] = new ArrayList<>();
        while (n-- > 0) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            connection[a].add(b);
            connection[b].add(a);
        }
        func(0);
        int sum = -1;
        for (boolean b : computers)
            sum += b?1:0;
        System.out.println(sum);
    }
}