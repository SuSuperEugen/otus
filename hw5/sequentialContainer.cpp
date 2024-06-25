#include "sequentialContainer.hpp"



int main(){
    CountainerSTL<int> countainer;
    countainer.push_back(33);
    countainer.push_back(34);
    countainer.push_back(35);
    countainer.push_back(36);
    countainer.push_back(37);
    countainer.insert(2, 99);
    countainer.erase(3);
    std::cout << "TEST" << std::endl;
    for(int i =0; i<countainer.size(); i++)std::cout << countainer.new_value[i] << std::endl;
    return 0;
    //std::cout << countainer.new_value[0] << std::endl;;
}