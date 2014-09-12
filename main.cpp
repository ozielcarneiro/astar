/* 
 * File:   main.cpp
 * Author: ozielcarneiro
 *
 * Created on September 27, 2012, 7:00 PM
 */

#include <cstdlib>

#include "Node.h"
#include "Search.h"
#include "IO.h"
#include <iostream>
#include <sstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    IO io;
    string fileStr = io.fileToString("input.txt");
    while (fileStr.at(fileStr.size() - 1) == '\n') {
        fileStr = fileStr.substr(0, fileStr.size() - 1);
    }
    stringstream sstream;
    sstream << fileStr;

    vector<string> lines;

    string line;

    while (getline(sstream, line, '\n')) {
        lines.push_back(line);
    }

    vector<int> endRunLineIndex;
    for (int i = 0; i < lines.size(); i++) {
        if (lines.at(i).compare("") == 0) {
            endRunLineIndex.push_back(i);
        }
    }
    endRunLineIndex.push_back(lines.size());

    int runStart = 0;
    stringstream nodesStream;
    stringstream pathStream;
    nodesStream << "\t\t\tNodes Expanded\n\t\tEuclidean\tManhattan\tChessboard";
    pathStream << "\nOptimal Path Solution:";
    for (int i = 0; i < endRunLineIndex.size(); i++) {
        int runFinish = endRunLineIndex.at(i);
        stringstream runStream;
        for (int j = runStart; j < runFinish; j++) {
            runStream << lines.at(j) << endl;
        }
        //cout << "run " << i << ":\n" << runStream.str() << endl;
        Node start(runStream.str());
        Search search;
        nodesStream << "\nInput" << i+1 <<":";
        pathStream << "\nInput" << i+1 <<":";
        for (int j = 1; j <= 3; j++) {
            Node goal;
            bool success = search.aStar(&start, &goal, j);
            if (success) {
                nodesStream << "\t\t" << search.getVisitedCounter();
                if(j==1){
                    pathStream << " " << goal.getPath();
                }
                //cout << search.getVisitedCounter() << endl;
                //cout << goal.getPath() << endl;
            } else {
                nodesStream << "\t\t-";
                if(j==1){
                    pathStream << " -1";
                }
                //cout << -1 << endl;
            }
        }
        runStart = runFinish + 1;
    }
    
    stringstream outStream;
    outStream << nodesStream.str() << endl;
    outStream << pathStream.str() << endl;

    io.stringToFile("output.txt",outStream.str());

    //    Node start;
    //
    //    start.setMapSize(7);
    //    start.setFather(NULL);
    //    start.setA(2, 3);
    //    start.setB(5, 6);
    //    start.setCost(0);
    //    start.setHeuristicFlag(1);
    //    start.setLevel(0);
    //    start.setObstaclesN(2);
    //    int obsX[] = {3, 5};
    //    int obsY[] = {6, 3};
    //    start.setObstacles(obsX, obsY);
    //    start.setMoveCost(2);
    //
    //    Node goal;
    //
    //    Search search;
    //    for (int i = 1; i <= 3; i++) {
    //        bool success = search.aStar(&start, &goal, i);
    //
    //        if (success) {
    //            cout << search.getVisitedCounter() << endl;
    //            cout << goal.getPath() << endl;
    //        } else {
    //            cout << -1 << endl;
    //        }
    //
    //
    //    }

    //    bool success = search.aStar(&start, &goal, 1);
    //
    //    if (success) {
    //        cout << search.getVisitedCounter() << endl;
    //        cout << goal.getPath() << endl;
    //    } else {
    //        cout << -1 << endl;
    //    }

    return 0;
}

