// Software Engineer – Coding Challenge
// Program by Jack Partridge - 19/06/2023

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Machine.h"

void example1();
void example2();
void example3();

int main()
{
    example1();
    example2();
    example3();

    return 0;
}

void example1()
{
    Employee e("Production Manager", "Jack");   // Create an instance of Employee(s)
    Employee e1("Technician", "Bob");

    Machine m("Machine0");              // Create an instance of Machine
    m.setState("IDLE");                 // Set a State for the machine
    m.attach(e);                        // Attach the observer to the machine

    e.update("IDLE", "PRODUCING");      // Updated the observer via the employee

    m.notifyAllObservers();             // NotifyAllObserver(s) for machine0
}

void example2()
{
    Employee e("Production Manager", "Joe");   
    Employee e1("Production Manager", "Jane");
    Employee e2("Production Manager", "Richard");

    Machine m("Machine0");
    m.setState("IDLE");
    m.attach(e);

    Machine m1("Machine1");
    m1.attach(e1);
    m1.attach(e2);
    m1.setState("PRODUCING");

    e2.update("PRODUCING", "STARVED");

    m1.notifyAllObservers();

}

void example3()
{
    Employee e("Technician", "Lucas");
    Employee e1("Technician", "Brett");

    Machine m("Machine0");
    m.setState("STARVED");

    m.attach(e);
    m.attach(e1);

    e.update("STARVED", "IDLE");

    m.notifyAllObservers();

    e1.update("STARVED", "PRODUCING");
    e.update("PRODUCING", "IDLE");

    m.notifyAllObservers();
}
