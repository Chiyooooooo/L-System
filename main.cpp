#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stack>
#include <random>

// Function to apply production rules to a string
std::string applyRules(const std::string& current, const std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& rules) {
    std::string next;
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for (char ch : current) {
        std::string symbol(1, ch);
        if (rules.find(symbol) != rules.end()) {
            const auto& ruleSet = rules.at(symbol);
            float totalProbability = 0;
            for (const auto& rule : ruleSet) {
                totalProbability += rule.second;
            }
            std::uniform_real_distribution<> dist(0.0, totalProbability);
            float randomValue = dist(gen);

            float cumulativeProbability = 0;
            for (const auto& rule : ruleSet) {
                cumulativeProbability += rule.second;
                if (randomValue <= cumulativeProbability) {
                    next += rule.first;
                    break;
                }
            }
        } else {
            next += symbol;
        }
    }
    return next;
}

// Function to generate an L-System string
std::string generateLSystem(const std::string& axiom, const std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& rules, int iterations) {
    std::string current = axiom;
    for (int i = 0; i < iterations; ++i) {
        current = applyRules(current, rules);
        std::cout << "Iteration " << i + 1 << ": " << current << std::endl;  // Log the current string
    }
    return current;
}

// Function to draw the L-System string using SFML
void drawLSystem(sf::RenderWindow& window, const std::string& lSystem, float angle, float length, const sf::Vector2f& offset) {
    sf::Vector2f position(window.getSize().x / 2 + offset.x, window.getSize().y / 2 + offset.y);
    float currentAngle = -90.0f; // Start facing "right"
    std::stack<sf::Vector2f> positionStack;
    std::stack<float> angleStack;

    window.clear(sf::Color::Black); // Set background to black

    for (char ch : lSystem) {
        if (ch == 'F') {
            sf::Vector2f newPosition = position;
            newPosition.x += length * std::cos(currentAngle * M_PI / 180.0f);
            newPosition.y += length * std::sin(currentAngle * M_PI / 180.0f);

            sf::Vertex line[] = {
                sf::Vertex(position, sf::Color::White), // Set line color to white
                sf::Vertex(newPosition, sf::Color::White) // Set line color to white
            };

            window.draw(line, 2, sf::Lines);
            position = newPosition;
        } else if (ch == 'f') {
            position.x += length * std::cos(currentAngle * M_PI / 180.0f);
            position.y += length * std::sin(currentAngle * M_PI / 180.0f);
        } else if (ch == '+') {
            currentAngle += angle;
        } else if (ch == '-') {
            currentAngle -= angle;
        } else if (ch == '&') {
            currentAngle += angle;
        } else if (ch == '^') {
            currentAngle -= angle;
        } else if (ch == '\\') {
            currentAngle += angle;
        } else if (ch == '/') {
            currentAngle -= angle;
        } else if (ch == '|') {
            currentAngle += 180.0f;
        } else if (ch == '[') {
            positionStack.push(position);
            angleStack.push(currentAngle);
        } else if (ch == ']') {
            position = positionStack.top();
            positionStack.pop();
            currentAngle = angleStack.top();
            angleStack.pop();
        } else if (ch == 'O') { // Draw a fruit or sphere
            sf::CircleShape fruit(3); // Radius of 5
            fruit.setFillColor(sf::Color::Magenta); // Set fruit color to red
            fruit.setPosition(position);
            window.draw(fruit);
        }
    }

    window.display();
}

// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "L-System with Fruits");

//     std::string axiom = "F";
//     std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules;
//     rules["F"] = { {"F+F-F-OF+F", 1.0} }; // Modified rule to include 'O' at the end of some branches

//     int iterations = 4;
//     float angle = 90.0f;
//     float length = 10.0f;
//     sf::Vector2f offset(0.0f, 0.0f);

//     std::string lSystem = generateLSystem(axiom, rules, iterations);
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         drawLSystem(window, lSystem, angle, length, offset);
//     }

//     return 0;
// }


