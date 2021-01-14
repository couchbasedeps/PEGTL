// Copyright (c) 2020-2021 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#if !defined( __cpp_exceptions )
int main() {}
#else

#include <iostream>

#include <tao/pegtl/contrib/print.hpp>
#include <tao/pegtl/contrib/uri.hpp>

int main()  // NOLINT(bugprone-exception-escape)
{
   tao::pegtl::print_names< tao::pegtl::uri::URI >( std::cout );
   return 0;
}

#endif
