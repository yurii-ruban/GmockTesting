#ifndef MOCKUSED_H
#define MOCKUSED_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "used.h"


class MockUsed: public Used
{
public:
    MOCK_METHOD2(concat, string(string first, string second));
    MOCK_METHOD1(copy, string(string str));
    MOCK_METHOD1(revers, string(string str));
};

#endif // MOCKUSED_H
