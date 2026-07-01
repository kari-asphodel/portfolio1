#include "TaskManager.h"
#include <iostream>

void TaskManager::AddTask(std::string title)
{
	tasks.push_back(Task(title));
	std::cout << "\nTask added to the crypt.\n";
}

void TaskManager::ViewTasks() const
{
	std::cout << "\n==== TASK CRYPT ====\n";
	if (tasks.empty())
	{
		std::cout << "The crypt is empty. No tasks haunt you yet...";
		return;
	}
	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << i + 1 << ". " << tasks[i].GetTitle() << "\n";
	}
}