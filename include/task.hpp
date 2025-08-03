#ifndef TASK_HPP
#define TASK_HPP

#include <string>
using namespace std;
struct Task {
    int id;
    string title;
    string description;
    string deadline;
    int priority;         
    bool completed;
};

void addTask(vector<Task>& tasks);
void listTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void editTask(vector<Task>& tasks);
void markTaskDone(vector<Task>& tasks);
void viewOverdueTasks(const vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks, const string& filename);
void loadTasks(vector<Task>& tasks, const string& filename);

#endif
