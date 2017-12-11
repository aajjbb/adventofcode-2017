import collection.mutable.{ HashMap, ListBuffer, MultiMap, Set }

object day07_2 extends App {
  val lines = readInput()

  var graph = new HashMap[String, String]
  var rev_graph = new HashMap[String, Set[String]] with MultiMap[String, String]
  var nodes = ListBuffer[String]()
  var weights = new HashMap[String, Int]

  for (line <- lines) {
    val (parent, weight, children) = processLine(line)

    weights += (parent -> weight)
    nodes += parent

    if (children.size > 0) {
      for (child <- children) {
        graph += (child -> parent)
        rev_graph.addBinding(parent, child)
      }
    }
  }

  val root = dfs(nodes.head, graph)
  val (sum, diff) = findBalance(root, rev_graph, weights)

  println(diff)

  /*
   * Tranverse the Tree from root to leaves
   * Returns a tuple (Sum, Diffence)
   * Sum is the sum of the whole subtree of 'node'
   * Diffence is the largest difference betweeen the sum of 2 subtrees
   */
  def findBalance(node:    String,
                  graph:   HashMap[String, Set[String]],
                  weights: HashMap[String, Int]):
      (Int, Int) = {

    var sum = weights(node)
    var min = Int.MaxValue
    var max = 0

    var min_name = ""
    var max_name = ""

    var difference = -1
    var countSeen = HashMap[Int, Int]()

    graph.get(node) match {
      case Some(set) => {
        for (child <- set) {
          val (s, d) = findBalance(child, graph, weights)

          if (d != -1) {
            difference = d
          }

          sum += s

          if (s < min) {
            min = s
            min_name = child
          }
          if (s > max) {
            max = s
            max_name = child
          }

          if (countSeen.contains(s)) {
            countSeen(s) += 1
          } else {
            countSeen += (s -> 1)
          }

          if (difference == -1 && max - min > 0 && math.max(countSeen(min), countSeen(max)) > 1) {
            if (countSeen(max) < countSeen(min)) {
              difference = weights(max_name) - (max - min)
            } else {
              difference = weights(min_name) + (max - min)
            }
          }
        }
      }
      case None => 0
    }


    (sum, difference)
  }

  /*
   * Tranverse de Tree upwards returning the root.
   */

  def dfs(node: String, graph: HashMap[String, String]): String = {
    val next = graph.get(node)

    next match {
      case Some(value) => dfs(value, graph)
      case None => node
    }
  }

  /*
   *  Extract children programs from the line
   *  Example: "fwft (72) -> ktlj, cntj, xhth"
   *  Returns: ("fwft", [ktlj, cntj, xhth])
   */
  def processLine(line: String): (String, Int, List[String]) = {
    // filterNot removes ',' characters
    // slice takes the sublist [3, list.size - 1]
    val splitted = line.split(" ").map(
      str => str.replaceAll("[(),]", "")
    ).toList

    (splitted(0), splitted(1).toInt, splitted.slice(3, splitted.size))
  }

  /*
   *  Read all lines from StdIn recursively
   */
  def readInput(): List[String] = {
    var line = scala.io.StdIn.readLine()

    if (line == null) {
      List()
    } else {
      line :: readInput()
    }
  }
}
