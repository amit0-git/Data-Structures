#undirected unweighted graph  representation using adjacency list
#0 d 30
graph={}


def add_node(v):
    if v in graph:
        print(v,"already present in Graph")

    else:
        graph[v]=[]




def add_edge(v1,v2):
    #chek whether nodes are present in the graph

    if v1 not in graph:
        print(v1,"not in Graph")

    elif v2 not in graph:
        print(v2,"not in graph")

    else:
        graph[v1].append(v2)
        graph[v2].append(v1)

     

def del_node(v):
    if v not in graph:
        print(v,"not present in Graph")

    else:
        #delete node

        graph.pop(v)
        #delete all connections
        for i in graph:
            if v in graph[i]:
                graph[i].remove(v)

    


def del_edge(v1,v2):
    #chek whether nodes are present in the graph

    if v1 not in graph:
        print(v1,"not in Graph")

    elif v2 not in graph:
        print(v2,"not in graph")

    else:
        if v2 in graph[v1]:

            graph[v1].remove(v2)
            graph[v2].remove(v1)



add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_edge("A","B")
add_edge("C","B")
add_edge("C","D")
add_edge("A","D")
#del edge

del_edge("A","D")



print(graph)
