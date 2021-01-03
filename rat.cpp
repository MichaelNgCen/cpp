#include <iostream>
using namespace std;
class Rat
{
    private:
    int n;
    int d;
    public:
    Rat()
    {
        n=0;
        d=1;
    }
    Rat(int i, int j)
    {
        n=i;
        d=j;
    }
    Rat(int i)
    {
        n=i;
        d=1;
    }
    int getN(){ return n;}
    int getD(){ return d;}
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    Rat operator+(Rat r)
    {
        Rat t;
        t.n=n*r.d+d*r.n;
        t.d=d*r.d;
        return t;
    }
    Rat operator-(Rat r) 
    {
        Rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        return t;
    }
    Rat operator*(Rat r) 
    {
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        return t;
    }
    Rat operator/(Rat r) 
    {
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        return t;
    }
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
};
int gcd(int a, int b) 
{
    if(b == 0) 
    {
        return a;
    }
    else 
    {
        return gcd(b, a % b);
    }
}
ostream& operator<<(ostream& os, Rat r)
{
    if(r.n>=r.d)
    {
        if(r.n%r.d==0)
        {
            os<<r.n/r.d<<endl;
        } 
        else 
        {
            int x=gcd(r.n%r.d,r.d);
            os<<r.n/r.d<<" "<<(r.n%r.d)/x<<" / "<<(r.d)/x<<endl;
        }
    } 
    else if(r.n==0)
    {
        os<<r.n<<endl;
    } 
    else 
    {
        int x=gcd(r.n%r.d,r.d);
        os<<r.n/x<<" / "<<r.d/x<<endl;
    }
    return os;
}
Rat reduce(int &i, int &j)
{
    for(int a=i;a>0;a--)
    {
        if(i%a==0 && j%a==0)
        {
            i=i/a;
            j=j/a;
            break;
        }
    }
    return Rat(i,j);
}
istream& operator>>(istream& is, Rat& r)
{
    is>>r.n>>r.d;
    reduce(r.n,r.d);
    return is;
}
int main() 
{
    Rat r1(5, 2), r2(3, 2);
    cout<<"r1: "<<r1<< endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    r1 = r2;
    r2 = r1 * r2;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    return 0;
}
