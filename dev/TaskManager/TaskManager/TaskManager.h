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

	void WriteStringBinary(std::ofstream& file, const std::string text) const;
	std::string ReadStringBinary(std::ifstream& file) const;
public:
	void AddTask(std::string title, std::string priority, std::string category);
	void ViewActiveTasks() const;
	void ViewCompletedTasks() const;
	void ViewTasksByPriorty(std::string priority) const;

	void CompleteTask(int index);
	void SortActiveTasksByPriority();

	void DisplaySummary() const;
	int GetActiveTaskCount() const;

	void SaveToTextFile(std::string fileName) const;
	void LoadFromTextFile(std::string fileName);

	void SaveToBinaryFile(std::string fileName) const;
	void LoadFromBinaryFile(std::string fileName);
};

