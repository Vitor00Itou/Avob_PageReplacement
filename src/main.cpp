#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "PageReplacement.h"

int main(int argc, char* argv[]) {
    // Verifica se o número de argumentos está correto
    if (argc > 2) {
        std::cerr << "Uso: " << argv[0] << " <caminho_da_instância>" << std::endl;
        return 1;
    }

    // Arquivo default
    std::string nameFile = "instances/instance1.txt";

    // Caso o usuário tenha passado um caminho para uma instância específica
    if (argc == 2) {
        nameFile = argv[1];
    }

    PageReplacement PRS;
    std::ifstream arquivo(nameFile);
    int numFrames;
    int pageSolicitation;
    std::vector<int> solicitations;

    if (arquivo.is_open()) {
        arquivo >> numFrames;
        while (arquivo >> pageSolicitation) {
            solicitations.push_back(pageSolicitation);
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo!" << std::endl;
        return 1;
    }

    std::cout << "FIFO " << PRS.simulateFIFO(solicitations, numFrames) << std::endl;
    std::cout << "OTM " << PRS.simulateOTM(solicitations, numFrames) << std::endl;
    std::cout << "LRU " << PRS.simulateLRU(solicitations, numFrames) << std::endl;
    
    return 0;

}