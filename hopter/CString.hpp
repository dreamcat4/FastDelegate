#ifndef altstr__h_
#define altstr__h_

#include <string>
#include <stdarg.h>
#include <stdio.h>

// This is a quick-n-dirty implementation of a CString replacement.
// It promises nothing more than to provide enough functionality to get
// this program to run.
// Note that I have really never used CString, so the information to
// implement the members that are used in this program come from
// online documentation at http://msdn.microsoft.com/library/default.asp?url=/library/en-us/vcmfc98/html/_mfc_cstring.asp
// Also, I have only used VC++ a few times, a long time ago, so
// I really do not know what all their alphabet soup is suppoed to
// mean, so I just made a guess...


class CString
{
public:
  enum { MAX_FORMAT_STRING_SIZE = 8 * 1044 };
  CString()
    : str_()
  {
  }

  CString(
      CString const & rhs)
    : str_(rhs.str_)
  {
  }

  CString(
      char ch,
      int repeat = 1)
    : str_(repeat, ch)
  {
  }

  CString(
      char const * s)
    : str_(s)
  {
  }

  CString & operator=(
      CString const & rhs)
  {
    str_ = rhs.str_;
    return *this;
  }

  CString & operator=(
      char const * s)
  {
    str_ = s;
    return *this;
  }

  CString & operator=(
      char ch)
  {
    str_ = ch;
    return *this;
  }

  void Format(
      char const * fmt,
      ...)
  {
    char buffer[ MAX_FORMAT_STRING_SIZE ];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buffer, fmt, ap);
    va_end(ap);
    str_ = buffer;
  }

  char operator[](
      int x) const
  {
    return str_[x];
  }
  
  CString & operator+=(
      CString const & x)
  {
    str_ += x.str_; return *this;
  }

  int Replace(
      CString const & lhs,
      CString const & rhs)
  {
    int rval = 0;
    std::string::size_type pos = 0;
    while (pos < str_.length())
    {
      pos = str_.find(lhs.str_, pos);
      if (pos != std::string::npos)
      {
        str_.replace(pos, lhs.GetLength(), rhs.str_);
        pos += rhs.GetLength();
        ++rval;
      }
    }
    return rval;
  }

  int GetLength() const
  {
    return str_.length();
  }

  operator char const * () const
  {
    return str_.c_str();
  }

private:
  std::string str_;
};


CString operator+(
    CString const & x,
    CString const & y)
{
  CString result(x);
  result += y;
  return result;
}

#endif // altstr_h_
