#pragma once

#include "Elevator.h"

Elevator::Elevator()
{
    m_stops = make_shared<set<int, greater<int>>>();
}

int Elevator::GetCurrentFloor()
{
    lock_guard<mutex> lock(m_floorMutex);
    return m_currentFloor;
}

void Elevator::SetCurrentFloor(int floor)
{
    lock_guard<mutex> lock(m_floorMutex);
    m_currentFloor = floor;
}

ElevatorStatus Elevator::GetCurrentStatus()
{
    lock_guard<mutex> lock(m_statusMutex);
    return m_currentStatus;
}

void Elevator::SetCurrentStatus(ElevatorStatus status)
{
    lock_guard<mutex> lock(m_statusMutex);
    m_currentStatus = status;
}

Response Elevator::GoToFloor(int requestedFloor)
{
    int currentFloor = GetCurrentFloor();

    ElevatorStatus oldStatus = GetCurrentStatus();
    ElevatorStatus newStatus = oldStatus;

    lock_guard<mutex> lock(m_updateStopsMutex);

    if (oldStatus == ElevatorStatus::GoingUp || oldStatus == ElevatorStatus::GoingDown)
    {
        if ((oldStatus == ElevatorStatus::GoingUp && (currentFloor + 2) < requestedFloor) ||
            (oldStatus == ElevatorStatus::GoingDown && (currentFloor - 2) > requestedFloor))
        {
            return Response::Failure;
        }
    }
    else
    {
        m_stops->clear();
        newStatus = currentFloor > requestedFloor ? ElevatorStatus::GoingDown : ElevatorStatus::GoingUp;
    }

    this->SetCurrentStatus(newStatus);

    m_stops->insert(requestedFloor);

    return Response::Success;
}