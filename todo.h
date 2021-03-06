#ifndef TODO_H
#define TODO_H

#include <QMainWindow>

#include <task.h>

namespace Ui {
class ToDo;
}

class ToDo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ToDo(QWidget *parent = 0);
    ~ToDo();
    void updateStatus();

public slots:
    void addTask();
    void removeTask(Task *task);
    void statusChanged(Task *task);

private:
    Ui::ToDo *ui;
    QVector<Task*> mTask;
};

#endif // TODO_H
