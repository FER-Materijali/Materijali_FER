#include <cstdio>

class Base
{
    public:
        virtual void set(int x) = 0;
        virtual int get() = 0;
};

class CoolClass : public Base
{
    public:
        virtual void set(int x)
        {
            x_ = x;
        }

        virtual int get()
        {
            return x_;
        }

    private:
        int x_;
};

class PlainOldClass
{
    public:
        void set(int x)
        {
            x_ = x;
        }

        int get()
        {
            return x_;
        }

    private:
        int x_;
};

int main()
{
    PlainOldClass* poc = new PlainOldClass;
    Base* pb = new CoolClass;
    poc->set(42);
    pb->set(42);

    return 0;
} 