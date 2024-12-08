import itertools

def generate_hypercube_edges(vertices):
    """
    Generate edges for a k-dimensional hypercube graph.
    Vertices are represented as decimal numbers.
    """
    edges = []
    for i in range(len(vertices)):
        for j in range(i + 1, len(vertices)):
            if bin(vertices[i] ^ vertices[j]).count('1') == 1:  # Hamming distance = 1
                edges.append((vertices[i], vertices[j]))
    return edges

def binary_orientation(n, edges):
    """
    Generate binary configuration for a given integer n and edge count.
    Returns a binary string of fixed length `edges`.
    """
    binary_str = bin(n)[2:]  # Convert to binary and remove '0b' prefix
    return binary_str.zfill(edges)  # Pad with leading zeros to match edge count

def generate_digraph(edges, binary_config):
    """
    Generate adjacency matrix for a digraph based on binary configuration.
    """
    size = max(max(u, v) for u, v in edges) + 1
    matrix = [[0] * size for _ in range(size)]
    for idx, (u, v) in enumerate(edges):
        if binary_config[idx] == '0':
            matrix[u][v] = 1
        else:
            matrix[v][u] = 1
    return matrix

def has_cycle_util(graph, v, visited, stack):
    """
    Utility function to detect cycles using DFS.
    """
    visited[v] = True
    stack[v] = True
    for neighbor, edge in enumerate(graph[v]):
        if edge:
            if not visited[neighbor] and has_cycle_util(graph, neighbor, visited, stack):
                return True
            elif stack[neighbor]:
                return True
    stack[v] = False
    return False

def has_cycle(graph):
    """
    Check for cycles in a directed graph.
    """
    n = len(graph)
    visited = [False] * n
    stack = [False] * n
    for v in range(n):
        if not visited[v] and has_cycle_util(graph, v, visited, stack):
            return True
    return False

def check_transitivity(graph):
    """
    Check if the graph satisfies the transitivity property.
    """
    size = len(graph)
    for i in range(size):
        for j in range(size):
            if graph[i][j]:  # If there's a direct edge i -> j
                for k in range(size):
                    if graph[j][k] and not graph[i][k]:  # Transitivity violation
                        return False
    return True

def is_word_representable(n, edges, edges_list):
    """
    Check all possible digraph configurations for word representability.
    """
    total_configs = 2**len(edges_list)  # 2^edges configurations
    for config in range(total_configs):
        binary_config = binary_orientation(config, len(edges_list))
        digraph = generate_digraph(edges_list, binary_config)
        if not has_cycle(digraph) and check_transitivity(digraph):
            return True  # Found a word-representable configuration
    return False

def check_hypercube_word_representability(k):
    """
    Check word representability for hypercube graph of dimension k.
    """
    vertices = list(range(2**k))
    edges = generate_hypercube_edges(vertices)

    print(f"\nChecking {k}-dimensional hypercube graph:")
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")

    base_length = len(vertices)
    for length in range(1, k + 1):
        current_length = length * base_length
        print(f"Checking permutations of length {current_length}...")

        if is_word_representable(len(vertices), len(edges), edges):
            print(f"Hypercube is word-representable for permutations of length {current_length}.")
        else:
            print(f"Hypercube is NOT word-representable for permutations of length {current_length}.")

# Input the value of k
k = int(input("Enter the dimension of the hypercube (k): "))
check_hypercube_word_representability(k)
