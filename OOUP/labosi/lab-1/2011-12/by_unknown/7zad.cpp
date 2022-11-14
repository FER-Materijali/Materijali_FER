#include <iostream>

using namespace std;

class AbstractDatabase{
    public:
        virtual int getData()=0; //cisti virtualni funkcijski clan
};

class MockDatabase: public AbstractDatabase{
    public:
        virtual int getData(){
            return 5;
        }
};

class ConcreteDatabase{
    public:
        virtual int getData(){
            return 6;
        }
};

class Client1 {
    ConcreteDatabase myDatabase;
    public :
        int transaction () {
            myDatabase. getData ();
            // ....
        }
};

class Client2 { //koristi injekciju ovisnosti; ovisi o apstraktnom sucelju
    AbstractDatabase & myDatabase;
    public :
        Client2 ( AbstractDatabase & db ): myDatabase(db) {}
    public :
        int transaction () {
            myDatabase. getData (); //myDatabase je tipa Mock
            // ...
        }
};

int main (){
    // construct database
    MockDatabase* pdb = new MockDatabase ();
    // construct test object (`DI `!)
    Client2 client (* pdb );
    // test behaviour #1
    int b;
    b=client.transaction();
    cout<<b<<endl;
    Client1 clientbio;  //klijent bez injekcije ovisnosti
    b=clientbio.transaction();
    cout<<b<<endl;
    //assertGetDataWasCalled (* pdb );
    // test behaviour #2
    // ...
    // test behaviour #3
    // ...
}
