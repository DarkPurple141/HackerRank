#!/usr/bin/env python3

"""
You are given a tree (a simple connected graph with no cycles).
The tree has n nodes numbered from 1 to n and is rooted at node 1.
Find the maximum number of edges you can remove from the tree to get a forest /
/ such that each connected component of the forest contains an even number of vertices.


"""

def clean(a):
    return (int(a)-1)

def connected(Node):
    if Node.nedges < 1:
        return 0

    seen = []
    removes = 0
    for i,n in enumerate(Node.edges):
        if n:
             seen.append(i)

    for i in seen:
        if nodes[i].nedges > 1 and nodes[i].nedges != 4:
            nodes[i].remove_edge(Node.id)
            Node.remove_edge(i)
            removes += 1

    return removes

class Node:
    def __init__(self, vertices, ide):
        self.edges = [0]*vertices
        self.nedges = 0
        self.id = ide

    def add_edge(self,other):
        self.edges[other] = 1
        self.nedges += 1

    def remove_edge(self,other):
        self.edges[other] = 0
        self.nedges -= 1

n, m = map(int,input().split())

nodes = [0]*n

# make graph
for _ in range(m):
    a, b = map(clean,input().split())
    if not nodes[a]:
        nodes[a] = Node(n,a)

    nodes[a].add_edge(b)

    if not nodes[b]:
        nodes[b] = Node(n,b)

    nodes[b].add_edge(a)

removes = 0

for i in nodes:
    removes += connected(i)

print(removes)
