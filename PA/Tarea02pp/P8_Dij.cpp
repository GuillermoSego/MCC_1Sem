 
# include <iostream>
# include <vector>
# include <limits>
# include <set>

const int INF = std::numeric_limits<int>::max();

int encontrarMinimoDistancia(const std::vector<int>& dist, const std::set<int>& visitados) {
    
    int minimo = INF, indiceMinimo;

    for (int v = 0; v < dist.size(); v++) {

        if (visitados.find(v) == visitados.end() && dist[v] <= minimo) {
            minimo = dist[v], indiceMinimo = v;
        }

    }

    return indiceMinimo;
}

void dijkstra(const std::vector<std::vector<int>>& grafo, int origen, int destino) {
    
    std::vector<int> dist(grafo.size(), INF);
    std::set<int> visitados;
    dist[origen] = 0;

    for (int count = 0; count < grafo.size() - 1; count++) {

        int u = encontrarMinimoDistancia(dist, visitados);
        visitados.insert(u);

        for (int v = 0; v < grafo.size(); v++) {

            if (!visitados.count(v) && grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];

            }
        }
    }

    std::cout << "La distancia más corta desde el nodo " << origen << " hasta el nodo " << destino << " es: " << dist[destino] << std::endl;

}


int main() {

    int numVertices;
    std::cout << "Ingrese el número de vértices en el grafo: ";
    std::cin >> numVertices;

    std::vector<std::vector<int>> grafo(numVertices, std::vector<int>(numVertices));
    std::cout << "Ingrese la matriz de adyacencia del grafo (use 0 para indicar que no hay conexión):" << std::endl;
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cin >> grafo[i][j];
        }
    }

    int origen, destino;
    std::cout << "Ingrese el nodo de origen: ";
    std::cin >> origen;
    std::cout << "Ingrese el nodo de destino: ";
    std::cin >> destino;

    dijkstra(grafo, origen, destino);
    return 0;
    
}
