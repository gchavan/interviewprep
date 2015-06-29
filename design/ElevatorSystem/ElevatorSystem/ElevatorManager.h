#pragma once

#include "Elevator.h"

struct find_by_floor {
    find_by_floor(const int& floor)
        :m_floor(floor)
    {
    }

    bool operator()(const ElevatorRequest& request)
    {
        return request.requestedFloor == m_floor;
    }

private:
    int m_floor;
};

struct ElevatorRequest
{
    int numberOfPeople;
    int requestedFloor;

    bool operator >(const ElevatorRequest& rhs) const
    {
        return numberOfPeople > rhs.numberOfPeople;
    }
};

class ElevatorManager
{
public:
    ElevatorManager();
    void Request(int requestedFloor);
    
    void PrintRequests();

private:
    void GoToFloor(int requestedFloor);
    shared_ptr<IElevator> GetElevator(int requestedFloor);

private:
    mutex m_elevatorMutex;

    static const int m_totalElevators;
    shared_ptr<vector<shared_ptr<IElevator>>> m_elevators;

    shared_ptr<set<shared_ptr<ElevatorRequest>, greater<ElevatorRequest>>> m_requests;
};
