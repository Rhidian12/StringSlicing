#pragma once

#include <stdexcept>
#include <string>
#include <string_view>

namespace stdproposal
{
    // functions should obviously be part of std::basic_string
    // these are now free functions to show off implementation

    // 1
    std::string_view slice(const std::string& source, size_t start, size_t end)
    {
        if (start >= source.size())
        {
            throw std::out_of_range{ "slice() > Start is out of range" };
        }

        if (end > source.size())
        {
            end = source.size();
        }

        if (end < start)
        {
            end = start;
        }

        return std::string_view(source.data() + start, end - start);
    }

    // 2
    std::string_view first(const std::string& source, size_t count)
    {
        if (count >= source.size())
        {
            count = source.size();
        }

        return std::string_view(source.data(), count);
    }

    // 3
    std::string_view last(const std::string& source, size_t count)
    {
        if (count >= source.size())
        {
            count = source.size();
        }

        return std::string_view(source.data() + (source.size() - count), count);
    }
}