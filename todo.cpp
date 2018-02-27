#include "todo.h"
#include "ui_todo.h"

#include <QDebug>
#include <QInputDialog>

ToDo::ToDo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToDo)
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &ToDo::addTask);
}

ToDo::~ToDo()
{
    delete ui;
}

void ToDo::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add Task"),
                                         tr("Task Name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),
                                         &ok);
    if(ok && !name.isEmpty() )
    {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &ToDo::removeTask);
        mTask.append(task);
        ui->taskLayout->addWidget(task);
    }

}

void ToDo::removeTask(Task *task)
{
    mTask.removeOne(task);
    ui->taskLayout->removeWidget(task);
    task->setParent(0);
    delete task;
}
