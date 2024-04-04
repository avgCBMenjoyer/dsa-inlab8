#include <iostream>
#include <string>

using namespace std;

int id = 0;

class Ack
{
        int m, n;
        Ack * left, * right;
    public:
        Ack(int m, int n);
        Ack(const Ack &) = delete;

        void printEdges() const;

        ~Ack() { delete left; delete right; }
        string  str() const;

        int calc() const;
        string strPar() const;
};

Ack::Ack(int am, int an):
    m(am), n(an),
    left(nullptr), right(nullptr)
{
    if ( m < 0 ) return;
    if ( !m ) right = new Ack(-1, n + 1);
    else if ( !n ) right = new Ack(m - 1, 1);
    else
    {
        left = new Ack(-1, m - 1);
        right = new Ack(m, n - 1);
    }
}

string Ack::str() const
{
    if ( m < 0 ) return to_string(++id) + "(" + to_string(n) + ")";
    return to_string(m) + ":" + to_string(n);
}

void Ack::printEdges() const
{
    if (left) cout << str() << " --> " << left->str() << '\n';
    if (right)
    {
        cout << str() << " --> " << right->str() << '\n';
        right->printEdges();
    }
}

int main()
{
    Ack a(1, 2);
    //a.printEdges();

    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
        {
            Ack x(i, j);
            cout << "A(" << i << "," << j << ") = " << '\t'
                 << x.calc()
                 << '\t' << x.strPar() << '\n';
        }
}

int Ack::calc() const
{
    return -1;
}

string Ack::strPar() const
{
    return "Oops";
}
