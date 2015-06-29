#pragma once

#include "pch.h"

enum ElevatorStatus
{
    Free,
    GoingDown,
    GoingUp
};

enum Response
{
    Failure,
    Success
};

class IElevator
{
public:
    virtual int GetCurrentFloor() = 0;
    virtual Response GoToFloor(int floor) = 0;
};