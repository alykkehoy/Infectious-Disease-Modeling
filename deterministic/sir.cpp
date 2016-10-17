#include <iostream>
#include <vector>
#include <boost/numeric/odeint.hpp>

using namespace std;
using namespace boost::numeric::odeint;

//[my_vector
template< int MAX_N >
class my_vector
{
    typedef std::vector< double > vector;

public:
    typedef vector::iterator iterator;
    typedef vector::const_iterator const_iterator;

public:
    my_vector( const size_t N )
        : m_v( N )
    { 
        m_v.reserve( MAX_N );
    }

    my_vector()
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

namespace boost { namespace numeric { namespace odeint {

template<size_t N>
struct is_resizeable< my_vector<N> >
{
    typedef boost::true_type type;
    static const bool value = type::value;
};

} } }

typedef my_vector<3> state_type;

void diff( const state_type &x , state_type &dxdt , const double t )
{
    const double beta = 12.0;
    const double alpha = 21.0;

    dxdt[0] = -beta *x[0]*x[1];
    dxdt[1] = beta*x[0]*x[1] - alpha* x[1];
    dxdt[2] = alpha*x[1];
}

int main()
{
    state_type x;
	x[0] = 5.0 ; x[1] = 10.0 ;

    integrate_const( runge_kutta4< state_type >() ,diff, x , 1.0 , 0.1 );
}