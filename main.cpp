#include "dynamic_array.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    Array<int> a(8);

    for (int i = 0; i < 10; i++)
    {
        a.insert(i + 1);
    }
    
    // a.testm_print();

    for (int i = 0; i < a.size(); i++)
    {
        a[i] *= 2;
    }
    
    // a.testm_print();

    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        // std::cout << "it.get()" << std::endl;
        std::cout << it.get() << std::endl;
    }
    

    // auto it = a.iterator();

    // it.test_print();

    // a.insert(15);
    // // auto temp = it.get();
    // std::cout << "get " << it.get() << std::endl;
    
    // it.set(500);

    // std::cout << "get " << it.get() << std::endl;
    
    // a.insert(5);
    // a.insert(12);
    // a.testm_print();
    // a.insert(1, 100);
    // // a.test_resize();
    // a.testm_print();
    // a.remove(0);
    // a.testm_print();

    // std::cout << a[2] << std::endl;

    // a[2] = 222;
    // std::cout << a[2] << std::endl;
    // // a.remove(2);
    // // a.testm_print();
    // a.insert(88);
    // a.testm_print();
    // a.insert(9, 999);
    // a.testm_print();
    // a.remove(0);
    // a.testm_print();
    // a.remove(0);
    // a.testm_print();
    // a.testm_print();
    // a.insert(88);
    // a.testm_print();
    // a.insert(9, 555);
    // a.testm_print();
    // a.insert(3, 666);
    // a.testm_print();



    // a.insert(400);
    // a.testm_print();
    // a.remove(0);
    // a.testm_print();
    // a.insert(333);
    // a.testm_print();
    // // a.insert(88);
    // a.testm_print();
    // a.insert(9, 999);
    // // a.testm_print();
    // // a.insert(88);
    // a.testm_print();
    // a.insert(9, 555);
    // a.testm_print();
    // a.insert(3, 666);
    // a.testm_print();


    // a.insert(2);
    // a.insert(15);
    // a.insert(5);
    // a.insert(12);
    // a.insert(2);
    // a.testm_print();
    // a.insert(8, 100);
    // a.testm_print();
    // a.insert(888);
    // a.testm_print();
    // a.insert(104);
    // a.testm_print();
    // a.insert(5, 505);
    // a.testm_print();
    // a.testm_print();
    // a.insert(15);
    // a.insert(5);
    // a.insert(12);
    // a.insert(15);
    // a.insert(5);
    // a.testm_print();
    // a.insert(12);
    // a.testm_print();
    // a.insert(15);
    // a.insert(5);
    // a.insert(12);
    // a.insert(12);
    // a.insert(15);
    // a.insert(5);
    // a.insert(12);
    // a.testm_print();
    // a.insert(5);
    // a.testm_print();
}