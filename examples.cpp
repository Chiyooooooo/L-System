#include "examples.hpp"

// Example 1: Classic Fractal Plant
std::string axiom1 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules1 = {
    {"X", {{"F[+X]F[-X]+X", 1.0f}}},
    {"F", {{"FF", 1.0f}}}
};
int iterations1 = 6;
float angle1 = 25.0f;

// Example 2: Simple Bush
std::string axiom2 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules2 = {
    {"F", {{"F[+F]F[-F]F", 1.0f}}}
};
int iterations2 = 4;
float angle2 = 25.0f;

// Example 3: Dragon Curve
std::string axiom3 = "FX";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules3 = {
    {"X", {{"X+YF+", 1.0f}}},
    {"Y", {{"-FX-Y", 1.0f}}}
};
int iterations3 = 10;
float angle3 = 90.0f;

// Example 4: Sierpinski Triangle
std::string axiom4 = "R";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules4 = {
    {"F", {{"R+F+R", 1.0f}}},
    {"R", {{"F-R-F", 1.0f}}}
};
int iterations4 = 8;
float angle4 = 60.0f;

// Example 5: Koch Curve
std::string axiom5 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules5 = {
    {"F", {{"F+F-F-F+F", 1.0f}}}
};
int iterations5 = 4;
float angle5 = 90.0f;

// Example 6: Hilbert Curve
std::string axiom6 = "A";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules6 = {
    {"A", {{"-BF+AFA+FB-", 1.0f}}},
    {"B", {{"AF-BFB-FA+", 1.0f}}}
};
int iterations6 = 5;
float angle6 = 90.0f;

// Example 7: Peano Curve
std::string axiom7 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules7 = {
    {"F", {{"F+F-F-F-F+F+F+F-F", 1.0f}}}
};
int iterations7 = 4;
float angle7 = 90.0f;

// Example 8: Levy C Curve
std::string axiom8 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules8 = {
    {"F", {{"+F--F+", 1.0f}}}
};
int iterations8 = 10;
float angle8 = 45.0f;

// Example 9: Cross Curve
std::string axiom9 = "F+F+F+F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules9 = {
    {"F", {{"F+F-F+F", 1.0f}}}
};
int iterations9 = 4;
float angle9 = 90.0f;

// Example 10: Hexagonal Gosper Curve
std::string axiom10 = "-B";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules10 = {
    {"A", {{"AA-B-B+A+A-B-BA+B+AAB-A+B+AA+B-AB-B-A+A+BB-", 1.0f}}},
    {"B", {{"+AA-B-B+A+AB+A-BB-A-B+ABB-A-BA+A+B-B-A+A+BB", 1.0f}}}
};
int iterations10 = 1;
float angle10 = 90.0f;

// Example 11: Stochastic Fractal Plant
std::string axiom11 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules11 = {
    {"X", {{"F[+X]F[-X]+X", 0.5f}, {"F[-X]F[+X]-X", 0.5f}}},
    {"F", {{"FF", 1.0f}}}
};
int iterations11 = 6;
float angle11 = 25.0f;

// Example 12: Stochastic Simple Bush
std::string axiom12 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules12 = {
    {"F", {{"F[+F]F[-F]F", 0.33f}, {"F[+F]F", 0.33f}, {"F[-F]F", 0.33f}}}
};
int iterations12 = 4;
float angle12 = 25.0f;

// Example 13: Stochastic Plant
std::string axiom13 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules13 = {
    {"X", {{"F[+X][-X]FX", 0.33f}, {"F[-X][+X]FXO", 0.33f}, {"F[+X]F[-X]", 0.34f}}},
    {"F", {{"FF", 1.0f}}}
};
int iterations13 = 5;
float angle13 = 25.0f;

// Example 14: Stochastic Dragon Curve
std::string axiom14 = "FX";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules14 = {
    {"X", {{"X+YF+", 0.5f}, {"X-YF-", 0.5f}}},
    {"Y", {{"+FX-Y", 1.0f}}}
};
int iterations14 = 10;
float angle14 = 90.0f;

// Example 15: Stochastic Sierpinski Triangle
std::string axiom15 = "R";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules15 = {
    {"F", {{"R+F+R", 0.5f}, {"F+R+F", 0.5f}}},
    {"R", {{"F-R-F", 1.0f}}}
};
int iterations15 = 7;
float angle15 = 60.0f;

std::string getAxiom(int example) {
    switch(example) {
        case 1: return axiom1;
        case 2: return axiom2;
        case 3: return axiom3;
        case 4: return axiom4;
        case 5: return axiom5;
        case 6: return axiom6;
        case 7: return axiom7;
        case 8: return axiom8;
        case 9: return axiom9;
        case 10: return axiom10;
        case 11: return axiom11;
        case 12: return axiom12;
        case 13: return axiom13;
        case 14: return axiom14;
        case 15: return axiom15;
        default: return "";
    }
}

std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> getRules(int example) {
    switch(example) {
        case 1: return rules1;
        case 2: return rules2;
        case 3: return rules3;
        case 4: return rules4;
        case 5: return rules5;
        case 6: return rules6;
        case 7: return rules7;
        case 8: return rules8;
        case 9: return rules9;
        case 10: return rules10;
        case 11: return rules11;
        case 12: return rules12;
        case 13: return rules13;
        case 14: return rules14;
        case 15: return rules15;
        default: return std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>();
    }
}

int getIterations(int example) {
    switch(example) {
        case 1: return iterations1;
        case 2: return iterations2;
        case 3: return iterations3;
        case 4: return iterations4;
        case 5: return iterations5;
        case 6: return iterations6;
        case 7: return iterations7;
        case 8: return iterations8;
        case 9: return iterations9;
        case 10: return iterations10;
        case 11: return iterations11;
        case 12: return iterations12;
        case 13: return iterations13;
        case 14: return iterations14;
        case 15: return iterations15;
        default: return 0;
    }
}

float getAngle(int example) {
    switch(example) {
        case 1: return angle1;
        case 2: return angle2;
        case 3: return angle3;
        case 4: return angle4;
        case 5: return angle5;
        case 6: return angle6;
        case 7: return angle7;
        case 8: return angle8;
        case 9: return angle9;
        case 10: return angle10;
        case 11: return angle11;
        case 12: return angle12;
        case 13: return angle13;
        case 14: return angle14;
        case 15: return angle15;
        default: return 0.0f;
    }
}
