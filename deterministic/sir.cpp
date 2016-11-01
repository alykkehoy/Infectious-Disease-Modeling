
#include <iostream>
#include <vector>
#include <math.h>
#include <boost/numeric/odeint.hpp>
#include <boost/numeric/odeint/stepper_rk4.hpp>

using namespace std;
using namespace boost::numeric::odeint;

template< int MAX_N >
class SIR
{
    typedef std::vector< double > vector;

public:
    typedef vector::iterator iterator;
    typedef vector::const_iterator const_iterator;

    SIR( const size_t N )
        : m_v( N )
    { 
        m_v.reserve( MAX_N );
    }

    SIR()
        : m_v()
    {
        m_v.reserve( MAX_N );
    }

// ... [ implement container interface ]
//]
    const double & operator[]( const size_t n ) const
    { return m_v[n]; }

    double & operator[]( const size_t n )
    { return m_v[n]; }

    iterator begin()
    { return m_v.begin(); }

    const_iterator begin() const
    { return m_v.begin(); }

    iterator end()
    { return m_v.end(); }
    
    const_iterator end() const
    { return m_v.end(); }

    size_t size() const 
    { return m_v.size(); }

    void resize( const size_t n )
    { m_v.resize( n ); }

private:
    std::vector< double > m_v;

};

/*namespace boost { namespace numeric { namespace odeint {

template<size_t N>
struct is_resizeable < SIR<N> >
{
    typedef boost::true_type type;
    static const bool value = type::value;
};

} } }*/

typedef SIR<double> state_Type;

void diff( const state_Type &x , state_Type &dxdt , const double t )
{
    const double beta = 12.0;
    const double alpha = 21.0;

    dxdt[0] = -beta *x[0]*x[1];
    dxdt[1] = beta*x[0]*x[1] - alpha* x[1];
    dxdt[2] = alpha*x[1];
}
void write_diff( const state_Type &x , const double t )
{
    cout << t << '\t' << x[0] << '\t' << x[1] << endl;
}

int main(int argc, char** argv)
{
    state_Type x;
	x[0] = 5.0 ; x[1] = 10.0 ;
    stepper_rk4 < state_Type > srk4;
   //integrate_const( srk4,diff, x , 1.0,10.0,0.1);
   srk4.do_step(diff, x , 1.0,0.1);
}