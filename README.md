# Mapcoloring
# Aim : Color a map such that two regions with a common border are assigned different 
Each map can be represented by a graph.
Each region of the map is represented by 
a vertex.
Edges connect two vertices if the regions 
represented by these vertices have a common
 border.
 # Algorithm  : Greedy approach
 Input: graph G (V, E).
 Output: Colored Graph with the number of colors.
 Step 1: Assign an order to the set of colors.
 Step 2: Considering the first vertex in the vertex order,
 assign to it the first color.
 Step 3: Considering the next vertex, assign to it the
 lowest-ordered color that has not already been assigned
 to a vertex adjacent to it.
 Step 4: Repeat step 3 until the graph is colored.
 # Screenshots
 ![alt text](https://i.imgur.com/lEtYVcI.png)
  ![alt text](https://i.imgur.com/rTrHP4m.png)
   ![alt text](https://i.imgur.com/DL1Ok03.png)
