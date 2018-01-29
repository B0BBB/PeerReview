#include "RobotDB.h"

bool RobotDB::addRobot(Robot *robot) {
    vectorsUpdated = false;
    mapOfRobots.insert(pair<string, Robot*>(robot->getRobotName(), robot));
}

void RobotDB::deleteRobot(string robotName) {
    vectorsUpdated = false;
    std::map<string, Robot*>::iterator it;
    it = mapOfRobots.find(robotName);
    if ( it != mapOfRobots.end())
    {
        // found it - delete it
        delete it->second;
        mapOfRobots.erase(it);
    }
}

Robot* RobotDB::getRobot(string robotName) {
    std::map<string, Robot*>::iterator it;
    it = mapOfRobots.find(robotName);
    if ( it != mapOfRobots.end())
        return it->second;
    else return NULL;
}

const vector <string>& RobotDB::getRobots() {
    if (!vectorsUpdated){
        updateVectors();
    }
    return robotsVector;
}

const vector <int>& RobotDB::getRanks() {
    if (!vectorsUpdated){
        updateVectors();
    }
    return ranksVector;
}

const vector <int>& RobotDB::getTanks() {
    if (!vectorsUpdated){
        updateVectors();
    }
    return tanksVector;
}

bool RobotDB::isRobotAtLocation(pair<int, int> location) {
    std::map<string, Robot*>::iterator it;
    for (it = mapOfRobots.begin(); it != mapOfRobots.end(); ++it){
        if (it->second->getLocation() == location) return true;
    }
    return false;
}

void RobotDB::updateVectors() {
    std::map<string, Robot*>::iterator it;
    robotsVector.erase(robotsVector.begin(), robotsVector.end());
    ranksVector.erase(ranksVector.begin(), ranksVector.end());
    tanksVector.erase(tanksVector.begin(), tanksVector.end());
    for (it = mapOfRobots.begin(); it != mapOfRobots.end(); ++it){
        robotsVector.push_back( it->second->getRobotName() );
        ranksVector.push_back( it->second->getRobotRank() );
        tanksVector.push_back( it->second->getRobotTank() );
    }
    vectorsUpdated = true;
}

RobotDB::~RobotDB() {
    std::map<string, Robot*>::iterator it;
    for (it = mapOfRobots.begin(); it != mapOfRobots.end(); ++it){
        delete it->second;
        mapOfRobots.erase(it);
    }
    robotsVector.erase(robotsVector.begin(), robotsVector.end());
    ranksVector.erase(ranksVector.begin(), ranksVector.end());
    tanksVector.erase(tanksVector.begin(), tanksVector.end());
}

const map<string, Robot *> &RobotDB::getMapOfRobots() const {
    return mapOfRobots;
}
