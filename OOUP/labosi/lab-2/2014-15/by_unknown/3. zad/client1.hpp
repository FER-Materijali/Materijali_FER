//==== client1.hpp
class Client1 {
		ConcreteDatabase myDatabase;
	public:
		Client1():
			myDatabase(){}
		void transaction(){
			myDatabase.getData();
		}
};
