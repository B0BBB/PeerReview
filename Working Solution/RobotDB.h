#ifndef Robot1_ROBOTDB_H
#define Robot1_ROBOTDB_H

#include <map>
#include <string>
#include "Robot.h"

using namespace std;


class RobotDB {
public:
    Robot *getRobot(string robotName);

    const vector<string> &getRobots();

    const vector<int> &getRanks();

    const vector<int> &getTanks();

    bool isRobotAtLocation(pair<int, int> location);

    bool addRobot(Robot *robot);

    void deleteRobot(string robotName);

    const map<string, Robot *> &getMapOfRobots() const;

    RobotDB() { vectorsUpdated = false; }

    ~RobotDB();

private:
    map<string, Robot *> mapOfRobots;
    vector<string> robotsVector;
    vector<int> ranksVector;
    vector<int> tanksVector;
    bool vectorsUpdated;

    void updateVectors();
};

#endif //Robot1_ROBOTDB_H