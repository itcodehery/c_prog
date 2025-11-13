class Node:
    def __init__(self,name):
        self.name = name
        self.distance_from_source = 999
        self.is_visited = False

class Edge:
    def __init__(self,source,weight,dest):
        self.source = source
        self.weight = weight
        self.dest = dest

def main():
    a = Node('A')
    b = Node('B')
    c = Node('C')
    d = Node('D')
    e = Node('E')

    e1 = Edge(a, 10, b)
    e2 = Edge(a, 7, c)
    e3 = Edge(b, 9, c)
    e4 = Edge(c, 5, d)
    e5 = Edge(d, 11, e)

    list_of_edges = [e1, e2, e3, e4, e5]
    for i in list_of_edges: 
        print(f"{i.source.name} -{i.weight} -> {i.dest.name}")


if __name__ == "__main__":
    main()
