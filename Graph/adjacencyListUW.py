#undirected Weighted graph  representation using adjacency list

graph={}


def add_node(v):
    if v in graph:
        print(v,"already present in Graph")

    else:
        graph[v]=[]




def add_edge(v1,v2,cost):
    #chek whether nodes are present in the graph

    if v1 not in graph:
        print(v1,"not in Graph")

    elif v2 not in graph:
        print(v2,"not in graph")

    else:
        l1=[v2,cost]
        l2=[v1,cost]
        graph[v1].append(l1)
        graph[v2].append(l2)


def del_node(v):
    #del a node from the graph
    if v not in graph:
        print(v,"not present in Graph")

    else:
        #delete node
        
        graph.pop(v)
        #delete all connections
        for i in graph:
            list1=graph[i]
            for j in list1:
                if v == j[0]:
                    list1.remove(j)
                    break



def del_edge(v1,v2):
    #del edge from the graph

    if v1 not in graph:
        print(v1,"not in Graph")

    elif v2 not in graph:
        print(v2,"not in graph")

    else:
        for i in graph[v1]:
            if v2 == i[0]:
                graph[v1].remove(i)
                break

        for i in graph[v2]:
            if v1 == i[0]:
                graph[v2].remove(i)
                break

        



add_node("A")
add_node("B")
add_node("C")
add_node("D")
add_edge("A","B",10)
add_edge("C","B",10)
add_edge("C","D",10)
add_edge("A","D",10)
del_edge("A","D")

print(graph)
