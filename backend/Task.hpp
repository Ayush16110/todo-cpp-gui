#pragma once
#include<QString>

struct Task {
    int id;
    QString title;
    QString description;
    bool completed;

    Task(int id, const QString &title, const QString &description, bool completed = false)
        : id(id), title(title), description(description), completed(completed) {}
};
