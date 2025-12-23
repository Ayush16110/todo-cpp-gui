#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "backend/TodoManager.hpp"
#include <QMainWindow>
#include<QListWidgetItem>
#include<QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_taskItem_changed(QListWidgetItem *item);
    void on_editButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    TodoManager manager;
    void refreshUI();
};
#endif // MAINWINDOW_H
