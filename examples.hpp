// examples.hpp
#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include <string>
#include <unordered_map>
#include <vector>

std::string getAxiom(int example);
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> getRules(int example);
int getIterations(int example);
float getAngle(int example);

#endif // EXAMPLES_HPP
