#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockused.h"
#include "worker.h"
#include "used.h"

using namespace std;

using ::testing::Return;
using ::testing::DoAll;


class WorkerTest : public ::testing::Test {
public:
        std::string test_str_1;
        std::string test_str_2;
        std::string test_str_3;
        MockUsed *usd;
        Worker *wrk;
        virtual void SetUp()
        {
            usd= new MockUsed();
            wrk= new Worker(usd);
            test_str_1= "abcd";
            test_str_2 = "";
            test_str_3 = "ABCD";
        }

        virtual void TearDown()
        {
            delete usd;
            delete wrk;
            test_str_1="";
            test_str_2="";
            test_str_3="";
        }

};

class ParTest : public WorkerTest, public ::testing::WithParamInterface<std::string>
{
};

TEST_P(ParTest, concatTest)
{
    std::string str=GetParam();
    EXPECT_CALL(*usd, concat(str, str)).WillOnce(Return(str+str));
    wrk->checker(str, str);
    EXPECT_EQ(str+str, wrk->get_result());
}

INSTANTIATE_TEST_CASE_P(Case1,
                        ParTest,
                        ::testing::Values("meeny", "miny", "moe", "", "ABCCBA"));




TEST_F(WorkerTest, reversTest)
{
    std::string rev_true= "dcba";
    EXPECT_CALL(*usd, revers(test_str_1)).WillOnce(Return(rev_true));
    wrk->checker("revers", test_str_1);
    EXPECT_EQ(rev_true, wrk->get_result());

}

TEST_F(WorkerTest, reversTest_null)
{
    std::string rev_true= "";
    EXPECT_CALL(*usd, revers(test_str_2)).WillOnce(Return(rev_true));
    wrk->checker("revers", test_str_2);
    EXPECT_EQ(rev_true, wrk->get_result());

}

TEST_F(WorkerTest, reversTest_upper)
{
    std::string rev_true= "DCBA";
    EXPECT_CALL(*usd, revers(test_str_3)).WillOnce(Return(rev_true));
    wrk->checker("revers", test_str_3);
    EXPECT_EQ(rev_true, wrk->get_result());

}

TEST_F(WorkerTest, copyTest)
{
    EXPECT_CALL(*usd, copy(test_str_1)).WillOnce(Return(test_str_1));
    wrk->checker("copy", test_str_1);
    EXPECT_EQ(test_str_1, wrk->get_result());

}

TEST_F(WorkerTest, copyTest_null)
{
    EXPECT_CALL(*usd, copy(test_str_2)).WillOnce(Return(test_str_2));
    wrk->checker("copy", test_str_2);
    EXPECT_EQ(test_str_2, wrk->get_result());

}

TEST_F(WorkerTest, copyTest_upper)
{
    EXPECT_CALL(*usd, copy(test_str_3)).WillOnce(Return(test_str_3));
    wrk->checker("copy", test_str_3);
    EXPECT_EQ(test_str_3, wrk->get_result());

}


int main(int argc, char **argv)
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

