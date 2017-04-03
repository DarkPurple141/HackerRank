#!/usr/bin/env python3

import queue

# treat each pair as an edge in the graph
# create sub connected graphs from edge list

# for each sub-graph, each node can be connected to any node in
# any other tree, but not its own.

def conns(index,g):
    # bfs
    small_graph = set()
    small_graph.add(index)
    q = queue.Queue()
    q.put(index)

    while not q.empty():
        toDo = q.get()
        small_graph.add(toDo)
        for j in g[toDo]:
            if j in small_graph:
                continue
            q.put(j)

    return small_graph

def add_pairs(index,size,connected,g,seen):
    local = conns(index,g)
    pairs = 0
    for item in local:
        seen.add(item)
        for i in range(size):
            if i in local:
                continue
            else:
                pairs+=1
    return pairs

def main():
    n, lines = map(int,input().split())

    graph = [[] for _ in range(n)]

    for _ in range(lines):
        a, b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)

    connected = 0
    seen = set()

    for i in range(n):
        if i in seen:
            continue
        connected += add_pairs(i,n,connected,graph,seen)

    print(connected//2)

if __name__ == '__main__':
    main()
