#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    connectSignals();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    mainLayout = new QVBoxLayout(centralWidget);
    inputLayout = new QHBoxLayout();
    buttonLayout = new QHBoxLayout();
    
    // Task input field
    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Enter a new task...");
    taskInput->setMinimumHeight(35);
    
    // Add button
    addButton = new QPushButton("Add", this);
    addButton->setMinimumHeight(35);
    addButton->setStyleSheet("background-color: #4CAF50; color: white; font-weight: bold;");
    
    // Input layout
    inputLayout->addWidget(taskInput);
    inputLayout->addWidget(addButton);
    
    // Task list
    taskList = new QListWidget(this);
    taskList->setStyleSheet("QListWidget::item { padding: 10px; }");
    
    // Action buttons
    completeButton = new QPushButton("Mark Complete", this);
    completeButton->setStyleSheet("background-color: #2196F3; color: white;");
    
    removeButton = new QPushButton("Remove", this);
    removeButton->setStyleSheet("background-color: #f44336; color: white;");
    
    clearButton = new QPushButton("Clear All", this);
    clearButton->setStyleSheet("background-color: #FF9800; color: white;");
    
    // Button layout
    buttonLayout->addWidget(completeButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(clearButton);
    
    // Main layout assembly
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(taskList);
    mainLayout->addLayout(buttonLayout);
    
    // Set margins and spacing
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(10);
}

void MainWindow::connectSignals()
{
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);
    connect(completeButton, &QPushButton::clicked, this, &MainWindow::markComplete);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearAllTasks);
    
    // Allow adding task by pressing Enter
    connect(taskInput, &QLineEdit::returnPressed, this, &MainWindow::addTask);
}

void MainWindow::addTask()
{
    QString task = taskInput->text().trimmed();
    
    if (task.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a task!");
        return;
    }
    
    QListWidgetItem *item = new QListWidgetItem(task);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    taskList->addItem(item);
    
    taskInput->clear();
    taskInput->setFocus();
}

void MainWindow::removeTask()
{
    QListWidgetItem *currentItem = taskList->currentItem();
    
    if (!currentItem) {
        QMessageBox::warning(this, "Warning", "Please select a task to remove!");
        return;
    }
    
    int row = taskList->row(currentItem);
    delete taskList->takeItem(row);
}

void MainWindow::markComplete()
{
    QListWidgetItem *currentItem = taskList->currentItem();
    
    if (!currentItem) {
        QMessageBox::warning(this, "Warning", "Please select a task to mark as complete!");
        return;
    }
    
    if (currentItem->checkState() == Qt::Checked) {
        // Unmark as complete
        currentItem->setCheckState(Qt::Unchecked);
        QFont font = currentItem->font();
        font.setStrikeOut(false);
        currentItem->setFont(font);
        currentItem->setForeground(Qt::black);
    } else {
        // Mark as complete
        currentItem->setCheckState(Qt::Checked);
        QFont font = currentItem->font();
        font.setStrikeOut(true);
        currentItem->setFont(font);
        currentItem->setForeground(Qt::gray);
    }
}

void MainWindow::clearAllTasks()
{
    if (taskList->count() == 0) {
        QMessageBox::information(this, "Info", "The list is already empty!");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", 
                                   "Are you sure you want to clear all tasks?",
                                   QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        taskList->clear();
    }
}