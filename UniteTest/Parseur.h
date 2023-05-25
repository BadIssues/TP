#pragma once
#include "pch.h"
#include <string>
#include "../TP/Forme.h"

class Parseur
{
public:
    Forme* parse(const std::string& description);
};