int main() {
    // Example 1: Classic Fractal Plant
    std::string axiom1 = "X";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules1;
    rules1["X"] = {{"F[+X]F[-X]+X", 1.0f}};
    rules1["F"] = {{"FF", 1.0f}};
    int iterations1 = 6;
    float angle1 = 25.0f;

    // Example 2: Simple Bush
    std::string axiom2 = "F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules2;
    rules2["F"] = {{"F[+F]F[-F]F", 1.0f}};
    int iterations2 = 4;
    float angle2 = 25.0f;

    // Example 3: Dragon Curve
    std::string axiom3 = "FX";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules3;
    rules3["X"] = {{"X+YF+", 1.0f}};
    rules3["Y"] = {{"-FX-Y", 1.0f}};
    int iterations3 = 10;
    float angle3 = 90.0f;

    // Example 4: Sierpinski Triangle
    std::string axiom4 = "R";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules4;
    rules4["F"] = {{"R+F+R", 1.0f}};
    rules4["R"] = {{"F-R-F", 1.0f}};
    int iterations4 = 8;
    float angle4 = 60.0f;

    // Example 5: Koch Curve
    std::string axiom5 = "F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules5;
    rules5["F"] = {{"F+F-F-F+F", 1.0f}};
    int iterations5 = 4;
    float angle5 = 90.0f;

    // Example 6: Hilbert Curve
    std::string axiom6 = "A";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules6;
    rules6["A"] = {{"-BF+AFA+FB-", 1.0f}};
    rules6["B"] = {{"AF-BFB-FA+", 1.0f}};
    int iterations6 = 5;
    float angle6 = 90.0f;

    // Example 7: Peano Curve
    std::string axiom7 = "F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules7;
    rules7["F"] = {{"F+F-F-F-F+F+F+F-F", 1.0f}};
    int iterations7 = 4;
    float angle7 = 90.0f;

    // Example 8: Levy C Curve
    std::string axiom8 = "F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules8;
    rules8["F"] = {{"+F--F+", 1.0f}};
    int iterations8 = 10;
    float angle8 = 45.0f;

    // Example 9: Cross Curve
    std::string axiom9 = "F+F+F+F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules9;
    rules9["F"] = {{"F+F-F+F", 1.0f}};
    int iterations9 = 4;
    float angle9 = 90.0f;

    // // Example 10: Hexagonal Gosper Curve
    // std::string axiom10 = "A";
    // std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules10;
    // rules10["A"] = {{"A-B--B+A++AA+B-", 1.0f}};
    // rules10["B"] = {{"+A-BB--B-A++A+B", 1.0f}};
    // int iterations10 = 4;
    // float angle10 = 60.0f;

    // std::string axiom10 = "A";
    // std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules10;
    // rules10["A"] = {{"A+B++B-A--AA-B+", 1.0f}};
    // rules10["B"] = {{"-A+BB++B+A--A-B", 1.0f}};
    // int iterations10 = 1;
    // float angle10 = 60.0f;


// n=4, δ=60◦
// Fl 
// Fl→Fl+Fr++Fr-Fl--FlFl-Fr+ 
// Fr →-Fl +Fr Fr ++Fr +Fl --Fl -Fr


    std::string axiom10 = "-B";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules10;
    rules10["A"] = {{"AA-B-B+A+A-B-BA+B+AAB-A+B+AA+B-AB-B-A+A+BB-", 1.0f}};
    rules10["B"] = {{"+AA-B-B+A+AB+A-BB-A-B+ABB-A-BA+A+B-B-A+A+BB", 1.0f}};
    int iterations10 = 1;
    float angle10 = 90.0f;

// n=2, δ=90◦
// -Fr 
// A→AA-B-B+A+A-B-BA+B+AAB-A+B+AA+B-AB-B-A+A+BB- 
// B→+AA-B-B+A+AB+A-BB-A-B+ABB-A- BA+A+B-B-A+A+BB



    // Example 11: Stochastic Fractal Plant
    std::string axiom11 = "X";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules11;
    rules11["X"] = {{"F[+X]F[-X]+X", 0.5f}, {"F[-X]F[+X]-X", 0.5f}};
    rules11["F"] = {{"FF", 1.0f}};
    int iterations11 = 6;
    float angle11 = 25.0f;

    // Example 12: Stochastic Simple Bush
    std::string axiom12 = "F";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules12;
    rules12["F"] = {{"F[+F]F[-F]F", 0.33f}, {"F[+F]F", 0.33f}, {"F[-F]F", 0.33f}};
    int iterations12 = 4;
    float angle12 = 25.0f;

    // Example 13: Stochastic Plant
    std::string axiom13 = "X";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules13;
    rules13["X"] = {{"F[+X][-X]FX", 0.33f}, {"F[-X][+X]FXO", 0.33f}, {"F[+X]F[-X]", 0.34f}};
    rules13["F"] = {{"FF", 1.0f}};
    int iterations13 = 5;
    float angle13 = 25.0f;

    // Example 14: Stochastic Dragon Curve
    std::string axiom14 = "FX";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules14;
    rules14["X"] = {{"X+YF+", 0.5f}, {"X-YF-", 0.5f}};
    rules14["Y"] = {{"+FX-Y", 1.0f}};
    int iterations14 = 10;
    float angle14 = 90.0f;

    // Example 15: Stochastic Sierpinski Triangle
    std::string axiom15 = "R";
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules15;
    rules15["F"] = {{"R+F+R", 0.5f}, {"F+R+F", 0.5f}};
    rules15["R"] = {{"F-R-F", 1.0f}};
    int iterations15 = 7;
    float angle15 = 60.0f;

    // Select the L-system to use
    std::string axiom;
    std::unordered_map<std::string, std::vector<std::pair<std::string, float>>> rules;
    int iterations;
    float angle;

    // Uncomment the desired L-system
     //axiom = axiom1; rules = rules1; iterations = iterations1; angle = angle1; // Classic Fractal Plant
    // axiom = axiom2; rules = rules2; iterations = 2; angle = angle2; // Simple Bush
    // axiom = axiom3; rules = rules3; iterations = iterations3; angle = angle3; // Dragon Curve
  //  axiom = axiom4; rules = rules4; iterations = iterations4; angle = angle4; // Sierpinski Triangle
    // axiom = axiom5; rules = rules5; iterations = iterations5; angle = angle5; // Koch Curve
    // axiom = axiom6; rules = rules6; iterations = iterations6; angle = angle6; // Hilbert Curve
    // axiom = axiom7; rules = rules7; iterations = iterations7; angle = angle7; // Peano Curve
    // axiom = axiom8; rules = rules8; iterations = iterations8; angle = angle8; // Levy C Curve
    //axiom = axiom9; rules = rules9; iterations = iterations9; angle = angle9; // Cross Curve
  //   axiom = axiom10; rules = rules10; iterations = iterations10; angle = angle10; // Hexagonal Gosper Curve    marche pas 
    // axiom = axiom11; rules = rules11; iterations = iterations11; angle = angle11; // Stochastic Fractal Plant
    //axiom = axiom12; rules = rules12; iterations = iterations12+2; angle = angle12; // Stochastic Simple Bush
     axiom = axiom13; rules = rules13; iterations = iterations13+1; angle = angle13; // Stochastic Plant
    // axiom = axiom14; rules = rules14; iterations = iterations14; angle = angle14; // Stochastic Dragon Curve
   // axiom = axiom15; rules = rules15; iterations = iterations15; angle = angle15; // Stochastic Sierpinski Triangle

    // Generate the L-System string
    std::string result = generateLSystem(axiom, rules, iterations);

    // Print the result
    std::cout << "Result after " << iterations << " iterations: " << result << std::endl;

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "L-System");
    sf::Vector2f offset(0.0f, 400.0f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        drawLSystem(window, result, angle, 5.0f, offset);
    }
    return 0;
}



