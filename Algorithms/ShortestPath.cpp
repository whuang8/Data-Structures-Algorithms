#define MaxVertices 50
void shortest_path(int v, int n, 
					int weight[MaxVertices][MaxVertices],
					int aDistance[MaxVertices],
					int parent[MaxVertices]){

	int i;

	int *visited = new int[n];

	int MaxDistance = 1000000000;
	for (int i = 0; i < n; i++){
		aDistance[i] = MaxDistance;
		visited[i] = 0;
	}
	aDistance[v] = 0;

	parent[v] = v;

	while(1){
		int u = -1;
		for (int i = 0; i < n; i++){
			if (!visited[i]){
				if (u < 0 || aDistance[i] < aDistance[u])
				{
					u = i;
				}
			}
		}
		if(u == -1){
			return;
		}
		visited[u] = 1;
		int z;
		for(z = 0; z < n; z++){
			if (weight[u][z]){
				if (aDistance[z] > aDistance[u] + weight[u][z])
				{
					aDistance[z] = aDistance[u] + weight[u][z];
					parent[z] = u;
				}
			}
		}
	}
}