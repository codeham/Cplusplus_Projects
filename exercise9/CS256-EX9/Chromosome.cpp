#include "Chromosome.h"

Chromosome::Chromosome(std::string d) : data(d)
{
}

std::string Chromosome::getData() const
{
    return data;
}

Chromosome Chromosome::mutate() const
{
    int coinToss = rand() %2;
    std::string str = this->data;
    int i = rand() % data.length();
    char alphabet = data[i];
    
    if(!coinToss){
        alphabet = alphabet - 1;
    }else{
        alphabet = alphabet + 1;
    }
    
    if(alphabet < 97){
        alphabet = 'z';
    }

    if(alphabet > 122){
        alphabet = 'a';
    }
    
    str[i] = alphabet;
    return str;
}

Chromosome Chromosome::crossover(const Chromosome& c) const
{
    // implement crossover here
    int slicePosition = rand() % (data.length());
    std::string tempString = "";
    std::string tempString2 = data;

    for ( int i = 0; i < slicePosition; i++){
        tempString += tempString2[i];
    }

    std::string tempString3 = c.getData();

    for ( int j = slicePosition; j < data.length(); j++){
        tempString += tempString3[j];
    }

   return tempString;

}

int Chromosome::fitness(const std::string& target) const
{
    // computes fitness by sum of differences of each character
    // smaller is better (0 is perfect)

    int diff = 0;
    for (int i = 0; i < data.size(); i++)
    {
        int change = std::abs(data[i] - target[i]);
        if (change > 13) // handles wrap around for alphabets
        {
            change = 26 - change;
        }
        diff += change;
    }
    return diff;
}

std::ostream& operator<<(std::ostream& os, const Chromosome& c)
{
    os << c.getData();
    return os;
}
