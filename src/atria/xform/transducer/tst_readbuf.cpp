//
// Copyright (C) 2014, 2015 Ableton AG, Berlin. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#include <atria/xform/into_vector.hpp>
#include <atria/xform/transducer/readbuf.hpp>
#include <atria/xform/transducer/cat.hpp>
#include <atria/prelude/comp.hpp>
#include <atria/testing/gtest.hpp>
#include <sstream>

namespace atria {
namespace xform {

TEST(readbuf, constant_sized)
{
  auto stream = std::stringstream{"123456"};
  auto res = into_vector(comp(readbuf<3>(stream), cat));
  EXPECT_EQ(res, (decltype(res) {
        '1', '2', '3', '4', '5', '6' }));
}

TEST(readbuf, dynamic_sized)
{
  auto stream = std::stringstream{"123456"};
  auto res = into_vector(comp(readbuf(stream, 3), cat));
  EXPECT_EQ(res, (decltype(res) {
        '1', '2', '3', '4', '5', '6' }));
}

} // namespace xform
} // namespace atria
