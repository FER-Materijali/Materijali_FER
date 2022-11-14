class MockDatabase: public AbstractDatabase{
	public:
		virtual void getData(){
			std::cout<<"Mock data.\n";
		};
};
