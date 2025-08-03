#include <bits/stdc++.h>
#include "../include/task.hpp"

using namespace std;

int currentId = 1;

void addTask(vector<Task> &tasks)
{
    Task t;
    t.id = currentId++;

    cout << "Enter Title: ";
    getline(cin >> ws, t.title);

    cout << "Enter Description: ";
    getline(cin, t.description);

    cout << "Enter Deadline (YYYY-MM-DD): ";
    cin >> t.deadline;

    cout << "Enter Priority (1-5): ";
    cin >> t.priority;

    t.completed = false;

    tasks.push_back(t);
    cout << "Task added!\n";
}

void listTasks(const vector<Task> &tasks)
{
    cout << left << setw(5) << "ID" << setw(20) << "Title" << setw(12) << "Deadline" << setw(8) << "Priority" << "Status" << endl;
    cout << "-----------------------------------------------------------\n";
    for (const Task &t : tasks)
    {
        cout << left << setw(5) << t.id
             << setw(20) << t.title
             << setw(12) << t.deadline
             << setw(8) << t.priority
             << (t.completed ? " Done" : "Pending") << endl;
    }
}

void deleteTask(vector<Task> &tasks)
{
    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;

    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if (it->id == id)
        {
            tasks.erase(it);
            cout << "Task deleted.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void editTask(vector<Task> &tasks)
{
    int id;
    cout << "Enter Task ID to edit: ";
    cin >> id;

    for (Task &t : tasks)
    {
        if (t.id == id)
        {
            cout << "New Title (" << t.title << "): ";
            getline(cin >> ws, t.title);

            cout << "New Description (" << t.description << "): ";
            getline(cin, t.description);

            cout << "New Deadline (" << t.deadline << "): ";
            cin >> t.deadline;

            cout << "New Priority (" << t.priority << "): ";
            cin >> t.priority;

            cout << "  Task updated!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void markTaskDone(vector<Task> &tasks)
{
    int id;
    cout << "Enter Task ID to mark as done: ";
    cin >> id;

    for (Task &t : tasks)
    {
        if (t.id == id)
        {
            t.completed = true;
            cout << "  Task marked as completed.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void saveTasks(const vector<Task> &tasks, const string &filename)
{
    ofstream file(filename);
    for (const Task &t : tasks)
    {
        file << t.id << ";" << t.title << ";" << t.description << ";" << t.deadline << ";" << t.priority << ";" << t.completed << endl;
    }
    cout << "Tasks saved to " << filename << "\n";
}

void loadTasks( vector<Task>& tasks, const  string& filename) {
     ifstream file(filename);
    if (!file.is_open()) return;

     string line, field;
    while (getline(file, line)) {
         stringstream ss(line);
         vector< string> fields;
        
        while (getline(ss, field, ';')) {
            fields.push_back(field);
        }

        if (fields.size() != 6) {
             cerr << "⚠️ Skipping malformed line: " << line << "\n";
            continue;
        }

        try {
            Task t;
            t.id =  stoi(fields[0]);
            t.title = fields[1];
            t.description = fields[2];
            t.deadline = fields[3];
            t.priority =  stoi(fields[4]);
            t.completed = (fields[5] == "1");

            tasks.push_back(t);
        } catch (...) {
             cerr << "⚠️ Skipping invalid line (stoi failed): " << line << "\n";
            continue;
        }
    }
}
void viewOverdueTasks(const vector<Task> &tasks)
{
    time_t now = time(0);
    tm *now_tm = localtime(&now);

    char today[11];
    strftime(today, 11, "%Y-%m-%d", now_tm);
    string todayStr = today;

    cout << "Overdue Tasks (Before " << todayStr << "):\n";
    for (const Task &t : tasks)
    {
        if (!t.completed && t.deadline < todayStr)
        {
            cout << "Overduse: [ " << t.id << " ]" << t.title << " - Deadline : " << t.deadline << endl;
        }
    }
}
