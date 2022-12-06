#include <iostream>
#include <stdlib.h>

using namespace std;

class Vehicle {

public:
    int vehicle_id;
    string location;
    double distance;
    double speed;
    double time;

Vehicle(int vehicle_id, string location, double distance, double speed) {
    this->vehicle_id = vehicle_id;
    this->location = location;
    this->distance = distance;
    this->speed = speed;
    this->time = distance / speed;
}

Vehicle() {
    this->vehicle_id = 0;
    this->location = "";
    this->distance = 0;
    this->speed = 0;
    this->time = 0;
}

double getTime(){
    return this->time;
}


string getLoc(){
    return this->location;
}

int getID(){
    return this->vehicle_id;
}


double getDistance(){
    return this->distance;
}

double getSpeed(){
    return this->speed;
}

void setTime(double distance, double speed) {
    this->time = distance / speed;
}

void setDist(double dist) {
    this->distance = dist;
}

void setLoc(string loc) {
    this->location = loc;
}

void setSpeed(double speed) {
    this->speed = speed;
}

void setID(int id) {
    this->vehicle_id = id;
}

bool operator<(Vehicle obj) {
    if(this->getTime() < obj.getTime()) {            
        return true;
    }
    return false;
}

bool operator>(Vehicle obj) {
    if(this->getTime() > obj.getTime()) {
        return true;
    }
    return false;
}

bool operator<=(Vehicle obj) {
    if(this->getTime() <= obj.getTime()){
        return true;
    }
    return false;
}

bool operator>=(Vehicle obj) {
    if(this->getTime() >= obj.getTime()){
        return true;
    }
    return false;
}

};