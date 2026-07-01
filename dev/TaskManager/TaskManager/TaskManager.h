#pragma once
#include "Task.h"
#include <vector>
#include <string>
class TaskManager
{
private:
	std::vector<Task> tasks;
public:
	void AddTask(std::string title);
	void ViewTasks() const;
};

