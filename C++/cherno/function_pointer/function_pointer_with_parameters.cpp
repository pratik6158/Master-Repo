#include <iostream>

void HelloWorld(int a){
    std::cout<<"Hello world!!Value : "<<a<<std::endl;
}

int main(){

    typedef void(*HelloWorldFunction)(int) ;
    HelloWorldFunction function=HelloWorld;

    function(8);
    return 0;
}