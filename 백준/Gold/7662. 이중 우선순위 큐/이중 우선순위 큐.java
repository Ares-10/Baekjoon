import java.util.*;

public class Main {
    public static void main(String[] args) {
        TreeMap<Integer, Integer> map = new TreeMap();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            int M = scanner.nextInt();
            for (int j = 0; j < M; j++) {
                if (scanner.next().equals("I")) {
                    int n = scanner.nextInt();
                    if (map.containsKey(n)) map.replace(n, map.get(n) + 1);
                    else map.put(n, 1);
                } else if (!map.isEmpty()) {
                    int n = (scanner.nextInt() == 1) ? map.lastKey(): map.firstKey();
                    if (map.containsKey(n)) {
                        map.replace(n, map.get(n) - 1);
                        if (map.get(n) == 0)
                            map.remove(n);

                    }
                }
                else scanner.next();
            }
            if (map.isEmpty()) System.out.println("EMPTY");
            else System.out.println(map.lastKey()+ " " + map.firstKey());
            map.clear();
        }
    }
}