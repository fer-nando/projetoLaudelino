#ifndef DBTHREAD_H
#define DBTHREAD_H

#include <QThread>
#include <iostream>
#include <management.h>

using namespace std;

class DbThread : public QThread
{
    Q_OBJECT
public:
    explicit DbThread(QObject *parent = 0, int sleepSeg=0, Management* management=0);
    void run();
private:
    int sleep_seg;
    Management* mgmt;
signals:

public slots:

};

#endif // DBTHREAD_H
