#include "gtest/gtest.h"
#include "../include/DoublyLinkedList.h"

class DoublyLinkedListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        list.append(1);
        list.append(2);
        list.append(4);
    }

    void TearDown() override
    {
    }

    DoublyLinkedList<int> list;
};

TEST_F(DoublyLinkedListTest, AppendTest)
{

    EXPECT_EQ(list.getSize(), 3);

    list.append(3);

    EXPECT_EQ(list.getSize(), 4);
}

TEST_F(DoublyLinkedListTest, InsertTest)
{

    Node<int> *secondNode = list.getHead()->next;
    list.insert(secondNode, 3);

    EXPECT_EQ(list.getSize(), 4);

    EXPECT_EQ(list.getHead()->next->next->data, 3);
}

TEST_F(DoublyLinkedListTest, RemoveTest)
{
    list.remove(2);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.getHead()->next->data, 4);
}

TEST_F(DoublyLinkedListTest, PrintTest)
{

    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 4 \n");
}

TEST_F(DoublyLinkedListTest, ReversePrintTest)
{

    testing::internal::CaptureStdout();
    list.reversePrint();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "4 2 1 \n");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
