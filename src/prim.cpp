#include "grafo.hpp"
#include "prim.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <cstring>

void showHelp();

int main(int argc, char **argv){
    std::map<char*,int> flags;
    std::map<char*,char*> fileFlags;
    bool printSolution = false, readFile = false, writeFile = false;
    std::ifstream fRead;

    for (int i = 0; i < argc; i++){        
        if((strcmp(argv[i], "-i") == 0) || (strcmp(argv[i], "-l") == 0)){
            flags.insert(std::pair<char*, int>(argv[i], (atoi(argv[i+1]))-1));
            i++;
        }
        else if((strcmp(argv[i], "-f") == 0) || (strcmp(argv[i], "-o") == 0)){
            fileFlags.insert(std::pair<char*, char*>(argv[i], argv[i+1]));
            i++;
        }
        else{
            flags.insert(std::pair<char*, int>(argv[i], -1));
        }
    }

    std::map<char*, int>::iterator it = flags.begin();
    std::map<char*, char*>::iterator itFRead, itFWrite;
    int second = 0, first = 0;
    for(auto i = flags.begin(); i != flags.end(); ++i){
        if((strcmp(i->first, "-h") == 0)){
            showHelp();
            return 0;
        }
        if((strcmp(i->first, "-l") == 0)){
            second = i -> second;
            it = i;
        }
        if((strcmp(i->first, "-i") == 0)){
            first = i -> second;
        }
        if((strcmp(i->first, "-s") == 0)){
            printSolution = true;
        }
    }

    for(auto i = fileFlags.begin(); i != fileFlags.end(); i++){
        if((strcmp(i->first, "-o") == 0)){
            writeFile = true;
            itFWrite = i;
        }
        if((strcmp(i->first, "-f") == 0)){
            readFile = true;
            itFRead = i;
        }
    }

    if(readFile){
        fRead.open(itFRead ->second);
        if(!fRead){
            std::cout << "Nao foi possivel ler o arquivo.\n Cheque se voce inseriu corretamente o nome do arquivo "
                      << "e tente novamente\n";
            return 1;
        }
    }else{
        std::cout << "Nenhum arquivo de entrada foi disponibilizado ao programa!\n\n"
                  << "ENCERRANDO EXECUCAO...\n";
        return 0;
    }

    int n, e;
    fRead >> n;
    fRead >> e;
    
    grafo G(n);
    

    while(fRead.is_open()){
        while(!fRead.eof()){
            int v1, v2, w;
            if(!(fRead>>v1>>v2>>w)){break;}
            
            G.setAresta(v1-1,v2-1,w);
            G.setAresta(v2-1,v1-1,w);
            //G.getAresta(v1-1, v2-1);
        }
        fRead.close();
    }

    if((strcmp(it->first, "-l") == 0)){

        if(writeFile){ 
            std::cout << "-i -l -o\n";
            prim(G, first, second, itFWrite -> second);
        }else{
            std::cout << "-i -l\n";
            prim(G, first, second);
        }
    }else{
        if(writeFile){
            if(printSolution){
                prim(G, first, printSolution, itFWrite -> second);    
            }else{
                prim(G, first, itFWrite -> second);
            }
        }else if(printSolution){
            prim(G, first, printSolution);
        }else{
            prim(G, first);
        }
    }
    
    G.~grafo();
}

void showHelp(){
        std::cout<<
        "Implementacao do algoritmo de Prim por Joao Victor Araujo\nversao 1.0\nPara utilizar o programa voce "
        << "necessita de um arquivo de entrada, caso contrario, o programa nao sera executado.\n\n"
        << "Argumentos de entrada:\n\t-h : mostra esta mensagem\n\t-o <arquivo> : redireciona a saida para o \"arquivo\""
        <<"\n\t-f <arquivo> : indica o \"arquivo\" que contem o grafo de entrada\n\t-s : mostra a solucao (neste programa, "
        <<"caso \"-s\" seja utilizado juntamente com o comando \"-l\", nao fara diferenca alguma)\n\t-i : vertice inicial"
        <<"\n\t-l : vertice final\n\n"
        <<"EXEMPLOS DE EXECUCAO:\n1)\tprim -i 1 -l 4 -f entrada.txt -o saida.txt\n"
        <<"saida:\tO resultado do programa foi salvo no arquivo \"saida.txt\"\n\n"
        <<"2)\tprim -i 1 -f entrada.txt -s\nsaida:\t(1,3) (1,4) (2,4) (3,5) (4,6)\n\n"
        <<"3)\tprim -i 1\nsaida:\tNenhum arquivo de entrada foi disponibilizado ao programa!\n\n"
        << "\tENCERRANDO EXECUCAO...\n\nNo caso 3 o comando \"-f\" nao fora explicitado, de modo que o programa "
        <<"nao conseguiu ler as entradas para construir o grafo.\n\n"
        <<"4)\tprim -i 1 -f entrada.txt -l 4\nsaida:\t2\n\n"
        <<"5)\tprim -i 1 -l 4 -f entrada.txt -s\nsaida:\t2\nNo caso 5 o comando \"-s\" fora utilizado junto do "
        <<"comando \"-l\", sendo que o comando \"-s\" gera a solucao completa do problema na saida, enquanto que "
        <<"o comando \"-l\" restringe a solucao da saida ser a distancia na AGM entre o vertice passado juntamente com "
        <<"o comando \"-i\" e o vertice passado com \"-l\" (aresta w = il), mas o comando \"-l\" tem precedencia sobre \"-s\"\n\n"
        <<"Ademais, os vertices podem ser indicados em formato de indice 1 a n, diferentemente de como indices "
        <<"sao interpretados por C e C++ (o a n-1).\nE os vertices devem ser indicados imediatamente apos \"-i\" ou \"-l\": "
        << "\"prim -i -s 1 -l -f entrada.txt 4\" nao sera executado propriamente";
    ;
    }