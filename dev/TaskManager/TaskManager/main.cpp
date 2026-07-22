#include <iostream>
#include "App.h"
int main()
{
    App app;
    app.Run();
}
//My project is a console-based productivity app.
//
//It uses Task, TaskManager, and App classes.
//
//The user can add tasks, complete tasks, sort by priority, and save / load data.
//
//One challenge was keeping active and completed tasks separated while saving and loading.
//
//I improved the project by adding input validation and file persistence.
//
//I learned how class structure makes it easier to expand a project safely.