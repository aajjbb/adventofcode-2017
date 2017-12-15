import java.util.*;
import static java.util.stream.Collectors.toList;

public class day12 {
    public static final int MAX_NODES = 10000;
    public static boolean[] visited = new boolean[MAX_NODES];

    public static int dfs(ArrayList<ArrayList<Integer>> graph, int start) {
        int answer = 0;


        Stack<Integer> stk = new Stack<Integer>();
        stk.push(start);

        while (!stk.empty()) {
            int curr = stk.peek();
            stk.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                answer += 1;

                for (Integer next: graph.get(curr)) {
                    if (!visited[next]) {
                        stk.push(next);
                    }
                }
            }
        }

        return answer;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(MAX_NODES);


        for (int i = 0; i < MAX_NODES; i++) {
            graph.add(new ArrayList<Integer>());
        }

        while (input.hasNext()) {
            List<String> line = Arrays.asList(input.nextLine().replaceAll("[-<>,]", "").replaceAll("  ", " ").split(" "));
            List<Integer> edges = line.stream().map(Integer::parseInt).collect(toList());

            for (int i = 1; i < edges.size(); i++) {
                int a = edges.get(0);
                int b = edges.get(i);

                graph.get(a).add(b);
                graph.get(b).add(a);
            }
        }

        System.out.println(dfs(graph, 0));
    }
}
