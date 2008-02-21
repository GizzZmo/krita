/*
 *  Copyright (c) 2007 Boudewijn Rempt boud@valdyas.org
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

#include "kis_complex_color_test.h"

#include <qtest_kde.h>


#include <KoColor.h>
#include <KoColorSpaceRegistry.h>
#include <KoColorSpace.h>
#include "kis_complex_color.h"

void KisComplexColorTest::testCreation()
{
    const KoColorSpace * cs = KoColorSpaceRegistry::instance()->rgb8();
    KoColor cl(Qt::red, cs);
    KisComplexColor a(cs);
    KisComplexColor b(cs, cl);
}


QTEST_KDEMAIN(KisComplexColorTest, GUI)
#include "kis_complex_color_test.moc"
