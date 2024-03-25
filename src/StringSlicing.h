#pragma once

#include <stdexcept>
#include <string>
#include <string_view>

namespace stdproposal
{
    // functions should obviously be part of std::basic_string and std::basic_string_view
    // these are now free functions to show off implementation

    // 1
    std::string subview(const std::string& source, size_t start, size_t end)
    {
        if (start >= source.size())
        {
            throw std::out_of_range{ "subview() > Start is out of range" };
        }

        if (end > source.size())
        {
            end = source.size();
        }

        if (end < start)
        {
            end = start;
        }

        return std::string(source.data() + start, end - start);
    }

    // 2
    std::string_view subview(const std::string_view source, size_t start, size_t end)
    {
        if (start >= source.size())
        {
            throw std::out_of_range{ "subview() > Start is out of range" };
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
}