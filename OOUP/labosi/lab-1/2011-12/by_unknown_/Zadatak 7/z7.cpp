#include <cstdio>
#include "mockDatabase.hpp"
#include "client2.hpp"

void assertGetDataWasCalled(AbstractDatabase& pdb)
{
    // ...
}

int main()
{
    // construct database
    MockDatabase* pdb = new MockDatabase();

    // construct test object (`DI `!)
    Client2 client(* pdb);

    // test behaviour #1
    client.transaction();
    assertGetDataWasCalled(* pdb);

    // test behaviour #2
    // ...
    // test behaviour #3
    // ...

    return 0;
}