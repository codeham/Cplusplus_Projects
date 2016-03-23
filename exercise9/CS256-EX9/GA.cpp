#include "Chromosome.h"
//Global Target String
std::string target ="";

bool sort(const Chromosome& a, const Chromosome b, std::string target){
    return a.fitness(target) < b.fitness(target);
}

auto bots = [](const Chromosome& a, const Chromosome& b) {
    return sort(a,b, target);
};

Chromosome randomChromosome(int size)
{
    std::ostringstream sout;
    for (int i = 0; i < size; i++)
    {
        sout << (char) ((rand() % 26) + 97);
    }
    return Chromosome(sout.str());
}

Chromosome runGA(std::string target, int popSize, double mr, double cr)
{
    std::vector<Chromosome> chromosome;
    int fitness = 1;
    
    for(int i = 0; i < popSize; i++){
        //Adding to vector....
        chromosome.push_back(randomChromosome(target.size()));
    }
    
    while(fitness != 0){
        //fitness does not reach best fitness 0
        std::vector<Chromosome> chromosome2;
        
        int count = 0;
        int newPop = popSize*2;

        while(count <= newPop){
            //Random mutation  
            Chromosome x = chromosome[0];

            double mutateProb = (rand() % 101);
            int index = rand() % popSize;
            
            if(mutateProb <= mr){
                //call mutation
                x = chromosome[index].mutate();
            }

            double crossProb = (rand() % 101);
            int index2 = rand() % popSize;
            
            if(crossProb <= cr){
                //call crossover
                x = x.crossover(chromosome[index2]);
            }
            //Push back to vector
            chromosome2.push_back(x);
            count++;
        }
        //Using sort()
        std::sort(chromosome2.begin(), chromosome2.end(), bots);
        std::cout << chromosome2[0] << std::endl;
        //Clear vector
        chromosome.clear();
        
        for(int i = 0; i < popSize; i++){
            chromosome.push_back(chromosome2[i]);
        }
        
        fitness = chromosome2[0].fitness(target);
        std::cout << fitness << " : fitness" <<std::endl;        
    }
    
    return chromosome[0];
}

int main(int argc, char **argv)
{
    srand(time(0));
    target = argv[1];
    int popSize = atoi(argv[2]);
    double mr = atof(argv[3]);
    double cr = atof(argv[4]);
    Chromosome answer = runGA(target, popSize, mr, cr);

    std::cout << "Solution found: " << answer << std::endl;
}
