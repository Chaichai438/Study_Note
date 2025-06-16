#ifndef IMPORTANT_PARAMS_HPP_
#define IMPORTANT_PARAMS_HPP_

#include <vector>
#include <string>

namespace xz_rm
{
    enum Color
    {
        Red,
        Blue,
        None
    };
    const std::vector<std::string> COLORS = {"Red", "Blue", "None"};

    enum ArmorType
    {
        Big,
        Small
    };

    enum ArmorName
    {
        One,
        Two,
        Three,
        Four,
        Five,
        Sentry,
        Outpost,
        Base,
        Unknow
    };
    const std::vector<std::string> ARMOR_NAMES = {"One", "Two", "Three", "Four", "Five",
                                                  "Sentry", "Outpost", "Base", "Unknow"};

    enum ArmorPriority
    {
        first = 1,
        second,
        third,
        forth,
        fifth
    };

}

#endif