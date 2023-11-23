#include<iostream>
template <typename Comparable>
class  A
{
public:

    Comparable root;

    void set_root(Comparable & x)
    {
        root = x;
    }

    class a
    {
        Comparable aroot;

        void set_a(Comparable & x)
        {
            aroot = x;
        }
        void p(){
            std::cout<<"a"<<std::endl;
        }
    };
    a bya;

    
};