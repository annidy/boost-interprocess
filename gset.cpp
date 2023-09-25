#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    boost::interprocess::shared_memory_object shdmem(boost::interprocess::open_or_create, "Highscore", boost::interprocess::read_write, 1024);
    if (argc > 1)
    {
        boost::interprocess::mapped_region region(shdmem, boost::interprocess::read_write);
        int *i1 = static_cast<int *>(region.get_address());
        *i1 = atoi(argv[1]);
        std::cout << "set " << *i1 << std::endl;
    }
    else
    {
        boost::interprocess::mapped_region region2(shdmem, boost::interprocess::read_only);
        int *i2 = static_cast<int *>(region2.get_address());
        std::cout << *i2 << std::endl;
    }
}