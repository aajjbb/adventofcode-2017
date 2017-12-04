import java.util.*;

public class day04 {
    public static boolean isValid(String[] tokens) {
        HashMap<String, Boolean> map = new HashMap<>();

        for (String s: tokens) {
            if (map.containsKey(s)) {
                return false;
            }
            map.put(s, true);
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int answer = 0;

        while (input.hasNext()) {
            String[] tokens = input.nextLine().split(" ");

            if (isValid(tokens)) {
                answer += 1;
            }
        }

        System.out.println(answer);
    }
}
