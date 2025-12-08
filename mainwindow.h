#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void removeTask();
    void markComplete();
    void clearAllTasks();

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputLayout;
    QHBoxLayout *buttonLayout;
    
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *completeButton;
    QPushButton *clearButton;
    QListWidget *taskList;
    
    void setupUI();
    void connectSignals();
};

#endif // MAINWINDOW_H