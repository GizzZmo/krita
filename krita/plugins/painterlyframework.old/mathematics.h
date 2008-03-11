/*
 *  Copyright (c) 2007 Emanuele Tamponi <emanuele@valinor.it>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include "kritapainterlycommon_export.h"

namespace maths {

KRITAPAINTERLYCOMMON_EXPORT double coth(double z);

KRITAPAINTERLYCOMMON_EXPORT double acoth(double z);

KRITAPAINTERLYCOMMON_EXPORT double sigmoid(double v);

KRITAPAINTERLYCOMMON_EXPORT double smoothstep(double min, double max, double v);

KRITAPAINTERLYCOMMON_EXPORT double clamp(double min, double max, double v);

KRITAPAINTERLYCOMMON_EXPORT int sign(double v);

}


#endif // MATHEMATICS_H_
