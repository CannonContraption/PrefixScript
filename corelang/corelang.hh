class corelang{
	private:
		double buff;
	protected:
		commandparser * cparser;
	public:
		bool add();
		bool (*addfunction)();
		bool sub();
		bool mul();
		bool div();
		corelang(commandparser * par);
};
