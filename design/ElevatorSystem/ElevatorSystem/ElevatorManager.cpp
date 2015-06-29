#pragma once

#include "ElevatorManager.h"

const int ElevatorManager::m_totalElevators = 4;

ElevatorManager::ElevatorManager()
{
    m_elevators = make_shared<vector<shared_ptr<IElevator>>>();
    shared_ptr<IElevator> elevator = nullptr;
    for (int i = 0; i < m_totalElevators; i++)
    {
        elevator = make_shared<Elevator>();
        m_elevators->push_back(elevator);
    }

    m_requests = make_shared<set<shared_ptr<ElevatorRequest>, greater<ElevatorRequest>>>();
}

void ElevatorManager::Request(int requestedFloor)
{
    set<shared_ptr<ElevatorRequest>>::iterator result = std::find_if(m_requests->begin(), m_requests->end(),
        find_by_floor(requestedFloor));

    auto newRequest = make_shared<ElevatorRequest>();
    newRequest->requestedFloor = requestedFloor;
    if (result == m_requests->end())
    {
        newRequest->numberOfPeople = 1;
    }
    else
    {
        int numberOfPeople = (*result)->numberOfPeople;
        m_requests->erase(result);
        newRequest->numberOfPeople = ++numberOfPeople;
    }

    m_requests->insert(newRequest);
}

void ElevatorManager::PrintRequests()
{
    for (auto& request : *m_requests)
    {
        cout << request->requestedFloor << endl;
    }
}

void ElevatorManager::GoToFloor(int requestedFloor)
{
    lock_guard<mutex> lock(m_elevatorMutex);
}

shared_ptr<IElevator> ElevatorManager::GetElevator(int requestedFloor)
{
    shared_ptr<IElevator> elevator = nullptr;
    for (int i = 0; i < m_totalElevators; i++)
    {
        elevator = m_elevators->at(i);
        if (elevator->)
    }
}