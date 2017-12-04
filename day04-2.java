import java.util.*;

public class day04-2 {
    public static boolean isValid(String[] tokens) {
        HashMap<String, Boolean> map = new HashMap<>();

        for (String s: tokens) {
            char[] as_array = s.toCharArray();
            Arrays.sort(as_array);
            String sorted = new String(as_array);

            if (map.containsKey(sorted)) {
                return false;
            }
            map.put(sorted, true);
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
