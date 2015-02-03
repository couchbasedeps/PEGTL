// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_ONE_HH
#define PEGTL_INTERNAL_ONE_HH

#include "any.hh"
#include "utility.hh"

#include "../analysis/rule_class.hh"

namespace pegtl
{
   namespace internal
   {
      template< bool Want, typename Peek, typename Peek::data_t ... Cs >
      struct one
      {
         using analyze_t = analysis::consumes<>;

         template< typename Input >
         static bool match( Input & in )
         {
            if ( in.size() ) {
               if ( const auto t = Peek::peek( in ) ) {
                  if ( Want == contains( t.data, { Cs ... } ) ) {
                     in.bump( t.size );
                     return true;
                  }
               }
            }
            return false;
         }
      };

      template< bool Want, typename Peek, typename Peek::data_t C >
      struct one< Want, Peek, C >
      {
         using analyze_t = analysis::consumes<>;

         template< typename Input >
         static bool match( Input & in )
         {
            if ( in.size() ) {
               if ( const auto t = Peek::peek( in ) ) {
                  if ( Want == ( t.data == C ) ) {
                     in.bump( t.size );
                     return true;
                  }
               }
            }
            return false;
         }
      };

   } // internal

} // pegtl

#endif
