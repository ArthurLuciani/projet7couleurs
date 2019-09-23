#include "divers.hpp"


char rand_a_b(char min, char max)  // interval inclus
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased
    
    int random_integer = uni(rng);
    
    return (char)random_integer;
}