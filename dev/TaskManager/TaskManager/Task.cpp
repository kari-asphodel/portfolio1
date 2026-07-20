#include "Task.h"
Task::Task()
{
    title = "";
    priority = "Low";
    category = "General";
    completed = false;
}
Task::Task(std::string taskTitle, std::string taskPriority, std::string taskCategory, bool isCompletd)
{
    title = taskTitle;
    priority = taskPriority;
    category = taskCategory;
    completed = isCompleted;
}

std::string Task::GetTitle() const
{
    return title;
}
std::string Task::GetPriority() const
{
    return priority;
}
std::string Task::GetCategory() const
{
    return category;
}

bool Task::IsCompleted() const
{
    return completed;
}

void Task::CompleteTask()
{
    completed = true;
}
int Task::GetPriorityScore() const
{
    if (priority == "HIGH" || priority == "High" || priority == "high")
    {
        return 3; 
    }
    else if (priority == "MEDIUM" || priority == "Medium" || priority == "medium")
    {
        return 2;
    }
    else if (priority == "LOW" || priority == "Low" || priority == "low")
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

std::string Task::ToTextLine() const
{
    std::string completedText = completed ? "1" : "0";

    return title + "|" + priority + "|" + category + "|" + completedText;
}