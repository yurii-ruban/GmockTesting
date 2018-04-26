#include "worker.h"

Worker::Worker(Used *new_item): item(new_item){}

string Worker::get_result()
{
    return summary;
}

void Worker::checker(string first, string second)
{
    if(first=="copy")
    {
        summary=item->copy(second);
    }
    else if(first=="revers")
    {
        summary=item->revers(second);
    }
    else
    {
        summary=item->concat(first,second);
    }
}
