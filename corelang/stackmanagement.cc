/*! \brief Handles stack pop command

Pops the stack
 */
bool stack_pop(){
  if(!prs.empty())
    cout<<prs.pop();
  else
    prs.pop();
  return true;
}

/*! \brief Handles silentpop command

  Pops the stack without displaying anything
*/
bool stack_silentpop(){
  prs.pop();
  return true;
}

/*! \brief Handles popn command

  Pops the stack and adds a line break
*/
bool stack_popn(){
  if(!prs.empty())
    cout<<prs.pop()<<endl;
  else
    prs.pop();
  return true;
}

/*! \brief handles stack top command

  Displays the top stack number
*/
bool stack_top(){
  if(!prs.empty())
    cout<<prs.top();
  else
    prs.top();
  return true;
}

/*! \brief handles stack topn command

  Displays the top stack number followed by a line break
*/
bool stack_topn(){
  if(!prs.empty())
    cout<<prs.top()<<endl;
  else
    prs.top();
  return true;
}

/*! \brief command to switch stack

  Reads one more after the stack command and sets the stack based on what is entered. If not
  in the range 1-3, screams at user gently. If in that range, switches stack
*/
bool switchstack(){
  string input = prs.read();
  int stacknum = prs.toint(input);
  if(stacknum<4&&stacknum>0){
    prs.setstack(stacknum);
  }
  else{
    cerr<<"\033[1;31mERROR: \033[0;31mInvalid stack number.\033[m"<<endl;
  }
  return true;
}
