import numpy as np
from math import inf
from copy import deepcopy

# class GraphNode(object):
# 	"""docstring for GraphNode"""
# 	def __init__(self, arg):
# 		self.arg = arg
# 		

class UndirectedGraph():
	def __init__(self,type = 'matrix'):
		self.type = type
		self.g = []
		self.N = 0
		self.nodes = {}

	def add_node(self, label, value):
		self.N += 1
		if label in self.nodes:
			print("Duplicate label")
			exit(0)
		self.nodes[label] = [self.N-1,value]
		for el in self.g:
			el.append(inf)

		self.g.append([inf]*(self.N))

	def add_edge(self, n1, n2, w):
		"""O(V^2)"""
		n1_pos = self.nodes[n1][0]
		n2_pos = self.nodes[n2][0]

		self.g[n1_pos][n2_pos] = w
		self.g[n2_pos][n1_pos] = w

	def __str__(self):
		str_rep = ""
		for el in self.g:
			str_rep += str(el) + "\n"

		return str_rep.strip("\n")


	def dijkstra(self, origin_label):
		origin_pos = self.nodes[origin_label][0]
		distances = [ inf if label != origin_label else 0 for label in self.nodes]

		# Being a bit sloppy here mixing between labels and positions, will come back to tidy at some point - trying to have cake and eat it too!
		heap = sorted([ [inf, self.nodes[label][0] ] if label != origin_label else [0,origin_pos] for label in self.nodes]) # upgrade to binary/fib heap later

		while len(heap) > 0:
			# get node with lowest distance
			heap = sorted(heap)
			current_dist, current_node = heap.pop()

			# get nodes connected to current node
			current_connections = self.g[current_node]
			for i in range(len(current_connections)):
				if current_connections[i] < inf:
					if (i != current_node) and (distances[current_node] + current_connections[i] < distances[i]):
						distances[i] = distances[current_node] + current_connections[i]
						heap.append([distances[i],i])
			print(heap)
		print(distances)

graph = UndirectedGraph()
graph.add_node('A',0)
graph.add_node('B',0)
graph.add_node('C',0)
graph.add_node('D',0)

graph.add_edge('A','B',1)
graph.add_edge('A','C',3)

graph.add_edge('B','C',1)
graph.add_edge('B','D',4)

graph.add_edge('C','D',2)

print(graph)
print()
graph.dijkstra('A')