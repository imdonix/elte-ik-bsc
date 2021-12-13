// A multimap_view osztály template, ami meglévő
// std::map-ek unióját egy multimap-pé láttatja. A map-ek független módon
// élhetik a saját életüket, de a nézeten keresztül is megváltozhatnak.
//
// A view-hoz add-dal/remove-val egy map-et lehet hozzávenni, ill. elvenni.
// Az erase az adott kulcsú elemeket törli, visszaadja a törölt elemek
// számát. A nézet konvertálódik tetszőleges rendezéssel rendelkező
// multimap-pé, valamint (input)iterátort biztosít a bejáráshoz.

#include <iostream>
#include <algorithm>
#include "mmapview.h"
#include <map>
#include <numeric>
#include <string>
#include "mmapview.h"

struct string_size_less
{

  bool operator()( const std::string& lhs, const std::string& rhs ) const
  {
    return lhs.size() < rhs.size();
  }

};

struct nice
{

  bool operator()( const std::pair<const std::string, std::string>& p ) const
  {
    return p.first == "Ada" || p.first == "C++";
  }

};

struct love
{

  bool operator()( const std::pair<const std::string, std::string>& p ) const
  {
    return p.second == "<3";
  }

};

struct sum
{

  double operator()( double d, const std::pair<const int, double>& p ) const
  {
    return d + p.second;
  }

};

const int max = 1000;

bool check()
{
  multimap_view<int, double> mvid;

  std::map<int, double> m;
  mvid.add( m );

  for( int i = 0; i < max; ++i )
  {
    m[ i ] = 1.23;
  }

  std::map<int, double> mm;
  mvid.add( mm );

  for( int i = 0; i < max; ++i )
  {
    mm[ i ] = 3.21;
  }

  multimap_view<std::string, std::string> mvss;
  std::map<std::string, std::string> la;
  mvss.add( la );

  la[ "C++" ] = ":-)";
  la[ "Ada" ] = ":-/";
  la[ "Fortran" ] = "OMG";

  std::map<std::string, std::string> lb;
  mvss.add( lb );

  lb[ "C++" ] = "<3";
  lb[ "Haskell" ] = ":-o";

  std::map<std::string, std::string> lc;
  mvss.add( lc );

  lc[ "C++" ] = ":-D";
  lc[ "Java" ] = ":-|";
  lc[ "Fortran" ] = ":'(";

  const multimap_view<std::string, std::string> cmvss = mvss;

  if ( 1 != cmvss.count( "Java" ) || 3 != cmvss.count( "C++" ) ||
       mvid.count( 0 ) != mvss.count( "Fortran" ) || 1 != lc.count( "C++" ) ||
       3U != la.size() || max * 1U != m.size() )
  {
    return false;
  }

  mvss.erase( "Fortran" );

  mvss.remove( lb );

  mvid.remove( mm );
  mvid.erase( 0 );

  if ( 0 != lc.count( "Fortran" ) || max * 1U  != mm.size() ||
       m.count( 0 ) == mm.count( 0 ) || mm.size() == m.size() )
  {
    return false;
  }
  mvid.add( mm );
  mvss.add( lb );
  std::multimap<std::string, std::string, string_size_less> a = mvss;
  std::multimap<int, double, std::greater<int> > b = mvid;

  return max - 1 == b.begin() -> first && 6 == a.size() && 1 == b.count( 0 ) &&
         1 == a.count( "Fortran" ) && 0 == a.count( "Brainfuck" );
}

int main()
{
  std::cout
    << "Your solution is "
    << (check() ? "" : "not ")
    << "ready for submission."
    << std::endl;
}
