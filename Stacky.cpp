#include<stack>
using namespace std;
template <class T>
class Stacky: public stack<T> {
public:
    T pop(){
        if(!this->empty()){
            T value = this->top();
            stack<T>::pop();
            return value;
        }
    }
};
