#include<stdio.h>
#include<string.h>
#define V 10
#define STR 20
#define INF 9999

char cities[V][STR];

void getCities(int num) {
	int i;
	for (i = 0 ; i < num ; i++) {
		printf("\nEnter the name of City #%d: ",i + 1);
		scanf("%s",cities[i]);
	}
	
	printf("\nCities Named!\n");
}

int minDistance(int dist[V], int visited[V], int num, int graph[V][V]) {
	int u, v, index;
	// the outer for loop has to iterate through 
	// all the vertices
	for (u = 0 ; u < num ; u++){
		// the inner loop has to iterate through all the  
		// adjacent nodes of u
		for (v = 0 ; v < num ; v++) {
			// Conditions:
			// if the node is not visited
			// if the node exists in the graph (g[u][v] == 0 
			// means that there is no edge)
			// dist of current node + weight of edge u to v is less than dist of adj node
			if (!visited[u] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
				index = v;
			}
		}
	}
	return index;
}

void showPath(int path_indices[V], int path_weights[V], int num) {
	int i;
	for (i = 0; i < num ; i++) {
		printf("%s -%d-> ",cities[path_indices[i]],path_weights[i]);
	}
	int sum = 0;
	for (i = 0 ; i < num ; i++) {
		sum += path_weights[i];
	}
	printf("\nTotal cost of construction: %d", sum);
}

int prims(int graph[V][V],int src,int num) {
	// commenting to understand my code better 
	// Initialize variables to show current path
	int path_indices[V];
	int path_weights[V];
	// To track path top
	int path_index = -1;
	// To store weights and visited
	int dist[V], visited[V];
	
	// initialize dist and visited with defaults
	int i;
	for (i = 0 ; i < num ; i++) {
		dist[i] = INF;
		visited[i] = 0;
	}
	
	// visited and distance of source
	// would be 1 and 0
	visited[src] = 1;
	dist[src] = 0;
	
	// the first node of the path is assigned as src
	path_indices[++path_index] = src;
	path_weights[path_index] = dist[src];
	
	// iterates through all the nodes
	int count;
	for (count = 0 ; count < num ; count ++) {
		// get the current local minimum distanced node index
		int u = minDistance(dist,visited,num,graph);
		// set it as visited
		visited[u] = 1;
		
		// add it to path and continue
		path_index++;
		path_indices[path_index] = u;
		path_weights[path_index] = dist[u];
	}
	
	showPath(path_indices, path_weights, num);
}

void initGraph(int graph[V][V], int num) {
	printf("\nEnter the connections of each city and their construction cost: ");
	int i;
	for (i = 0 ; i < num ; i++) {
		printf("\nEnter for city %d:\n", i);
		int j;
		for (j = 0 ; j < num ; j++) {
			printf("City %d to City %d: ", i , j);
			scanf("%d",&graph[i][j]);
		}
	}
	printf("\nCity Connections initialized!\n");
}

void showCityStructure(int graph[V][V], int num) {
	int i,j;
	for (i = 0 ; i < num ; i++) {
		printf("\n%s to",cities[i]);
		for (j = 0 ; j < num ; j++) {
			printf("\n%s with distance %d", cities[j], graph[i][j]);
		}
	}
}

void createCableNetwork(int num, int graph[V][V]) {
	int src;
	printf("\nSelect the start city: ");
	int i;
	for (i = 0; i < num ; i++) {
		printf("\n%d. %s", i, cities[i]);
	}
	printf("\nEnter your choice: ");
	scanf("%d",&src);
	
	prims(graph, src, num);
}

int main() {
	int ch = 0, num = -1, graph[V][V];
	printf("\nEnter the number of cities (<10): ");
	scanf("%d",&num);
	
	while (ch != -1) {
		printf("\nSmart City Planning: Cable Network Project");
	printf("\n-------------");
	printf("\n1. Plan for Cities");
	printf("\n2. Show City Network Structure");
	printf("\n3. Create Cable Network from City");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch (ch) {
		case 1: getCities(num);
		initGraph(graph, num);
		break;
		
		case 2: showCityStructure(graph, num);
		break;
		
		case 3: createCableNetwork(num, graph);
		break;
		
		case 4: ch = -1;
		break;
		
		default: printf("\nInvalid choice!! Please try again!");
		break;
	}
	}
}