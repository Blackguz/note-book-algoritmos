// . camino vacio
// X obstaculo
// t tesoro

// ALGORITMO DFS = booleano

#include <iostream>
#include <vector>

using namespace std;


//	Direcciones posibles para moverse en el Mapa
vector <pair<int, int> > direcciones = { {0,1}, {0,-1}, {-1,0}, {1,0} };


// Retorna cierto si estoy dentro del límite del mapa, en caso contrario, retorna falso

bool limitado(vector < vector<char>>& T, int i, int j) {
	return i >= 0 and j >= 0 and i < int(T.size()) and j < int(T[0].size());
}




// Retorna true si puedo llegar a un tesoro en mi mapa desde (i,j) y false en caso contrario
// Parametros: Mapa T, posicion inicial = (i,j)

bool tesoro_dfs(vector< vector<char> >& T, int i, int j) {

	// CASOS BASE

	if (T[i][j] == 't') return true;	// si estoy en 't' retorno cierto
	if (T[i][j] == 'X') return false;	// si estoy en 'X' retorno falso


	// en caso contrario, estoy en un punto libre '.'

	T[i][j] = 'X';	// VISITADO

	// Moverme en el mapa

	for (auto& d : direcciones) {
		
		int adj_i = i + d.first;
		int adj_j = j + d.second;
		

		// (adj_i,adj_j) nueva posicion casilla
		if (limitado(T, adj_i, adj_j) and tesoro_dfs(T, adj_i, adj_j)) return true;

	}

	return false;	// No he sido capaz de llegar a ningún tesoro


}



int main() {

	int n;	// numero de filas del mapa
	int m;  // numero de columnas del mapa
	cin >> n >> m;	// leemos los valores de filas y columnas (n y m)

	vector< vector<char> > T(n, vector<char>(m));	// Declaración del mapa T

	// Inicializar matriz

	for (int i = 0; i < n; ++i) {			// Itero sobre filas con variable i
		for (int j = 0; j < m; ++j) {	// Itero sobre columnas con variable j
			cin >> T[i][j];

		}
	}

	int r;	// fila inicial en que me encuentro
	int c;	// columna inicial en que me encuentro

	cin >> r >> c;

	// output --> "yes"  /  "no"
	// matriz original -> filas = (0...n-1)  ,  columnas = (0...m-1)
	// input -> r = (1...n)   ,   c = (1...m)

	bool respuesta = tesoro_dfs(T, r-1, c-1);	// retornara true si puedo llegar a un tesoro desde (r,c)
												// en caso contrario, retornara false
										
	if (respuesta) cout << "yes";
	else cout << "no";
	cout << endl;	// salto de linea
		

}
