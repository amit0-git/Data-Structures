"""
Add nodes and edges in the graph using adjacency matrix 
"""

nodes=[] #array for storing nodes
graph=[] #2d array for storing graph matrix
node_count=0 #keep count of nodes




queue=[]  #queue for graph traversal
def bfs(size,start_node):

    #visited array initialised with 0
    visited=[0]*size

    #array to store the level or distance from the source and the distance
    level=[0]*size
    

    #enque the starting node and mark as visited
    queue.append(start_node)
    visited[start_node]=1

    while(len(queue)>0):
        node=queue.pop(0)
        print(nodes[node],end=" ")

        #visit all the neighbor nodes and push unvisited in the queue and mark visited

        for i in range(0,size):

            if graph[node][i]==1 and not visited[i]:
                queue.append(i)
                visited[i]=1
                level[i]=level[node]+1




    print("\nLevel: ",level)






#dfs algorithm




def dfs(size,start_node,visited):
    #mark the current node as visited and traverse its single adjacent node 
    #repeat this untill the end 
    #backtrack and visit unvisited nodes

    visited[start_node]=1
    print(start_node)

    for i in range(size):

        if (graph[start_node][i]==1 and  visited[i]!=1):

            dfs(size,i,visited)



def print_graph():
    for i in graph:
        print(i)




def add_node(node):
    global node_count

    if node in nodes:
        print(node,"already Pesent!")
    else:
        node_count+=1
        #add node in the nodes array
        nodes.append(node)

        #add column
        for n in graph:
            n.append(0)

        #add new row in the matrix
        tmp=[]
        for i in range(node_count):
            tmp.append(0)

        graph.append(tmp)





def add_edge(v1,v2):
    #add an edge b/w two nodes
    if v1 not in nodes:
        print(v1,"not exist")

    elif v2 not in nodes:
        print(v2,"not exist")
        
    else:
        ind1=nodes.index(v1)
        ind2=nodes.index(v2)
        graph[ind1][ind2]=1
        graph[ind2][ind1]=1





def del_node(v):

    #delete node from the graph
    global node_count
    if v not in nodes:
        print(v,"not in graph")

    else:
        index1=nodes.index(v)
        node_count-=1
        nodes.remove(v)
        #del row
        graph.pop(index1)

        #del col

        for i in graph:
            i.pop(index1)





def del_edge(v1,v2):
    #delete an edge b/w two nodes
    if v1 not in nodes:
        print(v1,"not exist")

    elif v2 not in nodes:
        print(v2,"not exist")

    else:
        ind1=nodes.index(v1)
        ind2=nodes.index(v2)
        graph[ind1][ind2]=0
        graph[ind2][ind1]=0
        

add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_node("E")
add_node("F")
add_edge("A","B")
add_edge("A","C")

add_edge("B","D")
add_edge("B","E")

add_edge("C","D")
add_edge("D","E")
add_edge("E","F")
add_edge("A","F")



        



visited=[0]*node_count
dfs(node_count,0,visited)

