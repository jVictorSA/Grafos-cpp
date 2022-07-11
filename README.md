# Grafos-cpp
Implementação de alguns algoritmos de processamento de grafos em C++, para a disciplina de Teoria dos Grafos.</br></br>
Cada algoritmo está presente em sua respectiva pasta e.g. o algoritmo de Dijkstra está na pasta "dijkstra".</br></br>
Para compilar um algoritmo, entre na respectiva pasta e execute o comando:
````
make all
````
E o algoritmo será compilado em um executável .exe.</br></br>
Por padrão o compilador utilizado é o Clang++, cas deseje utilizar o g++, execute:
````
make all CC=g++
````
Todo algoritmo precisa de um arquivo de entrada para ser executado. O arquivo deve seguir este formato:
````
<n = numero de vértices> <e = números de arestas>
(por e vezes):
<vértice 1> <vértice 2> <peso da aresta>
````
Caso não tenha ficado claro, olhe pelos arquivos "entrada.txt" presentes nas pastas dos algoritmos.</br></br>
Caso o arquivo de entrada não esteja em conformidade com o padrão exposto, os algoritmos não funcionarão corretamente.</br></br>
Cada algoritmo possui uma função de ajuda denotada por
````
<nome do algoritmo> -h
````
que elucida os parâmetros de entrada do algoritmo e alguns casos de execução (correta e incorreta), a fim de auxiliar o uso dos programas.
