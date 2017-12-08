import collection.mutable.{ HashMap, ListBuffer }

object day07 extends App {
  val lines = readInput()

  var graph = new HashMap[String, String]
  var nodes = ListBuffer[String]()

  for (line <- lines) {
    val (root, children) = processLine(line)

    nodes += root

    if (children.size > 0) {
      for (child <- children) {
        graph += (child -> root)
      }
    }
  }

  println(dfs(nodes.head, graph))

  /*
   * Tranverse de Tree looking for the root.
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
  def processLine(line: String): (String, List[String]) = {
    // filterNot removes ',' characters
    // slice takes the sublist [3, list.size - 1]
    val splitted = line.split(" ").map(
      str => str.replaceAll(",", "")
    ).toList

    (splitted.head, splitted.slice(3, splitted.size))
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
