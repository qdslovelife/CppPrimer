class Base
{
public:
    void pub_mem() {}
    void memefcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Pub_Derv : public Base
{

};

class Prot_Derv : protected Base
{

};

class Priv_Derv : private Base
{

};

class Derived_From_Public : public Pub_Derv
{

};

class Derived_From_Prot : public Prot_Derv
{

};

class Derived_From_Priv : public Priv_Derv
{

};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_From_Public dd1;
    Derived_From_Priv dd2;
    Derived_From_Prot dd3;
}