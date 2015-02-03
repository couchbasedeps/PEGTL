// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#include "rule_impl.hh"

namespace pegtl
{
   void unit_test()
   {
      verify< list_must< one< 'a' >, one< ',' > > >( "", false, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "b", false, 1, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( ",", false, 1, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( ",a", false, 2, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a,", -1, 2, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a", true, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a,a", true, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a,b", -1, 3, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a,a,a", true, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a,a,a,a", true, 0, __LINE__ );

      verify< list_must< one< 'a' >, one< ',' > > >( "a ", true, 1, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( " a", false, 2, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a ,a", true, 3, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' > > >( "a, a", -1, 0, __LINE__ );

      verify< list_must< one< 'a' >, one< ',' >, blank > >( "a ", true, 1, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' >, blank > >( " a", false, 2, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' >, blank > >( "a ,a", true, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' >, blank > >( "a, a", true, 0, __LINE__ );
      verify< list_must< one< 'a' >, one< ',' >, blank > >( " a , a ", false, 7, __LINE__ );
   }

} // pegtl

#include "main.hh"
