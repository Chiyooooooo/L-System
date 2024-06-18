// main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stack>
#include <random>
#include <fstream>


#include "examples.hpp"


std::string applyRules(const std::string& current, const std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& rules) {
    std::string next;
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for (char ch : current) {
        std::string symbol(1, ch);

        if (rules.count(symbol)) {
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
            next += ch;
        }
    }
    return next;
}


// Function to generate an L-System string
std::string generateLSystem(const std::string& axiom, const std::unordered_map<std::string, std::vector<std::pair<std::string, float>>>& rules, int iterations) {
    std::string current = axiom;
    for (int i = 0; i < iterations; ++i) {
        current = applyRules(current, rules);
       // std::cout << "Current l-system : " << current << std::endl;  
    }
    return current;
}

// Function to draw the L-System string using SFML
void drawLSystem(sf::RenderWindow& window, const std::string& lSystem, float angle, float length, const sf::Vector2f& offset, float initialThickness) {
    sf::Vector2f position(window.getSize().x / 2 + offset.x, window.getSize().y / 2 + offset.y);
    float currentAngle = -90.0f; // Start facing "up"
    std::stack<sf::Vector2f> positionStack;
    std::stack<float> angleStack;
    std::stack<float> thicknessStack;
    float thickness = initialThickness;

    window.clear(sf::Color::Black); // Set background to black

    for (char ch : lSystem) {
        if (ch == 'F') {
            sf::Vector2f newPosition = position;
            newPosition.x += length * std::cos(currentAngle * M_PI / 180.0f);
            newPosition.y += length * std::sin(currentAngle * M_PI / 180.0f);

            sf::RectangleShape line(sf::Vector2f(length, thickness));
            line.setPosition(position);
            line.setFillColor(sf::Color::White);
            line.setRotation(currentAngle);

            window.draw(line);
            position = newPosition;
        } else if (ch == 'f') {
            position.x += length * std::cos(currentAngle * M_PI / 180.0f);
            position.y += length * std::sin(currentAngle * M_PI / 180.0f);
        } else if (ch == '+') {
            currentAngle += angle;
        } else if (ch == '-') {
            currentAngle -= angle;
        } else if (ch == '|') {
            currentAngle += 180.0f;
        } else if (ch == '[') {
            positionStack.push(position);
            angleStack.push(currentAngle);
            thicknessStack.push(thickness);
            thickness = std::max(thickness - 1, 2.0f); 
            //thickness -= 1; // Decrease thickness for branches
        } else if (ch == ']') {
            position = positionStack.top();
            positionStack.pop();
            currentAngle = angleStack.top();
            angleStack.pop();
            thickness = thicknessStack.top();
            thicknessStack.pop();
        } else if (ch == 'O') { // Draw a fruit or sphere
            sf::CircleShape fruit(3); // Radius of 3
            fruit.setFillColor(sf::Color::Magenta); // Set fruit color to magenta
            fruit.setPosition(position);
            window.draw(fruit);
        }
    }
    window.display();
}

int main() {
    int exampleNumber = 25; // Example number to use
    std::string axiom = getAxiom(exampleNumber);
    auto rules = getRules(exampleNumber);
    int iterations = getIterations(exampleNumber) ;
    float angle = getAngle(exampleNumber);

    // Generate the L-System string
    std::string result = generateLSystem(axiom, rules, iterations);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "L-System with Larger Base Tree");
    sf::Vector2f offset(0.0f, 400.0f);
    float initialThickness = 2 ; // Initial thickness of the base tree


    std::ofstream outFile("lsystem.txt");
    outFile << result;
    outFile.close();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        drawLSystem(window, result, angle, 10.0f, offset, initialThickness);
    }



    return 0;
}
