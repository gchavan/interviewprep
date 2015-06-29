#pragma once

#include "IElevator.h"

class Elevator
{
public:
    Elevator();

    int GetCurrentFloor();

    ElevatorStatus GetCurrentStatus();

    Response GoToFloor(int requestedFloor);

private:
    void SetCurrentFloor(int floor);

    void SetCurrentStatus(ElevatorStatus status);


    shared_ptr<set<int, greater<int>>> m_stops;
    
    mutex m_floorMutex;
    mutex m_statusMutex;
    mutex m_updateStopsMutex;

    int m_currentFloor;
    ElevatorStatus m_currentStatus;
};