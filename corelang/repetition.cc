bool repeatmemory() {
	double tostore;
	int slot;
	string memstore = prs.read();
	string strslot = prs.read();
	slot = prs.toint(strslot);
	if (memstore == "pop") {
		tostore = prs.pop();
	}
	else if (memstore == "top") {
		tostore = prs.top();
	}
	else {
		tostore = prs.todouble(memstore);
	}
}
