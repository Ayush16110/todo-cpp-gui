#pragma once
#include<vector>
#include"Task.hpp"
#include<QString>

class TodoManager {
    public:
        TodoManager();

    public:
        void addTask(const QString &title, const QString &description);
        void deleteTask(int id);
        void editTask(int id, const QString &newTitle, const QString &newDescription);
        void toggleCompleted(int id);
        std::vector<Task> getTasks() const;
        void loadFromFile(const QString &filePath);
        void saveToFile(const QString &filePath);


    private:
        std::vector<Task> tasks;
        int nextId;
        int findTaskIndex(int id) const;
};
