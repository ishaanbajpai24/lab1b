#include <iostream>

#include "hash_list.h"

/** Ignore this function until part C of lab 1 */
void iterator_example(hash_list &list)
{
    /** We have to reset the iterator before we use it */
    list.reset_iter();

    /** We want to iterate over all nodes, so keep iterating until we're at the end */
    while (!list.iter_at_end())
    {
        /** Get pointers to key/value pairs */
        std::optional<std::pair<int *, float *>> node_values = list.get_iter_value();

        /** Increment the VALUE. Note that the key remains unchanged */
        node_values.value().second++;

        /** Go to the next element */
        list.increment_iter();
    }
}

int main(int argc, char *argv[])
{
    hash_list list;

    if (list.get_size() != 0)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }

    list.insert(3, 4);
    list.insert(4, 5);

    if (list.get_size() != 2)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }

    if (!list.get_value(3).has_value())
    {
        std::cout << "expected 3 to be in list but it wasn't" << std::endl;
        exit(1);
    }

    if (!list.remove(3))
    {
        std::cout << "Failed to remove 3 from list" << std::endl;
        exit(1);
    }

    if (list.get_value(3).has_value())
    {
        std::cout << "Unexpected 3 in list" << std::endl;
        exit(1);
    }
}
