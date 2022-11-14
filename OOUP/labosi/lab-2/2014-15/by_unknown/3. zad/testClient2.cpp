//==== testClient2.cpp
#include <iostream>
#include "concretedatabase.hpp"
#include "abstractdatabase.hpp"
#include "mockdatabase.hpp"
#include "client1.hpp"
#include "client2.hpp"

int main(int argc, char** argv) {
	MockDatabase* pdb = new MockDatabase();
	
	Client2 client(*pdb);
	
	client.transaction();
	
	Client1 client2;
	client2.transaction();
	//assertGetDataWasCalled(*pdb);
}
