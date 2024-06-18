#include "examples.hpp"

// Example 1: Classic Fractal Plant
std::string axiom111 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules111 = {
    {"X", {{"F[+X]F[-X]+X", 1.0f}}},
    {"F", {{"FF", 1.0f}}}
};
int iterations111 = 6;
float angle111 = 20.0f;


// Define the L-system rules for a sympodial tree
std::string axiom1 = "A(1,10)";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules1 = {
    {"A", {{"!(w)F(l)[&(a1)B(l*r1,w*wr)]/(180)[&(a2)B(l*r2,w*wr)]", 1.0f}}},
    {"B", {{"!(w)F(l)[+(a1)$B(l*r1,w*wr)][-(a2)$B(l*r2,w*wr)]", 1.0f}}}
};

// Parameters
#define r1 0.9
#define r2 0.7
#define a1 10
#define a2 60
#define wr 0.707

int iterations1 = 5;
float angle1 = 22.5f;






// Example 100: symetrical Plant   e page 37
std::string axiom100 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules100 = {
    //{"X", {{"F[+X][-X]FX", 1.0f}}},
    {"X", {{"F-[[X]+X]+F[+FX]-X", 1.0f}}},

    {"F", {{"FF", 1.0f}}}
};
int iterations100 = 6;
float angle100 = 25.0f;

// std::string axiom1 = "X";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules1 = {
//     {"X", {{"F-[[X]+X]+F[+FX]-X", 1.0f}}},
//     {"F", {{"FF", 1.0f}}}
// };
// int iterations1 = 5;
// float angle1 = 25.0f;

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
int iterations4 = 5;
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
int iterations6 = 8;
float angle6 = 90.0f;


// Example 7: 3D Peano Curve
std::string axiom7 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules7 = {
    {"F", {{"F+F-F&F^F+F+F/F\\F-F", 1.0f}}}
};
int iterations7 = 3;
float angle7 = 90.0f;

// // Example 7: Peano Curve
// std::string axiom7 = "F";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules7 = {
//     {"F", {{"F+F-F-F-F+F+F+F-F", 1.0f}}}
// };
// int iterations7 = 4;
// float angle7 = 90.0f;

// // Example 7: 3D Levy C Curve
// std::string axiom7 = "F";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules7 = {
//     {"F", {{"+F&--F^+", 0.5f}, {"+F\\--F/+", 0.5f}}}
// };
// int iterations7 = 6;
// float angle7 = 45.0f;


// Example 8: Levy C Curve
std::string axiom8 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules8 = {
    {"F", {{"+F--F+", 1.0f}}}
};
int iterations8 = 6;
float angle8 = 45.0f;

// Example 9: Cross Curve
std::string axiom9 = "F+F+F+F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules9 = {
    {"F", {{"F+F-F+F", 1.0f}}}
};
int iterations9 = 5;
float angle9 = 90.0f;

// Example 10: Hexagonal Gosper Curve
std::string axiom10 = "-B";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules10 = {
    {"A", {{"AA-B-B+A+A-B-BA+B+AAB-A+B+AA+B-AB-B-A+A+BB-", 1.0f}}},
    {"B", {{"+AA-B-B+A+AB+A-BB-A-B+ABB-A-BA+A+B-B-A+A+BB", 1.0f}}}
};
int iterations10 = 1;
float angle10 = 90.0f;

// // Example 11: Stochastic Fractal Plant
// std::string axiom11 = "F[+F]F[-F]";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules11 = {
//     //{"X", {{"F[+X]F[-X]+X", 0.5f}, {"F[-X]F[+X]-X", 0.5f}}},
//     {"X", {{"X", 1.0f}}},
//     {"F", {{"F", 1.0f}}}
// };
// int iterations11 = 6;
// float angle11 = 25.0f;

