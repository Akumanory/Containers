#include <gtest/gtest.h>
#include "dynamic_array.cpp"
#include "test_classes.h"

TEST(ArrayInsertClass, CompareElements)
{
    int size = 6;
    Array<Test_Class> a(4);
    Test_Class first_array[size] {{1, 12}, {1, 18}, {32, 8}, {45, 45}, {11, 37}, {8, 8}};

    for (int i = 0; i < size; i++)
    {
        a.insert(first_array[i]);
    }
    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        ASSERT_EQ(it.get().test_int2,first_array[count].test_int2);
        count++;
    }

}

TEST(ArrayRemove, CompareElements)
{
    int size = 6;
    Array<int> a(4);
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    int data2[size- 1] {12, 24, 1, 12, 56, 4554, 8080};

    for (int i = 0; i < size; i++)
    {
        a.insert(data[i]);
    }

    a.remove(3);

    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        ASSERT_EQ(it.get(),data2[count]);
        count++;
    }

}

TEST(ArraySet, CompareElements)
{
    int size = 6;
    Array<int> a(4);
    int data[size] {12, 24, 1, 5, 12, 56, 4554, 8080};
    int data2[size] {12, 24, 1, 0, 12, 56, 4554, 8080};

    for (int i = 0; i < size; i++)
    {
        a.insert(data[i]);
    }

    int count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        if (count == 3)
        {
            it.set(0);
        }
        count++;
    }

    count = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        ASSERT_EQ(it.get(),data2[count]);
        count++;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}