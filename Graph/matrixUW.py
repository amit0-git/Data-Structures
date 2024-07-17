"""
Add nodes and edges in the Undirected weighted using adjacency matrix 
"""

nodes=[] #array for storing nodes
graph=[] #2d array for storing graph matrix
node_count=0 #keep count of nodes

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


def add_edge(v1,v2,cost):
    #add an edge b/w two nodes
    if v1 not in nodes:
        print(v1,"not exist")

    elif v2 not in nodes:
        print(v2,"not exist")
        
    else:
        ind1=nodes.index(v1)
        ind2=nodes.index(v2)
        graph[ind1][ind2]=cost
        graph[ind2][ind1]=cost



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
add_edge("A","B",10)
add_edge("A","C",20)
add_edge("C","B",12)


del_edge("A","C")

print(nodes)
print_graph()

        






