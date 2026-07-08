#include "TaskManager.h"
#include <iostream>

void TaskManager::AddTask(std::string title)
{
	activeTasks.push_back(Task(title));
	std::cout << "\nTask added to the crypt.\n";
}

void TaskManager::ViewActiveTasks() const
{
	std::cout << "\n==== ACTIVE TASKS ====\n";
	if (activeTasks.empty())
	{
		std::cout << "No active tasks. The crypt is quiet...suspiciously quiet.\n";
		return;
	}
	for (int i = 0; i < activeTasks.size(); i++)
	{
		std::cout << i + 1 << ". " << activeTasks[i].GetTitle() << "\n";
	}
}

void TaskManager::ViewCompletedTasks() const
{
	std::cout << "\n==== COMPLETED TASKS ====\n";
	if (completedTasks.empty())
	{
		std::cout << "No completed tasks yet. The ghosts remain employed.\n";
		return;
	}
	for (int i = 0; i < completedTasks.size(); i++)
	{
		std::cout << i + 1 << ". " << completedTasks[i].GetTitle() << "\n";
	}
}

void TaskManager::CompleteTask(int index)
{
	if (index >= 0 && index < activeTasks.size())
	{
		activeTasks[index].CompleteTask();
		completedTasks.push_back(activeTasks[index]);
		activeTasks.erase(activeTasks.begin() + index);
		std::cout << "\nTask completed and moved to the completed crypt.\n";
	}
	else
	{
		std::cout << "\nInvalid task number. That task does not exist in this realm.\n";
	}
}

void TaskManager::DisplaySummary()const
{
	std::cout << "\n==== CRYPT SUMMARY====\n";
	std::cout << "Active Tasks: " << activeTasks.size() << "\n";
	std::cout << "Completed Tasks: " << completedTasks.size() << "\n";
	std::cout << "Total Tasks Created: " <<
		activeTasks.size() + completedTasks.size() << "\n";
}

int TaskManager::GetActiveTaskCount() const
{
	return activeTasks.size();
}