// Example 11: Stochastic Fractal Plant
std::string axiom11 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules11 = {
    {"X", {{"F[+X]F[-X]+X", 0.5f}, {"F[-X]F[+X]-X", 0.5f}}},
    //{"X", {{"F[+X]F[-X]+X", 1.0f}}},
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

// Example 15: herbe 1
std::string axiom15 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules15 = {
    {"F", {{"[\\F]/[F+F]//[F-F]", 1.0f}}}
};
int iterations15 = 3;
float angle15 = 17.0f;

// // Example 15: herbe 2
// std::string axiom15 = "F";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules15 = {
//     {"F", {{"F[+FF]////", 1.0f}}}
// };
// int iterations15 = 2;
// float angle15 = 17.0f;

// // Example 15: herbe 3
// std::string axiom15 = "F";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules15 = {
//     {"F", {{"F[F++F]////", 1.0f}}}
// };
// int iterations15 = 2;
// float angle15 = 17.0f;


///////////////////////////////////////////////////////////////////////////////////////////

// Parameters
#define r1 0.9
#define r2 0.6
#define a0 45
#define a2 45
#define d 137.5
#define wr 0.707

// Example 16: Custom 3D Tree
std::string axiom16 = "A(1,10)";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules16 = {
    {"A", {{"!(w)F(l)[&(a0)B(l*r2,w*wr)]/(d)A(l*r1,w*wr)", 1.0f}}},
    {"B", {{"!(w)F(l)[-(a2)$C(l*r2,w*wr)]C(l*r1,w*wr)", 1.0f}}},
    {"C", {{"!(w)F(l)[+(a2)$B(l*r2,w*wr)]B(l*r1,w*wr)", 1.0f}}}
};
int iterations16 = 10;
float angle16 = 45.0f;



// Example 17: Custom 3D Tree
std::string axiom17 = "A";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules17 = {
    {"A", {{"[&FL!A]/////'[&FL!A]///////'[&FL!A]", 1.0f}}},
    {"F", {{"S/////F", 1.0f}}},
    {"S", {{"FL", 1.0f}}},
    {"L", {{"['''^^{-f+f+f-|-f+f+f}]", 1.0f}}}
};
int iterations17 = 7;
float angle17 = 22.5f;


#define r1 0.9
#define r2 0.7
#define a1 10
#define a2 60
#define wr 0.707

// Example 18: Custom 3D Tree
std::string axiom18 = "A(1,10)";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules18 = {
    {"A", {{"!(w)F(l)[&(a1)B(l*r1,w*wr)]/(180)[&(a2)B(l*r2,w*wr)]", 1.0f}}},
    {"B", {{"!(w)F(l)[+(a1)$B(l*r1,w*wr)][-(a2)$B(l*r2,w*wr)]", 1.0f}}}
};
int iterations18 = 5;
float angle18 = 17.0f;  // This angle should match your drawing angle in the Python script



#define d1 137.50 // 94.74
#define d2 137.50 // 132.63
#define a 18.95
#define lr 1.109
#define vr 1.732

// // Example 19: Custom 3D Tree
// std::string axiom19 = "!(1)F(200)/(45)A";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules19 = {
//     {"A", {{"!(vr)F(50)[&(a)F(50)A]/(d1)[&(a)F(50)A]/(d2)[&(a)F(50)A]", 1.0f}}},
//     {"F", {{"F(l*lr)", 1.0f}}},
//     {"!", {{"!(w*vr)", 1.0f}}}
// };
// int iterations19 = 5;
// float angle19 = 18.95f;



// // Example 19: Custom 3D Tree
// std::string axiom19 = "A";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules19 = {
//     {"A", {{"F(1)[&(25)B]//F(1)[&(25)B]//F(1)[&(25)B]", 1.0f}}},
//     {"B", {{"!(0.707)F(0.75)[+B][-B]", 1.0f}}}
// };

// int iterations19 = 6;
// float angle19 = 25.0f;



// Example 20: Majestic Tree
std::string axiom19 = "A";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules19 = {
    {"A", {{"F(1)[&(20)B]//F(1)[&(20)B]//F(1)[&(20)B]", 1.0f}}},
    {"B", {{"!(0.707)F(0.75)[+B][-B]", 1.0f}}},
    {"C", {{"!(0.707)F(0.75)[/C][\\C]", 1.0f}}}
};
int iterations19 = 8;
float angle19 = 20.0f;

// Example 21: 3D Stochastic Bush
std::string axiom21 = "F";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules21 = {
    {"F", {{"F[+F&F]F[-F^F]F", 0.25f}, {"F[+F]F", 0.25f}, {"F[-F]F", 0.25f}, {"F[\\F]F", 0.125f}, {"F[/F]F", 0.125f}}}
};
int iterations21 = 5;
float angle21 = 25.0f;


// // Example 22: 3D Stochastic Plant
// std::string axiom22 = "X";
// std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules22 = {
//     {"X", {{"F[+X&X][-X^X]FX", 0.33f}, {"F[-X\\X][+X/X]FXO", 0.33f}, {"F[+X]F[-X]", 0.34f}}},
//     {"F", {{"FF", 1.0f}}}
// };
// int iterations22 = 4;
// float angle22 = 25.0f;


// Example 22: 3D Stochastic Plant
std::string axiom22 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules22 = {
    {"X", {{"F[+X&X][-X^X]FX", 0.33f}, {"F[-X\\X][+X/X]FXO", 0.33f}, {"F[+X]F[-X]", 0.34f}}},
    {"F", {{"FF", 1.0f}}}
};
int iterations22 = 4;
float angle22 = 25.0f;



// Example 25: 3D Menger Sponge
// Example 26: 3D Flower
std::string axiom25 = "X";
std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules25 = {
    {"X", {{"F[+X][-X]FX", 0.25f}, {"F[&X][^X]FXW", 0.25f}, {"F[\\X][X]FXK", 0.25f}, {"F[+X][-X][&X][^X][\\X][X]O", 0.25f}}},
    {"F", {{"FF\\+", 0.5f}, {"F", 0.5f}}}
};
int iterations25 = 5;
float angle25 = 15.0f;






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
        case 16: return axiom16;
        case 17: return axiom17;
        case 18: return axiom18;
        case 19: return axiom19;
        case 21: return axiom21;
        case 22: return axiom22;
        case 25: return axiom25;
        case 100: return axiom100;
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
        case 16: return rules16;
        case 17: return rules17;
        case 18: return rules18;
        case 19: return rules19;
        case 21: return rules21;
        case 22: return rules22;
        case 25: return rules25;
        case 100: return rules100;
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
        case 16: return iterations16;
        case 17: return iterations17;
        case 18: return iterations18;
        case 19: return iterations19;
        case 21: return iterations21;
        case 22: return iterations22;
        case 25: return iterations25;

        case 100: return iterations100;
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
        case 16: return angle16;
        case 17: return angle17;
        case 18: return angle18;
        case 19: return angle19;
        case 21: return angle21;
        case 22: return angle22;  
        case 25: return angle25;   
        case 100: return angle100;

        default: return 0.0f;
    }
}
