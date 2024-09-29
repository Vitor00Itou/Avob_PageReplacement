#include "PageReplacement.h"

PageReplacement::PageReplacement()
{

}

PageReplacement::~PageReplacement()
{

}

int PageReplacement::simulateFIFO(const std::vector<int>& pages, unsigned long numFrames)
{
    std::deque<int> frames;
    int numReplaces = 0;

    for (size_t i = 0; i < pages.size(); i++)
    {
        
        /* 
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Number:" << pages[i] << std::endl;
        for (size_t i = 0; i < frames.size(); i++)
        {
            std::cout << frames[i] << std::endl;
        }
         */

        // Verifica se a página já existe na memória
        if (std::find(frames.begin(), frames.end(), pages[i]) != frames.end())
        {
            // Caso já esteja na memória, não ha necessidade de troca
            continue;
        }

        // Verifica se ainda há espaço sobrando na mémoria
        if (frames.size() < numFrames)
        {
            // Se sim, apenas adiciona a nova página
            frames.push_back(pages[i]);
            numReplaces++;
            //std::cout << "=+1" << std::endl;
            continue;
        }

        // Caso não haja espaço, retira a mais antiga para adicionar a nova;
        frames.pop_front();
        frames.push_back(pages[i]);
        numReplaces++;
        //std::cout << "=+1" << std::endl;
        
    }

    //std::cout << "-----------------------------" << std::endl;
    return numReplaces;
    
}
int PageReplacement::simulateOTM(const std::vector<int>& pages, unsigned long numFrames)
{
    std::deque<int> frames;
    int numReplaces = 0;

    for (size_t i = 0; i < pages.size(); i++)
    {
        
/*         
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Number:" << pages[i] << std::endl;
        for (size_t i = 0; i < frames.size(); i++)
        {
            std::cout << frames[i] << std::endl;
        }
         */

        // Verifica se a página já existe na memória
        if (std::find(frames.begin(), frames.end(), pages[i]) != frames.end())
        {
            // Caso já esteja na memória, não ha necessidade de troca
            continue;
        }

        // Verifica se ainda há espaço sobrando na mémoria
        if (frames.size() < numFrames)
        {
            // Se sim, apenas adiciona a nova página
            frames.push_back(pages[i]);
            numReplaces++;
            //std::cout << "=+1" << std::endl;
            continue;
        }

        // Caso não haja espaço, olha para o futuro para ver qual vai demorar mais para adicionar
        std::deque<int> temp = frames;

        for (size_t j = i+1; j < pages.size(); j++)
        {
            // Verifica se o atual do futuro está presente na lista temporária
            if (std::find(temp.begin(), temp.end(), pages[j]) != temp.end())
            {
                // Se sim, remove da lista temporária
                temp.erase(std::remove(temp.begin(), temp.end(), pages[j]), temp.end());
                //std::cout << "retira " << pages[j] << std::endl;
            }

            // Caso só tenha sobrado 1 elemento, ele é o que vai demorar mais para aparecer
            if (temp.size() == 1)
            {
                break;
            }
            
        }

        //std::cout << "sobra " << temp[0] << std::endl;

        frames.erase(std::remove(frames.begin(), frames.end(), temp[0]), frames.end());
        frames.push_back(pages[i]);
        numReplaces++;
        //std::cout << "=+1" << std::endl;
        
    }

    //std::cout << "-----------------------------" << std::endl;
    return numReplaces;
}
int PageReplacement::simulateLRU(const std::vector<int>& pages, unsigned long numFrames)
{
    std::deque<int> frames;
    int numReplaces = 0;

    for (size_t i = 0; i < pages.size(); i++)
    {

        /*         
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Number:" << pages[i] << std::endl;
        for (size_t i = 0; i < frames.size(); i++)
        {
            std::cout << frames[i] << std::endl;
        }
         */

        // Verifica se a página já existe na memória
        if (std::find(frames.begin(), frames.end(), pages[i]) != frames.end())
        {
            // Caso já esteja na memória, não ha necessidade de troca
            continue;
        }

        // Verifica se ainda há espaço sobrando na mémoria
        if (frames.size() < numFrames)
        {
            // Se sim, apenas adiciona a nova página
            frames.push_back(pages[i]);
            numReplaces++;
            //std::cout << "=+1" << std::endl;
            continue;
        }

        // Caso não haja espaço, olha para o futuro para ver qual vai demorar mais para adicionar
        std::deque<int> temp = frames;

        for (size_t j = i-1; j >= 0; j--)
        {
            // Verifica se o atual do futuro está presente na lista temporária
            if (std::find(temp.begin(), temp.end(), pages[j]) != temp.end())
            {
                // Se sim, remove da lista temporária
                temp.erase(std::remove(temp.begin(), temp.end(), pages[j]), temp.end());
                //std::cout << "retira " << pages[j] << std::endl;
            }

            // Caso só tenha sobrado 1 elemento, ele é o que vai demorar mais para aparecer
            if (temp.size() == 1)
            {
                break;
            }
            
        }

        //std::cout << "sobra " << temp[0] << std::endl;

        frames.erase(std::remove(frames.begin(), frames.end(), temp[0]), frames.end());
        frames.push_back(pages[i]);
        numReplaces++;
        //std::cout << "=+1" << std::endl;
        
    }

    //std::cout << "-----------------------------" << std::endl;
    return numReplaces;
}