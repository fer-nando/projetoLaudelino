#include "dbthread.h"

DbThread::DbThread(QObject *parent, int sleepSeg, Management *management) : QThread(parent) {
    this->sleep_seg = sleepSeg;
    this->mgmt = management;
}

void DbThread::run(){
    while(true){
        sleep(sleep_seg);
        cout << "thread exec ";
        mgmt->updateStatusTopology();
    }
}
