/* 
 * File:   Node.cpp
 * Author: ozielcarneiro
 * 
 * Created on September 11, 2012, 10:01 PM
 */

#include <sstream>
#include <math.h>
#include <vector>
#include "Node.h"
#include "IO.h"

using namespace std;

Node::Node() {
}

Node::Node(const Node& orig) {
    father = orig.father;
    xA = orig.xA;
    xB = orig.xB;
    yA = orig.yA;
    yB = orig.yB;
    cost = orig.cost;
    level = orig.level;
    mapSize = orig.mapSize;
    obstaclesN = orig.obstaclesN;
    xObstacle = orig.xObstacle;
    yObstacle = orig.yObstacle;
    moveCost = orig.moveCost;
    heuristicFlag = orig.heuristicFlag;
}

Node::Node(string inputData) {
    while(inputData.at(inputData.size()-1)=='\n'){
        inputData = inputData.substr(0,inputData.size()-1);
    }
    stringstream ss(inputData);
    vector<string> lines;
    string line;
    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }
    int values[(1 + (lines.size() - 1)*2)];
    int j = 0;
    for (int i = 0; i < lines.size(); i++) {
        stringstream linestream(lines.at(i));
        if (i < 1) {
            linestream >> values[j];
            j++;
        } else {
            linestream >> values[j] >> values[j + 1];
            j += 2;
        }
    }

    mapSize = values[0];
    xA = values[1];
    yA = values[2];
    xB = values[3];
    yB = values[4];
    obstaclesN = lines.size() - 3;
    if (obstaclesN > 0) {
        xObstacle = new int[obstaclesN];
        yObstacle = new int[obstaclesN];
        for (int i = 0; i < obstaclesN; i++) {
            xObstacle[i] = values[5 + i * 2];
            yObstacle[i] = values[5 + i * 2 + 1];
        }
    }
    heuristicFlag = 1;
    father = NULL;
    cost = 0;
    moveCost = 2;
    level = 0;
}

Node::~Node() {
}

Node* Node::moveUp() {
    Node newNode;
    int nextXA = xA;
    int nextYA = yA - 1;
    int nextXB = xB + 1;
    int nextYB = yB;

    if (nextYA < 1 || nextXB > mapSize) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setHeuristicFlag(heuristicFlag);
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveRight() {
    Node newNode;
    int nextXA = xA + 1;
    int nextYA = yA;
    int nextXB = xB;
    int nextYB = yB + 1;

    if (nextXA > mapSize || nextYB > mapSize) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setHeuristicFlag(heuristicFlag);
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveDown() {
    Node newNode;
    int nextXA = xA;
    int nextYA = yA + 1;
    int nextXB = xB - 1;
    int nextYB = yB;

    if (nextYA > mapSize || nextXB < 1) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setHeuristicFlag(heuristicFlag);
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

Node* Node::moveLeft() {
    Node newNode;
    int nextXA = xA - 1;
    int nextYA = yA;
    int nextXB = xB;
    int nextYB = yB - 1;

    if (nextXA < 1 || nextYB < 1) {
        return NULL;
    } else {
        for (int i = 0; i < obstaclesN; i++) {
            if ((nextXA == xObstacle[i] && nextYA == yObstacle[i]) || (nextXB == xObstacle[i] && nextYB == yObstacle[i])) {
                return NULL;
            }
        }

    }
    newNode.setHeuristicFlag(heuristicFlag);
    newNode.setA(nextXA, nextYA);
    newNode.setB(nextXB, nextYB);
    newNode.setMapSize(mapSize);
    newNode.setMoveCost(moveCost);
    newNode.setObstaclesN(obstaclesN);
    newNode.setObstacles(xObstacle, yObstacle);
    newNode.setCost(getCost() + moveCost);
    newNode.setLevel(getLevel() + 1);
    newNode.setFather(this);
    return &newNode;
}

bool Node::checkGoal() {
    if (xA == xB && yA == yB) {
        return 1;
    } else {
        return 0;
    }
}

string Node::getPath() {
    string out;
    if (father != NULL) {
        out = (*father).getPath();
    } else {
        out = "";
    }
    stringstream stream;
    stream << out << "(" << xA << "," << yA << ") ";
    return stream.str();
}

void Node::setA(int xA, int yA) {
    this->xA = xA;
    this->yA = yA;
}

void Node::setB(int xB, int yB) {
    this->xB = xB;
    this->yB = yB;
}

void Node::setMapSize(int n) {
    mapSize = n;
}

void Node::setMoveCost(int cost) {
    moveCost = cost;
}

void Node::setObstaclesN(int n) {
    obstaclesN = n;
}

void Node::setCost(int x) {
    cost = x;
}

void Node::setLevel(int l) {
    level = l;
}

void Node::setFather(Node* node) {
    if (node != NULL) {
        father = new Node(*node);
    } else {
        father = NULL;
    }
}

void Node::setObstacles(int xObs[], int yObs[]) {
    xObstacle = xObs;
    yObstacle = yObs;
}

void Node::setHeuristicFlag(int flag){
    heuristicFlag = flag;
}

int Node::getCost() {
    return cost;
}

int Node::getLevel() {
    return level;
}

Node* Node::getFather() {
    return father;
}

int Node::getXA() {
    return xA;
}

int Node::getXB() {
    return xB;
}

int Node::getYA() {
    return yA;
}

int Node::getYB() {
    return yB;
}

double Node::getHeuristicCost() {
    if (heuristicFlag == 1) {
        return (sqrt(pow((xA - xB), 2) + pow((yA - yB), 2)));
    } else if (heuristicFlag == 2) {
        return (abs(xA - xB) + abs(yA - yB));
    } else if (heuristicFlag == 3) {
        return (max(abs(xA-xB),abs(yA-yB)));
    } else {
        return 0;
    }
}

double Node::getTotalCost(){
    return (getCost()+getHeuristicCost());
    //return getHeuristicCost();
}