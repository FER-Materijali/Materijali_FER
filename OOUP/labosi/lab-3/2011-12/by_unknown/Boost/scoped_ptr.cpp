#include <iostream>
#include <boost/scoped_ptr.hpp>

class Writer
{
public:
    void Write(const char *text)
    {
        std::cout << "Writer: " << text << "\n";
    }

    ~Writer()
    {
        std::cout << "Destructing writer\n";
    }
};

typedef boost::scoped_ptr<Writer> WriterPtr;
//typedef Writer* WriterPtr;

int main()
{
    WriterPtr writer(new Writer);
    writer->Write("Hello boost");

    return 0;
}