#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QString>
#include<QListWidget>
#include<QListWidgetItem>
#include<QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(
        ui->taskList,
        &QListWidget::itemChanged,
        this,
        &MainWindow::on_taskItem_changed
    );

    manager.loadFromFile("tasks.txt");
    refreshUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshUI()
{
    ui->taskList->blockSignals(true);
    ui->taskList->clear();

    std::vector<Task> tasks = manager.getTasks();

    for (const Task &task : tasks) {
        QString text = task.title;
        if (!task.description.trimmed().isEmpty()) {
            text += "\n" + task.description;
        }

        QListWidgetItem *item = new QListWidgetItem(text);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(task.completed ? Qt::Checked : Qt::Unchecked);
        item->setData(Qt::UserRole, task.id);
        item->setForeground(task.completed ? Qt::gray : Qt::black);

        ui->taskList->addItem(item);
    }

    ui->taskList->blockSignals(false);
}


void MainWindow::on_addButton_clicked() {
    QString title = ui->taskTitle->text().trimmed();
    QString description = ui->taskDescription->text().trimmed();

    if(title.isEmpty()) {
        return;
    }

    manager.addTask(title, description);

    ui->taskTitle->clear();
    ui->taskDescription->clear();

    refreshUI();
}

void MainWindow::on_deleteButton_clicked() {
    QListWidgetItem *item = ui->taskList->currentItem();

    if(!item) {
        return;
    }

    int id = item->data(Qt::UserRole).toInt();

    manager.deleteTask(id);

    refreshUI();
}

void MainWindow::on_taskItem_changed(QListWidgetItem *item) {
    if(!item) {
        return;
    }

    int id = item->data(Qt::UserRole).toInt();

    manager.toggleCompleted(id);

    if (item->checkState() == Qt::Checked) {
        item->setForeground(Qt::gray);
    } else {
        item->setForeground(Qt::black);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    manager.saveToFile("tasks.txt");
    event->accept();
}

void MainWindow::on_editButton_clicked() {
    QListWidgetItem *item = ui->taskList->currentItem();

    if(!item) {
        return;
    }

    int id = item->data(Qt::UserRole).toInt();

    QString oldText = item->text();
    QStringList line = oldText.split("\n");

    QString oldTitle = line.value(0);
    QString oldDescription = line.value(1);

    bool ok;

    QString newTitle = QInputDialog::getText(this, "Edit task", "Title: ", QLineEdit::Normal, oldTitle, &ok);

    if(!ok || newTitle.trimmed().isEmpty()) return;

    QString newDescription = QInputDialog::getText(this, "Edit task", "Description: ", QLineEdit::Normal, oldDescription, &ok);

    if(!ok) return;

    manager.editTask(id, newTitle.trimmed(), newDescription.trimmed());
    refreshUI();
}
