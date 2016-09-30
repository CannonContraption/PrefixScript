class corelang{
	private:
		double buff;
	protected:
		commandparser * cparser;
		commandregister * cregister;
	public:
		bool add();
		bool sub();
		bool mul();
		bool div();
		corelang(commandparser par, commandregister reg);
}
