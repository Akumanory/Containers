#include <gtest/gtest.h>
#include "linked_list.cpp"
#include "test_classes.h"

TEST(InsertHead_Class, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 6;
    Test_Class first_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};
    Test_Class second_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};

    Unrolled_List<Test_Class> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertTail(first_array[i]);
    }
    
    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        ASSERT_EQ(it.get().test_int2,first_array[count].test_int2);
        count++;
    }
}


TEST(InsertHead_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    int data2[size] {56, 4554, 8080, 12, 24, 1, 5, 12};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertHead(data[i]);
    }
    
    a.iterator();
    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        int temp = it.get();
        std::cout << temp << std::endl;
        ASSERT_EQ(temp,data2[count]);
        count++;
    }
}

TEST(InsertTail_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    // int data2[size] {4554, 8080, 12, 24, 1, 5, 12, 56};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertTail(data[i]);
    }
    
    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        int temp = it.get();
        std::cout << temp << std::endl;
        ASSERT_EQ(temp,data[count]);
        count++;
    }
}

TEST(RemoveHead_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    int data2[size -1] {56, 4554, 12, 24, 1, 5, 12};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertHead(data[i]);
    }
    
    a.removeHead();

    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        int temp = it.get();
        std::cout << temp << std::endl;
        count++;
    }
}

TEST(RemoveTail_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    int data2[size - 1] {12, 24, 1, 5, 12, 56, 4554};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertTail(data[i]);
    }
    
    a.removeTail();

    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        int temp = it.get();
        std::cout << temp << std::endl;
        ASSERT_EQ(temp,data2[count]);
        count++;
    }
}

TEST(HeadShow_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    // int data2[size -1] {56, 4554, 12, 24, 1, 5, 12};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertHead(data[i]);
    }
    ASSERT_EQ(a.head(), data[5]);
}

TEST(TailShow_int, CompareElements)
{
    // Unrolled_List<int> uList;
    int size = 8;
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    // int data2[size -1] {56, 4554, 12, 24, 1, 5, 12};

    Unrolled_List<int> a;

    for (size_t i = 0; i < size; i++)
    {
        a.insertTail(data[i]);
    }
    ASSERT_EQ(a.tail(), data[7]);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}