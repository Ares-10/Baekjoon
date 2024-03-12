import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] st = scanner.next().split("");
        Stack<String> stack = new Stack<>();
        Map<String, Integer> map1 = new HashMap();
        Map<String, Integer> map2 = new HashMap();
        map1.put("+", 2);
        map1.put("-", 2);
        map1.put("*", 1);
        map1.put("/", 1);
        map1.put("(", 3);
        map2.put("+", 2);
        map2.put("-", 2);
        map2.put("*", 1);
        map2.put("/", 1);
        map2.put("(", 0);
        for (String str : st) {
            if (map1.containsKey(str)) {
                while (!stack.isEmpty() && map1.get(stack.peek()) <= map2.get(str))
                    System.out.print(stack.pop());
                stack.add(str);
            } else if (str.equals(")")) {
                while (!stack.peek().equals("(")) System.out.print(stack.pop());
                stack.pop();
            } else {
                System.out.print(str);
            }
        }
        while (!stack.isEmpty()) System.out.print(stack.pop());
    }
}