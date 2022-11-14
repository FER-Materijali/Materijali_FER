#include <iostream>

class Command;

class Queue 
{
public:

    Queue() 
    {
        add_ = remove_ = 0; 
    }

    void Enque(Command* c) 
    {
        array_[add_] = c;
        add_ = (add_ + 1) % SIZE; 
    }

    Command* Deque() 
    {
        int temp = remove_;
        remove_ = (remove_ + 1) % SIZE;
        return array_[temp]; 
    }

private:

    enum { SIZE = 10 };
    Command*  array_[SIZE];
    int       add_;
    int       remove_;
};

class File
{
private:

    char _name[30];

public:

    File(char *name)
    {
        strcpy(_name, name);
    }

    void Unarchive()
    {
        std::cout << "Unarchive " << _name << std::endl;
    }

    void Compress()
    {
        std::cout << "Compress " << _name << std::endl;
    }

    void Transfer()
    {
        std::cout << "Transfer " << _name << std::endl;
    }
};

class Command
{
private:

    typedef void (File::* Action)();
    Action _action;
    File *_receiver;

public:

    Command(File *file, Action action)
    {
        _receiver = file;
        _action = action;
    }

    void Execute()
    {
        (_receiver->*_action)();
    }
};

Command *Input[8] = 
{
    new Command(new File("irImage.dat"),    &File::Unarchive),
    new Command(new File("screenDump.jpg"), &File::Transfer),
    new Command(new File("paper.ps"),       &File::Unarchive),
    new Command(new File("widget.tar"),     &File::Compress),
    new Command(new File("esmSignal.dat"),  &File::Unarchive),
    new Command(new File("msword.exe"),     &File::Transfer),
    new Command(new File("ecmSignal.dat"),  &File::Compress),
    new Command(new File("image.gif"),      &File::Transfer)
};

int main()
{
    Queue que;

    for (int i = 0; i < 8; i++)
    {
        que.Enque(Input[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        Command *cmd = que.Deque();
        cmd->Execute();
    }

    return 0;
}