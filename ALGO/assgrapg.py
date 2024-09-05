import networkx as nx
import matplotlib.pyplot as plt

# Define the graph with specified even weights
graph = {
    'A': [(2, 'B'), (4, 'C'), (6, 'D')],
    'B': [(2, 'A'), (8, 'E'), (10, 'F')],
    'C': [(4, 'A'), (12, 'G')],
    'D': [(6, 'A'), (14, 'H')],
    'E': [(8, 'B'), (10, 'F')],
    'F': [(10, 'B'), (10, 'E'), (12, 'G')],
    'G': [(12, 'C'), (12, 'F'), (16, 'H')],
    'H': [(14, 'D'), (16, 'G')],
    'I': [(6, 'J'), (10, 'K')],
    'J': [(6, 'I'), (12, 'L')],
    'K': [(10, 'I'), (14, 'M')],
    'L': [(12, 'J'), (16, 'N')],
    'M': [(14, 'K'), (18, 'O')],
    'N': [(16, 'L'), (18, 'P')],
    'O': [(18, 'M'), (20, 'Q')],
    'P': [(18, 'N'), (22, 'R')],
    'Q': [(20, 'O'), (22, 'S')],
    'R': [(22, 'P'), (24, 'T')],
    'S': [(22, 'Q'), (26, 'U')],
    'T': [(24, 'R'), (26, 'V')],
    'U': [(26, 'S'), (28, 'W')],
    'V': [(26, 'T'), (30, 'X')],
    'W': [(28, 'U'), (32, 'Y')],
    'X': [(30, 'V'), (34, 'Z')],
    'Y': [(32, 'W'), (36, 'A')],
    'Z': [(34, 'X'), (36, 'B')]
}

# Create a graph object
G = nx.Graph()

# Add nodes
for node in graph:
    G.add_node(node)

# Add edges with weights
for node, edges in graph.items():
    for weight, neighbor in edges:
        G.add_edge(node, neighbor, weight=weight)

# Draw the graph
pos = nx.spring_layout(G, seed=42)  # Position nodes using the spring layout
edge_labels = nx.get_edge_attributes(G, 'weight')

plt.figure(figsize=(14, 14))
nx.draw(G, pos, with_labels=True, node_size=700, node_color='lightblue', font_size=12, font_weight='bold', edge_color='gray')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red')

plt.title('City Graph with Even Weights')
plt.show()
