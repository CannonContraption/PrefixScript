#include<stack>
using namespace std;
template <class T>
class Stacky: public stack<T> {
public:
    T pop(){
        if(!this->empty()){
            T number = this->top();
            stack<T>::pop();
            return number;
        } else {
            return -666;
        }
    }
};
