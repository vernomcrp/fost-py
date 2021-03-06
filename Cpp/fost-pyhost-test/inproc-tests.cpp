/*
    Copyright 2009-2015, Felspar Co Ltd. http://support.felspar.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/pyhost>
#include <fost/test>


FSL_TEST_SUITE( inproc );


FSL_TEST_FUNCTION( singleton ) {
    fostlib::python::inproc_host host1;
    FSL_CHECK_EXCEPTION(fostlib::python::inproc_host host2, fostlib::exceptions::not_implemented&);
}


FSL_TEST_FUNCTION( reload ) {
    {
        fostlib::python::inproc_host host;
        FSL_CHECK_NOTHROW( host( "t = True" ) );
        FSL_CHECK( host.eval<bool>("t") );
    }
    {
        fostlib::python::inproc_host host;
        FSL_CHECK_EXCEPTION( host.eval<bool>("t"), fostlib::exceptions::not_implemented& );
    }
}

FSL_TEST_FUNCTION( version ) {
    {
        fostlib::python::inproc_host host;
        host("import sys; print sys.version_info");
    }
}

