#include"TodoManager.hpp"
#include <QFile>
#include <QTextStream>
#include <QStringList>

TodoManager::TodoManager() : nextId(1) {}

int TodoManager::findTaskIndex(int id) const {

    for(int i = 0; i < tasks.size(); i++) {
        if(tasks[i].id == id) return i;
    }

    return -1;
}

void TodoManager::addTask(const QString &title, const QString &description) {
    Task newTask(nextId, title, description);
    tasks.push_back(newTask);
    nextId++;
}

void TodoManager::deleteTask(int id) {
    int index = TodoManager::findTaskIndex(id);
    if(index != -1) {
        tasks.erase(tasks.begin() + index);
    }
}

void TodoManager::editTask(int id, const QString &newTitle, const QString &newDescription) {
    int index = TodoManager::findTaskIndex(id);
    if(index != -1) {
        tasks[index].title = newTitle;
        tasks[index].description = newDescription;
    }
}

void TodoManager::toggleCompleted(int id) {
    int index = TodoManager::findTaskIndex(id);
    if(index != -1) {
        tasks[index].completed = !tasks[index].completed;
    }
}

std::vector<Task> TodoManager::getTasks() const {
    return tasks;
}

void TodoManager::saveToFile(const QString &filePath) {
    QFile file(filePath);

    if(!file.open(QIODevice::Text | QIODevice::WriteOnly)) {
        return;
    }

    QTextStream out(&file);

    for(const Task &task : tasks) {
        int completedInt = task.completed ? 1 : 0;

        out << task.id << "|"
            << task.title << "|"
            << task.description << "|"
            << completedInt << "\n";
    }

    file.close();
}

void TodoManager::loadFromFile(const QString &filePath) {
    tasks.clear();
    nextId = 1;
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();

        if(line.trimmed().isEmpty()) continue;

        QStringList parts = line.split("|");
        int id = parts.value(0).toInt();
        QString title = parts.value(1);
        QString description = parts.value(2, "");
        bool completed = parts.value(3).toInt() == 1;

        Task newTask(id, title, description, completed);
        tasks.push_back(newTask);
        if(id >= nextId) {
            nextId = id + 1;
        }
    }

    file.close();
}
