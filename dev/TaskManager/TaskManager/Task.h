#pragma once
#include <string>
class Task
{
private:
	std::string title = "";
	std::string priority = "";
	std::string category = "";
	bool completed = false;

public:
	Task();
	Task(std::string taskTitle, std::string taskPriority, std::string taskCategory, bool isCompleted = false);

	std::string GetTitle()const;
	std::string GetPriority()const;
	std::string GetCategory()const;
	bool IsCompleted() const;

	int GetPriorityScore() const;

	void CompleteTask();

	std::string ToTextLine() const;
};

