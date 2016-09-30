class corelang{
	private:
		double buff;
	protected:
		commandparser * cparser;
	public:
		static bool add();
		bool sub();
		bool mul();
		bool div();
		corelang(commandparser * par);
};
