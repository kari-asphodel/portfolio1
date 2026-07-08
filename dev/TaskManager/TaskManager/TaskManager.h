#pragma once
#include "Task.h"
#include <vector>
#include <string>
class TaskManager
{
private:
	std::vector<Task> activeTasks;
	std::vector<Task> completedTasks;
public:
	void AddTask(std::string title);
	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;

	void CompleteTask(int index);
	void DisplaySummary() const;
	int GetActiveTaskCount() const;
};

