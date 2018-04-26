#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

int main()
{
    string str = "ABCD";
    string add = "abcd";
    Used doing;
    Worker man(doing);
    Worker woman(doing);
    woman.checker(str, add);
    man.checker("reverse",str);
    cout<<"MAN: "<<man.get_result()<<endl;
    cout<<"WOMAN: "<<woman.get_result()<<endl;
    return 0;
}
