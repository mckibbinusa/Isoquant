/*
  Isoquant, a UCI-compliant chess playing engine
  Copyright (C) 2004-2008 Tord Romstad
  Copyright (C) 2008-2014 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2016 William McKibbin

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License,
  or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, see <http://www.gnu.org/licenses>.
*/

#ifndef NOTATION_H_INCLUDED
#define NOTATION_H_INCLUDED

#include <string>

#include "types.h"

class Position;

std::string score_to_uci(Value v, Value alpha = -VALUE_INFINITE, Value beta = VALUE_INFINITE);
Move move_from_uci(const Position& pos, std::string& str);
const std::string move_to_uci(Move m, bool chess960);

inline char to_char(File f, bool tolower = true) {
  return char(f - FILE_A + (tolower ? 'a' : 'A'));
}

inline char to_char(Rank r) {
  return char(r - RANK_1 + '1');
}

inline const std::string to_string(Square s) {
  char ch[] = { to_char(file_of(s)), to_char(rank_of(s)), 0 };
  return ch;
}

#endif // #ifndef NOTATION_H_INCLUDED
