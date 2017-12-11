import java.util.*;

public class day11 {
    public static int getDist(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);

        return Math.min(x, y) + (int) Math.floor(Math.abs(x - y) / 2);
    }
    public static void main(String[] args) {
        Map<String, Integer> dx = new HashMap<String, Integer>() {{
                put("n", 0);
                put("s", 0);
                put("nw", -1);
                put("ne", +1);
                put("sw", -1);
                put("se", +1);
            }};

        Map<String, Integer> dy = new HashMap<String, Integer>() {{
                put("n", -2);
                put("s", +2);
                put("nw", -1);
                put("ne", -1);
                put("sw", +1);
                put("se", +1);
            }};

        Scanner input = new Scanner(System.in);
        String[] input_coordinates = input.nextLine().split(",");

        int x = 0;
        int y = 0;
        int ans = 0;

        for (int i = 0; i < input_coordinates.length; i++) {
            int nx = x + dx.get(input_coordinates[i]);
            int ny = y + dy.get(input_coordinates[i]);

            x = nx;
            y = ny;
        }

        System.out.println(getDist(x, y));
    }
}
