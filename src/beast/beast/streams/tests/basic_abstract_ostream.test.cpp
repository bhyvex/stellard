//------------------------------------------------------------------------------
/*
    This file is part of Beast: https://github.com/vinniefalco/Beast
    Copyright 2013, Vinnie Falco <vinnie.falco@gmail.com>

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#if BEAST_INCLUDE_BEASTCONFIG
#include "../../BeastConfig.h"
#endif

#include "../basic_abstract_ostream.h"

#include "../../unit_test/suite.h"

namespace beast {

class basic_abstract_ostream_test : public unit_test::suite
{
public:
    class test_stream : public basic_abstract_ostream <char>
    {
    public:
        test_stream&
        operator= (test_stream const&) = delete;

        explicit
        test_stream (unit_test::suite& suite_)
            : m_suite (suite_)
        {
        }

        void write (string_type const& s) override
        {
            m_suite.log << s;
        }

    private:
        unit_test::suite& m_suite;
    };

    void run()
    {
        test_stream ts (*this);

        ts << "Hello";

        pass();
    }
};

BEAST_DEFINE_TESTSUITE(basic_abstract_ostream,streams,beast);

}
