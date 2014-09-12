/* 
 * File:   Search.cpp
 * Author: ozielcarneiro
 * 
 * Created on September 13, 2012, 6:43 PM
 */

#include "Search.h"
#include <iostream>

using namespace std;

Search::Search() {
}

Search::Search(const Search& orig) {
}

Search::~Search() {
}

bool Search::bfs(Node* start, Node* goal) {
    Node current;
    current = *start;
    while (1) {
        if (current.checkGoal()) {
            *goal = current;
            return 1;
        } else {
            if (current.moveUp() != NULL) {
                Node next;
                next = *current.moveUp();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveRight() != NULL) {
                Node next;
                next = *current.moveRight();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveDown() != NULL) {
                Node next;
                next = *current.moveDown();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveLeft() != NULL) {
                Node next;
                next = *current.moveLeft();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (searchQueue.size() == 0) {
                return 0;
            } else {
                visited.push_back(current);
                current = searchQueue.front();
                searchQueue.erase(searchQueue.begin());
            }
        }
    }
}

bool Search::ucs(Node* start, Node* goal) {
    Node current;
    current = *start;
    searchQueue.clear();
    visited.clear();
    while (1) {
        if (current.checkGoal()) {
            *goal = current;
            return 1;
        } else {
            if (current.moveUp() != NULL) {
                Node next;
                next = *current.moveUp();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveRight() != NULL) {
                Node next;
                next = *current.moveRight();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveDown() != NULL) {
                Node next;
                next = *current.moveDown();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveLeft() != NULL) {
                Node next;
                next = *current.moveLeft();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (searchQueue.size() == 0) {
                return 0;
            } else {
                visited.push_back(current);
                sortQueue();
                current = searchQueue.front();
                searchQueue.erase(searchQueue.begin());
            }
        }
    }
}

bool Search::aStar(Node* start, Node* goal, int flag) {
    Node current;
    current = *start;
    current.setHeuristicFlag(flag);
    searchQueue.clear();
    visited.clear();
    visitedCounter = 0;
    while (1) {
        if (current.checkGoal()) {
            *goal = current;
            return 1;
        } else {
            if (current.moveUp() != NULL) {
                Node next;
                next = *current.moveUp();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveRight() != NULL) {
                Node next;
                next = *current.moveRight();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveDown() != NULL) {
                Node next;
                next = *current.moveDown();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (current.moveLeft() != NULL) {
                Node next;
                next = *current.moveLeft();
                if (checkVisited(&next)) {
                    searchQueue.push_back(next);
                }
            }
            if (searchQueue.size() == 0) {
                return 0;
            } else {
                visited.push_back(current);
                sortQueue();
                current = searchQueue.front();
                visitedCounter++;
                searchQueue.erase(searchQueue.begin());
                //cout << current.getTotalCost() << endl;
            }
        }
    }
}


bool Search::checkVisited(Node* node) {
    for (int i = 0; i < visited.size(); i++) {
        if ((node->getXA()) == visited[i].getXA() && (node->getYA()) == visited[i].getYA()
                && (node->getXB()) == visited[i].getXB() && (node->getYB()) == visited[i].getYB()) {
            return 0;
        }
    }
    return 1;
}

void Search::sortQueue() {
    searchQueue = mergeSort(searchQueue);
}

vector<Node> Search::mergeSort(vector<Node> queue) {
    if (queue.size() == 1) {
        return queue;
    } else {
        vector<Node> a;
        vector<Node> b;
        for (int i = 0; i < queue.size(); i++) {
            if (i < queue.size() / 2.0)
                a.push_back(queue.at(i));
            else
                b.push_back(queue.at(i));
        }
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }
}

vector<Node> Search::merge(vector<Node> a, vector<Node> b) {
    vector<Node> outVector;
    int aInd = 0, bInd = 0;
    while (aInd < a.size() || bInd < b.size()) {
        if (aInd < a.size() && bInd < b.size()) {
            if (a.at(aInd).getTotalCost() <= b.at(bInd).getTotalCost()) {
                outVector.push_back(a.at(aInd));
                aInd++;
            } else {
                outVector.push_back(b.at(bInd));
                bInd++;
            }
        } else {
            if (aInd < a.size()) {
                outVector.push_back(a.at(aInd));
                aInd++;
            } else {
                outVector.push_back(b.at(bInd));
                bInd++;
            }
        }
    }
    return outVector;
}

int Search::getVisitedCounter(){
    return visitedCounter;
}