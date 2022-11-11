#!/usr/bin/python

import sys
from heapq import heappop, heappush
from subprocess import Popen

edges = (
      'E F', 'F C',
      'D E', 'D C',
      'B C', 'A E',
      'A D', 'A B')

ordered = []


def dijkstra(adj, startnode, name):
   global ordered

   dist = {node: sys.maxint for node in adj.keys()}
   dist[startnode] = 0
   q = [(0, startnode)] 

   vis = {startnode:  1}
   par = {startnode: -1}

   cnt = 0
   while q:
      cnt += 1
      filename_dot = "%s-%d.dot" % (name, cnt)
      filename_jpg = "%s-%d.jpg" % (name, cnt)
      filename_txt = "%s-%d.txt" % (name, cnt)

      with open(filename_dot, "w") as dot, open(filename_txt, "w") as txt:

         curr = heappop(q)[1]
         vis[curr] = 1
         
         ## write to dot file
         dot.write('graph {\nrankdir=LR;\n')
         for x, y, w in ordered:
            dot.write('%s -- %s [label="%d", color="%s"]\n' \
                  % (x, y, w, "red" if vis.get(x, 0) and vis.get(y, 0) and \
                     (par.get(y, -1) == x or par.get(x, -1) == y) else "black"))

         for node in adj.keys():
            dot.write('%s [label="%s\\n%s", color="%s"]\n' \
                  % (node, node, str(dist[node]) if vis.get(node) else 'inf',
                     "red" if vis.get(node, 0) else "black"))
         dot.write("}")
         ##

         ## write to txt file
         txt.write("S = {")
         first = True
         for node in [n for n in dist.keys() if n in vis]:
            txt.write("%s{%s, %d}" % ("" if first else ", ", node, dist[node]))
            first = False 
         txt.write("}\n")

         txt.write("T = {") 
         first = True
         for node in [n for n in adj.keys() if n not in vis]:
            txt.write("%s{%s, %s}" % 
                  ("" if first else ", ", node, str(dist[node]) if dist[node] != sys.maxint else "inf"))
            first = False
         txt.write("}\n")
         ##
         
         for nxt, weight in adj[curr]:
            if dist[nxt] > dist[curr] + weight:
               dist[nxt] = dist[curr] + weight
               heappush(q, (dist[nxt], nxt))
               par[nxt] = curr


      cmd = ['dot', '-Tjpg', '-o', filename_jpg, filename_dot]
      p = Popen(cmd)
      p.wait()


def main():
   global edges, ordered

   adj = {}
   for i, w in enumerate(sys.argv[1]):
      x, y = edges[i].split()

      if x not in adj: adj[x] = []
      if y not in adj: adj[y] = []

      weight = int(w if w != '0' else '10') 
      adj[x].append((y, weight))
      adj[y].append((x, weight))

      ordered.append((x, y, weight))

   ordered = list(reversed(ordered))

   dijkstra(adj, 'A', 'A')
   dijkstra(adj, 'C', 'C')

   return 0


if __name__ == '__main__':
   sys.exit(main())
