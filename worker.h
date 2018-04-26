#ifndef WORKER_H
#define WORKER_H

#include <string>
#include "used.h"
using namespace std;


class Worker
{
private:
    string summary;
    Used *item;
public:
    Worker(Used *new_item);
    string get_result();
    void checker(string first, string second);
};

#endif // WORKER_H
