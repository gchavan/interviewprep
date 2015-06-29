#include "ElevatorManager.h"

int main()
{
    auto elevatorManager = make_shared<ElevatorManager>();
    elevatorManager->Request(5);
    elevatorManager->Request(2);
    elevatorManager->Request(50);
    elevatorManager->Request(8);
    elevatorManager->Request(5);
    elevatorManager->Request(50);
    elevatorManager->Request(5);

    elevatorManager->PrintRequests();

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}