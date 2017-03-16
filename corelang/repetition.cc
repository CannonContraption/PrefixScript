int repeatstart;
int repeatend;

/* \brief Sets repeat start, starts looking for end.
 * 
 * This function is designed to take the beginning of a repeat sequence, store its
 * position in the stream, then look for the end of the repeat block. If it finds the end
 * of the repeat block, it records its position.
 */
bool get_repeat_bounds(){
	if(prs.scriptread)
		repeatstart = prs.scriptfile.tellg();
	else
		repeatstart = cin.tellg();
	string readthis = prs.read();
	while(readthis != "/repeat"){
		readthis = prs.read();
	}
	if(prs.scriptread)
		repeatend = prs.scriptfile.tellg()-7; //length of /repeat
	else
		repeatend = cin.tellg()-7;
}
