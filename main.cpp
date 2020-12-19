#include "dynamic_array.cpp"
#include "linked_list.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    Unrolled_List<double> a;

    a.insertHead(150);
    a.insertHead(160);
    a.insertHead(404);
    a.insertTail(2);
    a.insertTail(3);


    a.insertTail(4);
    // a.insertHead(888);
    a.insertTail(5);
    // a.insertTail(6);
    // a.insertTail(7);
    // a.insertTail(8);
    
    a.print_head_chunk();
    a.print_tail_chunk();

    auto it = a.iterator();

    std::cout << "HasNext " << it.hasNext() << std::endl;
    // std::cout << "HasPrev " << it.hasPrev() << std::endl;
    std::cout << "Iterator " << std::endl;
    int i = 0;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        // it.set(12);
        std::cout << it.get() << std::endl;
        // it.remove();
        if(it.get() == 3)
        {
            it.remove();
            // it.insert(5454);
        }
        // if (i == 1)
        // {
        //     it.insert(5454);
        // }
        // i++;
        
    }
    std::cout << " " << std::endl;
    std::cout << "Iterator2 " << std::endl;
    for (auto it = a.iterator(); it.hasNext(); it.next())
    {
        // it.set(12);
        std::cout << it.get() << std::endl;   
    }
    // a.print_head_chunk();

    // a.insertHead(404);

    
    
    
    
    
    
    
    
    
    // a.print_head_chunk();

    // a.print_tail_chunk();

    // a.insertTail(333);
    
    // a.print_tail_chunk();

    // a.insertHead(888);

    // a.print_tail_chunk();

    // a.insertHead(777);

    // a.print_tail_chunk();

    // a.print_head_chunk();

    // a.insertTail(123);

    // a.print_tail_chunk();

    // a.removeHead();

    // a.print_head_chunk();

    // a.removeTail();

    // a.print_tail_chunk();

    // a.removeHead();

    // a.print_head_chunk();


    // a.removeTail();
    
    // a.print_tail_chunk();

    // a.removeHead();

    // a.print_head_chunk();

    // a.insertTail(999);

    // a.print_tail_chunk();

    // a.insertHead(111);
    
    // a.print_head_chunk();

    // a.print_tail_chunk();

    // a.removeHead();

    // a.print_head_chunk();

    // a.removeHead();

    // a.print_head_chunk();

    // a.removeHead();

    // a.print_head_chunk();

    // a.removeTail();

    // a.print_tail_chunk();

    // a.~Unrolled_List();

    // std::cout << "head element " << a.head() << std::endl;
    // std::cout << "tail element " << a.tail() << std::endl;
    // std::cout << "count of elements " << a.size() << std::endl;
    // int b[15];

    // int* c = b;

    // // new (c) int(1);
    // // new (c + 1) int(1);

    // for (int i = 0; i < 15; i++)
    // {
    //     new (c + i) int(i * 4);
    //     std::cout << b[i] << " " << std::endl;
    // }
    



    // Array<int> a(8);

    // for (int i = 0; i < 10; i++)
    // {
    //     a.insert(i + 1);
    // }
    
    // // a.testm_print();

    // for (int i = 0; i < a.size(); i++)
    // {
    //     a[i] *= 2;
    // }
    
    // // a.testm_print();

    // for (auto it = a.iterator(); it.hasNext(); it.next())
    // {
    //     // std::cout << "it.get()" << std::endl;
    //     std::cout << it.get() << std::endl;
    // }
    

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