#pragma once

namespace Interview
{
    double Power(double base, unsigned int exp)
    {
        if (0 == exp)
            return 0.0;
        if (1 == exp)
            return base;
        
        double ret = Power(base, exp >> 1);
        ret *= ret;
        if (exp & 0x1 == 1)
            ret *= base;

        return ret;
    }

}