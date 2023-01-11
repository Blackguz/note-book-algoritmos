// IMPLEMENTACIÓN DE UN GRAFO EN PROGRAMACIÓN
#include <iostream>
#include <vector>


using namespace std;






int main() {

	int n;	// numero de vertices (filas en mi matriz)
	int m;  // numero de aristas de mi grafo


	cin >> n >> m;

	// Declarar la Matriz de Adyacencia

	vector< vector<int> > G(n);	// grafo G

	// Leer el Grafo por la Consola


	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;	// Leo arista (x,y) del grafo

		G[x].push_back(y);	// Voy a la fila x e introduzco el vertice y
		G[y].push_back(x);	// Voy a la fila y e introduzco el vertice x

	}

	// Imprimir el Grafo G por la Consola

	for (int i = 0; i < n; ++i) {
		cout << "Vertices adyacentes a " << i << ": ";
		for (int j = 0; j < G[i].size(); ++j) cout << G[i][j] << ' ';
		cout << endl;
	}




}
