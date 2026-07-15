#pragma once
#include "Task.h"
#include <vector>
#include <string>
class TaskManager
{
private:
	std::vector<Task> activeTasks;
	std::vector<Task> completedTasks;

	void DisplayTaskList(const std::vector<Task>& taskList, std::string heading) const;
public:
	void AddTask(std::string title, std::string priority, std::string category);
	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;
	void ViewTasksByPriorty(std::string priority) const;

	void CompleteTask(int index);
	void SortActiveTasksByPriority();

	void DisplaySummary() const;
	int GetActiveTaskCount() const;
};

