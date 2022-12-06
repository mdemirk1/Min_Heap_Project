//Mustafa Dora Demirkir - HW2 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {

    public:
        string vehicle_id;
        string location;
        double distance;
        double speed;
        double time;

    Vehicle(string vehicle_id, string location, double distance, double speed) {
        this->vehicle_id = vehicle_id;
        this->location = location;
        this->distance = distance;
        this->speed = speed;
        this->time = distance / speed;
    }

    Vehicle() {
        this->vehicle_id = "";
        this->location = "";
        this->distance = 0;
        this->speed = 0;
    }

    void setID(string id) {
        this->vehicle_id = id;
    }
    
    void setLoc(string loc) {
        this->location = loc;
    }
    
    void setDist(string dist) {
        this->distance = stod(dist);
    }

    void setSpeed(string speed) {
        this->speed = stod(speed);
    }

    void setTime(string distance, string speed) {
        this->time = stod(distance) / stod(speed);
    }

    double getTime() {
        return this->time;
    }

    string getID() {
        return this->vehicle_id;
    }

    double getSpeed() {
        return this->speed;
    }

    double getDistance() {
        return this->distance;
    }
    
    friend ostream& operator<<(ostream &os, const Vehicle &v) {
        // os << v.vehicle_id << "\t" << v.location << "\t" << v.distance << "\t" 
        // << v.speed << "\t" << v.time;

        os << v.time;

        return os;
    }

    friend bool operator<(Vehicle &l, Vehicle &r) {
        if (to_string(l.getTime()) < to_string(r.getTime())) {
            return true;
        }
        return false;
    }

    friend bool operator>(Vehicle &l, Vehicle &r) {
        if (to_string(l.getTime()) > to_string(r.getTime())) {
            return true;
        }
        return false;
    }

    friend bool operator==(Vehicle &l, Vehicle &r) {
        if (to_string(l.getTime()) == to_string(r.getTime())) {
            return true;
        }
        return false;
    }
    
    friend bool operator>=(Vehicle &l, Vehicle &r) {
        if (to_string(l.getTime()) >= to_string(r.getTime())) {
            return true;
        }
        return false;
    }

    Vehicle& operator=(const Vehicle &other) {
        if (this != &other) {
            this->distance = other.distance;
            this->vehicle_id = other.vehicle_id;
            this->location = other.location;
            this->speed = other.speed;
            this->time = other.time;
        }
        return *this;
    }
};
